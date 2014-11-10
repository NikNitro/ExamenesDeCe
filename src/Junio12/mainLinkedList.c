/*
 * mainLinkedList.c
 *
 *  Created on: 6/9/2014
 *      Author: NikNitro
 */


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"



int mainLink () {

	LProc list;

	Crear(&list);
	MostrarLista(list);

	AnadirProceso(&list, 3);
	AnadirProceso(&list, 8);
	AnadirProceso(&list, 1);
	AnadirProceso(&list, 14);
	AnadirProceso(&list, 0);

	printf("Despues de introducir: 3, 8, 1, 14, 0 la lista es es \n");

	MostrarLista(list);
	system("PAUSE");

	AnadirProceso(&list, 7);
	AnadirProceso(&list, 15);
	AnadirProceso(&list, 19);
	AnadirProceso(&list, 20);
	AnadirProceso(&list, 50);


	printf("Despues de introducir: 3, 8, 1, 14, 0, 7, 15, 19, 20, 50 la lista es es \n");
	MostrarLista(list);
	system("PAUSE");


	printf("Tras ejecutar 3 procesos");
	EjecutarProceso(&list);
	EjecutarProceso(&list);
	EjecutarProceso(&list);

	MostrarLista(list);
	system("PAUSE");

	printf("Fin Programa\n");

	fflush(stdout);
	system("PAUSE");

	return 0;
}
