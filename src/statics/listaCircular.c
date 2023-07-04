#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <libdstruct.h>

SNode *nueva_lista_circular(int value)
{
	SNode *nodo = (SNode*) malloc(sizeof(SNode));
	if(nodo != NULL){
		nodo -> value = value;
		nodo -> next = nodo; 
	}
	
	return nodo;
}
	   	
void insertar_lista_circular(SNode **lista, SNode *nodo)
{
    SNode *actual, *previo;
	if (*lista == NULL){
		*lista = nodo;
		nodo -> next = *lista;
	}
	else{
		if(nodo -> value < (*lista) -> value){
			actual = *lista;
			while (actual -> next != *lista){
				actual = actual -> next;
			}
			nodo -> next = *lista;
			*lista = nodo;
			actual -> next = *lista;
		}
		else{
			actual = *lista;
			previo = *lista;
			while(nodo -> value >= actual -> value){
				actual = actual -> next;
				if (actual == *lista)
					break;
			}
			while(previo -> next != actual){
				previo = previo -> next;
			}
			nodo -> next = actual;
			previo -> next = nodo;
		}
	}
}


SNode *extraer_lista_circular(SNode **inicio, int value)
{
	SNode *actual, *previo = NULL ,*final = NULL;
	int encontrado = 0;
	actual = *inicio;
	if(*inicio != NULL){

		while((actual -> next != *inicio) && (!encontrado)){	
			encontrado = (actual -> value == value);
			if(!encontrado){
				previo = actual;
				actual = actual -> next;
			}
		}
		if(actual -> value == value){	
			if(*inicio == (*inicio) -> next){ 
				(*inicio) -> next = NULL;
				*inicio = NULL; 				
				actual -> next = NULL;
			}
			else if(actual == *inicio){ 
				final = *inicio;
	            while(final -> next != *inicio){
		            final = final -> next;
                }

				*inicio = actual -> next;
				final -> next = *inicio;
				actual->next=NULL;
			}
			else{	
				previo -> next = actual -> next;
				actual -> next = NULL;
			}
			return actual;
		}
	}
	return NULL;
}

void eliminar_lista_circular(SNode *nodo)
{
	free(nodo);
}


SNode* buscar_lista_circular(SNode *inicio, int value)
{
	SNode *indice;
	
	if(inicio != NULL){
		for(indice = inicio; indice -> next != inicio; indice = indice -> next){
				if(value == indice -> value){
					return indice;
				}
		}
		if(value == indice -> value){
			return indice;
		}
		return NULL;
	}
	return NULL;
}

SNode *copiar_lista_circular(SNode *inicio, int value)
{
	SNode *nodo;
	
	nodo = buscar_lista_circular(inicio, value);
	if(nodo != NULL){
		nodo = nueva_lista_circular(nodo -> value);
		return nodo;
	}
	else
		return NULL;
}

void imprimir_lista_circular(SNode *lista)	// 0 -> cabecera 1 -> 5 -> 5 -> 7 -> 0
{
	SNode *nodoImprimir = lista;
	if(lista != NULL){
		while(nodoImprimir -> next != lista){
			printf("%d -> ", nodoImprimir -> value);
			nodoImprimir = nodoImprimir -> next;
		}
		printf("%d ->", nodoImprimir -> value);
	}
}