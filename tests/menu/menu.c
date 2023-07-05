#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <libdstruct.h>
#include "utilidades.h"


int32_t
main(void)
{
    //Simplemente ligadas.
    SNode *cola_simple = NULL, *pila_simple = NULL, *lista_simple = NULL, *nodo_simple_temporal;
    //Doblemente ligadas.
    Node *cola_doble = NULL, *lista_doble = NULL, *nodo_doble_temporal; 
    //Cola con cabecera
    HQueue *cola_cabecera = NULL; 
    //Lista con cabecera.
    List *lista_cabecera = NULL;
    //Cola con prioridad.
    PQueue *cola_prioridad = NULL;
    PNode *nodo_prioridad_temporal;
    //Cola circular
    SNode *primero = NULL, *final = NULL;
    //Cola estática
    #define TAMAÑO 8
    int cola[TAMAÑO] = {0, 0, 0, 0, 0, 0, 0, 0};
    int inicio = 0, finalEstatico = 0;	
	int llena = 0;

    //Pila estática
    int pila[TAMAÑO] = {0, 0, 0, 0, 0, 0, 0, 0};

    const char *menu_principal_opciones_cortas = "sdcpeix";
    const char *menu_principal_opciones_largas[] = {
        "Simplemente ligadas.", "Doblemente ligadas.", "Con cabecera.",
        "Con prioridad.", "Estáticas.", "Circulares.", "Salir.", NULL
    };

    const char *menu_secundario_opciones_cortas = "cplx";
    const char *menu_secundario_opciones_largas[] = {
        "Cola.", "Pila.", "Lista.", "Volver.", NULL
    };

    const char *menu_secundario_doblemente_opciones_cortas = "clx";
    const char *menu_secundario_doblemente_opciones_largas[] = {
        "Cola.", "Lista.",  "Volver.", NULL
    };

    const char *menu_secundario_estatica_opciones_cortas = "cpx";
    const char *menu_secundario_estatica_opciones_largas[] = {
        "Cola.", "Pila.", "Volver.", NULL
    };

    const char *menu_cola_pila_opciones_cortas = "aqx";
    const char *menu_cola_pila_opciones_largas[] = {
        "Agregar (crear + insertar).", "Quitar (extraer + eliminar).",
        "Volver.", NULL
    };

    const char *menu_lista_opciones_cortas = "aqbcx";
    const char *menu_lista_opciones_largas[] = {
        "Agregar (crear + insertar).", "Quitar (extraer + eliminar).",
        "Buscar.", "Copiar.", "Volver.", NULL
    };
    //Variables enteras a usar.
    int opcion, id, prioridad;
    do {
        system("clear");
        opcion = menu_crear("Estructuras de datos lineales.",
                menu_principal_opciones_cortas,
                menu_principal_opciones_largas);
        switch (opcion) { // Inicio del menú principal 
            case 's': // Simplemente ligadas. ---------------------
                do {
                    system("clear");
                    opcion = menu_crear("Simplemente ligadas",
                            menu_secundario_opciones_cortas,
                            menu_secundario_opciones_largas);
                    switch (opcion) {
                        case 'c': // Cola. ----------------------------
                            do {
                                system("clear");
                                squeue_print(cola_simple);
                                opcion = menu_crear("Cola simplemente ligada.",
                                        menu_cola_pila_opciones_cortas,
                                        menu_cola_pila_opciones_largas);
                                switch (opcion) {
                                    case 'a':
                                        printf("\t|________________________________.\n");
                                        printf("\t|_____________Agregar____________|\n");
                                        printf("\t| Ingrese el valor del nodo: ");
                                        scanf("%d", &id);
                                        squeue_enqueue(&cola_simple, snode_new(id));
                                        break;
                                    case 'q':
                                        if ((nodo_simple_temporal = squeue_dequeue(&cola_simple))) {
                                            printf("Se eliminó: %d\n", nodo_simple_temporal->value);
                                            snode_free(&nodo_simple_temporal);
                                        } else {
                                            printf("No hay nada.\n");
                                        }
                                        pausar();
                                        break;
                                    case 'x': 
                                        squeue_free(&cola_simple);
                                        break;    
                                }
                            } while (opcion != 'x');
                            opcion = 0;
                            break;

                        case 'p': // Pila. -----------------------------
                            do {
                                system("clear");
                                sstack_imprimir(&pila_simple);
                                opcion = menu_crear("Pila simplemente ligada.",
                                        menu_cola_pila_opciones_cortas,
                                        menu_cola_pila_opciones_largas);
                                switch (opcion) {
                                    case 'a':
                                        printf("\t|________________________________.\n");
                                        printf("\t|_____________Agregar____________|\n");
                                        printf("\t| Ingrese el valor del nodo: ");
                                        scanf("%d", &id);
                                        sstack_insert_node(&pila_simple, snode_new(id));
                                        break;
                                    case 'q':
                                        if ((nodo_simple_temporal = sstack_delete(&pila_simple))) {
                                            printf("Se eliminó: %d\n", nodo_simple_temporal->value);
                                            snode_free(&nodo_simple_temporal);
                                        } else {
                                            printf("No hay nada.\n");
                                        }
                                        pausar();
                                        break;
                                    case 'x': 
                                        sstack_free(&pila_simple);
                                        break; 
                                }
                            } while (opcion != 'x');
                            opcion = 0;
                            break;

                        case 'l': // Lista. --------------------------------------
                            do {
                                system("clear");
                                slist_print(lista_simple);
                                opcion = menu_crear("Lista simplemente ligada.",
                                        menu_lista_opciones_cortas,
                                        menu_lista_opciones_largas); 
                                switch (opcion) {
                                    case 'a':
                                        printf("\t|________________________________.\n");
                                        printf("\t|_____________Agregar____________|\n");
                                        printf("\t| Ingrese el valor del nodo: ");
                                        scanf("%d", &id);
                                        slist_insert_snode(&lista_simple, snode_new(id));
                                        system("clear");
                                        break;
                                    case 'q':
                                        printf("\t|_________________________________________.\n");
                                        printf("\t|__________________Quitar_________________|\n");
                                        printf("\t| Ingrese el valor del nodo a eliminar: ");
                                        scanf("%d", &id);
                                        getchar();
                                        if ((nodo_simple_temporal = slist_extract_node(&lista_simple, id))) {
                                            printf("\t| Se elimino: %d\n", nodo_simple_temporal->value);
                                            snode_free(&nodo_simple_temporal);
                                        } else {
                                            printf("\t| + No se encontró el nodo. +\n");
                                        }
                                        pausar();
                                        break;
                                    case 'b': 
                                        printf("\t|_________________________________________.\n");
                                        printf("\t|__________________Buscar_________________|\n");
                                        printf("\t| Ingrese el valor del nodo a buscar: ");
                                        scanf("%d", &id);
                                        getchar();
                                        printf("\t| El nodo %s en la lista.\n", 
                                                (slist_search_snode(&lista_simple, id)? "existe": "no existe"));
                                        pausar();
                                        break;  
                                    case 'c':
                                        printf("\t|_________________________________________.\n");
                                        printf("\t|__________________Copiar_________________|\n");
                                        printf("\t| Ingrese el id del nodo que quiere copiar: ");
                                        scanf("%d", &id);
                                        getchar();
                                        if ((nodo_simple_temporal = slist_search_snode(&lista_simple, id))) {
                                            slist_insert_snode(&lista_simple, snode_clone(nodo_simple_temporal));
                                        } else {
                                            printf("No existe el nodo con id: %d", id);
                                            pausar();
                                        }
                                        break;  
                                    case 'x':
                                        slist_free(&lista_simple);
                                        break;
                                }

                            } while (opcion != 'x');
                            opcion = 0;

                            break;
                        case 'x': 
                            break;
                    }
                } while (opcion != 'x');
                opcion = 0;
                break;

            case 'd': // Doblemente ligadas. ----------------------------------------------
                do {
                    system("clear");
                    opcion = menu_crear("Doblemente ligadas.",
                            menu_secundario_doblemente_opciones_cortas,
                            menu_secundario_doblemente_opciones_largas);
                    switch (opcion) {
                        case 'c': // Cola. --------------------------------
                            do {
                                system("clear");
                                dqueue_print(cola_doble);
                                opcion = menu_crear("Cola doblemente ligada",
                                        menu_cola_pila_opciones_cortas,
                                        menu_cola_pila_opciones_largas);
                                switch (opcion) {
                                    case 'a':
                                        printf("\t|________________________________.\n");
                                        printf("\t|_____________Agregar____________|\n");
                                        printf("\t| Ingrese el valor del nodo: ");
                                        scanf("%d", &id);
                                        dqueue_enqueue(&cola_doble, node_new(id));
                                        break;
                                    case 'q':
                                        if ((nodo_doble_temporal = dqueue_dequeue(&cola_doble))) {
                                            printf("| Se eliminó: %d\n", nodo_doble_temporal->value);
                                            node_delete(&nodo_doble_temporal);
                                        } else {
                                            printf("No hay nada.\n");
                                        }
                                        pausar();
                                        break;
                                    case 'x': 
                                        dqueue_free(&cola_doble);
                                        break;    
                                }

                            } while (opcion != 'x');
                            opcion = 0;
                            break;

                        case 'l':  // Lista. ---------------------------
                            do {
                                system("clear");
                                dlist_imprimir(&lista_doble);
                                opcion = menu_crear("Lista doblemente ligada.",
                                        menu_lista_opciones_cortas,
                                        menu_lista_opciones_largas);
                                switch (opcion) {
                                    case 'a':
                                        printf("\t|________________________________.\n");
                                        printf("\t|_____________Agregar____________|\n");
                                        printf("\t| Ingrese el valor del nodo: ");
                                        scanf("%d", &id);
                                        getchar();
                                        dlist_insert_node(&lista_doble, node_new(id));
                                        break;
                                    case 'q':
                                        printf("\t|_________________________________________.\n");
                                        printf("\t|__________________Quitar_________________|\n");
                                        printf("\t| Ingrese el valor del nodo a eliminar: ");
                                        scanf("%d", &id);
                                        getchar();
                                        if ((nodo_doble_temporal = dlist_extract_node(&lista_doble, id))) {
                                            printf("Se elimino: %d \n", nodo_doble_temporal->value);
                                            node_delete(&nodo_doble_temporal);
                                        } else {
                                            printf("No se encontró el nodo. \n");
                                        }
                                        pausar();
                                        break;
                                    case 'b': 
                                        printf("\t|_________________________________________.\n");
                                        printf("\t|__________________Buscar_________________|\n");
                                        printf("\t| Ingrese el valor del nodo a buscar: ");
                                        scanf("%d", &id);
                                        getchar();
                                        printf("\t| El nodo %s en la lista.\n",
                                                (dlist_search_node(&lista_doble, id))? "existe": "no existe");
                                        pausar();
                                        break; 
                                    case 'c': 
                                        printf("\t|_________________________________________.\n");
                                        printf("\t|__________________Copiar_________________|\n");
                                        printf("\t| Ingrese el id del nodo a copiar: ");
                                        scanf("%d", &id);
                                        if ((nodo_doble_temporal = dlist_search_node(&lista_doble, id))) {
                                            dlist_insert_node(&lista_doble, node_clone(nodo_doble_temporal));
                                        } else {
                                            printf("No existe el nodo con id: %d.\n", id);
                                            getchar();
                                            pausar();
                                        }
                                        break;        
                                    case 'x': 
                                        dlist_free(&lista_doble);
                                        break; 
                                }
                            } while (opcion != 'x');
                            opcion = 0;
                            break;
                        case 'x': 
                            break;
                    }
                } while (opcion != 'x');
                opcion = 0;
                break;

            case 'c':// Con cabecera. ---------------------------------------------------------------
                do {
                    system("clear");
                    opcion = menu_crear("Con cabecera.",
                            menu_secundario_doblemente_opciones_cortas,
                            menu_secundario_doblemente_opciones_largas);
                    switch (opcion) {
                        case 'c': // Cola. -----------------------------------
                            cola_cabecera = hqueue_new();
                            do {
                                system("clear");
                                hqueue_print(cola_cabecera);
                                opcion = menu_crear("Cola con cabecera.",
                                        menu_cola_pila_opciones_cortas,
                                        menu_cola_pila_opciones_largas);
                                switch (opcion) {
                                    case 'a':
                                        printf("\t|________________________________.\n");
                                        printf("\t|_____________Agregar____________|\n");
                                        printf("\t| Ingrese el valor del nodo: ");
                                        scanf("%d", &id);
                                        hqueue_insert(cola_cabecera, node_new(id));
                                        break;
                                    case 'q':
                                        if ((nodo_doble_temporal = hqueue_extract(cola_cabecera))) {
                                            printf("| Se eliminó: %d\n", nodo_doble_temporal->value);
                                            node_delete(&nodo_doble_temporal);
                                        } else {
                                            printf("No hay nada.\n");
                                        }
                                        pausar();
                                        break;
                                    case 'x': 
                                        hqueue_free(&cola_cabecera);
                                        break;  
                                }
                            } while (opcion != 'x');
                            opcion = 0;
                            break;
                        case 'l':  // Lista. ---------------------------------------
                            lista_cabecera = list_new();
                            do {
                                system("clear");
                                list_print(lista_cabecera);
                                opcion = menu_crear("Lista con cabecera.",
                                        menu_lista_opciones_cortas,
                                        menu_lista_opciones_largas);
                                switch (opcion) {
                                    case 'a':
                                        printf("\t|________________________________.\n");
                                        printf("\t|_____________Agregar____________|\n");
                                        printf("\t| Ingrese el valor del nodo: ");
                                        scanf("%d", &id);
                                        list_insert_node(lista_cabecera, node_new(id));
                                        break;
                                    case 'q':
                                        printf("\t|_________________________________________.\n");
                                        printf("\t|__________________Quitar_________________|\n");
                                        printf("\t| Ingrese el valor del nodo a eliminar: ");
                                        scanf("%d", &id);
                                        if ((nodo_doble_temporal = list_extract_node(lista_cabecera, id))) {
                                            printf("Se elimino: %d \n", nodo_doble_temporal->value);
                                            node_delete(&nodo_doble_temporal);
                                        } else {
                                            printf("No se encontró el nodo. \n");
                                        }
                                        pausar();
                                        break;
                                    case 'b':
                                        printf("\t|_________________________________________.\n");
                                        printf("\t|__________________Buscar_________________|\n");
                                        printf("\t| Ingrese el indice del nodo a buscar: ");
                                        scanf("%d", &id);
                                        getchar();
                                        printf("\t| El nodo %s en la lista.\n",
                                                (list_search_node(lista_cabecera, id))? "existe": "no existe");
                                        pausar();
                                        break;  
                                    case 'c': 
                                        printf("\t|_________________________________________.\n");
                                        printf("\t|__________________Copiar_________________|\n");
                                        printf("\t| Ingrese el índice que quiere copiar: ");
                                        scanf("%d", &id);
                                        if ((nodo_doble_temporal = list_search_node(lista_cabecera, id))) {
                                            list_insert_node(lista_cabecera, node_clone(nodo_doble_temporal));
                                        } else {
                                            printf("No existe el nodo con id: %d.\n", id);
                                            getchar();
                                            pausar();
                                        }
                                        break;      
                                    case 'x':
                                        list_free(&lista_cabecera);
                                        break;       
                                }

                            } while (opcion != 'x');
                            opcion = 0;
                            break;
                        case 'x': 
                            break;
                    }
                } while (opcion != 'x');
                opcion = 0;
                break;

            case 'p': // Con prioridad.
                cola_prioridad = pqueue_new();
                do {
                    system("clear");
                    pqueue_print(cola_prioridad);
                    opcion = menu_crear("Cola con prioridad.",
                            menu_cola_pila_opciones_cortas,
                            menu_cola_pila_opciones_largas);
                    switch (opcion) {
                        case 'a':     
                            printf("\t|________________________________.\n");
                            printf("\t|_____________Agregar____________|\n");
                            printf("\t| Ingrese el valor del nodo: ");
                            scanf("%d", &id);
                            printf("\t| Ingrese su prioridad: ");
                            scanf("%d", &prioridad);
                            pqueue_enqueue(cola_prioridad, pnode_new(id, prioridad));
                            system("clear");
                            break;
                        case 'q':
                            if ((nodo_prioridad_temporal = pqueue_dequeue(cola_prioridad))) {
                                printf("| Se eliminó: %d\n", nodo_prioridad_temporal->value);
                                pnode_delete(&nodo_prioridad_temporal);
                            } else {
                                printf("No hay nada.\n");
                            }
                            pausar();
                            break;
                        case 'x': 
                            pqueue_free(&cola_prioridad);
                            break;    
                    }
                } while (opcion != 'x');
                opcion = 0;
                break;
            case 'e': // Estática. -----------------------
                do {
                    system("clear");
                    opcion = menu_crear("Estáticas.",
                            menu_secundario_estatica_opciones_cortas,
                            menu_secundario_estatica_opciones_largas);
                    switch (opcion) {
                        case 'c': //Cola -------------------------------
                            do {
                                system("clear");
                                //Imprimir la cola y el arreglo de la cola.
                                printf("Cola: \n");
				                if (llena)
    			                {
        			                int condicParo = (TAMAÑO - 1 + inicio) % TAMAÑO, i;
        			                for (i = inicio;i != condicParo; i = (i + 1) % TAMAÑO) {
            			                printf("%d ", cola[i]);
        			                }
        			                printf("%d \n", cola[i]);
    			                }
    
                                for (int i = inicio; i != finalEstatico; i = (i + 1) % TAMAÑO) {
                                    printf("%d ", cola[i]);
                                }
                                printf("\n");
                                printf("Arreglo:\n");
                                for (int i = 0; i < TAMAÑO; i++) {
                                    printf("%d ", cola[i]);
                                }
                                printf("\n");

                                opcion = menu_crear("Cola estática.",
                                        menu_cola_pila_opciones_cortas,
                                        menu_cola_pila_opciones_largas);
                                switch (opcion) {
                                    case 'a':

                                        if(!llena){
					                    printf("\t|________________________________.\n");
                                        printf("\t|_____________Agregar____________|\n");
                                        printf("\t| Ingrese el valor del nodo: ");
					                    scanf("%d", &cola[finalEstatico]);
					                    finalEstatico = (finalEstatico + 1) % TAMAÑO;
					                    if(finalEstatico % TAMAÑO == inicio)
					                    {
						                    llena = 1;
					                    }
					                    break;
				                        }
				                        printf("\nCola llena.\n");
				                        break;

                                    case 'q':
                                       if (finalEstatico == inicio && llena == 0)
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

                                    case 'x':
                                    inicio = 0;
                                    finalEstatico = 0;
                                    llena = 0;
                                    for (int i = 0; i < TAMAÑO; i++)
                                    {
                                        cola[i] = 0;
                                    }
                                        break;       
                                } 
                            } while (opcion != 'x');
                            opcion = 0;
                            break;

                        case 'p': // Pila ----------------------------------
                            do {
                                system("clear");
                                //Imprimir la pila
                                printf("Pila: \n");
                                for (int i = 0; i < finalEstatico; i ++) {
                                    printf("%d ", pila[i]);
                                }

                                printf("\n");
                                printf("Arreglo:\n");
                                for (int i = 0; i < TAMAÑO; i++) {
                                    printf("%d ", pila[i]);
                                }
                                printf("\n");
                                opcion = menu_crear("Pila estática.",
                                        menu_cola_pila_opciones_cortas,
                                        menu_cola_pila_opciones_largas);
                                switch (opcion) {
                                    case 'a':
                                        
                                        if(!llena){
                                            printf("\t|________________________________.\n");
                                            printf("\t|_____________Agregar____________|\n");
                                            printf("\t| Ingrese el valor del nodo: ");
                                            scanf("%d", &pila[finalEstatico]);
                                            finalEstatico++;
                                        
                                            if(finalEstatico == TAMAÑO)
                                            {
                                                llena = 1;
                                            }
                                            break;
                                        }
                                        printf("\nPila llena.\n");
                                        break;

                                    case 'q':
                                       if (finalEstatico ==  0)
                                        {
                                            printf("Está vacía.\n");
                                            break;
                                        }
                                        finalEstatico--;
                                        if (llena)
                                        {
                                            llena = 0;
                                        }
                                        break;
                                    case 'x':
                                    finalEstatico = 0;
                                    llena = 0;
                                    for (int i = 0; i < TAMAÑO; i++)
                                    {
                                        pila[i] = 0;
                                    }
                                        break;       
                                }
                            } while (opcion != 'x');
                            opcion = 0;
                            break;

                        case 'x': //Salir 
                            break;
                    }
                } while (opcion != 'x');
                opcion = 0;
                break;

            case 'i': //Circular
                do {
                    system("clear");
                    opcion = menu_crear("Circulares.",
                            menu_secundario_doblemente_opciones_cortas,
                            menu_secundario_doblemente_opciones_largas);
                    switch (opcion) {
                        case 'c': // Cola. --------------------------------
                            do {
                                system("clear");
                                imprimir_cola_circular(primero);
                                opcion = menu_crear("Cola circular",
                                        menu_cola_pila_opciones_cortas,
                                        menu_cola_pila_opciones_largas);
                                switch (opcion) {
                                    case 'a':
                                        printf("\n\t|________________________________.\n");
                                        printf("\t|_____________Agregar____________|\n");
                                        printf("\t| Ingrese el valor del nodo: ");
                                        scanf("%d", &id);
                                        insertar_cola_circular(&primero, &final, nueva_cola_circular(id));
                                        break;
                                    case 'q':
                                        if ((nodo_simple_temporal = extraer_cola_circular(&primero, &final))) {
                                            printf("| Se eliminó: %d\n", nodo_simple_temporal->value);
                                            eliminar_cola_circular(nodo_simple_temporal);
                                        } else {
                                            printf("No hay nada.\n");
                                        }
                                        pausar();
                                        break;
                                    case 'x': 
                                        eliminar_cola_circular(cola_simple);
                                        eliminar_cola_circular(primero);
                                        eliminar_cola_circular(final);
                                        break;    
                                }

                            } while (opcion != 'x');
                            opcion = 0;
                            break;

                        case 'l':  // Lista. ---------------------------
                            do {
                                system("clear");
                                imprimir_lista_circular(lista_simple);
                                printf("\n");
                                opcion = menu_crear("Lista Circular.",
                                        menu_lista_opciones_cortas,
                                        menu_lista_opciones_largas);
                                switch (opcion) {
                                    case 'a':
                                        printf("\t|________________________________.\n");
                                        printf("\t|_____________Agregar____________|\n");
                                        printf("\t| Ingrese el valor del nodo: ");
                                        scanf("%d", &id);
                                        getchar();
                                        insertar_lista_circular(&lista_simple, nueva_lista_circular(id));
                                        break;
                                    case 'q':
                                        printf("\n\t|_________________________________________.\n");
                                        printf("\t|__________________Quitar_________________|\n");
                                        printf("\t| Ingrese el valor del nodo a eliminar: ");
                                        scanf("%d", &id);
                                        getchar();
                                        if ((nodo_simple_temporal = extraer_lista_circular(&lista_simple, id))) {
                                            printf("Se elimino: %d \n", nodo_simple_temporal->value);
                                            eliminar_lista_circular(nodo_simple_temporal);
                                        } else {
                                            printf("No se encontró el nodo. \n");
                                        }
                                        pausar();
                                        break;
                                    case 'b': 
                                        printf("\n\t|_________________________________________.\n");
                                        printf("\t|__________________Buscar_________________|\n");
                                        printf("\t| Ingrese el valor del nodo a buscar: ");
                                        scanf("%d", &id);
                                        getchar();
                                        printf("\t| El nodo %s en la lista.\n",
                                                (buscar_lista_circular(lista_simple, id))? "existe": "no existe");
                                        pausar();
                                        break; 
                                    case 'c': 
                                        printf("\n\t|_________________________________________.\n");
                                        printf("\t|__________________Copiar_________________|\n");
                                        printf("\t| Ingrese el id del nodo a copiar: ");
                                        scanf("%d", &id);
                                        nodo_simple_temporal = copiar_lista_circular(lista_simple, id);
                                        if (nodo_simple_temporal) {
                                            insertar_lista_circular(&lista_simple, nodo_simple_temporal);
                                        } else {
                                            printf("No existe el nodo con id: %d.\n", id);
                                            getchar();
                                            pausar();
                                        }
                                        break;        
                                    case 'x': 
                                        eliminar_lista_circular(lista_simple);
                                        break; 
                                }
                            } while (opcion != 'x');
                            opcion = 0;
                            break;
                        case 'x': 
                            break;
                    }
                } while (opcion != 'x');
                opcion = 0;
                break;

            case 'x':
                break;

        } //Fin del menú principal
    } while (opcion != 'x');
    return 0;
}
