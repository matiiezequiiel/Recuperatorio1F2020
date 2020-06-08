#include"Mascotas.h"
#include"Clientes.h"
#include"Validaciones.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//INICIALIZACION

void hardcodearMascotas(eMascota listadoMascotas[],int sizeMascotas)
{
    char nombre[11][20]= {"Reyna","Juana","Slack","Noah","Pedro","Raul","Berta","Hercules","Michi","Blanquito","Eduardo"}; //,"","","","","","","","",};
    char tipo [11][20]= {"Gato","Gato","Perro","Perro","Gato","Perro","Raro","Perro","Gato","Gato","Perro"};
    int raza [11]= {1,2,3,4,1,4,5,3,2,2,4};
    int edad[11]= {7,10,5,3,1,4,8,15,9,7,2};
    float peso[11]= {20,10,15,8,7.5,6.9,2.6,4.6,12,13,6.6};
    char sexo[11]= {'H','H','M','M','M','M','H','M','M','M','M'};
    int idDelDuenio[11]= {3,3,1,1,1,5,5,2,4,4,4};
    int idMascota[11]= {1,2,3,4,5,6,7,8,9,10,11};
    int estado[11]= {1,1,1,1,1,1,1,1,1,1,1};
    int i;

    for(i=0; i<sizeMascotas; i++)
    {
        strcpy(listadoMascotas[i].nombre,nombre[i]);
        strcpy(listadoMascotas[i].tipo,tipo[i]);
        listadoMascotas[i].idRaza=raza[i];
        listadoMascotas[i].edad=edad[i];
        listadoMascotas[i].peso=peso[i];
        listadoMascotas[i].sexo=sexo[i];
        listadoMascotas[i].idDelDuenio=idDelDuenio[i];
        listadoMascotas[i].idMascota=idMascota[i];
        listadoMascotas[i].estado=estado[i];


    }


}

void initMascotas(eMascota listadoMascotas[],int sizeMascotas)
{
    int i;

    for(i=0; i<sizeMascotas; i++)
    {
        listadoMascotas[i].estado=0;
        listadoMascotas[i].idMascota=i+1;

    }

}


//MOSTRAR

void promedioEdadMascotas(eMascota listadoMascotas[],int sizeMascotas)
{
    int i;
    int acumEdades=0;
    int contMascotas=0;
    float promedio;

    for(i=0; i<sizeMascotas; i++)
    {
        if(listadoMascotas[i].estado==1)
        {
            acumEdades=listadoMascotas[i].edad+acumEdades;
            contMascotas++;
        }
    }
    promedio=(float)acumEdades/contMascotas;

    if(contMascotas!=0)
    {
        printf("El promedio de edad entre las mascotas es: %2.f\n\n",promedio);
    }
    else
    {
        printf("\nNO HAY MASCOTAS CARGADAS.\n\n");
    }


    system("pause");
}

void promedioEdadMascotaPorTipo(eMascota listadoMascotas[],int sizeMascotas)
{
    char entrada[10];
    int i;
    int acumEdades=0;
    int contMascotas=0;
    float promedio;


    printf("Ingrese el tipo de mascota por la cual desea saber el promedio de edad (Perro/Gato/Raro):");
    fflush(stdin);
    gets(entrada);
    formatearNombres(entrada);

    while(validarCadena(entrada)==0 || validarTipoMascota(entrada)==0)
    {
        system("cls");
        printf("Tipo invalido, reeingrese el tipo (Gato/Perro/Raro): ");
        gets(entrada);
        formatearNombres(entrada);
        validarCadena(entrada);
        validarTipoMascota(entrada);
    }


    for(i=0; i<sizeMascotas; i++)
    {
        if(strcmp(listadoMascotas[i].tipo,entrada)==0 && listadoMascotas[i].estado==1)
        {
            acumEdades=listadoMascotas[i].edad+acumEdades;
            contMascotas++;
        }
    }
    promedio=acumEdades/(float)contMascotas;

    if(contMascotas!=0)
    {
        printf("El promedio de edad entre las mascotas de tipo %s: %.2f\n\n",entrada,promedio);
    }
    else
    {
        printf("\nNO HAY MASCOTAS CARGADAS.\n\n");
    }


    system("pause");
}


//ALTA

int buscarLibreArrayMascota(eMascota listadoMascotas[],int sizeMascotas )
{
    int i;
    int lugarLibre=-1;

    for(i=0; i<sizeMascotas; i++)
    {
        if(listadoMascotas[i].estado==0)
        {
            lugarLibre=i;
            return lugarLibre;
        }
    }
    return lugarLibre;
}



//BAJA

int bajaMascota(eMascota listadoMascotas[],int sizeMascotas,int idEliminar)
{
    int i;
    char entrada[10];
    int confirmacion;
    int retorno=0;
    int contMascotas=0;

    for(i=0; i<sizeMascotas; i++)

    {
        if((listadoMascotas[i].idMascota==idEliminar) && (listadoMascotas[i].estado==1))
        {
            contMascotas++;
            printf("MASCOTA ENCONTRADA. \n");

            printf("Ingrese 1 para confirmar la eliminacion.\n");
            printf("Ingrese 2 para salir.\n\n");
            printf("Opcion elegida: ");

            gets(entrada);

            confirmacion=validarIntEntreRangos(entrada,1,2);

            if (confirmacion==1)
            {
                listadoMascotas[i].estado=0;
                return 1;
            }
            else
            {
                return 0;
            }
            break;
        }

    }

    if(contMascotas==0)
    {
        printf("No se encontraron mascotas\n\n");

    }


    return retorno;

}



