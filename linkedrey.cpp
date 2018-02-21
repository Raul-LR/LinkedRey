#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct Usuario{
	string login;
	string nombre;
	string apellido1;
	int edad;
	string localidad;
	string *competencias;
	int dim_competencias;
	int util_competencias;
};

struct TablaU{
	Usuario** punteroapuntero;
	int totaltuplas;
};

/**
*@Brief, Módulo que inicializa el valor de login en la estructura Usuario.
*@Param, *user -> Dirección de la burbuja Usuario, nuevo_login -> nuevo login a introducir en el Usuario.
*/
void setLogin(Usuario *user, string nuevo_login){
	user->login = nuevo_login;
}

/**
*@Brief, Módulo que inicializa el valor de nombre en la estructura Usuario.
*@Param, *user -> Dirección de la burbuja Usuario, nuevo_nombre -> nuevo nombre a introducir en el Usuario.
*/
void setNombre(Usuario *user, string nuevo_nombre){
	user->nombre = nuevo_nombre;
}

/**
*@Brief, Módulo que inicializa el valor de apellido1 en la estructura Usuario.
*@Param, *user -> Dirección de la burbuja Usuario, nuevo_apellido1 -> nuevo apellido1 a introducir en el Usuario.
*/
void setApellido1(Usuario *user, string nuevo_apellido1){
	user->apellido1 = nuevo_apellido1;
}

/**
*@Brief, Módulo que inicializa el valor de login en la estructura Usuario.
*@Param, *user -> Dirección de la burbuja Usuario, nueva_edad -> nuevo login a introducir en el Usuario.
*/
void setEdad(Usuario *user, int nueva_edad){
	user->edad = nueva_edad;
}

/**
*@Brief, Módulo que inicializa el valor de localidad en la estructura Usuario.
*@Param, *user -> Dirección de la burbuja Usuario, nueva_localidad -> nuevo localidad a introducir en el Usuario.
*/
void setLocalidad(Usuario *user, string nueva_localidad){
	user->localidad = nueva_localidad;
}

/**
*@Brief, Módulo que inicializa el valor de competencias en la estructura Usuario.
*@Param, *user -> Dirección de la burbuja Usuario, competencias -> nuevas_competencias a introducir en el Usuario.
*/
void setCompetencias(Usuario *user, string* nuevas_competencias){
	user->competencias = nuevas_competencias;
}

/**
*@Brief, Módulo que inicializa el valor de util_competencias en la estructura Usuario.
*@Param, *user -> Dirección de la burbuja Usuario, nuevas_utiles -> nuevo util_competencias a introducir en el Usuario.
*/
void setUtil_competencias(Usuario *user, int nuevas_utiles){
	user->util_competencias = nuevas_utiles;
}

/**
*@Brief, Módulo que inicializa el valor de dim_competencias en la estructura Usuario.
*@Param, *user -> Dirección de la burbuja Usuario, nueva_dim -> nuevo dim_competencias a introducir en el Usuario.
*/
void setDim_competencias(Usuario *user, int nueva_dim){
	user->dim_competencias = nueva_dim;
}

/**
*@Brief, Módulo que inicializa el valor de totaltuplas en la estructura Usuario.
*@Param, *user -> Dirección de la burbuja Usuario, nuevo_totaltuplas -> nuevo totaltuplas a introducir en el Usuario.
*/
void setTotaltuplas(TablaU *tabla, int nuevo_totaltuplas){
	tabla->totaltuplas = nuevo_totaltuplas;
}

/**
*@Brief, Módulo que devuelve el valor de login de la estructura Usuario.
*@Param, *user -> Dirección de la burbuja Usuario.
*/
string getLogin(Usuario *user){
	return user->login;
}

/**
*@Brief, Módulo que devuelve el valor de nombre de la estructura Usuario.
*@Param, *user -> Dirección de la burbuja Usuario.
*/
string getNombre(Usuario *user){
	return user->nombre;
}

