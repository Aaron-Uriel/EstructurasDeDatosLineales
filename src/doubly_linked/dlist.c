#include <stdio.h>
#include <stdlib.h>
#include <libdstruct.h>


/*
No regresa nada y recibe una dirección de un Node * y un Node *
Mientras el nodo que sigue del nodo actual sea distinto de NULL y "Listo"
no sea 0: Si el nodo que se va a ingresar es mayor que el actual, se recorre al siguiente
Pero si es menor o igual lo inserta en ese lugar.

*/
void dolist_insert_node(Node **dlist, Node *node)
{
    int listo = 0, cont = 0; 
    Node *actual = *dlist;
    Node *prev, *temporal = node; 

    if (node != NULL)
    {
        if (*dlist == NULL) {
        *dlist = node;

        } else {
            actual = *dlist; 
            while (actual->next != NULL && listo == 0) 
            {
                if (node->value > actual->value) 
                {
                    cont ++;
                    prev = actual;
                    actual = actual->next;
                    actual->previous = prev;

                    if (actual->next == NULL && node->value <= actual->value)
                    {
                        temporal = actual;
                        node->previous = prev;
                        actual->previous = node;
                        node->next = temporal;
                        prev->next = node;
                        listo = 1;
                    }
                    
                } else if (node->value <= actual->value)
                {
                    if (cont == 0)
                    {
                        temporal = actual;
                        node->previous = NULL;
                        actual->previous = node;
                        node->next = temporal;
                        *dlist = node;
                    } else {
                        temporal = actual;
                        node->previous = prev;
                        actual->previous = node;
                        node->next = temporal;
                        prev->next = node;
                    }
                    listo = 1;
                }
            }

            if (listo < 1)
            {
                if (node->value <= actual->value)
                {
                    temporal = actual;
                    node->previous = NULL;
                    actual->previous = node;
                    node->next = temporal;
                    *dlist = node;

                } else
                {
                    actual->next = node;
                    node->previous = actual;
                    node->next = NULL;
                }
            }
        } 
    }
}

//Imprime
void dlist_imprimir(Node **list)
{
    node_print_all_linked_nodes(*list);
}




/*
Se hace el recorrido por los nodos, si en el nodo actual
su valor es igual al id ingresado se rompe el ciclo, si no
sigue avanzando hasta llegar al final.
Si sí se encontró lo extrae y regresa el extraido, si no, regresa
un Node * = NULL 
*/
Node *dlist_delete_node(Node **dlist, int id)
{
    Node *actual = *dlist, *prev = NULL, *next = NULL, *deleted = NULL;
    int cont = 0;
    if (actual != NULL)
    {
        while (actual->next != NULL)
        {
            if (actual->value == id)
            {
                break;
            } else
            {
                cont ++;
                actual = actual->next;
                
            }
        }
        if (actual->value != id)
        {
            deleted = NULL;
        } else{
            deleted = actual;
            prev = actual->previous;
            next = actual->next;
            if (prev != NULL)
            {
                prev->next = next;
            }
            
            
            if (next != NULL)
            {
                next->previous = prev;
            }
            actual->previous = NULL;
            actual->next = NULL;
            if (cont == 0)
            {
                *dlist = next;
            }
        }
    }
        return deleted;
}

/*

*/
int dlist_search_node(Node **dlist, Node* node)
{
    Node *actual = *dlist;
    int cont = -1;
    if (*dlist == NULL || node == NULL)
    {
        return -2;
    } else
    {
        while (actual != NULL)
        {
            if (actual->value == node->value)
            {
                //cont++;
                return cont + 1;
            }else
            {
                cont++;
                actual = actual->next;
            }
        }
        return cont; 
    }    
}
