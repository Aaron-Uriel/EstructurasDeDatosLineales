#include <stdio.h>
#include <string.h>

#include <error.h>

void
error(const char *const function_name, enum ErrorKind errkind) {
    char err_as_string[100];
    switch (errkind) {
    case ERR_OUT_OF_BOUNDS:
        strcpy(err_as_string, "Fuera de límites");
        break;
    case ERR_NULL_NODE:
        strcpy(err_as_string, "Uno de los valor del nodo recibido es NULL");
        break;
    case ERR_NULL_DATA_STRUCT:
        strcpy(err_as_string, "La estructura de datos está vacía, es NULL");
        break;
    default:
        strcpy(err_as_string, "Error desconocido");
    }
        
    fprintf(stderr,
            "%s() reporta error: \"%s\"\n",
            function_name,
            err_as_string);
}

void
info(const char *const function_name, enum InfoKind infokind)
{
    char info_as_string[100];
    switch (infokind) {
    case INFO_DATA_STRUCT_WILL_BE_EMPTY:
        strcpy(info_as_string, "La estructura de dato se va a vacíar después de esta operación");
        break;
    default:
        strcpy(info_as_string, "");
    }

    fprintf(stderr,
            "%s() informa: \"%s\"\n",
            function_name,
            info_as_string);
}
