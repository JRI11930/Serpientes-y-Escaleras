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
#include <math.h>


//Definición de constantes y variables globales ----------------------------------------------------

#define tamtab 10   //El tablero será cuadrado
int J1 = 0, J2 = 50;

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

    MostrarTablero(camino);

    return 0;
}

//Definicion de las funciones utilizadas -----------------------------------------------------------

void MostrarTablero(Lista* tablero){
    printf("Mostrando tablero...\n");
    for(int fila = 1; fila<=tamtab; fila++){
        if(fila%2){
            for(int columna = tamtab-1; columna >= 0; columna--){

                int celda = Obtener(pow(tamtab, 2)-(fila*tamtab)+columna, tablero);

                if( celda == J1){
                    printf("[ J1 ] ");
                }else if( celda == J2){
                    printf("[ J2 ] ");
                }else{
                    if(celda / 10 < 1){
                        printf("[ 0%d ] ", celda);
                    }else{
                        printf("[ %d ] ", celda);
                    }
                } 
            }
            printf(" Fila: %d\n", fila);
        }else{
            for(int columna = 0; columna < tamtab; columna++){

                int celda = Obtener(pow(tamtab, 2)-(fila*tamtab)+columna, tablero);

                if(celda == J1){
                    printf("[ J1 ] ");
                }else if(celda == J2){
                    printf("[ J2 ] ");
                }else{
                    if(celda / 10 < 1){
                        printf("[ 0%d ] ", celda);
                    }else{
                        printf("[ %d ] ", celda);
                    }
                }
            }
            printf(" Fila: %d\n", fila);
        }
    }
}

int TirarDados(){

}

//Funcion que mueve al jugador en el tablero--------------------------------------------------------

void mover(){

}

//hola prueba
//Buenos dias, tarde ya que barbaro
