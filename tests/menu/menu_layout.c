#include <stdio.h>
#include <stdlib.h>
#include <libdstruct.h>

#include "menu_functions.c"

int main(void)
{
    SNode *squeue = NULL, *sstack = NULL, *slist = NULL, *snodecpy = NULL, *sdeleted = NULL; 
    Node *queue = NULL, *stack = NULL, *list = NULL, *node = NULL, *deleted = NULL; 
    int opcion, opcionSecun, tercerOpcion, id, search, cont = 0;
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
                            //Agregar
                            printf("\t|________________________________.\n");
                            printf("\t|_____________Agregar____________|\n");
                            printf("\t| Ingrese el valor del nodo: ");
                            scanf("%d", &id);
                            squeue_enqueue(&squeue, snode_new(id));
                            system("clear");
                            break;
                        case 2:
                            //Quitar
                            sdeleted = squeue_dequeue(&squeue);
                            if (sdeleted == NULL)
                            {
                                printf("No hay nada.\n");
                            } else
                            {
                                printf("Se eliminó: %d\n", sdeleted->value);
                                snode_delete(&sdeleted);
                            }
                            break;
                        case 3: 
                            //imprimir
                            system("clear");
                            printf("|________Cola__________ _ _  _  _   _    _\n| ");
                            squeue_print(squeue);
                            break;
                        case 4: 
                            break;    
                        
                        default:
                            system("clear");
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
                            //Agregar
                            printf("\t|________________________________.\n");
                            printf("\t|_____________Agregar____________|\n");
                            printf("\t| Ingrese el valor del nodo: ");
                            scanf("%d", &id);
                            sstack_insert_node(&sstack, snode_new(id));
                            system("clear");
                            break;
                        case 2:
                            //Quitar
                            sdeleted = sstack_delete(&sstack);
                            if (sdeleted == NULL)
                            {
                                printf("No hay nada.\n");
                            } else
                            {
                                printf("Se eliminó: %d\n", sdeleted->value);
                                snode_delete(&sdeleted);
                            }
                            break;
                        case 3: 
                            //Imprimir
                            system("clear");
                            printf("|________Pila__________ _ _  _  _   _    _\n| ");
                            sstack_imprimir(&sstack);
                            break;
                        case 4: 
                            break;    
                        
                        default:
                            system("clear");
                            printf("\tOpcion invalida.\n");
                            break;
                        }

                        } while (tercerOpcion != 4);
                    break;

                case 3:  //Lista--------------------------------------
                        do
                        {
                        tercerOpcion = menu_lista(); 
                        switch (tercerOpcion)
                        {
                        case 1:
                            //Agregar
                            printf("\t|________________________________.\n");
                            printf("\t|_____________Agregar____________|\n");
                            printf("\t| Ingrese el valor del nodo: ");
                            scanf("%d", &id);
                            slist_insert_snode(&slist, snode_new(id));
                            system("clear");
                            break;
                        case 2:
                            //Quitar
                            system("clear");
                            printf("\t|_________________________________________.\n");
                            printf("\t|__________________Quitar_________________|\n");
                            printf("\t| Esta función requiere el índice de lista|\n");
                            printf("\t| Ingrese el indice del nodo a eliminar: ");
                            scanf("%d", &id);
                            sdeleted = slist_extract_node(&slist, id);
                            if (sdeleted == NULL)
                            {
                                printf("\t| + No se encontró el nodo. +\n");
                            } else
                            {
                                printf("\t| Se elimino: %d\n", sdeleted->value);
                                free(sdeleted);
                            }
                            break;
                        case 3: 
                            //Imprimir
                             system("clear");
                            printf("|________Lista__________ _ _  _  _   _    _\n| ");
                            slist_print(slist);
                            break;
                        case 4: 
                            //Buscar
                            printf("\t|_________________________________________.\n");
                            printf("\t|__________________Buscar_________________|\n");
                            printf("\t| Ingrese el valor del nodo a buscar: ");
                            scanf("%d", &id);

                            search = slist_search_snode(&slist, snode_new(id));
                            if (search == -1)
                            {
                                printf("\t| + Está vacío. +\n");
                            } else if (search == -2)
                            {
                                printf("\t| El nodo que busca no se encuentra en la lista %d. \n", search);
                            }  else if (search >= 0)
                            {
                                printf("\t| El nodo está en en índice %d.\n", search);
                            }
                            break;  
                        case 5:
                            //Copiar
                            printf("\t|_________________________________________.\n");
                            printf("\t|__________________Copiar_________________|\n");
                            printf("\t| Ingrese el índice que quiere copiar: ");
                            scanf("%d", &id);
                            snodecpy = snode_jump_to_n(slist, id);
                            slist_insert_snode(&slist, snode_new(snodecpy->value));
                            break;  
                        case 6:
                            break;
                        
                        default:
                            printf("\tOpcion invalida.\n");
                            break;
                        }

                        } while (tercerOpcion != 6);

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
                opcionSecun = menu_secundario_doblemente();
                switch (opcionSecun)
                {
                case 1: //Cola --------------------------------
                        do
                        {
                        tercerOpcion = menu_cola_pila();
                        switch (tercerOpcion)
                        {
                        case 1:
                            //Agregar
                            break;
                        case 2:
                            //Quitar
                            break;
                        case 3: 
                            //Imprimir
                            break;
                        case 4: 
                            break;    
                        
                        default:
                            printf("\tOpcion invalida.\n");
                            break;
                        }

                    } while (tercerOpcion != 4);
                    break;

                case 2:  //Lista ---------------------------
                        do
                        {
                        tercerOpcion = menu_lista();
                        switch (tercerOpcion)
                        {
                        case 1:
                            //Agregar
                            printf("\t|________________________________.\n");
                            printf("\t|_____________Agregar____________|\n");
                            printf("\t| Ingrese el valor del nodo: ");
                            scanf("%d", &id);
                            dolist_insert_node(&list, node_new(id));
                            system("clear");
                            break;
                        case 2:
                            //Quitar
                            printf("\t|_________________________________________.\n");
                            printf("\t|__________________Quitar_________________|\n");
                            printf("\t| Ingrese el valor del nodo a eliminar: ");
                            scanf("%d", &id);
                            deleted = dlist_delete_node(&list, id);
                            if (deleted == NULL)
                            {
                                printf("No se encontró el nodo. \n");
                            } else
                            {
                                printf("Se elimino: %d", deleted->value);
                                free(deleted);
                            }
                            break;
                        case 3: 
                            //Imprimir
                            system("clear");
                            printf("|________Lista__________ _ _  _  _   _    _\n| ");
                            dlist_imprimir(&list);
                            break;
                        case 4: 
                            //Buscar
                            printf("\t|_________________________________________.\n");
                            printf("\t|__________________Buscar_________________|\n");
                            printf("\t| Ingrese el valor del nodo a buscar: ");
                            scanf("%d", &id);

                            search = dlist_search_node(&list, node_new(id));
                            if (search == -2)
                            {
                                printf("\t| + Está vacío. +\n");
                            } else if (search == -1)
                            {
                                printf("\t| El nodo que busca no se encuentra en la lista %d. \n", search);
                            }  else if (search >= 0)
                            {
                                printf("\t| El nodo está en en índice %d.\n", search);
                            }
                            break; 
                        case 5: 
                            //Copiar
                            break;        
                        case 6: 
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
                            //Agregar
                            break;
                        case 2:
                            //Quitar
                            break;
                        case 3: 
                            //Imprimir
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
                            //Agregar
                            break;
                        case 2:
                            //Quitar
                            break;
                        case 3: 
                            //Imprimir
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
                            //Agregar
                            break;
                        case 2:
                            //Quitar
                            break;
                        case 3: 
                            //Imprimir
                            break;
                        case 4:
                            //Buscar 
                            break;  
                        case 5: 
                            //Copiar
                            break;      
                        case 6:
                            //Salis 
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

        case 4: //Con prioridad
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
                            //Agregar
                            printf("\t|________________________________.\n");
                            printf("\t|_____________Agregar____________|\n");
                            printf("\t| Ingrese el valor del nodo: ");
                            scanf("%d", &id);
                            
                            system("clear");
                            break;
                        case 2:
                            //Quitar
                           //Funcion para extraer
                            if (sdeleted == NULL)
                            {
                                printf("No hay nada.\n");
                            } else
                            {
                                printf("Se eliminó: %d\n", sdeleted->value);
                                snode_delete(&sdeleted);
                            }
                            break;
                        case 3: 
                            //imprimir
                            system("clear");
                            printf("|________Cola__________ _ _  _  _   _    _\n| ");
                           
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
                            //Agregar
                            printf("\t|________________________________.\n");
                            printf("\t|_____________Agregar____________|\n");
                            printf("\t| Ingrese el valor del nodo: ");
                            scanf("%d", &id);
                            
                            system("clear");
                            break;
                        case 2:
                            //Quitar
                           //Función para extraer iría aquí
                            if (sdeleted == NULL)
                            {
                                printf("No hay nada.\n");
                            } else
                            {
                                printf("Se eliminó: %d\n", sdeleted->value);
                                snode_delete(&sdeleted);
                            }
                            break;
                        case 3: 
                            //Imprimir
                            system("clear");
                            printf("|________Pila__________ _ _  _  _   _    _\n| ");
                            
                            break;
                        case 4: 
                            break;    
                        
                        default:
                            system("clear");
                            printf("\tOpcion invalida.\n");
                            break;
                        }

                        } while (tercerOpcion != 4);
                    break;

                case 3:  //Lista--------------------------------------
                        do
                        {
                        tercerOpcion = menu_lista(); 
                        switch (tercerOpcion)
                        {
                        case 1:
                            //Agregar
                            break;
                        case 2:
                            //Quitar
                            break;
                        case 3: 
                            //Imprimir
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
        case 5:
            break;

        default:
            printf("------ Oopción invalida. ------\n");
            break;
        } //Fin del menú principal
    } while (opcion != 5);
    

    return 0;
}
