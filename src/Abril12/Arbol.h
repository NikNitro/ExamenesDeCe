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

//Este procedimiento construye un árbol binario de búsqueda vacio.
	void CrearABB(TArbol *arb);
//Este procedimiento inserta elem en un árbol binario de búsqueda. Después de la inserción el árbol seguirá siendo un ABB
	void InsertarEnABB(TArbol *arb, int elem);
//Dado un árbol binario de búsqueda, este procedimiento muestra en pantalla los elementos del árbol ordenados de menor a mayor.
	void RecorrerABB(TArbol arb);
//Este procedimiento libera la memoria de todos los nodos del árbol.
	void DestruirABB(TArbol *arb);


#endif /* ARBOL_H_ */

