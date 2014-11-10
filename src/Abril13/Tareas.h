/*
 * Tareas.h
 *
 *  Created on: 6/9/2014
 *      Author: NikNitro
 */

#ifndef TAREAS_H_
#define TAREAS_H_

typedef struct T_Tarea* Tarea;
struct T_Tarea {

	char* id;
	int prioridad;
	Tarea sig;
};

typedef struct Planificador* T_Planificador;
struct Planificador {
	Tarea prim;
};

void crear(T_Planificador *planif);
//Inicializa el planificador creando un planificador vacío.

void insertar_tarea(T_Planificador *planif,int pri,char *id);
//Inserta una nueva tarea id de prioridad pri en el planificador planif.
//La lista está ordenada por prioridad y en el caso de que exista una tarea con la misma prioridad se almacenará por orden de llegada.
//El identificador de tarea es único.

void mostrar (T_Planificador planificador);
//Muestra el estado del planificador.

void eliminar_tarea(T_Planificador *planif,char *id,unsigned *ok);
////Dado un planificador, elimina una tarea id que está preparada para ejecución.
//En el caso de que no exista dicha tarea, se devolverá 0 en el parámetro ok. OK valdrá 1 en el caso de que se haya realizado el borrado.

void planificar(T_Planificador *planif);
//Extrae de la estructura la tarea que le corresponde ejecutarse.

void destruir(T_Planificador *planif);
//Destruye toda la estructura eliminando y liberando la memoria de todos los nodos.


#endif /* TAREAS_H_ */