/**
*@Brief, Módulo que devuelve el valor de Apellido1 de la estructura Usuario.
*@Param, *user -> Dirección de la burbuja Usuario.
*/
string getApellido1(Usuario *user){
	return user->apellido1;
}

/**
*@Brief, Módulo que devuelve el valor de Edad de la estructura Usuario.
*@Param, *user -> Dirección de la burbuja Usuario.
*/
int getEdad(Usuario *user){
	return user->edad;
}

/**
*@Brief, Módulo que devuelve el valor de localidad de la estructura Usuario.
*@Param, *user -> Dirección de la burbuja Usuario.
*/
string getLocalidad(Usuario *user){
	return user->localidad;
}

/**
*@Brief, Módulo que devuelve el valor de competencias de la estructura Usuario.
*@Param, *user -> Dirección de la burbuja Usuario.
*/
string* getCompetencias(Usuario *user){
	return user->competencias;
}

/**
*@Brief, Módulo que devuelve el valor de util_competencias de la estructura Usuario.
*@Param, *user -> Dirección de la burbuja Usuario.
*/
int getUtil_competencias(Usuario *user){
	return user->util_competencias;
}

/**
*@Brief, Módulo que devuelve el valor de dim_competencias de la estructura Usuario.
*@Param, *user -> Dirección de la burbuja Usuario.
*/
int getDim_competencias(Usuario *user){
	return user->dim_competencias;
}

/**
*@Brief, Módulo que devuelve el valor de totaltuplas de la estructura Usuario.
*@Param, *user -> Dirección de la burbuja Usuario.
*/
int getTotaltuplas(TablaU *tabla){
	return tabla->totaltuplas;
}

/**
*@Brief, Módulo que imprimirá las competencias de un usuario.
*/
void imprimeCompetencias(Usuario *user){
	for (int i = 0; i < user->util_competencias; ++i)
	{
		cout << "	| " << user->competencias[i] << endl;
	}
}

/**
*@Brief, Módulo que imprimirá un usuario.
*/
void imprimeUsuario(Usuario *user){
	cout << "-----------------------------------" << endl;
	cout << ">Login: " << getLogin(user) << endl;
	cout << ">Nombre: " << getNombre(user) << endl;
	cout << ">Apellido: " << getApellido1(user) << endl;
	cout << ">Edad: " << getEdad(user) << endl;
	cout << ">Localidad: " << getLocalidad(user) << endl;
	cout << ">Competencias: " << endl;
	imprimeCompetencias(user);
}

/**
*@Brief, Módulo que imprimirá las tabla actual.
*/
void imprimeTabla(TablaU *tabla){
	for (int i = 0; i < tabla->totaltuplas; ++i)
	{
		imprimeUsuario(tabla->punteroapuntero[i]);
	}
	cout << "-----------------------------------" << endl;
}

/**
*@Brief, Módulo que se encargará de ordenar la tabla por sus competencias.
*/
void ordenarTabla(TablaU *tabla){
	bool cambio = true;
	for (int izqd = 0; izqd < tabla->totaltuplas && cambio; ++izqd)
	{
		cambio = false;
		for (int i = tabla->totaltuplas - 1; i > izqd; --i)
		{
			if (getNombre(tabla->punteroapuntero[i]) < getNombre(tabla->punteroapuntero[i - 1]))
			{
				cambio = true;

				Usuario *user_aux = tabla->punteroapuntero[i];
				tabla->punteroapuntero[i] = tabla->punteroapuntero[i - 1];
				tabla->punteroapuntero[i -1] = user_aux; 
			}
		}
	}
}

/**
*@Brief, Módulo que se encargará de liberar la memoria del vector competencias.
*/
void liberaCompetencias(Usuario *user){
	delete [] user->competencias;
	user->competencias = 0;
}

