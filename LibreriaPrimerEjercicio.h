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


//se crea la cabeza con la lista que retorna el tpuntero que es igual a NULL
tpuntero CrearLista(){
    return NULL;
}

void añadirElemento(tpuntero *cabeza, char texto[]){
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo)); //nodo que va a contener los datos de la lista ligada
    strcpy(nuevo->Texto, texto); //se copia el string al arreglo del nodo
    nuevo->siguente = NULL; //se asigna el siguiente valor NULL ya que no apunta a nada
    if(*cabeza == NULL){
        *cabeza = nuevo;//se asigna el valor a la cabeza si no hay nada en la lista
    }
    else{
        tpuntero actual = *cabeza;
        while(actual->siguente != NULL){
            actual = actual->siguente;//busca hasta que el siguiente nodo sea null y se asigna el valor nuevo
        }
        actual->siguente = nuevo;
    }
}

char** devolverElementos(tpuntero cabeza, int NroDeElementosARetornal){
    int longitud = tamanio(cabeza); //llama la funcion tamaño para no retornar valores nulos
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
        actual = actual->siguente;//se guardan los elementos de la lista en el puntero de punteros que creamos
    }
    return arreglo;
}

int tamanio(tpuntero cabeza){
    tpuntero actual = cabeza;
    int longitud = 0;
    while(actual != NULL){
        ++longitud; //funcion espera a que actual sea NULL y va sumando uno a la longitud para ver el tamaño de la lista
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
