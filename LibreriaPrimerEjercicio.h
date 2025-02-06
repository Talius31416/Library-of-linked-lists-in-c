#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//esta es la estructura que va a contener los datos de cada indice de la lista

typedef struct Nodo{
    char Texto[50];
    struct Nodo *siguente;
}Nodo;

//este puntero representa la cabeza de la lista, la cual nos ayuda a ubicarnos

typedef Nodo *tpuntero;

//las funciones que van a hacer que la lista funciones

int tamanio(tpuntero cabeza);

tpuntero CrearLista(){
    return NULL;
}

void añadirElemento(tpuntero *cabeza, char texto[]){
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    strcpy(nuevo->Texto, texto);
    nuevo->siguente = NULL;
    if(*cabeza == NULL){
        *cabeza = nuevo;
    }
    else{
        tpuntero actual = *cabeza;
        while(actual->siguente != NULL){
            actual = actual->siguente;
        }
        actual->siguente = nuevo;
    }
}

char** devolverElementos(tpuntero cabeza, int NroDeElementosARetornal){
    int longitud = tamanio(cabeza);
    if(longitud < NroDeElementosARetornal){
        return NULL;
    }
    //Se crea el arreglo con un puntero doble porque este contiene punteros y se asigna la memoria
    //a este y a sus elementos
    char** arreglo = (char**)malloc(sizeof(char*)*NroDeElementosARetornal);
    for(int i = 0;i<NroDeElementosARetornal;i++){
        arreglo[i] = (char*)malloc(sizeof(char)*100);
    }
    tpuntero actual = cabeza;
    for(int i = 0; i<NroDeElementosARetornal;i++){
        strcpy(arreglo[i], actual->Texto);
        actual = actual->siguente;
    }
    return arreglo;
}

int tamanio(tpuntero cabeza){
    tpuntero actual = cabeza;
    int longitud = 0;
    while(actual != NULL){
        ++longitud;
        actual = actual->siguente;
        
    }
    return longitud;
}

void eliminarLista(tpuntero *cabeza){
    tpuntero actual = *cabeza;
    while(actual != NULL){
        *cabeza = actual->siguente;
        free(actual);
        actual = *cabeza;
    }
}

void liberarArreglo(char** arreglo, int NroDeElementos) {
    if (arreglo != NULL) {
        for (int i = 0; i < NroDeElementos; i++) {
            free(arreglo[i]);
        }
        free(arreglo);
    }
}
