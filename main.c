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
#include <string.h>
#include <time.h>


//Definición de constantes y variables globales ----------------------------------------------------

typedef struct Move{
    NodoL* ini;
    NodoL* fin;
}Move;


#define tamtab 10   //El tablero será cuadrado
int J1 = 0, J2 = 0; 

//Encabezados de las funciones utilizadas ----------------------------------------------------------

void MostrarTablero(Lista* tablero, Move e[], Move s[]);
int TirarDados();
void mover(int jugador, int pasos, Lista* tablero, Move e[], Move s[]);
void Inicio();

//Programa Principal -------------------------------------------------------------------------------

int main(){

    srand(time(NULL));

    Lista* camino = CrearLista();
    Move s[5];
    Move e[5];

    for (int i = 0; i < 100; i++){
        InsertarFinal(camino, i);
    }

    printf("La cabeza de la lista es:\t%d", camino->head->e);
    system("pause");
    //Creacion de escaleras
    for(int i = 0; i < 5; i++){
        int ini = (7*i+13);
        int fin = ini + 12;
    
        NodoL* puntero_ini = camino->head; 
    
        for(int i = 1; i <= ini; i++){
            puntero_ini = puntero_ini->siguiente;
        }
    
        e[i].ini = puntero_ini;
    
        NodoL* puntero_fin = camino->head;

        for(int i = 1; i <= fin; i++){
            puntero_fin = puntero_fin->siguiente;
        }

        e[i].fin = puntero_fin;
        puntero_fin = puntero_ini = NULL;
        
    }
    system("pause");
    //Creación de serpientes
    for(int i = 0; i < 5; i++){
        int fin = (16*i+5);
        int ini = fin + 15;
    
        NodoL* puntero_fin = camino->head; 
    
        for(int i = 1; i <= fin; i++){
            puntero_fin = puntero_fin->siguiente;
        }
    
        s[i].fin = puntero_fin;
    
        NodoL* puntero_ini = camino->head;

        for(int i = 1; i <= ini; i++){
            puntero_ini = puntero_ini->siguiente;
        }

        s[i].ini = puntero_ini;
        puntero_fin = puntero_ini = NULL;
        
    }

    Inicio();
    MostrarTablero(camino, e, s);


    return 0;
}

//Definicion de las funciones utilizadas -----------------------------------------------------------

