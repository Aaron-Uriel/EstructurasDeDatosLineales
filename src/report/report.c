#include <stdio.h>
#include <string.h>

#include <report.h>

void
report(const char *const function_name,
       enum ReportKind report_kind,
       enum ReportDesc report_desc)
{
    char report_kind_as_string[30];
    switch (report_kind) {
    case DEBUG:
        strcpy(report_kind_as_string, "Depuración");
        break;
    case INFO:
        strcpy(report_kind_as_string, "Información (acción tomada)");
        break;
    case WARN:
        strcpy(report_kind_as_string, "Advertencia");
        break;
    case ERROR:
        strcpy(report_kind_as_string, "Error");
        break;
    default:
        strcpy(report_kind_as_string, "");
    }

    char report_desc_as_string[100];
    switch (report_desc) {
    case OUT_OF_BOUNDS:
        strcpy(report_desc_as_string, "fuera de límites");
        break;
    case NULL_NODE:
        strcpy(report_desc_as_string, "el nodo recibido es de valor NULL");
        break;
    case NULL_DATA_STRUCT:
        strcpy(report_desc_as_string, "la estructura de datos está vacía; es NULL");
        break;
    default:
        strcpy(report_desc_as_string, "DESCONOCIDO");
    }

    fprintf(stderr, "En la función %s():\n"
            "\t%s: %s.\n",
            function_name,
            report_kind_as_string,
            report_desc_as_string);
}
