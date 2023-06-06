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
int TirarDados();
void Mover();

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

}

int TirarDados(){

}

void Mover(){

}

//hola prueba
//Buenos dias, tarde ya que barbaro
