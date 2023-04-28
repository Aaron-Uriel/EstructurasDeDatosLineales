#include <stdio.h>
#include <stdlib.h>
#include <libdstruct.h>

#include "menu_functions.c"

int main(void)
{
    //Simplemente ligadas.
    SNode *squeue = NULL, *sstack = NULL, *slist = NULL, *snodecpy = NULL, *sdeleted = NULL; 
    //Doblemente ligadas.
    Node *queue = NULL, *stack = NULL, *list = NULL, *node = NULL, *deleted = NULL, *nodecpy = NULL; 
    //Cola con cabecera
    HQueue *headqueue = hqueue_new(); 
    //Lista con cabecera.
    List *headlist = list_new();
    //Cola con prioridad.
    PQueue *prioqueue = pqueue_new();
    PNode *pdeleted;
    //Cola estática
    StaticQueue *staqueue = static_queue_new(10);

    //Variables enteras a usar.
    int opcion, opcionSecun, tercerOpcion, id, search, cont = 0, prioridad;
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
                                system("clear");
                                printf("\t| + Está vacío. +\n");
                            } else if (search == -2)
                            {
                                system("clear");
                                printf("\t| El nodo que busca no se encuentra en la lista %d. \n", search);
                            }  else if (search >= 0)
                            {
                                system("clear");
                                printf("\t| El nodo está en en índice %d.\n", search);
                            }
                            break;  
                        case 5:
                            //Copiar
                            printf("\t|_________________________________________.\n");
                            printf("\t|__________________Copiar_________________|\n");
                            printf("\t| Ingrese el índice que quiere copiar: ");
                            scanf("%d", &id);
                            snodecpy = snode_clone(snode_jump_to_n(slist, id));
                            slist_insert_snode(&slist, snodecpy);
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
                            printf("\t|________________________________.\n");
                            printf("\t|_____________Agregar____________|\n");
                            printf("\t| Ingrese el valor del nodo: ");
                            scanf("%d", &id);
                            dqueue_enqueue(&queue, node_new(id));
                            system("clear");
                            break;
                        case 2:
                            //Quitar
                            deleted = dqueue_dequeue(&queue);
                            if (deleted == NULL)
                            {
                                printf("No hay nada.\n");
                            } else
                            {
                                printf("| Se eliminó: %d\n", deleted->value);
                                node_delete(&deleted);
                            }
                            break;
                        case 3: 
                            //Imprimir
                            system("clear");
                            printf("|________Cola__________ _ _  _  _   _    _\n| ");
                            dqueue_print(queue);
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
                            dlist_insert_node(&list, node_new(id));
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
                                system("clear");
                                printf("No se encontró el nodo. \n");
                            } else
                            {
                                system("clear");
                                printf("Se elimino: %d \n", deleted->value);
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
                                system("clear");
                                printf("\t| + Está vacío. +\n");
                            } else if (search == -1)
                            {
                                system("clear");
                                printf("\t| El nodo que busca no se encuentra en la lista. \n");
                            }  else if (search >= 0)
                            {
                                system("clear");
                                printf("\t| El nodo está en en índice %d.\n", search);
                            }
                            break; 
                        case 5: 
                            //Copiar
                            printf("\t|_________________________________________.\n");
                            printf("\t|__________________Copiar_________________|\n");
                            printf("\t| Ingrese el índice que quiere copiar: ");
                            scanf("%d", &id);
                            nodecpy = node_clone(node_jump_to_n(list, id));
                            dlist_insert_node(&list, nodecpy);
                            system("clear");
                            break;        
                        case 6: 
                            break; 
                        default:
                            printf("\tOpcion invalida.\n");
                            break;
                        }

                    } while (tercerOpcion != 6);
                    break;
                case 3: 
                    break;
                
                default:
                    printf("\tOpcion invalida.\n");
                    break;
                }
            } while (opcionSecun != 3);
            break;

        case 3:  //Con cabecera ---------------------------------------------------------------
            do
            {
                opcionSecun = menu_secundario_doblemente();
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
                            printf("\t|________________________________.\n");
                            printf("\t|_____________Agregar____________|\n");
                            printf("\t| Ingrese el valor del nodo: ");
                            scanf("%d", &id);
                            hqueue_insert(headqueue, node_new(id));
                            system("clear");
                            break;
                        case 2:
                            //Quitar
                            deleted = hqueue_extract(headqueue);
                            if (deleted == NULL)
                            {
                                printf("No hay nada.\n");
                            } else
                            {
                                printf("| Se eliminó: %d\n", deleted->value);
                                node_delete(&deleted);
                            }
                            break;
                        case 3: 
                            //Imprimir
                            system("clear");
                            printf("|________Cola__________ _ _  _  _   _    _\n| ");
                            hqueue_print(headqueue);
                            break;
                        case 4: 
                            break;  
                        
                        default:
                            printf("\tOpcion invalida.\n");
                            break;
                        }

                    } while (tercerOpcion != 4);
                    break;
                case 2:  //Lista ---------------------------------------
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
                            list_insert_node(headlist, node_new(id));
                            system("clear");
                            
                            break;
                        case 2:
                            //Quitar
                             printf("\t|_________________________________________.\n");
                            printf("\t|__________________Quitar_________________|\n");
                            printf("\t| Ingrese el valor del nodo a eliminar: ");
                            scanf("%d", &id);
                            deleted = list_extract_node(headlist, id);
                            if (deleted == NULL)
                            {
                                system("clear");
                                printf("No se encontró el nodo. \n");
                            } else
                            {
                                system("clear");
                                printf("Se elimino: %d \n", deleted->value);
                                free(deleted);
                            }
                            break;
                        case 3: 
                            //Imprimir
                            system("clear");
                            printf("|________Lista__________ _ _  _  _   _    _\n| ");
                            list_print(headlist);
                            break;
                        case 4:
                            //Buscar 
                            printf("\t|_________________________________________.\n");
                            printf("\t|__________________Buscar_________________|\n");
                            printf("\t| Ingrese el indice del nodo a buscar: ");
                            scanf("%d", &id);

                            search = list_search_node(headlist, node_new(id));
                            if (search == -1)
                            {
                                system("clear");
                                printf("\t| + Está vacío. +\n");
                            } else if (search == -2)
                            {
                                system("clear");
                                printf("\t| El nodo que busca no se encuentra en la lista. \n");
                            }  else if (search >= 0)
                            {
                                system("clear");
                                printf("\t| El nodo está en en índice %d.\n", search);
                            }
                            break;  
                        case 5: 
                            //Copiar
                            printf("\t|_________________________________________.\n");
                            printf("\t|__________________Copiar_________________|\n");
                            printf("\t| Ingrese el índice que quiere copiar: ");
                            scanf("%d", &id);
                            nodecpy = node_clone(node_jump_to_n(headlist->first, id));
                            list_insert_node(headlist, nodecpy);
                            system("clear");
                            break;      
                        case 6:
                            //Salir
                            break;  
                        break;       
                        default:
                            printf("\tOpcion invalida.\n");
                            break;
                        }

                    } while (tercerOpcion != 6);
                    break;

                case 3: 
                    break;
                
                default:
                    printf("\tOpcion invalida.\n");
                    break;
                }
            } while (opcionSecun != 3);

            break;

        case 4: //Con prioridad
        system("clear");
            do   
            {
                printf("\n|________Cola__________ _ _  _  _   _    _\n");
                tercerOpcion = menu_cola_pila();
                switch (tercerOpcion)
                   {
                    case 1:     
                       //Agregar
                        printf("\t|________________________________.\n");
                        printf("\t|_____________Agregar____________|\n");
                        printf("\t| Ingrese el valor del nodo: ");
                        scanf("%d", &id);
                        printf("\t| Ingrese su prioridad: ");
                        scanf("%d", &prioridad);
                        pqueue_enqueue(prioqueue, pnode_new(id, prioridad));
                        system("clear");
                        break;
                        case 2:
                            //Quitar
                           //Funcion para extraer
                            pdeleted = pqueue_dequeue(prioqueue);
                            if (pdeleted == NULL)
                            {
                                printf("No hay nada.\n");
                            } else
                            {
                                printf("| Se eliminó: %d\n", pdeleted->value);
                                pnode_delete(&pdeleted);
                            }
                            break;
                        case 3: 
                            //imprimir
                            system("clear");
                            pqueue_print(prioqueue);
                           
                            break;
                        case 4: 
                            break;    
                        
                        default:
                            printf("\tOpcion invalida.\n");
                            break;
                 }
            } while (tercerOpcion != 4);
            break;
        case 5:
            opcionSecun = menu_secundario_estatica();
            do
            {
                switch (opcionSecun)
                {
                case 1: //Cola -------------------------------
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
                            static_queue_insert(staqueue, id);
                            system("clear");
                            break;
                        case 2:
                            //Quitar.
                            static_queue_extract(staqueue);
                            break;
                         case 3:
                            //Imprimir
                            system("clear");
                            printf("|________Cola__________ _ _  _  _   _    _\n| ");
                            static_queue_print(staqueue);
                            break;
                        case 4: //Salir
                            break;       
                        default:
                            printf("Opcion invalida.\n");
                            break;
                        }
                     } while (tercerOpcion != 4);
                     
                    break;
                
                case 2: //Pila ----------------------------------
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
                            //Quitar.
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
                            //Imprimir
                            system("clear");
                            printf("|________Cola__________ _ _  _  _   _    _\n| ");
                            squeue_print(squeue);
                            break;
                        case 4: //Salir
                            break;       
                        default:

                            break;
                        }
                     } while (tercerOpcion != 4);


                    break;
                
                case 3: //Salir 

                    break;
                default:
                    break;
                }
            } while (opcionSecun != 3);
            
            break;
        case 6:
            break;    

        default:
            printf("------ Oopción invalida. ------\n");
            break;
        } //Fin del menú principal
    } while (opcion != 6);
    

    return 0;
}