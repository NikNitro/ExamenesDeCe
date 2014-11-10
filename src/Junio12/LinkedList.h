/*
 * LinkedList.h
 *
 *  Created on: 5/9/2014
 *      Author: NikNitro
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

typedef struct Linked_List* LProc;

struct Linked_List {
	unsigned valor;
	LProc sig;
	LProc ejecucion;

};
//Crea una lista de procesos vacía.
void Crear (LProc *lista);

//Añade el proceso con identificador idproc a la lista de procesos disponibles para ejecución.
//Este proceso se añade como nodo anterior al nodo al que apunta ejecución.
void AnadirProceso (LProc *lista, int idproc);

//Muestra la lista de los procesos que están disponibles para la ejecución.
void MostrarLista( LProc lista);

//Simula la ejecución del proceso apuntado por ejecución, eliminándolo de la lista de procesos.
void EjecutarProceso(LProc *lista);


#endif /* LINKEDLIST_H_*/
