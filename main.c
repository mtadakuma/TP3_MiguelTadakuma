#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    EMovie arrayMovies[TAM];
    char seguir='s';
    int opcion=0;
    int i;

    for(i=0; i<TAM; i++) //Inicializo el array de estructuras
    {
        arrayMovies[i].indexM=0;
    }

    if(cargarDesdeArchivo(arrayMovies))
    {
        printf("No se pudo abrir el fichero");
    }
    else
    {
        printf("Se cargaron las estructuras con exito\n");
    }

    system("pause");
    system("cls");

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            agregarPelicula(arrayMovies);
            break;
        case 2:
            system("cls");
            borrarPelicula(arrayMovies);
            break;
        case 3:
            system("cls");
            modificarPelicula(arrayMovies);
            break;
        case 4:
            system("cls");
            generarPagina(arrayMovies, "index.html");
            break;
        case 5:
            if(guardarEnArchivoBinario(arrayMovies))
            {
                printf("\nNo se pudo abrir el fichero\n");
            }
            else
            {
                printf("\nSe guardo la informacion con exito\n");
            }
            seguir = 'n';
            break;
        }
    }

    return 0;
}
