#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define TAM 100

typedef struct
{
    int indexM;
    char titulo[50];
    char genero[50];
    int duracion;
    char descripcion[200];
    int puntaje;
    char linkImagen[400];
} EMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param arrayMovie la estructura a ser agregada al archivo
 */
void agregarPelicula(EMovie* arrayMovie);

/**
 *  Borra una pelicula del archivo binario
 *  @param arrayMovie la lista de estructuras a ser eliminada al archivo
 */
void borrarPelicula(EMovie* arrayMovie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param arrayMovie la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie* arrayMovie, char nombre[]);

/**
 *  Carga las estructuras en el array de estructuras desde un archivo binario
 *  @param arrayMovie la lista de estructuras donde se cargaran las estructuras
 *  @return Devuelve un 1 si se creo el archivo o un 0 si se leyo correctamente
 */
int cargarDesdeArchivo(EMovie* arrayMovie);

/**
 *  Busca el primer lugar libre en el array de estructuras
 *  @param arrayMovie la lista donde se buscara la primer posicion libre
 *  @return Devuelve el primer indice libre
 */
int buscarLibre(EMovie* arrayMovie);

/**
 *  Agrega una pelicula al archivo binario
 *  @param arrayMovie la estructura a ser modificada
 */
void modificarPelicula(EMovie* arrayMovie);

/**
 *  Agrega una pelicula al archivo binario
 *  @param arrayMovie el array de estructuras a ser guardada en un archivo binario
 *  @return Devuelve un 1 si no se puede crear o un 0 si lo creo
 */
int guardarEnArchivoBinario(EMovie* arrayMovie);

#endif // FUNCIONES_H_INCLUDED
