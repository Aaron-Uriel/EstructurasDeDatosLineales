#include <stdio.h>

#define TAMAÑO 8

int cola[TAMAÑO];
/*
int main(void)
{
	int inicio = 0, final = 0;	
	int llena = 0, indice = 0, opcion;
	
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
					scanf("%d", &cola[final]);
					final = (final + 1) % TAMAÑO;
					indice++;
				
					if(final % TAMAÑO == inicio)
					{
						llena = 1;
					}
					break;
				}
				printf("\nCola llena.\n");
				break;

			case 2:
				if (final == inicio && llena == 0)
				{
					printf("Está vacía.\n");
					break;
				}
				inicio = (inicio + 1) % TAMAÑO;
				if (llena)
				{
					llena = 0;
				}
				break;
				
			case 3:
				printf("Cola: \n");
				if (llena)
    			{
        			int condicParo = (TAMAÑO - 1 + inicio) % TAMAÑO, i;
        			for (i = inicio;i != condicParo; i = (i + 1) % TAMAÑO) {
            			printf("%d ", cola[i]);
        			}
        			printf("%d \n", cola[i]);
    			}
    
				for (int i = inicio; i != final; i = (i + 1) % TAMAÑO) {
					printf("%d ", cola[i]);
				}
				printf("\n");
				printf("Arreglo:\n");
				for (int i = 0; i < TAMAÑO; i++) {
					printf("%d ", cola[i]);
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