/**
*@Brief, Módulo que se encargará de liberar la memoria de la burbuja usuario.
*/
void liberaUsuario(Usuario *user){
	liberaCompetencias(user); //Primero para poder liberar a un usuario hay que eliminar su vector competencias.
	delete user;
	user = 0;
}

/**
*@Brief, Módulo que se encargará de liberar la memoria de la tabla.
*/
void liberaTabla(TablaU *tabla){
	for (int i = 0; i < tabla->totaltuplas; ++i)
	{
		liberaUsuario(tabla->punteroapuntero[i]); //Primero tendrá que liberar el espacio de usuarios para poder liberar la tabla.
	}
	delete [] tabla;
	tabla = 0;
}

void inicializacionInicial(TablaU *tabla){
	for (int i = 0; i < tabla->totaltuplas; ++i)
	{
		tabla->punteroapuntero[i] = 0;
	}
}

/**
*@Brief, Móodulo que inicializará las competencias dentro de cada usuario.
*/
void inicializaVcompetencias(Usuario *user){
	string vacio = " ";
	user->competencias = new string[user->dim_competencias];
	if (user->competencias == 0)
	{
		cerr << "No hay espacio suficiente en memoria, se dentendrá la ejecución del programa." << endl;
	}
	for (int i = 0; i < user->util_competencias; ++i)
	{
		user->competencias[i] = vacio;
	}
}

void copiarCompetencias(Usuario *user_aux, Usuario *user){
	setUtil_competencias(user_aux, getUtil_competencias(user));
	setDim_competencias(user_aux, getDim_competencias(user));
	inicializaVcompetencias(user_aux);
	for (int i = 0; i < user_aux->util_competencias; ++i)
	{
		user_aux->competencias[i] = user->competencias[i];
	}
}

Usuario* copiaUsuario(Usuario *user){
	Usuario *user_aux;
	user_aux = new Usuario;
	setLogin(user_aux, getLogin(user));
	setNombre(user_aux, getNombre(user));
	setApellido1(user_aux, getApellido1(user));
	setEdad(user_aux, getEdad(user));
	setLocalidad(user_aux, getLocalidad(user));
	copiarCompetencias(user_aux, user);

	return user_aux;

	delete user_aux;
}

/**
*@Brief, Módulo que se encargará de gestionar la memoria del vector a punteros (la tabla).
*/
TablaU* gestorMemoria_tabla(TablaU *tabla){
//Se encargará de incrementar de 1 a 1 la dimensión, o decrementarla 1 a 1, cuando se detecte que no hay
//más espacio reservado, para la memoria.
	TablaU *tabla_aux;
	tabla_aux = new TablaU;
	tabla_aux->totaltuplas = tabla->totaltuplas + 1;
	tabla_aux->punteroapuntero = new Usuario*[tabla_aux->totaltuplas];

	inicializacionInicial(tabla_aux);
//Y se copiará el contenido en el nuevo espacio de memoria reservada.
	for (int i = 0; i < tabla->totaltuplas; ++i)
	{
		tabla_aux->punteroapuntero[i] = copiaUsuario(tabla->punteroapuntero[i]);
	}

	liberaTabla(tabla); //llamará a una función que se encargará de liberar el espacio de eliminar la antigua tabla.

	return tabla_aux;
	liberaTabla(tabla_aux);
}

/**
*@Brief, Módulo que se encargará de gestionar la memoria del vector competencias.
*/
Usuario* gestorMemoria_competencias(Usuario *user){
//Se encargará de incrementar al doble la dimensiónn, siempre que detecte que no hay más espacio 
//reservado para más usuarios.
	Usuario *user_aux;
	user_aux = new Usuario;
	string *competencias_aux;
	competencias_aux = new string[user->dim_competencias];

	competencias_aux = user->competencias;
	user_aux = user;

	if (user->util_competencias >= user->dim_competencias)
	{
		user_aux->dim_competencias = user->dim_competencias * 2;
		inicializaVcompetencias(user_aux);
		for (int i = 0; i < user_aux->util_competencias; ++i)
		{
			user_aux->competencias[i] = competencias_aux[i];
		}
	}

	return user_aux;
	liberaUsuario(user_aux);
	delete [] competencias_aux;
}

