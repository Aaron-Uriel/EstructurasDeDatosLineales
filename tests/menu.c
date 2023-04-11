#include <stdio.h>
#include <stdlib.h>
#include <libdstruct.h>

int menu_principal(void)
{
    int opcion;
    system("clear");
    printf("*******************************\n");
    printf("|   Colas, Pilas y listas.    |\n");
    printf("._____________________________.\n");
    printf("|            Menu.            |\n");
    printf("|-----------------------------|\n");
    printf("|1.- Simplemente ligadas.     |\n");
    printf("|2.- Doblemmente ligadas.     |\n");
    printf("|3.- Con cabecera.            |\n");
    printf("|4.- Salir.                   |\n");
    printf("|_____________________________|\n");
    printf("|Opcion: ");
    scanf("%d", &opcion);
    printf("|_____________________________|\n");
    return opcion;
}

int menu_secundario(void)
{
    int opcionSecun;
    printf("\t|____________.\n");
    printf("\t|1.- Cola.   |\n");
    printf("\t|2.- Pila.   |\n");
    printf("\t|3.- Lista.  |\n");
    printf("\t|4.- Volver. |\n");
    printf("\t|____________|\n");
    printf("\t|Opcion: ");
    scanf("%d", &opcionSecun);
    printf("\t|_____________|\n");
    return opcionSecun;
}

int menu_cola_pila (void)
{
    int opcion;
    system("clear");
    printf("._________________________________.\n");
    printf("|______________Menú_______________|\n");
    printf("| 1.- Agregar (Crear + insertar)  |\n");
    printf("| 2.- Quitar (Extraer + Eliminar) |\n");
    printf("| 3.- Imprimir cola               |\n");
    printf("| 4.- Volver                      |\n");
    printf("|_________________________________|\n");
    printf("| Opcion: ");
    scanf ("%d", &opcion);
    return opcion;
}
