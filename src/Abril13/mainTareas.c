#include <stdio.h>
#include <stdlib.h>
#include "Tareas.h"



int mainT () {

	T_Planificador planificador;
	 Crear(&planificador);
	 insertar_tarea(&planificador, 4, "t8");
	 insertar_tarea(&planificador, 8, "t1");
	 insertar_tarea(&planificador, 3, "t7");
	 insertar_tarea(&planificador, 8, "t2");
	 insertar_tarea(&planificador, 1, "t3");
	 mostrar(planificador);
	 planificar(&planificador);
	 mostrar(planificador);
	 planificar(&planificador);
	 mostrar(planificador);
	 destruir(&planificador);

	 return EXIT_SUCCESS;

/*	T_Planificador planif;

	Crear(&planif);
	mostrar(planif);
	system("PAUSE");
	unsigned* i = (unsigned*)5;
	char* c = "hola";
	eliminar_tarea(&planif, &c, &i);

	insertar_tarea(&planif, 2, c);

	printf("Despues de introducir 'hola' con prioridad 2\n");
	fflush(stdout);
	mostrar(planif);

	c = "que";
	insertar_tarea(&planif, 5, c);
	c = "Cojones?";
	insertar_tarea(&planif, 1, c);
	c = "123";
	insertar_tarea(&planif, 2, c);

	printf("Despues de introducir 'hola' con prioridad 2, 'que' -> 5, 'Cojones?' -> 1, '123' -> 2\n");
	fflush(stdout);
	mostrar(planif);

	printf("Eliminamos hola \n");
	 char* d = "hola";
	eliminar_tarea(&planif, d, &i);
	mostrar(planif);

	return 0;*/
}