/**
*@Brief, Busqueda de usuario dentro de la tabla por competencias.
*/
int busquedacompetencias(Usuario *user, string competencia){
	bool encontrado;
	int i;
	int posicion_competencia;

	for (i = 0; i < user->util_competencias && !encontrado; i++)
	{
		encontrado = (user->competencias[i] == competencia);
	}

	posicion_competencia = (i -1);
	
	if (encontrado){
		return posicion_competencia;
	}
	else{
		return -1;
	}	
}

/**
*@Brief, Busqueda de usuario dentro de la tabla por login.
*/

int busquedaUsuariologin(TablaU *tabla, string login){
	bool encontrado;
	int i;
	int posicion_usuario;

	for (i = 0; i < tabla->totaltuplas && !encontrado; i++)
	{
		encontrado = (getLogin(tabla->punteroapuntero[i]) == login);
	}

	posicion_usuario = (i -1);
	
	if (encontrado){
		return posicion_usuario;
	}
	else{
		return -1;
	}
}

/**
*@Brief, Módulo que nos permitirá eliminar competencias en un usuario.
*/
void eliminaCompetencias(Usuario *user, int posicion_competencia){
//Primero se le pedirá al usuario que inserte el nombre del usuario del que querrá eliminar las competencias.
//Una vez encontrado el usuario, se pediran las competencias a eliminar y se introduciran.
	string competencia_aux;
	int ultima_posicion = user->util_competencias - 1;

	competencia_aux = user->competencias[posicion_competencia];
	user->competencias[posicion_competencia] = user->competencias[ultima_posicion];
	user->competencias[ultima_posicion] = competencia_aux;
	user->competencias[ultima_posicion] = "";
	user->util_competencias--;
}

/**
*@Brief, Módulo que nos permitirá introducir competencias en un usuario.
*/
void insertaCompetencias(Usuario *user){
//Una vez encontrado el usuario, se pediran las competencias a introducir y se introduciran.

	if (user->util_competencias < user->dim_competencias)
	{
		user->util_competencias++;
		cout << "Introduzca la competencia que quiere añadir: ";
		cin >> user->competencias[user->util_competencias - 1];
	}
	else if (user->util_competencias >= user->dim_competencias)
	{
		user = gestorMemoria_competencias(user); //Se gestionará la memoria en el caso de que no haya más espacio reservado para estas.
		user->util_competencias++;
		cout << "Introduzca la competencia que quiere añadir: ";
		cin >> user->competencias[user->util_competencias - 1];
	}
}

/**
*@Brief, Módulo que nos permitirá eliminar un usuario.
*/
void eliminaUsuario(TablaU *tabla, int posicion_usuario){
	int ultima_posicion = tabla->totaltuplas - 1;
	char tecla;
	Usuario *user_aux;
	user_aux = new Usuario;
	if (user_aux == 0)
	{
		cerr << "No hay memoria suficiente, se va a detener la ejecución del programa." << endl;
	}

	if(posicion_usuario != -1 && posicion_usuario < tabla->totaltuplas){
		cout << "Bien, se va a Borrar el usuario introducido, estás seguro (S-Sí/N-No): "; 
		cin >> tecla;

		switch (tecla){
			case 's':
				user_aux = tabla->punteroapuntero[posicion_usuario];
				tabla->punteroapuntero[posicion_usuario] = tabla->punteroapuntero[ultima_posicion];
				tabla->punteroapuntero[ultima_posicion] = user_aux;
				liberaUsuario(tabla->punteroapuntero[ultima_posicion]);
				tabla->totaltuplas--;

				cout << "El usuario se ha borrado con exito." << endl;
				break;
			case 'n':
				cout << "Ha decidido cancelar." << endl;
				break;
			default:
				cerr << "Por favor, use unicamente S o N, Gracias." << endl;
		}
	}
	else
		cout << "No existe el usuario introducido." << endl;
}

