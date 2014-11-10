/*
 * Arbol.c
 *
 *  Created on: 4/9/2014
 *      Author: NikNitro
 */
#include <stdlib.h>
#include <stdio.h>
#include "Arbol.h"


void CrearABB(TArbol *arb) {
	*arb = NULL;

}
/*
void InsertarEnABB(TArbol *arb, int elem) {
	TArbol aux = malloc(sizeof(struct T_Arbol));
		aux->valor = elem;
		aux->izq = NULL;
		aux->der = NULL;

		if(arb==NULL)		//El árbol está vacío
			*arb = aux;
		else if(elem< ((*arb)->valor))
			InsertarEnABB(&((*arb)->izq), elem);
		else if(elem> ((*arb)->valor))
			InsertarEnABB(&((*arb)->der), elem);
}*/

void InsertarEnABB(TArbol *arb, int elem) {
	TArbol auxi = *arb;
	TArbol aux = malloc(sizeof(struct T_Arbol));
	aux->valor = elem;
	aux->izq = NULL;
	aux->der = NULL;

	if(auxi==NULL)		//El árbol está vacío
		*arb = aux;
	else {
		//Lo recorremos
		while(auxi != NULL) {
			if((auxi->valor)<elem && (auxi->der)== NULL)
				auxi->der = aux;
			else if((auxi->valor)>elem && (auxi->izq)==NULL)
				auxi->izq = aux;
			else if((auxi->valor)<elem)
				auxi = auxi->der;
			else
				auxi=auxi->izq;

		}
		//aux tiene el nodo donde debemos meter
		//auxi = aux;
	}//Fin else
}

void RecorrerABB(TArbol arb) {
	if(arb!=NULL){
		if(arb->izq != NULL)
			RecorrerABB(arb->izq);
		printf("%d ", arb -> valor);
		if(arb->der!=NULL)
			RecorrerABB(arb->der);
		}
}

void DestruirABB(TArbol *arb) {
	if((*arb)->izq != NULL)
		DestruirABB(&(*arb)->izq);
	if ((*arb)->der != NULL)
		DestruirABB(&(*arb)->der);
	free((void *)*arb);

}


