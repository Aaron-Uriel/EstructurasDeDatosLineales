# libdstruct
## Descripción del proyecto.
Biblioteca para demostrar el funcionamiento de algunas estructuras de datos como lo son:
- Colas. Estática (sin nodos), simplemente ligada, doblemente ligada, con cabecera y con prioridad.
- Pilas. Estática (sin nodos) y simplemente ligada.
- Listas. Simplemente ligada, doblemente ligada, con cabecera.

### Estructuras.
- Todas las estructuras están declaradas siguiendo el estilo 'UpperCamelCase'.
- Los nombres están abreviados para ahorrar espacio en pantalla.
- Las estructuras están declaradas de tal manera que no es necesario agregar la palabra `struct` antes de su uso, por lo que su su uso seguiría la forma: `Queue queue1;`.
- Para conseguir que el uso de `struct` no sea necesario, en la biblioteca las estructuras se definen así:
  - En la biblioteca `libdstruct.h`:
  ``` C
  struct Queue Queue;
  ```
  - En la declaración de la estructura (por ejemplo en el archivo `head_based/queue.c`):
  ```C
  struct Queue {
      ...
  }
  ```

### Cabeceras.
Todas las estructuras de datos con cabeceras están doblemente enlazadas y sus miembros se pueden acceder sin usar las funciones (aunque no es recomendable).
Las cabeceras disponibles son:
- `Queue`. Cola con cabecera.
- `PQueue`. Cola con prioridad (y con cabecera).
- `List`. Lista con cabecera.

### Funciones.
Todas las funciones relacionadas con las estructuras de datos van a empezar con el nombre de la estructura de dato, seguido de lo que hacen sobre la estructura de dato. Por ejemplo:
- `slist_insert()`. Inserta un nodo a una lista simplemente enlazada.
- `dqueue_extract_node()`. Una funcion que extrae un nodo de una cola doblemente enlazada.
- `list_extract_node()`. Una funcion que extrae un nodo de una lista con cabecera.

## Dependencias.
Para compilar el proyecto se necesita tener instalado 
- Un compilador de C (gcc o clang). Si tienes macOS y [brew](https://brew.sh/index_es) instalado, probablemente ya tienes instalado clang. En caso contrario prueba [aquí](https://command-not-found.com/clang) para instalar clang en tu sistema operativo favorito.
- Meson. Es la herramienta que usamos en este proyecto para facilitar la compilación, puedes instalarlo desde [aquí](https://mesonbuild.com/SimpleStart.html).
- Git (opcional). Puedes seguir [este](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git) tutorial para instalarlo o [aquí](https://command-not-found.com/git) si quieres saber como instalarlo directamente.

## Organización del proyecto.
- `include/`. Tiene todas las funciones que estarán disponibles para todos los archivos .c en el proyecto.
  - La cabecera `libdstruct.h` es la única que va a estar disponible públicamente (es decir, fuera de este proyecto), en dicha cabecera también se marca individualmente cuales funciones son públicas con la macro `PUBLIC`.
- `src/`. Es la carpeta que contiene todo el código fuente de la biblioteca, está dividida en subcarpetas.
  - `src/singly_linked`. Son todas las estructuras de datos simplemente enlazadas.
  - `src/doubly_linked`. Contiene las estructuras de datos doblemente enlazadas.
  - `src/head_based`. Aquí se localizan todas las estructuras de datos con cabecera.
  - `src/node`. Aquí están todos los nodos usados por las estructuras de datos.
  - `src/report`. Esta carpeta contiene archivos con funciones útiles para reportar errores.
- `tests/`. Aquí está el código fuente que pone a prueba las funciones declaradas en `src/`; sirve para poder probar que las funciones de la librería funcionan.
  - `tests/menu`. Aquí es donde se localiza el código fuente de un menú de demostración para este proyecto.

## Instrucciones de compilación.
Es necesario crear el entorno donde va a ocurrir la compilación del proyecto, generalmente se va a llamar "build" pero puede tener cualquier nombre. Para crear la carpeta donde se compilará el proyecto escribe lo siguiente en la carpeta principal del proyecto.
``` bash
$ meson setup build
```
Posteriormente necesitas cambiar a la carpeta recién creada, en este caso la carpeta se llama "build". Para cambiar simplemente has:
``` bash
$ cd build
```
Ahora puedes iniciar el proceso de compilación, para compilar escribe lo siguiente.
``` bash
$ meson compile
```
Podrás saber si la compilación fue exitosa, si no se mostró ningún error a la hora de ejecutar el comando anterior.

Una vez que lograste compilar por primera vez el proyecto, prácticamente lo único que ocupas hacer para compilar es:
``` bash
$ cd build
$ meson compile
```
O más corto:
``` bash
$ meson compile -C build
```

## Ejecución.
Este proyecto genera múltiples ejecutables, son para probar su funcionalidad. Todos los ejecutables se encuentran en la carpeta `build/tests`.
Si quieres probar el menú puedes escribir en tu terminal:
``` bash
$ build/tests/menu
```