/**
*@Brief, Módulo que insertará competencias dentro del vector competencias dentro del Usuario.
*/
void insertaVcompetencias(Usuario *user, string competencia){
	int salida = 0;
	for (int i = 0; i < user->util_competencias; ++i)
	{
		if (user->competencias[i] == " " && salida != 1)
		{
			user->competencias[i] = competencia;
			salida = 1;
		}
	}
}

/**
*@Brief, Módulo que inicializará usuario.
*/
void inicializaUsuario(TablaU *tabla, Usuario *user){
	int salida = 0;
	for (int i = 0; i < tabla->totaltuplas; ++i)
	{
		if (tabla->punteroapuntero[i] == 0 && salida != 1)
		{
			tabla->punteroapuntero[i] = user;
			salida = 1;
		}
	}
}

/**
*@Brief, Módulo que nos va a crear un usuario, y seguidamente inicializar estos en la tabla.
*/
void crearUsuario(TablaU *tabla, Usuario *user){
	user = new Usuario;
	if (user == 0)
	{
		cerr << "No hay memoria suficiente, se va a detener la ejecución del programa." << endl;
	}
	string login;
	string nombre;
	string apellido;
	int edad = 0;
	string localidad;
	int util_competencias = 0;
	string competencia;
//creación de un usuario (se le piden datos al usuario, y se almacenan en variables).
	cout << "Ha elegido crear un usuario, porfavor introduzca los datos pertinentes del usuario." << endl;
	cout << "Login: "; 
	cin >> login;
	setLogin(user, login);
	cout << "Nombre: ";
	cin >> nombre;
	setNombre(user, nombre);
	cout << "Apellido: ";
	cin >> apellido;
	setApellido1(user, apellido);
	cout << "Edad (mayor de 16): ";
	do{
		cin >> edad;
		if (edad < 16)
		{
			cerr << "Eres demasiado joven para poder registrarte, lo sentimos, ¡Prueba con otra edad!." << endl;
		}
	}while(edad < 16);
	setEdad(user, edad);
	cout << "Localidad: ";
	cin >> localidad;
	setLocalidad(user, localidad);
	cout << "Ahora por favor, indique cuantas competencias quiere introducir: ";
	cin >> util_competencias;
	setUtil_competencias(user, util_competencias);
	setDim_competencias(user, 5);
	
	cout << "Ahora introduce las correspondientes competencias: ";
	inicializaVcompetencias(user);

	for (int i = 0; i < user->util_competencias; ++i)
	{
		cin >> competencia;
		insertaVcompetencias(user, competencia);
	}

	inicializaUsuario(tabla, user); //llamada a la función despúes de la creación del usuario.
	cout << "Muchas gracias por registrarte en nuestra red Linkedrey, ¡se bienvenido!, estos son sus datos: " << endl;
	imprimeUsuario(user);

}

