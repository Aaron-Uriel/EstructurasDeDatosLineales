#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <libdstruct.h>

#define TAMAÑO 8

int pila[TAMAÑO];
/*
int main(void)
{
	int final = 0;	
	int llena = 0, opcion;
	
	do{
		printf("═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬\n"
            "x x ⁞ Menú. x x\n"
            "═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬\n"
            "▒┊1.- Agregar. (Crear + Insertar)\n"
            "▒┊2.- Quitar. (Extraer + Eliminar)\n"
            "▒┊3.- Imprimir.\n"
            "▒┊4.- Salir.\n"
            "═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬═▬\n"
            "➫ ");
    	scanf("%d", &opcion);
		switch(opcion){
			case 1:
				if(!llena){
					printf("Igrese un numero: ");
					scanf("%d", &pila[final]);
					final++;
				
					if(final == TAMAÑO)
					{
						llena = 1;
					}
					break;
				}
				printf("\nPila llena.\n");
				break;

			case 2:
				if (final ==  0)
				{
					printf("Está vacía.\n");
					break;
				}
				final--;
				if (llena)
				{
					llena = 0;
				}
				break;
				
			case 3:
				printf("Pila: \n");
        			for (int i = 0; i < final; i ++) {
            			printf("%d ", pila[i]);
        			}

                printf("\n");
				printf("Arreglo:\n");
				for (int i = 0; i < TAMAÑO; i++) {
					printf("%d ", pila[i]);
				}
				printf("\n");
				break;
			case 4:
				break;
			default:
				printf("\nOpción no válida.\n\n");
				break;
		}
	}while(opcion != 4);	
}*/