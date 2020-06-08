#include "Raza.h"
#include <string.h>
#include <stdio.h>

void hardcodearRaza(eRaza listaRazas[],int sizeRaza)
{

    char nombre[6][20]= {"Siames","Persa","Ovejero","Labrador","Lagarto","Piton"};
    char pais[6][20]= {"Argentina","China","Alemania","Italia","Japon","Sudan"};
    int i;

    for(i=0; i<6; i++)
    {

        strcpy(listaRazas[i].nombreRaza,nombre[i]);
        strcpy(listaRazas[i].pais,pais[i]);
        listaRazas[i].idRaza=i+1;

    }

}

void mostrarRaza(eRaza listadoRazas[], int sizeRazas)
{
    int i;

    printf("\n\nID      NOMBRE           PAIS");
    for(i=0; i<sizeRazas; i++)
    {
        printf("\n%d \t",listadoRazas[i].idRaza);
        printf("%s      \t",listadoRazas[i].nombreRaza);
        printf("%s\n",listadoRazas[i].pais);
    }
}

