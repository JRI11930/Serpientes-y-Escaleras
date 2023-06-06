#include<stdlib.h>

//Funciones básicas

NodoL* CrearNodo(element e){
    NodoL* nodo = (NodoL*)malloc(sizeof(NodoL));
    nodo->e = e;
    nodo->siguiente = NULL;
    nodo->anterior = NULL;
    return nodo;
}

void DestruirNodo(NodoL* nodo){
    nodo->siguiente = NULL;
    nodo->anterior = NULL;
    free(nodo);
}

Lista* CrearLista(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->head = NULL;
    lista->tail = NULL;
    lista->longitud = 0;
    return lista;
}

void DestruirLista(Lista* lista){
    NodoL* puntero = lista->head;
    while(puntero != NULL){
        lista->head = puntero->siguiente;
        DestruirNodo(puntero);
        puntero = puntero->siguiente;
    }
    free(lista);
}
//Funciones propias de las listas

void InsertarInicio(Lista* lista, element e){
    NodoL* nodo = CrearNodo(e);
    lista->head->anterior = nodo;
    nodo->siguiente = lista->head;
    lista->head = nodo;
    lista->longitud++;
}

void InsertarFinal(Lista* lista, element e){
    NodoL* nodo = CrearNodo(e);

    if(lista->head == NULL){
        nodo->siguiente = lista->head;
        nodo->anterior = NULL;
        lista->head = nodo;
    }else{
        NodoL* puntero = lista->head;
        lista->tail->siguiente = nodo; 
        nodo->anterior = lista->tail;
        lista->tail = nodo;
    }
    lista->longitud++;
}

void InsertarDespues(int n, Lista* lista, element e){
    NodoL* nodo = CrearNodo(e);

    if(lista->head == NULL){
        lista->head = nodo;
        lista->longitud++;
    }else{
        NodoL* puntero = lista->head;
        int posicion = 0;

        if(n>lista->longitud){
            printf("Esta fuera de rango. Insersión erronea");
            return;
        }

        if(n == lista->longitud - 1){
            InsertarFinal(lista, e);
        }else{
            
            while(posicion < n && puntero != NULL){
                puntero = puntero->siguiente;
                posicion ++;
            }

            NodoL* puntero1 = puntero;
            NodoL* puntero2 = puntero->siguiente;

            puntero1->siguiente = nodo;
            puntero2->anterior = nodo;
            nodo->anterior = puntero1; 
            nodo->siguiente = puntero2;

            lista->longitud++;
        }

    }
}

void EliminarInicio(Lista* lista){
    if(lista->head != NULL){
        NodoL* eliminar = lista->head;
        lista->head = lista->head->siguiente;
        DestruirNodo(eliminar);
        lista->head->anterior = NULL;
        lista->longitud--;
    }else{
        printf("Underflow");
    }
}

void EliminarFinal(Lista* lista){
    if(lista->head != NULL){
        if(lista->head->siguiente == NULL){ //Si la lista tiene solo un elemento...
            NodoL* puntero = lista->tail;
            lista->head = NULL;
            lista->head->siguiente = NULL;
            lista->tail = NULL;
            DestruirNodo(puntero);
        }      
    }else{
        printf("Underflow");
    }

}

void Eliminarn(int n, Lista* lista){
    if(lista->head != NULL){
        if(n == 0){
            NodoL* eliminar = lista->head;
            lista->head = lista->head->siguiente;
            lista->head->anterior = NULL;
            DestruirNodo(eliminar);
            lista->longitud--;
        }else if(n < lista->longitud){
            NodoL* puntero = lista->head;
            int posicion = 0;
            while(posicion < n-1 && puntero->siguiente != NULL){
                puntero = puntero->siguiente;
                posicion++;
            }
            NodoL* eliminar = puntero->siguiente;
            puntero->siguiente = eliminar->siguiente;
            eliminar->siguiente->anterior = puntero;
            DestruirNodo(eliminar);
            lista->longitud--;
        }
    }else{
        printf("Underflow");
    }
}
//Funciones adicionales

element Obtener(int n, Lista* lista){
    if(lista->head == NULL){
        return ERROR;
    }else{
        NodoL* puntero = lista->head;
        int posicion = 0;
        while(posicion < n && puntero != NULL){
            puntero = puntero->siguiente;
            posicion ++;
        }

        if(posicion != n){
            return ERROR;
        }else
            return puntero->e;
    }
}

int Longitud(Lista* lista){
    return lista->longitud;
}

int EstaVacia(Lista* lista){
    return lista->head == NULL;
}


