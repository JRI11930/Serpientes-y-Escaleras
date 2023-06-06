/*
    Programa que simula el juego "Serpientes y Escaleras"
    para dos jugadores

    Algoritmos y Estructuras de Datos
    Piña Del Valle José 
    Ramírez Islas José Armando 
    Reyes Camarillo María José

*/

#include <math.h>

#include "libs/colas.h"
#include "libs/pilas.h"
#include "libs/listas.h"


//Definición de constantes -------------------------------------------------------------------------

#define tamtab 10   //El tablero será cuadrado

//Encabezados de las funciones utilizadas ----------------------------------------------------------

void MostrarTablero(Lista* tablero);

//Programa Principal -------------------------------------------------------------------------------

int main(){

    Lista* camino = CrearLista();

    for (int i = 0; i < 100; i++){
        InsertarFinal(camino, i);
    }
    
    puts("\n\n");
    
    MostrarTablero(camino);

    return 0;
}

//Definicion de las funciones utilizadas -----------------------------------------------------------

void MostrarTablero(Lista* tablero){
    NodoL* puntero = tablero->head;
    for(int fila = 1; fila<=tamtab; fila++){ //i va a contar las filas
        if(fila%2){
            for(int j = tamtab; j>=0; j--){
                
            }
        }
    }


}


// Funcion Movimiento