/**
*@Brief, Módulo que nos va a crear una tabla, y seguidamente coger los usuarios "pre-asignados".
*/
TablaU* crearTabla(TablaU *tabla){
	cout << "Enhorabuena, se ha conectado con el servidor correctamente." << endl;
	tabla = new TablaU;
	tabla->totaltuplas = 5;
	tabla->punteroapuntero = new Usuario*[tabla->totaltuplas];
	if (tabla->punteroapuntero == 0)
	{
		cerr << "No hay memoria suficiente, se va a detener la ejecución del programa." << endl;
		exit(-1);
	}
	inicializacionInicial(tabla);
/*******CREAMOS A LOS USUARIOS PREFIJADOS********/
	
	Usuario *Lolo;
	Lolo = new Usuario;
	if (Lolo == 0){
		cerr << "No hay memoria suficiente, se va a deterner la ejecución del programa." << endl;
		exit(-1);
	}
	Usuario *Isaac;
	Isaac = new Usuario;
	if (Isaac == 0){
		cerr << "No hay memoria suficiente, se va a deterner la ejecución del programa." << endl;
		exit(-1);
	}
	Usuario *Arturo;
	Arturo = new Usuario;
	if (Arturo == 0){
		cerr << "No hay memoria suficiente, se va a deterner la ejecución del programa." << endl;
		exit(-1);
	}
	Usuario *Antonio;
	Antonio = new Usuario;
	if (Antonio == 0){
		cerr << "No hay memoria suficiente, se va a deterner la ejecución del programa." << endl;
		exit(-1);
	}
	Usuario *Tarek;
	Tarek = new Usuario;
	if (Tarek == 0){
		cerr << "No hay memoria suficiente, se va a deterner la ejecución del programa." << endl;
		exit(-1);
	}

	setNombre(Lolo, "Lolo");
	setLogin(Lolo, "@green");
	setApellido1(Lolo, "Palma");
	setEdad(Lolo, 26);
	setLocalidad(Lolo, "Granada");
	setUtil_competencias(Lolo, 5);
	setDim_competencias(Lolo, 10);
	setNombre(Isaac, "Isaac");
	setLogin(Isaac, "@Dimitri");
	setApellido1(Isaac, "Stalinovki");
	setEdad(Isaac, 20);
	setLocalidad(Isaac, "Granada");
	setUtil_competencias(Isaac, 4);
	setDim_competencias(Isaac, 5);
	setNombre(Arturo, "Arturo");
	setLogin(Arturo, "@ryder");
	setApellido1(Arturo, "Muñoz");
	setEdad(Arturo, 28);
	setLocalidad(Arturo, "Granada");
	setUtil_competencias(Arturo, 3);
	setDim_competencias(Arturo, 7);
	setNombre(Antonio, "Antonio");
	setLogin(Antonio, "@halamadrid");
	setApellido1(Antonio, "loquillo");
	setEdad(Antonio, 19);
	setLocalidad(Antonio, "Granada");
	setUtil_competencias(Antonio, 5);
	setDim_competencias(Antonio, 8);
	setNombre(Tarek, "Tarek");
	setLogin(Tarek, "@smoke");
	setApellido1(Tarek, "husmeante");
	setEdad(Tarek, 27);
	setLocalidad(Tarek, "Granada");
	setUtil_competencias(Tarek, 3);
	setDim_competencias(Tarek, 5);
	inicializaUsuario(tabla, Lolo);
	inicializaVcompetencias(Lolo);
	insertaVcompetencias(Lolo, "Animalista");
	insertaVcompetencias(Lolo, "Amante de la zanahoria");
	insertaVcompetencias(Lolo, "Programador verde");
	insertaVcompetencias(Lolo, "Amante del cafe");
	insertaVcompetencias(Lolo, "Miembro de la red de homless");
	inicializaUsuario(tabla, Isaac);
	inicializaVcompetencias(Isaac);
	insertaVcompetencias(Isaac, "Camarada");
	insertaVcompetencias(Isaac, "Uso de armas");
	insertaVcompetencias(Isaac, "Extorsionador");
	insertaVcompetencias(Isaac, "Experiencia en la KGB");
	inicializaUsuario(tabla, Arturo);
	inicializaVcompetencias(Arturo);
	insertaVcompetencias(Arturo, "El más rápido");
	insertaVcompetencias(Arturo, "Amante de las buenas vistas");
	insertaVcompetencias(Arturo, "Es un ligon");
	inicializaUsuario(tabla, Antonio);
	inicializaVcompetencias(Antonio);
	insertaVcompetencias(Antonio, "Madridista");
	insertaVcompetencias(Antonio, "Ultrasur");
	insertaVcompetencias(Antonio, "Amante de zizou");
	insertaVcompetencias(Antonio, "Odiador de mesi");
	insertaVcompetencias(Antonio, "Amante de la zanahoria");
	inicializaUsuario(tabla, Tarek);
	inicializaVcompetencias(Tarek);
	insertaVcompetencias(Tarek, "Desaparece con facilidad");
	insertaVcompetencias(Tarek, "Experto en T++");
	insertaVcompetencias(Tarek, "Amante de la zanahoria");
	
	return tabla;
}

