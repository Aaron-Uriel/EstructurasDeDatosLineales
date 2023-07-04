#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <libdstruct.h>


SNode *nueva_cola_circular(int value)
{
	SNode *nodo = (SNode*) malloc(sizeof(SNode));
	if(nodo != NULL){
		nodo -> value = value;
		nodo -> next = nodo; 
	}
	
	return nodo;
}

void insertar_cola_circular(SNode **inicio, SNode **final, SNode *nodo)
{
        SNode *tempUno = NULL, *tempDos = NULL;

	
	if (*inicio == NULL){					
		*inicio = nodo;
		*final = nodo;					
		(*inicio) -> next = *inicio;
    }else{								
		tempUno = *inicio;				
		if((tempUno -> next) == (*inicio)){
			tempUno-> next = nodo;		
			tempDos = nodo;
			tempDos -> next = tempUno;		
			*final = tempDos; 			
		}
		else{								
			tempDos = *inicio;			
			while((tempUno-> next) != tempDos){
				tempUno = tempUno-> next;
			}
			tempUno-> next = nodo;		
			*final = nodo;			
			(*final) -> next = *inicio;
		}
	}
}

SNode *extraer_cola_circular (SNode **inicio, SNode **final){

	SNode *extraido = NULL, *tempUno = NULL, *tempDos = NULL;
	
    	if(*inicio != NULL){
        	extraido = *inicio;		
        	tempUno = *inicio;				
        	tempDos = *final;
        	if((tempUno-> next != NULL) && (tempUno -> next != tempUno)){			
        	    *inicio = extraido -> next;			
        	    tempDos -> next = *inicio;
        	    extraido -> next = NULL;

        	}
        	else{
        		extraido -> next = NULL;
        		*inicio = NULL;
   			*final = NULL;
        	}
	    } else{
		return extraido;
	}
	
	return extraido;
}

void eliminar_cola_circular (SNode *extraido){
    free (extraido);
}

void imprimir_cola_circular(SNode *inicio){

	SNode *actual, *temp;
	if(inicio == NULL){
		printf("\nNo hay elementos en la cola\n");
	}
	else{
		actual = inicio;
		temp = inicio;
		while (actual -> next != temp){
			printf ("%d -> ", actual -> value);
			actual = actual -> next;
		}
		printf("%d -> ", actual -> value);
	}
}