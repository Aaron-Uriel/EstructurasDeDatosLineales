# libdstruct
## Descripción del proyecto.
Biblioteca para demostrar el funcionamiento de algunas estructuras de datos como lo son:
- Listas. Simplemente ligada, doblemente ligada, con cabecera.
- Pilas. Simplemente ligada.
- Colas. Simplemente ligada, doblemente ligada, con cabecera y con prioridad.

### Estructuras.
- Todas las estructuras están declaradas siguiendo el estilo 'CamelCase'.
- Varias estructuras estarán abreviadas para ahorrar espacio en pantalla.
- Las estructuras están declaradas de tal manera que no es necesario agregar la palabra `struct` antes de su uso, por lo que su su uso seguiría la forma: `HQueue queue1;`.
- Para conseguir que el uso de `struct` no sea necesario, en la biblioteca las estructuras se definen así:
  - En la biblioteca `libdstruct.h`:
  ```
  struct HQueue HQueue;
  ```
  - En la declaración de la estructura (por ejemplo en el archivo `head_based/queue.c`):
  ```
  struct HQueue {
      ...
  }
  ```

### Cabeceras.
Todas las estructuras de datos con cabeceras están doblemente enlazadas.
Las cabeceras disponibles son:
- `HQueue`. Cola con cabecera.
- `HList`. Lista con cabecera.
- `HStack`. Pila con cabecera.

### Funciones.
Todas las funciones relacionadas con las estructuras de datos van a empezar con el nombre de la estructura de dato con la que van a trabajar. Por ejemplo:
- slist_insert(). Una funcion que inserta algo a una lista simplemente enlazada.
- dqueue_extract_node(). Una funcion que extrae un nodo de una cola doblemente enlazada.
- stack_extract_node(). Una funcion que extrae un nodo de una pila simplemente enlazada.

## Dependencias.
Para compilar el proyecto se necesita tener instalado 
- Un compilador de C (gcc o clang). Si tienes macOS y [brew](https://brew.sh/index_es) instalado, probablemente ya tienes instalado clang. En caso contrario prueba [aquí](https://command-not-found.com/clang) para instalar clang en tu sistema operativo favorito.
- Meson. Puedes instalarlo desde [aquí](https://mesonbuild.com/SimpleStart.html).

## Organización del proyecto.
La forma en que están distribuidas las carpetas puede parecer un poco compleja al principio, pero están distribuidas de forma lógica para mantenerse organizadas conforme el proyecto va creciendo.
- `include/`. Tiene todas las funciones que estarán disponibles para todos los archivos .c en el proyecto. La cabecera `libdstruct.h` es la única que va a estar disponible públicamente (es decir, fuera de este proyecto), en dicha cabecera también se marca individualmente cuales funciones son públicas con la macro `PUBLIC`.
- `src/`. Es la carpeta que contiene todo el código fuente de la biblioteca, está dividida en subcarpetas.
  - `src/singly_linked`. Son todas las estructuras de datos simplemente enlazadas.
  - `src/doubly_linked`. Contiene las estructuras de datos doblemente enlazadas.
  - `src/head_based`. Aquí se localizan todas las estructuras de datos con cabecera.
- `tests/`. Aquí está el código fuente que pone a prueba las funciones declaradas en `src/`; sirve para poder probar que las funciones de la librería funcionan.

## Instrucciones de compilación.
Es necesario crear el entorno donde va a ocurrir la compilación del proyecto, generalmente se va a llamar "build" pero puede tener cualquier nombre. Para crear la carpeta donde se compilará el proyecto escribe lo siguiente en la carpeta principal del proyecto.
```
$ meson setup build
```
Posteriormente necesitas cambiar a la carpeta recién creada, en este caso la carpeta se llama "build". Para cambiar simplemente has:
```
$ cd build
```
Ahora puedes iniciar el proceso de compilación, para compilar escribe lo siguiente.
```
$ meson compile
```
Podrás saber si la compilación fue exitosa, si no se mostró ningún error a la hora de ejecutar el comando anterior.
Finalmente, si quieres ejecutar las pruebas que se compilaron junto con el proyecto, ellas estarán localizadas en build/tests.
```
$ tests/libdstruct_test
```

Una vez que lograste compilar por primera vez el proyecto, prácticamente lo único que ocupas hacer para compilar es:
```
$ cd build
$ meson compile
```
O más corto:
```
$ meson compile -C build
```