/**
*@Brief, Módulo que imprimirá cada vez que se le pida la información del menu.
*/
void infomenu(){
//Ordenes del menu.
	cout << " " << endl;
	cout << "************************************************************MENÚ***************************************************************" << endl;
	cout << " " << endl;
	cout << "***** 1. Pulsa 'a' para crear una tabla de usuarios." << endl;
	cout << "***** 2. Pulsa 'b' para crear un usuario y insertarlo en la tabla." << endl;
	cout << "***** 3. Pulsa 'c' para imprimir la tabla. " << endl;
	cout << "***** 4. Pulsa 'r' para eliminar la tabla. " << endl;
	cout << "***** 5. Pulsa 'l' para buscar un usuario por su login." << endl;
	cout << "***** 6. Pulsa 'd' para eliminar un usaurio." << endl;
	cout << "***** 7. Pulsa 'h' para introducir una nueva competencia en un usuario." << endl;
	cout << "***** 8. Pulsa 'k' para eliminar una competencia de un usuario." << endl;
	cout << "***** 9. Pulsa 'p' para imprimir las competencias de un usuario." << endl;
	cout << "***** 10. Pulsa 'o' para ordenar la tabla por sus atributos." << endl;
	cout << "***** n. Pulsa 'i' para obtener las opciones del menú." << endl;
	cout << "***** n. Pulsa 's' para salir del programa." << endl;
	cout << " " << endl;
	cout << "*******************************************************************************************************************************" << endl;
}

