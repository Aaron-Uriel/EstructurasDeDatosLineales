#include <stdio.h>
#include <libdstruct.h>

int menu_principal(void)
{
    int opcion;
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

int main(void)
{
    int opcion;
    opcion = menu_principal();
    if (opcion == 0)
    {
        printf("Fue 0");
    }
    

    return 0;
}
