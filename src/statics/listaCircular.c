#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <libdstruct.h>

SNode *nueva_lista_circular(int valor)
{
	SNode *nodo = (SNode*) malloc(sizeof(SNode));
	if(nodo != NULL){
		nodo -> valor = valor;
		nodo -> siguiente = nodo; 
	}
	
	return nodo;
}
	   	
void insertar_lista_circular(SNode **lista, SNode *nodo)
{
    SNode *actual, *previo;
	if (*lista == NULL){
		*lista = nodo;
		nodo -> siguiente = *lista;
	}
	else{
		if(nodo -> valor < (*lista) -> valor){
			actual = *lista;
			while (actual -> siguiente != *lista){
				actual = actual -> siguiente;
			}
			nodo -> siguiente = *lista;
			*lista = nodo;
			actual -> siguiente = *lista;
		}
		else{
			actual = *lista;
			previo = *lista;
			while(nodo -> valor >= actual -> valor){
				actual = actual -> siguiente;
				if (actual == *lista)
					break;
			}
			while(previo -> siguiente != actual){
				previo = previo -> siguiente;
			}
			nodo -> siguiente = actual;
			previo -> siguiente = nodo;
		}
	}
}


SNode *extraer_lista_circular(SNode **inicio, int valor)
{
	SNode *actual, *previo = NULL ,*final = NULL;
	int encontrado = 0;
	actual = *inicio;
	if(*inicio != NULL){

		while((actual -> siguiente != *inicio) && (!encontrado)){	
			encontrado = (actual -> valor == valor);
			if(!encontrado){
				previo = actual;
				actual = actual -> siguiente;
			}
		}
		if(actual -> valor == valor){	
			if(*inicio == (*inicio) -> siguiente){ 
				(*inicio) -> siguiente = NULL;
				*inicio = NULL; 				
				actual -> siguiente = NULL;
			}
			else if(actual == *inicio){ 
				final = *inicio;
	            while(final -> siguiente != *inicio){
		            final = final -> siguiente;
                }

				*inicio = actual -> siguiente;
				final -> siguiente = *inicio;
				actual->siguiente=NULL;
			}
			else{	
				previo -> siguiente = actual -> siguiente;
				actual -> siguiente = NULL;
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


SNode* buscar_lista_circular(SNode *inicio, int valor)
{
	SNode *indice;
	
	if(inicio != NULL){
		for(indice = inicio; indice -> siguiente != inicio; indice = indice -> siguiente){
				if(valor == indice -> valor){
					return indice;
				}
		}
		if(valor == indice -> valor){
			return indice;
		}
		return NULL;
	}
	return NULL;
}

SNode *copiar_lista_circular(SNode *inicio, int valor)
{
	SNode *nodo;
	
	nodo = buscar_lista_circular(inicio, valor);
	if(nodo != NULL){
		nodo = nueva_lista_circular(nodo -> valor);
		return nodo;
	}
	else
		return NULL;
}

void imprimir_lista_circular(SNode *lista)	// 0 -> cabecera 1 -> 5 -> 5 -> 7 -> 0
{
	SNode *nodoImprimir = lista;
	if(lista != NULL){
		while(nodoImprimir -> siguiente != lista){
			printf("%d -> ", nodoImprimir -> valor);
			nodoImprimir = nodoImprimir -> siguiente;
		}
		printf("%d ->", nodoImprimir -> valor);
	}
}