int main(){
/************DECLARACIÓN DE VARIABLES Y PUNTEROS***********/
	TablaU *tabla;
	Usuario *user;
	bool comprobacion_tabla = false;
	int posicion_login;
	int posicion_competencia;
	string login;
	string competencia;
	char tecla;
/*************************INDICACIONES DEL MENU*****************************/

	cout << "Bienvenido, a Linkedrey, la mejor red social para encontrar trabajo, acontinuación podrá elegir entre varias acciones a elegir." << endl;
	cout << " " << endl;
	infomenu();
	cout << "Introduzca la tecla: ";

/*************************MENU************************/
do{
	cout << "Esperando orden...";
	cin >> tecla;
	switch (tecla){
		case 'a':
			tabla = crearTabla(tabla);
			imprimeTabla(tabla);
			comprobacion_tabla = true;
			break;
		case 'b':
			if (comprobacion_tabla == true)
			{
				tabla = gestorMemoria_tabla(tabla); //Cada vez, que se cree un nuevo usuario, si no hay espacio reservado en memoria, habrá que aumentar la memoria.
				crearUsuario(tabla, user);
			}
			else 
				cerr << "Por favor, primero cree una tabla para poder continuar, Gracias." << endl;
			break;
		case 'c':
			if (comprobacion_tabla == true)
			{
				imprimeTabla(tabla);
			}
			else 
				cerr << "Por favor, primero cree una tabla para poder continuar, Gracias." << endl;
			break;
		case 'r':
			if (comprobacion_tabla == true)
			{
				cout << "Ha decidido eliminar la tabla, para continuar con el programa, cree una nueva tabla." << endl;
				liberaTabla(tabla);
				comprobacion_tabla = false;
			}
			else 
				cerr << "Por favor, primero cree una tabla para poder continuar, Gracias." << endl;
			break;
		case 'l':

			if (comprobacion_tabla == true)
			{
				cout << "Por favor introduce el login del usuario que quiere buscar: ";
				cin >> login;
				cout << "login introducido: " << login << endl;
				posicion_login = busquedaUsuariologin(tabla, login);
				cout << "posición del usuario: " << posicion_login << endl;
				if (posicion_login != -1 && posicion_login < tabla->totaltuplas)
				{
					cout << "El usuario buscado es: " << endl;
					imprimeUsuario(tabla->punteroapuntero[posicion_login]);
					posicion_login = 0;
					login = "";
				}
				else
					cout << "No se ha encontrado al usuario introducido." << endl;
			}
			else
				cerr << "Por favor, primero cree una tabla para poder continuar, Gracias." << endl;
			break;
		case 'd':
			if(comprobacion_tabla == true){
				cout << "Ha elegido eliminar un Usuario, para empezar introduzca el login del usuario al que quieres borrar: ";
				cin >> login;

				cout << "login introducido: " << login << endl;
				posicion_login = busquedaUsuariologin(tabla, login);
				cout << "posición del usuario: " << posicion_login << endl;

				eliminaUsuario(tabla, posicion_login);
				login = "";
				posicion_login = 0;
			}
			else
				cerr << "Por favor, primero cree una tabla para poder continuar, Gracias." << endl;
			break;
		case 'h':
			if(comprobacion_tabla == true){
					cout << "Por favor, introduzca el usuario al que le quieres añadir más competencias: ";
					cin >> login;
					posicion_login = busquedaUsuariologin(tabla, login);
					if (posicion_login != -1 && posicion_login < tabla->totaltuplas)
					{
						insertaCompetencias(tabla->punteroapuntero[posicion_login]);
						login = "";
						cout << "Se ha introducido la competencia correctamente." << endl;
					}
					else
						cout << "No se ha encontrado al usuario introducido." << endl;
			}
			else
				cerr << "Por favor, primero cree una tabla para poder continuar, Gracias." << endl;
				break;
		case 'k':
			if (comprobacion_tabla == true)
			{
				cout << "Por favor, introduzca al usuario al que le quieres quitar la competencia: ";
				cin >> login;
				cout << "Ahora, por favor, introduzca la competencia que quiere eliminar: ";
				cin >> competencia;
				posicion_login = busquedaUsuariologin(tabla, login);
				posicion_competencia = busquedacompetencias(tabla->punteroapuntero[posicion_login], competencia);
				if (posicion_login != -1 && posicion_competencia != -1)
				{
					eliminaCompetencias(tabla->punteroapuntero[posicion_login], posicion_competencia);
					login = "";
					competencia = "";
					cout << "Competencia eliminada correctamente." << endl;
				}
				else
					cout << "No se encuentra al usuario, o la competencia introducida." << endl;
			}
			else
				cerr << "Por favor, primero cree una tabla para poder continuar, Gracias." << endl;
			break;
		case 'p':
			if (comprobacion_tabla == true)
			{
				cout << "Por favor, introduzca al usuario del que quieres mostrar sus competencias: ";
				cin >> login;
				posicion_login = busquedaUsuariologin(tabla, login);
				if (posicion_login != -1)
				{
					imprimeCompetencias(tabla->punteroapuntero[posicion_login]);
				}
				else
					cout << "No se encuentra al usuario introducido." << endl;
			}
			else
				cerr << "Por favor, primero cree una tabla para poder continuar, Gracias." << endl;
			break;
		case 'o':
			if (comprobacion_tabla == true)
			{
				ordenarTabla(tabla);
				cout << "La tabla se ha ordenado correctamente." << endl;
			}
			else
				cerr << "Por favor, primero cree una tabla para poder continuar, Gracias." << endl;
			break;
		case 'i':
			infomenu();
			break;
		case 's':
			cout << "¡Muchas gracias y hasta pronto!." << endl;
			if (comprobacion_tabla == true)
			{
				liberaTabla(tabla);
			}
			break;
		default:
			cerr << "Parece que ha habido un error, introduzca una telca de nuevo." << endl;
		}
	}while(tecla != 's');
}