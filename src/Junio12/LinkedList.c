/*
 * LinkedList.c
 *
 *  Created on: 5/9/2014
 *      Author: NikNitro
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void CrearL (LProc *lista) {	//la L sobra
	*lista = NULL;
}

void AnadirProceso (LProc *lista, int idproc) {
	LProc* aux = lista;

	if(*aux == NULL){

		LProc nuevo = (LProc)malloc(sizeof(struct Linked_List));
		nuevo->valor = idproc;
		nuevo->sig   = nuevo;
		nuevo->ejecucion = nuevo;
		*lista = nuevo;
	} else {

		LProc nuevo = (LProc)malloc(sizeof(struct Linked_List));
		nuevo->valor = idproc;
		nuevo->sig   = (*lista)->ejecucion;
		nuevo->ejecucion = (*lista)->ejecucion;

		while((*aux)->sig != (*aux)->ejecucion)
			(*aux) = (*aux)->sig;	//Hacemos de aux el anterior a lista

		(*aux)->sig = nuevo;
	}
}

void MostrarLista( LProc lista) {
	if(lista!=NULL) {
		LProc aux = lista->ejecucion;
		while(aux->sig!=lista->ejecucion) {
			printf("%d, ", aux->valor);
			aux = aux->sig;
		}
		printf("%d.\n", aux->valor);	//Para el último
		fflush(stdout);
	}
}

void EjecutarProceso(LProc *lista) {
	if(*lista!=NULL){
		LProc ejec = (*lista)->ejecucion;
		LProc sig  = ejec->sig;
		LProc* aux = lista;
		while((*aux)->ejecucion == ejec) {
			(*aux)->ejecucion = sig;
			if((*aux)->sig  == ejec)
				(*aux)->sig = sig;

			*aux = (*aux)->sig;
		}
		free( (void*) ejec);

	}
}
