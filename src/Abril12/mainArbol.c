/*
 * mainArbol.c
 *
 *  Created on: 5/9/2014
 *      Author: NikNitro
 */


#include <stdio.h>
#include <stdlib.h>
#include "Arbol.h"



int mainArbol () {

	TArbol arb;

	CrearABB(&arb);
	RecorrerABB(arb);

	InsertarEnABB(&arb,21);
	InsertarEnABB(&arb,5);
	InsertarEnABB(&arb,78);
	InsertarEnABB(&arb,1);
	InsertarEnABB(&arb,7);
	InsertarEnABB(&arb,45);

	printf("Despues de introducir: 21, 5, 78, 1, 7, 45 el arbol es \n");

	RecorrerABB (arb);
	fflush(stdout);
	system("PAUSE");

	InsertarEnABB (&arb,90);
	InsertarEnABB (&arb,4);
	InsertarEnABB (&arb,6);
	InsertarEnABB (&arb,15);
	InsertarEnABB (&arb,77);
	InsertarEnABB (&arb,80);
	InsertarEnABB (&arb,99);
	printf("Despues de introducir: 21, 5, 78, 1, 7, 45, 90,4,6,15,77,80,99 el arbol es \n");
	RecorrerABB (arb);

	fflush(stdout);
	system("PAUSE");
	printf("Destruimos el arbol\n");
	DestruirABB(&arb);

	fflush(stdout);

	printf("Fin Programa\n");

	fflush(stdout);
	system("PAUSE");

	return 0;
}
