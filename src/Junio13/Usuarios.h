/*
 * Usuarios.h
 *
 *  Created on: 8/9/2014
 *      Author: NikNitro
 */

#ifndef USUARIOS_H_
#define USUARIOS_H_

typedef struct user* T_user;
struct user {
	int uid_;
	char *userName_;
	char *homeDirectory_;

	struct user *nextUser;
	struct user *previousUser;
};

typedef struct lista* T_userList;
struct lista {
	T_user* head;
	T_user* tail;
};

//Crea un usuario a partir de su nombre, UID y directorio home.
T_user* createUser(char* name, int uid, char *dir);

//Devuelve una lista de usuarios vacía
T_userList createUserList();

//Añade un usuario en la cabeza de la lista previa comprobación que ni el nombre ni el UID ya están en la lista.
//Si se añade con éxito se devuelve 1 y 0 en caso contrario.
int addUser(T_userList*, T_user);

//Dado el nombre de un usuario, busca su UID en la lista y lo devuelve si lo encuentra; en caso contrario, devuelve -1.
int getUid(T_userList list, char *userName);

//Borra a un usuario de la lista. Devuelve 0 si la operación tiene éxito y -1 si el usuario no existe.
int deleteUser(T_userList *list, char* userName) ;

//Imprime la lista de cabeza a cola o viceversa dependiendo si el segundo argumento es 0 o 1.
void printUserList(T_userList list, int reverse) ;


#endif /* USUARIOS_H_ */
