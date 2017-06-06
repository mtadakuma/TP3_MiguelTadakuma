
#include<stdio.h>
#include<stdlib.h>
#include "funciones.h"

int cargarDesdeArchivo(EMovie* arrayMovie)
{
    int flag = 0;
    FILE *pArch;

    pArch=fopen("bin.dat", "rb");
    if(pArch==NULL)
    {
        pArch= fopen("bin.dat", "wb");
        if(pArch==NULL)
        {
            return 1;
        }
        flag=1;
    }
    if(flag == 0)
    {
        fread(arrayMovie,sizeof(EMovie),TAM,pArch);
    }

    fclose(pArch);
    return 0;
}

int buscarLibre(EMovie* arrayMovie)
{
    int index=-1;
    int i;
    for( i=0; i<TAM; i++)
    {
        if(arrayMovie[i].indexM==0)
        {
            index=i;
            break;
        }
    }
    return index;
}

void agregarPelicula(EMovie* arrayMovie)
{
    int index, i;
    int encontro=0;
    int auxIndex, auxDuracion, auxPuntaje;
    index=buscarLibre(arrayMovie);
    if(index!=-1)
    {
        printf("INGRESO DE DATOS:\n");
        printf("Ingrese indice: ");
        scanf("%d", &auxIndex);
        for(i=0; i<TAM; i++)
        {
            if(auxIndex==arrayMovie[i].indexM)
            {
                encontro=1;//encontro en true
                break;
            }
        }
        if(!encontro)//entra si encontro==0
        {
            arrayMovie[index].indexM=auxIndex;
            printf("Ingrese titulo: ");
            fflush(stdin);
            gets(arrayMovie[index].titulo);
            printf("Ingrese genero: ");
            fflush(stdin);
            gets(arrayMovie[index].genero);
            printf("Ingrese duracion: ");
            scanf("%d", &auxDuracion);
            arrayMovie[index].duracion = auxDuracion;
            printf("Ingrese descripcion: ");
            fflush(stdin);
            gets(arrayMovie[index].descripcion);
            printf("Ingrese puntaje: ");
            scanf("%d", &auxPuntaje);
            arrayMovie[index].puntaje = auxPuntaje;
            printf("Ingrese link a imagen: ");
            fflush(stdin);
            gets(arrayMovie[index].linkImagen);
            system("cls");
        }
        else
        {
            printf("El indice ingresado ya existe");
        }
    }
    else
    {
        printf("No queda espacio");
    }
}

void borrarPelicula(EMovie* arrayMovie)
{
    int auxIndex, flag=0,i;
    printf("Ingrese indice a dar de baja: ");
    scanf("%d", &auxIndex);
    for(i=0; i<TAM; i++)
    {
        if(auxIndex == arrayMovie[i].indexM)
        {
            arrayMovie[i].indexM=0;
            printf("Registro eliminado\n");
            system("cls");
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("Indice inexistente");
    }
}

void modificarPelicula(EMovie* arrayMovie)
{
    int flag=0,i;
    int auxIndex, auxDuracion, auxPuntaje;
    char opcion;
    system("cls");
    printf("Ingrese indice de pelicula a modificar: ");
    scanf("%d",&auxIndex);
    for( i=0; i<TAM; i++)
    {
        if(auxIndex==arrayMovie[i].indexM)
        {
            printf("Indice encontrado\n");
            printf("Ingrese titulo: ");
            fflush(stdin);
            gets(arrayMovie[i].titulo);
            printf("Ingrese genero: ");
            fflush(stdin);
            gets(arrayMovie[i].genero);
            printf("Ingrese duracion: ");
            scanf("%d", &auxDuracion);
            arrayMovie[i].duracion = auxDuracion;
            printf("Ingrese descripcion: ");
            fflush(stdin);
            gets(arrayMovie[i].descripcion);
            printf("Ingrese puntaje: ");
            scanf("%d", &auxPuntaje);
            arrayMovie[i].puntaje = auxPuntaje;
            printf("Ingrese link a imagen: ");
            fflush(stdin);
            gets(arrayMovie[i].linkImagen);
            system("pause");
            system("cls");

            printf("\nPelicula modificada correctamente.\n");
            system("cls");

            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("indice de pelicula inexistente");
    }
}

void generarPagina(EMovie* arrayMovie, char nombre[])
{
    int i;
    FILE * pArch;
    pArch=fopen(nombre, "w");
    if(pArch == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        fprintf(pArch,"<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><title>Lista peliculas</title><!-- Bootstrap Core CSS --><link href='css/bootstrap.min.css' rel='stylesheet'><!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --><link href='css/custom.css' rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body><div class='container'><div class='row'>");
        for(i=0; i<TAM; i++)
        {
            if(arrayMovie[i].indexM != 0)
            {
                fprintf(pArch,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Genero:%s</li><li>Puntaje:%d</li><li>Duracion:%d</li></ul><p>%s</p></article>", arrayMovie[i].linkImagen, arrayMovie[i].titulo, arrayMovie[i].genero, arrayMovie[i].puntaje, arrayMovie[i].duracion, arrayMovie[i].descripcion);
            }
        }
        fprintf(pArch,"</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>");
    }
    fclose(pArch);
    printf("Pagina creada con exito\n");
    system("pause");
}

int guardarEnArchivoBinario(EMovie* arrayMovie)
{

    FILE *pArch;

    pArch=fopen("bin.dat","wb");
    if(pArch == NULL)
    {
        return 1;
    }

    fwrite(arrayMovie,sizeof(EMovie),TAM,pArch);

    fclose(pArch);

    return 0;
}