void MostrarTablero(Lista* tablero, Move *e, Move *s){

    system("cls");
    printf("\n\n");
    for(int fila = 1; fila<=tamtab; fila++){
        printf("\n\n\t\t\t\t\t");
        if(fila%2){
            for(int columna = tamtab-1; columna >= 0; columna--){   

                int celda = Obtener(pow(tamtab, 2)-(fila*tamtab)+columna, tablero);

                if(celda == J1 && celda == J2){
                    printf("\x1b[45m");
                    printf("[J1");
                    printf("\x1b[44m");
                    printf("J2]");
                    printf("\x1b[0m");
                    printf("  ");
                }else if(celda == J1){
                    printf("\x1b[45m");
                    printf("[ J1 ]");
                    printf("\x1b[0m");
                    printf("  ");
                }else if(celda == J2){
                    printf("\x1b[34m");
                    printf("[ J2 ]");
                    printf("\x1b[0m");
                    printf("  ");
                }else if(
                    celda == e[0].ini->e ||
                    celda == e[1].ini->e ||
                    celda == e[2].ini->e ||
                    celda == e[3].ini->e ||
                    celda == e[4].ini->e 
                    
                ){
                    if(celda == e[0].ini->e){
                        printf("\x1b[32m");
                        printf("[ e0 ]");
                        printf("\x1b[0m");
                        printf("  ");
                    }else if(celda == e[1].ini->e){
                        printf("\x1b[32m");
                        printf("[ e1 ]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }else if(celda == e[2].ini->e){
                        printf("\x1b[32m");
                        printf("[ e2 ]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }else if(celda == e[3].ini->e){
                        printf("\x1b[32m");
                        printf("[ e3 ]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }else if(celda == e[4].ini->e){
                        printf("\x1b[32m");
                        printf("[ e4 ]");
                        printf("\x1b[0m");
                        printf("  "); 
                    }
                }else if(
                    celda == e[0].fin->e ||
                    celda == e[1].fin->e ||
                    celda == e[2].fin->e ||
                    celda == e[3].fin->e ||
                    celda == e[4].fin->e 
                ){
                  if(celda == e[0].fin->e){
                        printf("\x1b[32m");
                        printf("[ e0f]");
                        printf("\x1b[0m");
                        printf("  ");
                    }else if(celda == e[1].fin->e){
                        printf("\x1b[32m");
                        printf("[ e1f]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }else if(celda == e[2].fin->e){
                        printf("\x1b[32m");
                        printf("[ e2f]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }else if(celda == e[3].fin->e){
                        printf("\x1b[32m");
                        printf("[ e3f]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }else if(celda == e[4].fin->e){
                        printf("\x1b[32m");
                        printf("[ e4f]");
                        printf("\x1b[0m");
                        printf("  ");    
                    }
                }else if(
                    celda == s[0].ini->e ||
                    celda == s[1].ini->e ||
                    celda == s[2].ini->e ||
                    celda == s[3].ini->e ||
                    celda == s[3].ini->e 
                ){
                    if(celda == s[0].ini->e){
                        printf("\x1b[33m");
                        printf("[ s0 ]");
                        printf("\x1b[0m");
                        printf("  ");
                    }else if(celda == s[1].ini->e){
                        printf("\x1b[33m");
                        printf("[ s1 ]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }else if(celda == s[2].ini->e){
                        printf("\x1b[33m");
                        printf("[ s2 ]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }else if(celda == s[3].ini->e){
                        printf("\x1b[33m");
                        printf("[ s3 ]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }else if(celda == s[4].ini->e){
                        printf("\x1b[33m");
                        printf("[ s4 ]");
                        printf("\x1b[0m");
                        printf("  ");
                    }
                }else if(
                    celda == s[0].fin->e ||
                    celda == s[1].fin->e ||
                    celda == s[2].fin->e ||
                    celda == s[3].fin->e ||
                    celda == s[4].fin->e
                ){
                    if(celda == s[0].fin->e){
                        printf("\x1b[33m");
                        printf("[ s0f]");
                        printf("\x1b[0m");
                        printf("  ");
                    }else if(celda == s[1].fin->e){
                        printf("\x1b[33m");
                        printf("[ s1f]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }else if(celda == s[2].fin->e){
                        printf("\x1b[33m");
                        printf("[ s2f]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }else if(celda == s[3].fin->e){
                        printf("\x1b[33m");
                        printf("[ s3f]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }else if(celda == s[4].fin->e){
                        printf("\x1b[33m");
                        printf("[ s4f]");
                        printf("\x1b[0m");
                        printf("  ");
                    }
                
                }else{
                    printf("\033[0m");
                    if(celda / 10 < 1){
                        printf("[ 0%d ]  ", celda);
                    }else{
                        printf("[ %d ]  ", celda);
                    }
                }
            
            }
            printf("\n");
        }else{
            for(int columna = 0; columna < tamtab; columna++){

                int celda = Obtener(pow(tamtab, 2)-(fila*tamtab)+columna, tablero);

                if(celda == J1 && celda == J2){
                    printf("\x1b[45m");
                    printf("[J1");
                    printf("\x1b[44m");
                    printf("J2]");
                    printf("\x1b[0m");
                    printf("  ");
                }else if(celda == J1){
                    printf("\x1b[45m");
                    printf("[ J1 ]");
                    printf("\x1b[0m");
                    printf("  ");
                }else if(celda == J2){
                    printf("\x1b[44m");
                    printf("[ J2 ]");
                    printf("\x1b[0m");
                    printf("  ");
                }else if(
                    celda == e[0].ini->e ||
                    celda == e[1].ini->e ||
                    celda == e[2].ini->e ||
                    celda == e[3].ini->e ||
                    celda == e[4].ini->e
                ){
                    if(celda == e[0].ini->e){
                        printf("\x1b[32m");
                        printf("[ e0 ]");
                        printf("\x1b[0m");
                        printf("  ");
                    }else if(celda == e[1].ini->e){
                    printf("\x1b[32m");
                        printf("[ e1 ]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }else if(celda == e[2].ini->e){
                        printf("\x1b[32m");
                        printf("[ e2 ]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }else if(celda == e[3].ini->e){
                        printf("\x1b[32m");
                        printf("[ e3 ]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }else if(celda == e[4].ini->e){
                        printf("\x1b[32m");
                        printf("[ e4 ]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }
                }else if(
                    celda == e[0].fin->e ||
                    celda == e[1].fin->e ||
                    celda == e[2].fin->e ||
                    celda == e[3].fin->e ||
                    celda == e[3].fin->e 
                ){
                  if(celda == e[0].fin->e){
                        printf("\x1b[32m");
                        printf("[ e0f]");
                        printf("\x1b[0m");
                        printf("  ");
                    }else if(celda == e[1].fin->e){
                        printf("\x1b[32m");
                        printf("[ e1f]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }else if(celda == e[2].fin->e){
                        printf("\x1b[32m");
                        printf("[ e2f]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }else if(celda == e[3].fin->e){
                        printf("\x1b[32m");
                        printf("[ e3f]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }else if(celda == e[4].fin->e){
                        printf("\x1b[32m");
                        printf("[ e4f]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }
                }else if(
                    celda == s[0].ini->e ||
                    celda == s[1].ini->e ||
                    celda == s[2].ini->e ||
                    celda == s[3].ini->e ||
                    celda == s[3].ini->e 
                ){
                    if(celda == s[0].ini->e){
                        printf("\x1b[33m");
                        printf("[ s0 ]");
                        printf("\x1b[0m");
                        printf("  ");
                    }else if(celda == s[1].ini->e){
                        printf("\x1b[33m");
                        printf("[ s1 ]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }else if(celda == s[2].ini->e){
                        printf("\x1b[33m");
                        printf("[ s2 ]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }else if(celda == s[3].ini->e){
                        printf("\x1b[33m");
                        printf("[ s3 ]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }else if(celda == s[4].ini->e){
                        printf("\x1b[33m");
                        printf("[ s4 ]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }
                }else if(
                    celda == s[0].fin->e ||
                    celda == s[1].fin->e ||
                    celda == s[2].fin->e ||
                    celda == s[3].fin->e ||
                    celda == s[3].fin->e 
                ){
                    if(celda == s[0].fin->e){
                        printf("\x1b[33m");
                        printf("[ s0f]");
                        printf("\x1b[0m");
                        printf("  ");
                    }else if(celda == s[1].fin->e){
                        printf("\x1b[33m");
                        printf("[ s1f]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }else if(celda == s[2].fin->e){
                        printf("\x1b[33m");
                        printf("[ s2f]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }else if(celda == s[3].fin->e){
                        printf("\x1b[33m");
                        printf("[ s3f]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }else if(celda == s[4].fin->e){
                        printf("\x1b[33m");
                        printf("[ s4f]");
                        printf("\x1b[0m");
                        printf("  ");   
                    }
                }else{
                    printf("\033[0m");
                    if(celda / 10 < 1){
                        printf("[ 0%d ]  ", celda);
                    }else{
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

    int random_num1,random_num2;

    int previous_num1 = 0;
    int previous_num2 = 0;
    int sum = 0;

    while (1) {
        if (kbhit()){
            char ch = getch();
            if (ch == ' ') {
                if (previous_num1 != 0 && previous_num2 != 0) {
                        printf("\r");  // Regresar al principio de la línea
                    for (int i = 0; i < 30; i++) {
                        printf(" ");  // Espacios en blanco para borrar la línea anterior
                    }
                    printf("\r");  // Regresar al principio de la línea nuevamente
                }
                random_num1 = rand() % 6 + 1;  // Genera un entero aleatorio entre 1 y 6
                random_num2 = rand() % 6 + 1;  // Genera otro entero aleatorio entre 1 y 6
                printf("%d %d", random_num1, random_num2);
                fflush(stdout);
                previous_num1 = random_num1;
                previous_num2 = random_num2;
                sum = random_num1 + random_num2;
            } else {
                break;
            }
        }
    }
    printf("\nLa suma es: %d\n", sum);
    return 0;
}

//Funcion que mueve al jugador en el tablero--------------------------------------------------------

void mover(int jugador, int pasos, Lista* tablero, Move e[], Move s[]){
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
    MostrarTablero(tablero, e, s);
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

//Funcion que asigna a las serpientes y escaleras



//Funcion que muestre el ganador

void ganador(){

}
