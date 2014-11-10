/*
 * Tareas.c
 *
 *  Created on: 6/9/2014
 *      Author: NikNitro
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tareas.h"

void Crear(T_Planificador *planif) {
	*planif= NULL;
}

void insertar_tarea(T_Planificador *planif, int pri, char *id) {
	T_Planificador plan = *planif;
	Tarea nuevo = (Tarea)malloc(sizeof(struct T_Tarea));
	nuevo->id = id;
	nuevo->prioridad = pri;
	nuevo->sig = NULL;

	if(plan==NULL) {
		plan = (T_Planificador)malloc(sizeof(struct Planificador));
		plan->prim = nuevo;
		*planif = plan;
	} else if(pri>((*planif)->prim)->prioridad) {	//Si es el primero

		Tarea aux = (*planif)->prim;
		nuevo->sig = aux;
		(*planif)->prim = nuevo;
	} else {
		Tarea aux = (*planif)->prim;

		while((aux->sig)!= NULL && (pri<=(aux->sig)->prioridad)) {		//Para que encuentre el último de los iguales
			aux = aux->sig;
		}
		if(aux!=NULL)
			nuevo->sig = aux->sig;

		aux->sig = nuevo;

	}
}

void mostrar(T_Planificador planif) {
	if(planif==NULL)
		printf("El planificador está vacío.\n");
	else{
		printf("La lista del planificador es la siguiente: \n");
		Tarea t = planif->prim;
		while(t!=NULL) {
			printf("\n  ->");
			char* aux = t->id;
			printf(aux);
			t = t->sig;
			fflush(stdout);

		}

	}
	printf("\n");
	fflush(stdout);

}

void eliminar_tarea(T_Planificador *planif, char *id, unsigned *ok) {
	printf(id);
	if(*planif!=NULL) {
		Tarea ptr = (*planif)->prim;
		Tarea ant = NULL;
		*ok = 0;

		while(!(*ok) && ptr != NULL) {
			if( (strcmp((ptr->id), id)!=0) ) {//Seguimos buscando
				ant = ptr;
				ptr = ptr->sig;
			} else {							//La hemos encontrado
				if(ant!=NULL)
					ant->sig = ptr->sig;
				else
					(*planif)->prim = ptr->sig;
				free(ptr);
				*ok = 1;
			}

		}
	}

}

void planificar(T_Planificador *planif) {
	if(*planif!=NULL && (*planif)->prim != NULL){
		Tarea t = (*planif)->prim;
		(*planif)->prim = t->sig;
		free(t);
	}
}

void destruir(T_Planificador *planif) {
	if(*planif!=NULL){
		Tarea t = (*planif)->prim;
		Tarea ant = NULL;
		while(t!=NULL){
			ant = t;
			free(ant);
			t = t->sig;
		}
		free(planif);
	}
}
