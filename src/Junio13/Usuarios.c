/*
 * Usuarios.c
 *
 *  Created on: 8/9/2014
 *      Author: NikNitro
 */

#include <stdio.h>
#include <stdlib.h>
#include "Usuarios.h"

//Crea un usuario a partir de su nombre, UID y directorio home.
T_user* createUser(char* name, int uid, char *dir) {
	T_user *usuario = (T_user*)malloc(sizeof(struct user));
	(*usuario)->userName_=name;
	(*usuario)->uid_=uid;
	(*usuario)->homeDirectory_=dir;
	return usuario;
}

//Devuelve una lista de usuarios vacía
T_userList createUserList() {
	T_userList lista = (T_userList)malloc(sizeof(struct lista));
	lista->head = NULL;
	lista->tail = NULL;
	return lista;
}

//Añade un usuario en la cabeza de la lista previa comprobación que ni el nombre ni el UID ya están en la lista.
//Si se añade con éxito se devuelve 1 y 0 en caso contrario.
int addUser(T_userList* list, T_user us) {
	int id = us->uid_;
	char* nombre = us->userName_;
	int noEsta = 1;
	T_user aux = list->head;

	while(noEsta && aux!=NULL) {
		int igual = strcmp(nombre, aux->userName_);
		if(igual==0 || id==aux->uid_)
			noEsta=0;
		aux = aux->nextUser;
	}

	if(noEsta) {
		T_user cabeza = list->head;
		us->nextUser=cabeza;
		cabeza->previousUser=us;
		list->head=us;
	}
	return noEsta;
}

//Dado el nombre de un usuario, busca su UID en la lista y lo devuelve si lo encuentra; en caso contrario, devuelve -1.
int getUid(T_userList list, char *userName) {

	T_user aux = list->head;
	unsigned ok = 0;
	int UID = -1;

	while(!ok && aux!=NULL) {
		if(aux->userName_==userName) {
			ok = 1;
			UID = aux->uid_;
		}
		else
			aux = aux->nextUser;
	}
	return UID;
}

//Borra a un usuario de la lista. Devuelve 0 si la operación tiene éxito y -1 si el usuario no existe.
int deleteUser(T_userList *list, char* userName) {
	int ok = -1;
	T_user usr= (*list)->head;
	if(usr!=NULL && usr->userName_==userName) {		//Era el primero
		usr->nextUser->previousUser = NULL;
		(*list)->head=usr->nextUser;
		free(usr);
		ok = 0;
	}
	usr = usr->nextUser;
	while(ok==-1 && usr != NULL) {
		if(usr->userName_==userName) {
			usr->previousUser->nextUser = usr->nextUser;
			usr->nextUser->previousUser = usr->previousUser;
			free(usr);
			ok = 0;
		} else{
			usr = usr->nextUser;
		}
	}
	return ok;
}

//Imprime la lista de cabeza a cola o viceversa dependiendo si el segundo argumento es 0 o 1.
void printUserList(T_userList list, int reverse) {
	if(reverse == 0) {
		T_user user = list->head;
		while(user!=NULL) {
			printf(user->userName_);
			printf(" \n");
			user = user->nextUser;
		}
	} else if(reverse == 1) {
		T_user user = list->tail;
		while(user!=NULL) {
			printf(user->userName_);
			printf(" \n");
			user = user->previousUser;
		}
	}
}




















