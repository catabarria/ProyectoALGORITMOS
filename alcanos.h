#include <stdbool.h>

typedef struct NodoSus {
  int h; //Este valor indica la cantidad de hidrogenos del nodo
  struct NodoSus *sigNodo;
} NodoSus;

typedef struct Sustituyente {
  NodoSus *inicial;
  int largo; //Este valor indica la cantidad de carbonos y el largo del sustituyente
} Sustituyente;

typedef struct NodoAl {
  int h; //Este valor indica la cantidad de hidrogenos del nodo
  Sustituyente *sus; //Los nodos guardaran la dirección del sustituyente con el cual esta conectado
	struct NodoAl *sigNodo;
} NodoAl;

typedef struct Alcano {
	NodoAl *inicial;
	int largo; //Este valor indica la cantidad de carbonos y el largo del alcano
} Alcano;


//Nodo
NodoAl crearNodoAl(int h, Sustituyente *LS);
void insertarNodoAl(Alcano *L, int h, Sustituyente *LS);
void eliminarNodoAl(Alcano *L);

NodoSus crearNodoSus(int h);
void insertarNodoSus(Alcano *L, int h);
void eliminarNodoSus(Sustituyente *LS);  //Crear

//Lista
Alcano crearListaAl();
bool listaAlVacia(Alcano *L);
void recorrerListaAl(Alcano *L);

Sustituyente crearListaSus(); //Crear
bool listaSusVacia(Sustituyente *LS); //Crear
