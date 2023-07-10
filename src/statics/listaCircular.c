#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <libdstruct.h>
	   	
void insertar_lista_circular(SNode **inicio, SNode **final, SNode *nodo)
{
    if (inicio && final && nodo) {
        if (*inicio && *final) {
            uint32_t conteo = 0;
            SNode *nodo_actual, *nodo_anterior;
            nodo_actual = nodo_anterior = *inicio;
            while (nodo_actual->next != *inicio &&
                   nodo_actual->value <= nodo->value)
            {
                nodo_anterior = nodo_actual;
                nodo_actual = nodo_actual->next;
                conteo++;
            }

            /* Es mayor que todos. */
            if ((*final)->value <= nodo->value) {
                (*final)->next = nodo;
                nodo->next = *inicio;
                *final = nodo;
            } else {
                nodo->next = nodo_actual;
                /* Cuando es el menor de todos. */
                if (conteo == 0) {
                    *inicio = nodo;
                    (*final)->next = nodo;
                } else {
                    nodo_anterior->next = nodo;
                }
            }
        } else {
            *inicio = nodo;
            *final = nodo;
            nodo->next = *inicio;
        }
    }
}


SNode *extraer_lista_circular(SNode **inicio, SNode **final, int id)
{
    SNode *nodo_extraido = NULL;
    if (inicio && final && *final) {
        uint32_t conteo = 0;
        SNode *nodo_actual, *nodo_anterior;
        nodo_actual = *inicio;
        while (nodo_actual->next != *inicio && nodo_actual->value != id) {
            nodo_anterior = nodo_actual;
            nodo_actual = nodo_actual->next;
            conteo++;
        }

        if (nodo_actual->value == id) {
            if (conteo) {
                nodo_anterior->next = nodo_actual->next;
            }
            else if (*inicio == *final) {
                nodo_extraido = *inicio;
                *inicio = NULL;
                *final = NULL;
            }
            else {
                *inicio = nodo_actual->next;
                (*final)->next = *inicio;
            }
            nodo_actual->next = NULL;
            nodo_extraido = nodo_actual;
        }
    }
    return nodo_extraido;
}

void eliminar_lista_circular(SNode **inicio, SNode **final)
{
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

void imprimir_lista_circular(SNode *inicio)	// 0 -> cabecera 1 -> 5 -> 5 -> 7 -> 0
{
	if(inicio){
        SNode *nodoImprimir = inicio;
		while(nodoImprimir -> next != inicio){
			printf("%d -> ", nodoImprimir -> value);
			nodoImprimir = nodoImprimir -> next;
		}
		printf("%d ->", nodoImprimir -> value);
	}
}

