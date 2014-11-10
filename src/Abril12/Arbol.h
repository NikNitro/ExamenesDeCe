/*
 * Arbol.h
 *
 *  Created on: 4/9/2014
 *      Author: NikNitro
 */

#ifndef ARBOL_H_
#define ARBOL_H_

typedef struct T_Arbol* TArbol;

struct T_Arbol {
	int valor;
	TArbol izq;
	TArbol der;

};

//Este procedimiento construye un �rbol binario de b�squeda vacio.
	void CrearABB(TArbol *arb);
//Este procedimiento inserta elem en un �rbol binario de b�squeda. Despu�s de la inserci�n el �rbol seguir� siendo un ABB
	void InsertarEnABB(TArbol *arb, int elem);
//Dado un �rbol binario de b�squeda, este procedimiento muestra en pantalla los elementos del �rbol ordenados de menor a mayor.
	void RecorrerABB(TArbol arb);
//Este procedimiento libera la memoria de todos los nodos del �rbol.
	void DestruirABB(TArbol *arb);


#endif /* ARBOL_H_ */

