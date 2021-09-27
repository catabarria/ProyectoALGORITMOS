#include <stdio.h>
#include <stdlib.h>
#include "alcanos.h"


int main(){
  FILE *alcanos = fopen("alcanos.txt", "r");
  int n = getc(alcanos);
  char h = getc(alcanos);  //Salta el primer \n

  Alcano listaAl = crearListaAl();
  
  while ((h=getc(alcanos)) != '\n' ){
    if (h == '2' || h == '3'){
      insertarNodoAl(&listaAl, h, NULL);
    } else if (h == '-' || h == '+'){
      Sustituyente listaSus = crearListaSus();
      insertarNodoAl(&listaAl, h, &listaSus);
    } else {
      //Completar//  h == '#'
      while ((h=getc(alcanos)) != '#'){  //El primer h=getc saltara el primer #
        insertarNodoSus(&listaAl, h);
      }
      insertarNodoSus(&listaAl, h);  //Meter a la mala ese ultimo #
    }
  }
  
  while (listaAlVacia(&listaAl)) {
    eliminarNodoAl(&listaAl);
  }
}