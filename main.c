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
#include <conio.h>


//Definición de constantes y variables globales ----------------------------------------------------

#define tamtab 10   //El tablero será cuadrado
int J1 = 0, J2 = 50;

//Encabezados de las funciones utilizadas ----------------------------------------------------------

void MostrarTablero(Lista* tablero);
int TirarDados();
void mover(int jugador, int pasos, Lista* tablero);
void Inicio();

//Programa Principal -------------------------------------------------------------------------------

int main(){

    Lista* camino = CrearLista();

    for (int i = 0; i < 100; i++){
        InsertarFinal(camino, i);
    }

    Inicio();
    MostrarTablero(camino);

    return 0;
}

//Definicion de las funciones utilizadas -----------------------------------------------------------

void MostrarTablero(Lista* tablero){

    system("cls");
    printf("\n\n");
    for(int fila = 1; fila<=tamtab; fila++){
        printf("\n\n\t\t\t\t\t");
        if(fila%2){
            for(int columna = tamtab-1; columna >= 0; columna--){   

                int celda = Obtener(pow(tamtab, 2)-(fila*tamtab)+columna, tablero);

                if( celda == J1){
                    printf("\033[0;31m");
                    printf("[ J1 ]  ");
                    printf("\033[0m");
                }else if( celda == J2){
                    printf("\033[1;34m");
                    printf("[ J2 ]  ");
                    printf("\033[0m");
                }else{
                    if(celda / 10 < 1){
                        printf("\033[0;32m");
                        printf("[ 0%d ]  ", celda);
                    }else{
                        printf("\033[0;32m");
                        printf("[ %d ]  ", celda);
                    }
                } 
            }
            printf("\n");
        }else{
            for(int columna = 0; columna < tamtab; columna++){

                int celda = Obtener(pow(tamtab, 2)-(fila*tamtab)+columna, tablero);

                if(celda == J1){
                    printf("\033[0;31m");
                    printf("[ J1 ]  ");
                    printf("\033[0m");
                }else if(celda == J2){
                    printf("\033[1;34m");
                    printf("[ J2 ]  ");
                    printf("\033[0m");
                }else{
                    if(celda / 10 < 1){
                        printf("\033[0;32m");
                        printf("[ 0%d ]  ", celda);
                    }else{
                        printf("\033[0;32m");
                        printf("[ %d ]  ", celda);
                    }
                }
            }
            printf("\n");
        }
    }
    printf("\n\n");
    printf("\033[0m");
}

int TirarDados(){

}

//Funcion que mueve al jugador en el tablero--------------------------------------------------------

void mover(int jugador, int pasos, Lista* tablero) {
    int posicionActual = 0;
    int nuevaPosicion = 0;

    if (jugador == 1) {
        posicionActual = J1;
        nuevaPosicion = posicionActual + pasos;
        if (nuevaPosicion <= 100) {
            J1 = nuevaPosicion;
        }
    } else if (jugador == 2) {
        posicionActual = J2;
        nuevaPosicion = posicionActual + pasos;
        if (nuevaPosicion <= 100) {
            J2 = nuevaPosicion;
        }
    }

    // Mostrar el tablero actualizado
    MostrarTablero(tablero);
}


void Inicio(){

    system("cls");
    printf("\n\n\n\n");

    printf("\033[1;32m");

    printf("\t\t\t                                       ##                         ##                                      \n");
    printf("\t\t\t                                                                  ##                                      \n");
    printf("\t\t\t  #####    ####    ######   ######    ###      ####    #####     #####    ####     #####            ##  ##\n");
    printf("\t\t\t ##       ##  ##    ##  ##   ##  ##    ##     ##  ##   ##  ##     ##     ##  ##   ##                ##  ##\n");
    printf("\t\t\t  #####   ######    ##       ##  ##    ##     ######   ##  ##     ##     ######    #####            ##  ##\n");
    printf("\t\t\t      ##  ##        ##       #####     ##     ##       ##  ##     ## ##  ##            ##            #####\n");
    printf("\t\t\t ######    #####   ####      ##       ####     #####   ##  ##      ###    #####   ######                ##\n");
    printf("\t\t\t                            ####                                                                    #####\n");


    printf("\t\t\t\t\t                                     ###\n");
    printf("\t\t\t\t\t                                      ##\n");
    printf("\t\t\t\t\t ####     #####    ####     ####      ##      ####    ######    ####     #####\n");
    printf("\t\t\t\t\t##  ##   ##       ##  ##       ##     ##     ##  ##    ##  ##      ##   ##\n");
    printf("\t\t\t\t\t######    #####   ##        #####     ##     ######    ##       #####    #####\n");
    printf("\t\t\t\t\t##            ##  ##  ##   ##  ##     ##     ##        ##      ##  ##        ##\n");
    printf("\t\t\t\t\t #####   ######    ####     #####    ####     #####   ####      #####   ######\n");

    printf("\n\n");

    printf("\033[0m");

    printf("\n\t\t\t\t\t\t\t\t   Pi%ca del Valle Jos%c", 164, 130);
    printf("\n\t\t\t\t\t\t\t\tRam%crez Islas Jos%c Armando", 161, 130);
    printf("\n\t\t\t\t\t\t\t\tReyes Camarillo Mar%ca Jos%c", 161, 130);

    printf("\n\n\t\t\t\t\t\t\tPara comenzar, pulsa cualquier tecla...");
    getche();


}