#include <stdlib.h>
#include <stdio.h>
#include "alcanos.h"

//Nodo
NodoAl crearNodoAl(int h, Sustituyente *LS){
  NodoAl *N = (NodoAl*)malloc(sizeof(NodoAl*));
  N -> h = h;
  N -> sigNodo = NULL;

  if (LS != NULL){
    N -> sus = LS;
  } else {
    N -> sus = NULL;
  }
  
  return *N;
}

void insertarNodoAl(Alcano *L, int h, Sustituyente *LS){
  NodoAl N = crearNodoAl(h, LS);
  
  if (listaAlVacia(L)){
    L -> inicial = &N;
  }else{
    NodoAl *aux = L -> inicial;
    while (aux -> sigNodo != NULL){
      aux = aux -> sigNodo;
    }
    aux -> sigNodo = &N;
  }
  L -> largo++;
}

void eliminarNodoAl(Alcano *L){
  if (!listaAlVacia(L)){
    NodoAl *eliminarNodo = L -> inicial;
    // Si 
    if (eliminarNodo -> sus != NULL){
      while (listaSusVacia(eliminarNodo -> sus)){
        eliminarNodoSus(eliminarNodo -> sus);
      }
    }
    L -> inicial = L -> inicial -> sigNodo;
    free(eliminarNodo);
    L -> largo--;
  }else{
    printf("Lista Vacia");
  }
}


NodoSus crearNodoSus(int h) {
  NodoSus *N = (NodoSus*)malloc(sizeof(NodoSus*));
  N -> h = h;
  N -> sigNodo = NULL;
  return *N;
}

void insertarNodoSus(Alcano *L, int h) {
  NodoSus N = crearNodoSus(h);

  NodoAl *aux = L -> inicial;
  while (aux -> sigNodo != NULL){  //Recorrer lista Alcano hasta el final
    if (aux -> sus != NULL){  //Si el nodo tiene una lista Sustituyente

      NodoSus *auxSus = aux -> sus -> inicial;
      if (auxSus != NULL){  //Si la lista Sustituyente esta vacia
        auxSus = &N;
      } else {
        
        while (auxSus -> sigNodo != NULL) { //Avanzar hasta el final de la lista Sustituyente
          auxSus = auxSus -> sigNodo;
        }
        if (auxSus -> h != '#'){
          auxSus = &N;
        } else {
          aux = aux -> sigNodo;  //Si el final de la lista Sustituyente es igual al final de un #, es porque tiene que avanzar al siguiente nodo Alcano y por ende, a la siguiente lista Sustituyente
        }
      }
    } else {
      aux = aux -> sigNodo;
    }
  }

  aux -> sus -> largo++;
}

//Lista
Alcano crearListaAl(){
  Alcano *L = (Alcano*)malloc(sizeof(Alcano));
  L -> largo = 0;
  L -> inicial = NULL;
  return *L;
}

bool listaAlVacia(Alcano *L){
  if (L -> inicial != NULL){
    return true;  //Verdadero si NO esta vacia
  } else {
    return false;
  }
}

void recorrerListaAl(Alcano *L){
  if (!listaAlVacia(L)){
    NodoAl *aux = L -> inicial;
    while (aux != NULL){
      printf("%d", aux -> h);
      aux = aux -> sigNodo;
    }
  }else{
    printf("Lista Vacia");
  }
}


Sustituyente crearListaSus() {
  Sustituyente *LS = (Sustituyente*)malloc(sizeof(Sustituyente));
  LS -> inicial = NULL;
  LS -> largo = 0;
  return *LS;
}