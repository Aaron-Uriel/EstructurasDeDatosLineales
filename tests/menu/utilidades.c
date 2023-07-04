#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#include <libdstruct.h>

/*
 * Lee la entrada y regresa el valor del primer caracter leido, no necesita que
 * se presione enter.
 */
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

char * 
repetir_cadena(char *cadena, uint32_t repeticiones)
{
    char *cadena_repetida = NULL;
    if (cadena && repeticiones) {
        cadena_repetida = malloc(strlen(cadena) * (repeticiones + 1));
        if (cadena_repetida) {
            strcpy(cadena_repetida, cadena);
            while (--repeticiones) {
                strcat(cadena_repetida, cadena);
            }
        }
    }
    return cadena_repetida;
}

/*
 * Imprime un menú visible para el usuario.
 * La función regresa el caracter que representa a la opción escogida por el
 * usuario (que tiene que ser válida). Para cada opción tiene que estar 
 * definido su nombre corto y su nombre largo.
 */
char
menu_crear(const char *nombre_menu, const char *opciones_cortas,
        const char *opciones_largas[])
{
    uint32_t i;
    uint8_t tamano_contenido, prueba;
    tamano_contenido = strlen(nombre_menu);
    for (i = 0; opciones_cortas[i] && opciones_largas[i]; i += 1) {
        prueba = strlen(opciones_largas[i]) + 5;
        if (prueba > tamano_contenido) {
            tamano_contenido = prueba;
        }
    }

    printf("┌─%s─┐\n", repetir_cadena("─", tamano_contenido));
    printf("│ %*s │\n", -tamano_contenido, nombre_menu);
    printf("├─%s─┤\n", repetir_cadena("─", tamano_contenido));
    for (i = 0; opciones_cortas[i] && opciones_largas[i]; i += 1) {
        printf("│  [%c] %*s │\n", 
                opciones_cortas[i], 
                (-tamano_contenido + 5), opciones_largas[i]);
    }
    printf("└─%s─┘\n", repetir_cadena("─", tamano_contenido));

    int ch;
    while (!strchr(opciones_cortas, ch = getch()));
    return ch;
}

void
pausar(void)
{
    puts("Presione cualquier tecla para continuar.");
    getch();
}
