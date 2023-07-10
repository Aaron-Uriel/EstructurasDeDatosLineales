#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <libdstruct.h>

void insertar_cola_circular(SNode **inicio, SNode **final, SNode *nodo)
{
    SNode *tempUno = NULL;

    if (inicio && final) {
        if (*inicio == NULL && *final == NULL){					
            *inicio = nodo;
            *final = nodo;					
            (*inicio) -> next = *inicio;
        } else {								
            if(((*inicio)-> next) == (*inicio)){
                (*inicio)-> next = nodo;		
                nodo-> next = *inicio;		
                *final = nodo;
            } else {								
                tempUno = *inicio;				
                while(tempUno->next != *inicio){
                    tempUno = tempUno->next;
                }
                tempUno->next = nodo;		
                *final = nodo;			
                (*final)->next = *inicio;
            }
        }
    }
	
}

SNode *extraer_cola_circular (SNode **inicio, SNode **final){

	SNode *extraido = NULL;
    if (inicio) {
        if (*inicio) {
            extraido = *inicio;	
            if((*inicio)->next && ((*inicio)->next != *inicio)){			
                *inicio = (*inicio)->next;			
                (*final)->next = *inicio;
            } else {
                *inicio = NULL;
                *final = NULL;
            }
            extraido->next = NULL;
        }
    }
	return extraido;
}

void eliminar_cola_circular(SNode **inicio, SNode **final){
    if (inicio && *inicio && final && *final) {
        SNode *nodo_actual, *nodo_anterior;
        nodo_actual = *inicio;
        while (nodo_actual->next != *inicio) {
            nodo_anterior = nodo_actual;
            nodo_actual = nodo_actual->next;
            snode_free(&nodo_anterior);
        }
        snode_free(&nodo_actual);
        *inicio = NULL;
        *final = NULL;
    }
}

void imprimir_cola_circular(SNode *inicio){
	SNode *actual;
	if(inicio == NULL){
		printf("\nNo hay elementos en la cola\n");
	} else {
		actual = inicio;
        while (actual->next != inicio){
			printf ("%d -> ", actual -> value);
			actual = actual -> next;
		}
        printf ("%d \n", actual -> value);
	}
}

