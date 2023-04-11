#include <stdio.h>
#include <stdlib.h>
#include <libdstruct.h>
#include <menu.c>

int main(void)
{
    int opcion, opcionSecun, tercerOpcion;
    do
    {
        opcion = menu_principal();  
        switch (opcion) //Inicio del menú principal
        {   
        case 1: //Simplemente ligadas. ---------------------
            do
            {
                opcionSecun = menu_secundario();
                switch (opcionSecun)
                {
                case 1: //Cola ----------------------------
                    do
                    {
                        tercerOpcion = menu_cola_pila();
                        switch (tercerOpcion)
                        {
                        case 1:
                            printf("Uno\n");
                            break;
                        case 2:
                                printf("dos");
                            break;
                        case 3: 
                                printf("tres");
                            break;
                        case 4: 
                            break;    
                        
                        default:
                            printf("\tOpcion invalida.\n");
                            break;
                        }

                    } while (tercerOpcion != 4);
                    
                    break;

                case 2: //Pila-----------------------------
                        do
                        {
                        tercerOpcion = menu_cola_pila();
                        switch (tercerOpcion)
                        {
                        case 1:
                            printf("Uno\n");
                            break;
                        case 2:
                                printf("dos");
                            break;
                        case 3: 
                                printf("tres");
                            break;
                        case 4: 
                            break;    
                        
                        default:
                            printf("\tOpcion invalida.\n");
                            break;
                        }

                        } while (tercerOpcion != 4);
                    break;

                case 3:  //Lista--------------------------------------
                        do
                        {
                        tercerOpcion = menu_cola_pila();
                        switch (tercerOpcion)
                        {
                        case 1:
                            printf("Uno\n");
                            break;
                        case 2:
                                printf("dos");
                            break;
                        case 3: 
                                printf("tres");
                            break;
                        case 4: 
                            break;    
                        
                        default:
                            printf("\tOpcion invalida.\n");
                            break;
                        }

                        } while (tercerOpcion != 4);

                    break;
                case 4: 
                    break;
                
                default:
                    printf("\tOpcion invalida.\n");
                    break;
                }
            } while (opcionSecun != 4);

            break;

        case 2: //Doblemente ligadas ----------------------------------------------
            do
            {
                opcionSecun = menu_secundario();
                switch (opcionSecun)
                {
                case 1: //Cola --------------------------------
                        do
                        {
                        tercerOpcion = menu_cola_pila();
                        switch (tercerOpcion)
                        {
                        case 1:
                            printf("Uno\n");
                            break;
                        case 2:
                                printf("dos");
                            break;
                        case 3: 
                                printf("tres");
                            break;
                        case 4: 
                            break;    
                        
                        default:
                            printf("\tOpcion invalida.\n");
                            break;
                        }

                    } while (tercerOpcion != 4);
                    break;

                case 2: //Pila --------------------------
                        do
                        {
                        tercerOpcion = menu_cola_pila();
                        switch (tercerOpcion)
                        {
                        case 1:
                            printf("Uno\n");
                            break;
                        case 2:
                                printf("dos");
                            break;
                        case 3: 
                                printf("tres");
                            break;
                        case 4: 
                            break;    
                        
                        default:
                            printf("\tOpcion invalida.\n");
                            break;
                        }

                    } while (tercerOpcion != 4);
                    break;

                case 3:  //Lista ---------------------------
                        do
                        {
                        tercerOpcion = menu_cola_pila();
                        switch (tercerOpcion)
                        {
                        case 1:
                            printf("Uno\n");
                            break;
                        case 2:
                                printf("dos");
                            break;
                        case 3: 
                                printf("tres");
                            break;
                        case 4: 
                            break;    
                        
                        default:
                            printf("\tOpcion invalida.\n");
                            break;
                        }

                    } while (tercerOpcion != 4);
                    break;
                case 4: 
                    break;
                
                default:
                    printf("\tOpcion invalida.\n");
                    break;
                }
            } while (opcionSecun != 4);
            break;

        case 3:  //Con cabecera
            do
            {
                opcionSecun = menu_secundario();
                switch (opcionSecun)
                {
                case 1: //Cola -----------------------------------
                        do
                        {
                        tercerOpcion = menu_cola_pila();
                        switch (tercerOpcion)
                        {
                        case 1:
                            printf("Uno\n");
                            break;
                        case 2:
                                printf("dos");
                            break;
                        case 3: 
                                printf("tres");
                            break;
                        case 4: 
                            break;    
                        
                        default:
                            printf("\tOpcion invalida.\n");
                            break;
                        }

                    } while (tercerOpcion != 4);
                    break;

                case 2: //Pila ------------------------------------
                        do
                        {
                        tercerOpcion = menu_cola_pila();
                        switch (tercerOpcion)
                        {
                        case 1:
                            printf("Uno\n");
                            break;
                        case 2:
                                printf("dos");
                            break;
                        case 3: 
                                printf("tres");
                            break;
                        case 4: 
                            break;    
                        
                        default:
                            printf("\tOpcion invalida.\n");
                            break;
                        }

                    } while (tercerOpcion != 4);
                    break;

                case 3:  //Lista ---------------------------------------
                        do
                        {
                        tercerOpcion = menu_cola_pila();
                        switch (tercerOpcion)
                        {
                        case 1:
                            printf("Uno\n");
                            break;
                        case 2:
                                printf("dos");
                            break;
                        case 3: 
                                printf("tres");
                            break;
                        case 4: 
                            break;    
                        
                        default:
                            printf("\tOpcion invalida.\n");
                            break;
                        }

                    } while (tercerOpcion != 4);
                    break;

                case 4: 
                    break;
                
                default:
                    printf("\tOpcion invalida.\n");
                    break;
                }
            } while (opcionSecun != 4);

            break;

        case 4: 
            break;

        default:
            printf("------ Oopción invalida. ------\n");
            break;
        } //Fin del menú principal
    } while (opcion != 4);
    

    return 0;
}
