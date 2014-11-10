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
//Crea una lista de procesos vac�a.
void Crear (LProc *lista);

//A�ade el proceso con identificador idproc a la lista de procesos disponibles para ejecuci�n.
//Este proceso se a�ade como nodo anterior al nodo al que apunta ejecuci�n.
void AnadirProceso (LProc *lista, int idproc);

//Muestra la lista de los procesos que est�n disponibles para la ejecuci�n.
void MostrarLista( LProc lista);

//Simula la ejecuci�n del proceso apuntado por ejecuci�n, elimin�ndolo de la lista de procesos.
void EjecutarProceso(LProc *lista);


#endif /* LINKEDLIST_H_*/
