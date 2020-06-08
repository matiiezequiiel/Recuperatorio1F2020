#include"Clientes-Mascotas.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//MOSTRAR

void mostrarMascotas(eMascota listadoMascotas[],int sizeMascotas,eCliente listadoClientes[],int sizeClientes,eRaza listadoRazas[],int sizeRaza)
{
    int i;
    int j;
    int k;
    int contMascotas=0;

    printf("\nID      NOMBRE          TIPO            RAZA           EDAD     PESO           SEXO    NOMBRE DEL DUENIO");

    for(i=0; i<sizeMascotas; i++)
    {

        if(listadoMascotas[i].estado==1)

        {
            printf("\n%d\t",listadoMascotas[i].idMascota);
            printf("%s    \t",listadoMascotas[i].nombre);
            printf("%s     \t",listadoMascotas[i].tipo);

            for(k=0; k<sizeRaza; k++)
            {
                if(listadoMascotas[i].idRaza==listadoRazas[k].idRaza)
                {
                    printf("%s   \t",listadoRazas[k].nombreRaza);
                }
            }

            printf("%d\t",listadoMascotas[i].edad);
            printf("%.2f     \t",listadoMascotas[i].peso);
            printf("%c\t",listadoMascotas[i].sexo);
            contMascotas++;

            for(j=0; j<sizeClientes; j++)
            {
                if(listadoMascotas[i].idDelDuenio== listadoClientes[j].id )
                {
                    printf("%s\n",listadoClientes[j].nombre);
                    break;
                }
            }
        }



    }

    if(contMascotas==0)
    {
        printf("\n\nNO HAY MASCOTAS CARGADAS.\n\n");
        system("pause");
    }

    system("pause");
}


void mostrarClientesConSusAnimales(eCliente listaClientes[],int sizeClientes,eMascota listadoMascotas[],int sizeMascotas,eRaza listadoRazas[],int sizeRaza)
{
    int i;
    int j;
    int k;
    int contMascotas;
    int contClientes=0;

    for(i=0; i<sizeClientes; i++)
    {
        contMascotas=0;
        if(listaClientes[i].estado==1)
        {
            printf("\n\nCliente: %s %s",listaClientes[i].nombre,listaClientes[i].apellido);
            printf("\nMascotas a cargo del cliente:");
            printf("\nNOMBRE          TIPO    RAZA            EDAD    PESO    SEXO");
            contMascotas=0;
            contClientes++;
        }
        else
        {
            continue;
        }


        for(j=0; j<sizeMascotas; j++)
        {

            if(listaClientes[i].id==listadoMascotas[j].idDelDuenio && listadoMascotas[j].estado==1 )
            {
                printf("\n%s    \t",listadoMascotas[j].nombre);
                printf("%s\t",listadoMascotas[j].tipo);
                for(k=0; k<sizeRaza; k++)
                {
                    if(listadoMascotas[j].idRaza==listadoRazas[k].idRaza)
                    {
                        printf("%s   \t",listadoRazas[k].nombreRaza);
                        break;
                    }
                }

                printf("%d\t",listadoMascotas[j].edad);
                printf("%.2f\t",listadoMascotas[j].peso);
                printf("%c\t",listadoMascotas[j].sexo);
                contMascotas++;
            }

        }

        if(contMascotas==0)
        {
            printf("\nNO TIENE MASCOTAS.\n\n");
        }
        if(contClientes==0)
        {
            printf("\nNO TIENE MASCOTAS.\n\n");
        }
    }
    if(contClientes==0)
    {
        printf("\nNO TIENE CLIENTES CARGADOS.\n\n");
    }
    printf("\n\n");
    system("pause");

}

void mostrarMascotasPorTipo(eMascota listadoMascotas[],int sizeMascotas,eCliente listadoClientes[],int sizeClientes,eRaza listadoRazas[],int sizeRaza)
{
    int i;
    int j;
    eMascota auxMascota;

    for(i=0; i<sizeMascotas-1; i++)
    {
        for(j=i+1; j<sizeMascotas; j++)
        {

            if(strcmp(listadoMascotas[i].tipo,listadoMascotas[j].tipo)>0)
            {
                auxMascota  =  listadoMascotas[i];
                listadoMascotas[i] = listadoMascotas[j];
                listadoMascotas[j] = auxMascota;
            }

        }

    }
    mostrarMascotas(listadoMascotas,sizeMascotas,listadoClientes,sizeClientes,listadoRazas,sizeRaza);

}

void listarClientesConMasUnaMascota(eMascota listadoMascotas[],int sizeMascotas,eCliente listadoClientes[],int sizeClientes)
{
    int i;
    int j;
    int contMascotas;
    int contClientes=0;

    printf("ID      NOMBRE          APELLIDO        LOCALIDAD       TELEFONO       EDAD   SEXO   CANT MASCOTAS \n");

    for(i=0; i<sizeClientes; i++)
    {

        contMascotas=0;
        for(j=0; j<sizeMascotas; j++)
        {
            if(listadoClientes[i].id == listadoMascotas[j].idDelDuenio && listadoClientes[i].estado==1 && listadoMascotas[j].estado==1)
            {
                contMascotas++;
                contClientes++;
            }
        }
        if(contMascotas>1)
        {
            printf("%d\t",listadoClientes[i].id);
            printf("%s   \t",listadoClientes[i].nombre);
            printf("%s   \t",listadoClientes[i].apellido);
            printf("%s   \t",listadoClientes[i].localidad);
            printf("%s\t",listadoClientes[i].telefono);
            printf("%d\t",listadoClientes[i].edad);
            printf("%c\t",listadoClientes[i].sexo);
            printf("%d\t\n",contMascotas);
        }
    }
    if(contClientes==0)
    {
        printf("\nNO HAY CLIENTES CARGADOS.\n");
    }
    system("pause");
}
void listarMascotasMas3Anios(eMascota listadoMascotas[],int sizeMascotas,eCliente listadoClientes[],int sizeClientes, eRaza listadoRazas[],int sizeRaza)
{
    int contMascotas=0;
    int contClientes=0;
    int i;
    int j;
    int k;

    printf("\nID    NOMBRE            TIPO    RAZA            EDAD    PESO    SEXO  NOMBRE DEL DUENIO");

    for(i=0; i<sizeMascotas; i++)
    {

        if(listadoMascotas[i].estado==1 && listadoMascotas[i].edad>3)

        {
            contMascotas++;
            printf("\n%d     ",listadoMascotas[i].idMascota);
            printf("%s       \t",listadoMascotas[i].nombre);
            printf("%s\t",listadoMascotas[i].tipo);
            for(k=0; k<sizeRaza; k++)
            {
                if(listadoMascotas[i].idRaza==listadoRazas[k].idRaza)
                {
                    printf("%s   \t",listadoRazas[k].nombreRaza);
                }
            }
            printf("%d\t",listadoMascotas[i].edad);
            printf("%.2f\t",listadoMascotas[i].peso);
            printf("%c\t",listadoMascotas[i].sexo);


            for(j=0; j<sizeClientes; j++)
            {
                if(listadoMascotas[i].idDelDuenio == listadoClientes[j].id)
                {
                    printf("%s\n",listadoClientes[j].nombre);
                    contClientes++;
                    break;
                }
            }
        }
    }
    if(contClientes==0)
    {
        printf("\nNO HAY CLIENTES CARGADOS.\n\n");
    }
    if(contMascotas==0)
    {
        printf("\n\nNo hay mascotas con mas de 3 anios.\n\n");
    }

    system("pause");
}


void mostrarMascotasPorTipoElegido(eMascota listadoMascotas[],int sizeMascotas,eRaza listadoRazas[],int sizeRazas)
{
    char entrada[10];
    int i;
    int j;
    int contMascotas=0;


    printf("Ingrese tipo de mascota (Gato/Perro/Raro): ");
    gets(entrada);
    formatearNombres(entrada);

    while(validarCadena(entrada)==0)
    {
        printf("Tipo de mascota invalida, ingrese (Perro,Gato,Raro) : ");
        gets(entrada);
        formatearNombres(entrada);
        validarTipoMascota(entrada);
        validarCadena(entrada);

    }

    printf("\nID      NOMBRE                  TIPO     RAZA          EDAD     PESO  SEXO ");

    for(i=0; i<sizeMascotas; i++)
    {

        if(strcmp(entrada,listadoMascotas[i].tipo)==0 && listadoMascotas[i].estado==1)
        {

            printf("\n%d     \t",listadoMascotas[i].idMascota);
            printf("%s              \t",listadoMascotas[i].nombre);
            printf("%s\t",listadoMascotas[i].tipo);
            for(j=0; j<sizeRazas; j++)
            {
                if(listadoMascotas[i].idRaza ==listadoRazas[j].idRaza)
                {
                    printf("%s   \t",listadoRazas[j].nombreRaza);
                    break;
                }
            }

            printf("%d\t",listadoMascotas[i].edad);
            printf("%.2f\t",listadoMascotas[i].peso);
            printf("%c\t",listadoMascotas[i].sexo);
            contMascotas++;

        }


    }
    if(contMascotas==0)
    {
        printf("\nNO HAY MASCOTAS CARGADAS.\n");
    }


    printf("\n\n");
    system("pause");
}

void listarClientesMascotasMismoSexo(eMascota listadoMascotas[],int sizeMascotas,eCliente listadoClientes [],int sizeClientes)
{

    int i;
    int j;
    int contMachos;
    int contHembras;
    int contClientes;

    printf("ID      NOMBRE          APELLIDO        LOCALIDAD       TELEFONO       EDAD   SEXO   \n");

    for(i=0; i<sizeClientes; i++)
    {

        contHembras=0;
        contMachos=0;


        if(listadoClientes[i].estado==1)
        {
            contClientes++;
            for(j=0; j<sizeMascotas; j++)
            {
                if(listadoClientes[i].id==listadoMascotas[j].idDelDuenio)
                {
                    if(listadoMascotas[j].sexo== 'M' )
                    {
                        contMachos++;
                    }
                    else
                    {
                        contHembras++;
                    }


                }
            }

            if((contMachos>0 && contHembras==0) || (contHembras>0 && contMachos==0))
            {
                printf("%d\t",listadoClientes[i].id);
                printf("%s   \t",listadoClientes[i].nombre);
                printf("%s   \t",listadoClientes[i].apellido);
                printf("%s   \t",listadoClientes[i].localidad);
                printf("%s\t",listadoClientes[i].telefono);
                printf("%d\t",listadoClientes[i].edad);
                printf("%c\t\n",listadoClientes[i].sexo);
            }
        }
        else
        {
            continue;
        }


    }

    if(contClientes==0)
    {
        printf("NO HAY CLIENTES CARGADOS\n\n");
    }
    system("pause");

}




//ALTA

int altaMascota(eMascota listadoMascotas[],int sizeMascotas,eCliente listadoClientes[], int sizeCliente,eRaza listadoRazas[],int sizeRazas)
{
    int posicionLibre;
    int confirmacion;

    posicionLibre=buscarLibreArrayMascota(listadoMascotas,sizeMascotas);

    system("cls");

    if(posicionLibre!=-1)

    {
        confirmacion=cargarCamposMascota(listadoMascotas,posicionLibre,listadoClientes,sizeCliente,listadoRazas,sizeRazas);


        if (confirmacion==1)
        {
            listadoMascotas[posicionLibre].estado=1;
            return 1;
        }
        else
        {
            return 0;
        }


    }
    else
    {
        printf("No hay espacio.");
        return 0;
    }


}

int cargarCamposMascota(eMascota listadoMascotas[],int posicionLibre,eCliente listadoClientes[], int sizeCliente,eRaza listadoRazas[],int sizeRazas)
{
    char entrada[10];
    char sexo;
    char opcion[5];
    int confirmacion;


    printf("Ingrese nombre de la mascota: ");
    fflush(stdin);
    gets(listadoMascotas[posicionLibre].nombre);
    formatearNombres(listadoMascotas[posicionLibre].nombre);
    while(validarCadena(listadoMascotas[posicionLibre].nombre)==0)
    {
        system("cls");
        printf("Nombre invalido, reeingrese nombre: ");
        gets(listadoMascotas[posicionLibre].nombre);
        formatearNombres(listadoMascotas[posicionLibre].nombre);
        validarCadena(listadoMascotas[posicionLibre].nombre);

    }
    printf("\nIngrese tipo de la mascota (Gato/Perro/Raro) :");
    fflush(stdin);
    gets(listadoMascotas[posicionLibre].tipo);
    formatearNombres(listadoMascotas[posicionLibre].tipo);

    while(validarCadena(listadoMascotas[posicionLibre].tipo)==0 || validarTipoMascota(listadoMascotas[posicionLibre].tipo)==0)
    {
        system("cls");
        printf("Tipo invalido, reeingrese el tipo (Gato/Perro/Raro): ");
        gets(listadoMascotas[posicionLibre].tipo);
        formatearNombres(listadoMascotas[posicionLibre].tipo);
        validarCadena(listadoMascotas[posicionLibre].tipo);
        validarTipoMascota(listadoMascotas[posicionLibre].tipo);
    }

    printf("Listado de razas disponibles: ");
    mostrarRaza(listadoRazas,sizeRazas);

    printf("\nIngrese  id raza de la mascota: ");
    fflush(stdin);
    gets(entrada);
    listadoMascotas[posicionLibre].idRaza=getInt(entrada);


    printf("\nIngrese edad de la mascota: ");
    fflush(stdin);
    gets(entrada);
    listadoMascotas[posicionLibre].edad=getInt(entrada);

    printf("\nIngrese peso de la mascota: ");
    fflush(stdin);
    gets(entrada);
    listadoMascotas[posicionLibre].peso=getFloat(entrada);

    printf("\nIngrese sexo de la mascota H/M: ");
    fflush(stdin);
    scanf("%c",&sexo);
    listadoMascotas[posicionLibre].sexo=getChar(sexo);

    while(validarSexoMascota(listadoMascotas[posicionLibre].sexo)==0)
    {
        printf("\n\nSexo invalido, ingrese H/M :");
        fflush(stdin);
        scanf("%c",&sexo);
        listadoMascotas[posicionLibre].sexo=getChar(sexo);
        validarSexoClientes(listadoMascotas[posicionLibre].sexo);
    }


    listadoMascotas[posicionLibre].sexo=toupper(listadoMascotas[posicionLibre].sexo);
    mostrarClientes(listadoClientes,sizeCliente);


    printf("\nIngrese ID del dueño de la mascota : ");
    fflush(stdin);
    gets(entrada);
    listadoMascotas[posicionLibre].idDelDuenio=getInt(entrada);

    system("cls");

    printf("Ingrese 1 para confirmar.\n");
    printf("Ingrese 2 para salir.\n\n");
    printf("Opcion elegida: ");

    gets(opcion);

    confirmacion=validarIntEntreRangos(opcion,1,2);

    return confirmacion;

}

//MODIFICACION DE MASCOTA

int modificarMascota(eMascota listadoMascotas[], int sizeMascotas, int idModificar, eRaza listadoRazas[],int sizeRazas,eCliente listadoClientes[],int sizeClientes)
{

    int i;
    int retorno=0;
    int contMascotas=0;



    if(idModificar<0 || idModificar>sizeMascotas)
    {
        return 0;
    }

    for(i=0; i<sizeMascotas; i++)

    {
        if((listadoMascotas[i].idMascota==idModificar) && (listadoMascotas[i].estado==1))
        {
            printf("MASCOTA ENCONTRADA. \n");

            contMascotas++;
            retorno=menuModificaciones(listadoMascotas,i,listadoRazas,sizeRazas,listadoClientes,sizeClientes);

        }

    }

    if(contMascotas==0)
    {
        printf("No se encontraron mascotas\n\n");

    }

    return retorno;

}

int menuModificaciones(eMascota listadoMascotas[],int posicionModificar,eRaza listadoRazas[],int sizeRazas,eCliente listadoClientes[],int sizeClientes)
{
    char entrada[10];
    int opcion;
    int confirmacion;
    int nuevaEdad;
    int nuevaRaza;
    char auxModificacion[30];
    char auxSexo;
    float nuevoPeso;
    int nuevoDuenio;

    printf("\n\n1.Modificar nombre.");
    printf("\n2.Modificar tipo.");
    printf("\n3.Modificar raza.");
    printf("\n4.Modificar edad.");
    printf("\n5.Modificar peso.");
    printf("\n6.Modificar sexo.");
    printf("\n7.Modificar duenio.");

    printf("\n\nIngrese opcion: ");

    gets(entrada);

    opcion=validarIntEntreRangos(entrada,1,7);

    switch(opcion)
    {
    case 1:
        system("cls");
        printf("Ingrese nuevo nombre: ");
        fflush(stdin);
        gets(auxModificacion);
        while (validarCadena(auxModificacion)==0)
        {
            system("cls");
            printf("Nombre invalido, reeingrese nombre: ");
            fflush(stdin);
            gets(auxModificacion);
            validarCadena(auxModificacion);
        }

        printf("Ingrese 1 para confirmar.\n");
        printf("Ingrese 2 para salir.\n\n");
        printf("Opcion elegida: ");

        gets(entrada);

        confirmacion=validarIntEntreRangos(entrada,1,2);

        if (confirmacion==1)
        {
            formatearNombres(auxModificacion);
            strcpy(listadoMascotas[posicionModificar].nombre,auxModificacion);
            return 1;
        }
        else
        {
            return 0;
        }
        break;

    case 2:
        system("cls");
        printf("Ingrese nuevo tipo (Perro/Gato/Raro): ");
        fflush(stdin);
        gets(auxModificacion);
        formatearNombres(auxModificacion);
        while (validarCadena(auxModificacion)==0 || validarTipoMascota(auxModificacion)==0)
        {
            system("cls");
            printf("Tipo invalido, reeingrese tipo (Perro/Gato/Raro): ");
            fflush(stdin);
            gets(auxModificacion);
            formatearNombres(auxModificacion);
            validarCadena(auxModificacion);
            validarTipoMascota(auxModificacion);
        }

        printf("Ingrese 1 para confirmar.\n");
        printf("Ingrese 2 para salir.\n\n");
        printf("Opcion elegida: ");

        gets(entrada);

        confirmacion=validarIntEntreRangos(entrada,1,2);

        if (confirmacion==1)
        {
            strcpy(listadoMascotas[posicionModificar].tipo,auxModificacion);
            return 1;
        }
        else
        {
            return 0;
        }
        break;

    case 3:
        system("cls");
        mostrarRaza(listadoRazas,sizeRazas);
        printf("Ingrese id nueva raza: ");
        fflush(stdin);
        gets(auxModificacion);
        nuevaRaza=getInt(auxModificacion);

        printf("Ingrese 1 para confirmar.\n");
        printf("Ingrese 2 para salir.\n\n");
        printf("Opcion elegida: ");

        gets(entrada);

        confirmacion=validarIntEntreRangos(entrada,1,2);

        if (confirmacion==1)
        {

            listadoMascotas[posicionModificar].idRaza=nuevaRaza;
            return 1;
        }
        else
        {
            return 0;
        }
        break;

    case 4:
        system("cls");
        printf("Ingrese nueva edad: ");
        fflush(stdin);
        gets(auxModificacion);
        nuevaEdad=getInt(auxModificacion);

        printf("Ingrese 1 para confirmar.\n");
        printf("Ingrese 2 para salir.\n\n");
        printf("Opcion elegida: ");

        gets(entrada);

        confirmacion=validarIntEntreRangos(entrada,1,2);

        if (confirmacion==1)
        {
            listadoMascotas[posicionModificar].edad=nuevaEdad;
            return 1;
        }
        else
        {
            return 0;
        }
        break;

    case 5:

        system("cls");
        printf("Ingrese nuevo peso: ");
        fflush(stdin);
        gets(auxModificacion);
        nuevoPeso=getFloat(auxModificacion);

        printf("Ingrese 1 para confirmar.\n");
        printf("Ingrese 2 para salir.\n\n");
        printf("Opcion elegida: ");

        gets(entrada);

        confirmacion=validarIntEntreRangos(entrada,1,2);

        if (confirmacion==1)
        {
            listadoMascotas[posicionModificar].peso=nuevoPeso;
            return 1;
        }
        else
        {
            return 0;
        }

        break;
    case 6:
        system("cls");
        printf("Ingrese nuevo sexo: ");
        fflush(stdin);
        scanf("%c",&auxSexo);

        auxSexo=getChar(auxSexo);

        while(validarSexoMascota(auxSexo)==0)
        {
            printf("\nSexo invalido, reeingrese sexo de mascota H/M: ");
            fflush(stdin);
            scanf("%c",&auxSexo);
            auxSexo=getChar(auxSexo);
            validarSexoMascota(auxSexo);
        }

        printf("Ingrese 1 para confirmar.\n");
        printf("Ingrese 2 para salir.\n\n");
        printf("Opcion elegida: ");

        fflush(stdin);
        gets(entrada);

        confirmacion=validarIntEntreRangos(entrada,1,2);

        if (confirmacion==1)
        {
            auxSexo=toupper(auxSexo);
            listadoMascotas[posicionModificar].sexo=auxSexo;
            return 1;
        }
        else
        {
            return 0;
        }
        break;

        break;
    case 7:
        printf("Listado de clientes disponibles: \n");
        mostrarClientes(listadoClientes,sizeClientes);

        printf("\nIngrese el ID del nuevo duenio: ");
        fflush(stdin);
        gets(entrada);
        nuevoDuenio=getInt(entrada);

        printf("Ingrese 1 para confirmar.\n");
        printf("Ingrese 2 para salir.\n\n");
        printf("Opcion elegida: ");

        fflush(stdin);
        gets(entrada);

        confirmacion=validarIntEntreRangos(entrada,1,2);

        if (confirmacion==1)
        {
            listadoMascotas[posicionModificar].idDelDuenio=nuevoDuenio;
            return 1;
        }
        else
        {
            return 0;
        }
        break;


        break;

    default:
        system("cls");
        printf("Opcion invalida, vuelva a comenzar.\n\n");
        system("pause");
        return 0;
        break;
    }
}


//BAJA CLIENTE

int bajaClienteConSusMascotas(eMascota listadoMascotas[],int sizeMascotas,eCliente listadoClientes[], int sizeCliente,int idEliminar)
{
    int i;
    char entrada[10];
    int confirmacion;
    int retorno=0;

    for(i=0; i<sizeCliente; i++)
    {
        if(listadoClientes[i].id == idEliminar && listadoClientes[i].estado==1)
        {
            printf("CLIENTE ENCONTRADO.\n\n");
            printf("Ingrese 1 para confirmar la eliminacion del cliente y sus mascotas.\n");
            printf("Ingrese 2 para salir.\n\n");
            printf("Opcion elegida: ");

            gets(entrada);

            confirmacion=validarIntEntreRangos(entrada,1,2);

            if (confirmacion==1)
            {
                listadoClientes[i].estado=0;
                for(i=0; i<sizeMascotas; i++)
                {
                    if(listadoMascotas[i].idDelDuenio==idEliminar && listadoMascotas[i].estado==1)
                    {
                        listadoMascotas[i].estado=0;
                    }
                }
                retorno=1;
            }
            else
            {
                retorno=0;
            }
            break;
        }
    }


    return retorno;
}




//SORT

void ordenarClientesPorCantMascotas(eMascota listadoMascotas[],int sizeMascotas,eCliente listadoClientes[],int sizeClientes)
{
    eClienteMascota aux[sizeClientes];
    eClienteMascota auxBurbujeo;
    int i;
    int j;
    int contMascotas;
    int contClientes=0;

    for(i=0; i<sizeClientes; i++)
    {
        contMascotas=0;
        if(listadoClientes[i].estado!=1)
        {
            continue;
        }
        for(j=0; j<sizeMascotas; j++)
        {
            if(listadoClientes[i].id == listadoMascotas[j].idDelDuenio && listadoMascotas[j].estado==1)
            {
                contMascotas++;
            }
        }
        aux[contClientes].idCliente=listadoClientes[i].id;
        aux[contClientes].cantidadMascotas=contMascotas;
        contClientes++;

    }


    printf("ID      NOMBRE          APELLIDO        LOCALIDAD       TELEFONO       EDAD   SEXO   CANT MASCOTAS \n");
    for(i=0; i<contClientes-1; i++)
    {
        for(j=i+1; j<contClientes; j++)
        {

            if(aux[i].cantidadMascotas < aux[j].cantidadMascotas )
            {
                auxBurbujeo  =  aux[i];
                aux[i] = aux[j];
                aux[j] = auxBurbujeo;
            }
        }
    }


    for(i=0; i<contClientes; i++)
    {
        for(j=0; j<sizeClientes; j++)
        {


            if(aux[i].idCliente==listadoClientes[j].id )
            {
                printf("%d\t",listadoClientes[j].id);
                printf("%s   \t",listadoClientes[j].nombre);
                printf("%s   \t",listadoClientes[j].apellido);
                printf("%s   \t",listadoClientes[j].localidad);
                printf("%s\t",listadoClientes[j].telefono);
                printf("%d\t",listadoClientes[j].edad);
                printf("%c\t",listadoClientes[j].sexo);
                printf("%d\t\n",aux[i].cantidadMascotas);

            }
        }
    }
    if(contClientes==0)
    {
        printf("\nNO HAY CLIENTES CARGADOS.\n");
    }

    if(contMascotas==0)
    {
        printf("\nNO HAY MASCOTAS CARGADAS.\n\n");
    }
    system("pause");
}

void ordenarClientesPorCantMascotasYnombre(eMascota listadoMascotas[],int sizeMascotas,eCliente listadoClientes[],int sizeClientes)
{
    eClienteMascota aux[sizeClientes];
    eClienteMascota auxBurbujeo;
    int i;
    int j;
    int contMascotas;
    int contClientes=0;

    for(i=0; i<sizeClientes; i++)
    {
        contMascotas=0;
        if(listadoClientes[i].estado!=1)
        {
            continue;
        }
        for(j=0; j<sizeMascotas; j++)
        {
            if(listadoClientes[i].id == listadoMascotas[j].idDelDuenio && listadoMascotas[j].estado==1)
            {
                contMascotas++;
            }
        }
        aux[contClientes].idCliente=listadoClientes[i].id;
        aux[contClientes].cantidadMascotas=contMascotas;
        strcpy(aux[contClientes].nombre,listadoClientes[i].nombre);
        contClientes++;

    }

    for(i=0; i<contClientes-1; i++)
    {
        for(j=i+1; j<contClientes; j++)
        {


            if(aux[i].cantidadMascotas < aux[j].cantidadMascotas)
            {

                auxBurbujeo  =  aux[i];
                aux[i] = aux[j];
                aux[j] = auxBurbujeo;

            }
            else
            {
                if(aux[i].cantidadMascotas == aux[j].cantidadMascotas)
                {
                    if(strcmp(aux[i].nombre,aux[j].nombre)>0)
                    {
                        auxBurbujeo  =  aux[i];
                        aux[i] = aux[j];
                        aux[j] = auxBurbujeo;
                    }
                }

            }
        }

    }


    printf("ID      NOMBRE          APELLIDO        LOCALIDAD       TELEFONO       EDAD   SEXO   CANT MASCOTAS \n");

    for(i=0; i<contClientes; i++)
    {

        for(j=0; j<sizeClientes; j++)
        {

            if(aux[i].idCliente==listadoClientes[j].id)
            {

                printf("%d\t",listadoClientes[j].id);
                printf("%s   \t",listadoClientes[j].nombre);
                printf("%s   \t",listadoClientes[j].apellido);
                printf("%s   \t",listadoClientes[j].localidad);
                printf("%s\t",listadoClientes[j].telefono);
                printf("%d\t",listadoClientes[j].edad);
                printf("%c\t",listadoClientes[j].sexo);
                printf("%d\t\n",aux[i].cantidadMascotas);
                break;
            }
        }
    }
    if(contClientes==0)
    {
        printf("\nNO HAY CLIENTES CARGADOS.\n");
    }

    if(contMascotas==0)
    {
        printf("\nNO HAY MASCOTAS CARGADAS.\n\n");
    }

    system("pause");

}

//NUEVO


void mostrarClientesConLocalidad(eCliente listaClientes[],int sizeClientes,eMascota listadoMascotas[],int sizeMascotas,eRaza listadoRazas[],int sizeRaza,eLocalidad localidades[],int sizeLocalidad)
{
    int i;
    int j;
    int k;
    int l;
    int contMascotas;
    int contClientes=0;

    for(i=0; i<sizeClientes; i++)
    {
        contMascotas=0;
        if(listaClientes[i].estado==1)
        {
            printf("\n\nCliente: %s %s",listaClientes[i].nombre,listaClientes[i].apellido);

             for(l=0;l<sizeLocalidad;l++)
            {
                if(listaClientes[i].idLocalidad==localidades[i].idLocalidad)
                {
                      printf("\t LOCALIDAD:%s",localidades[i].descripcion);
                      break;
                }
            }
            printf("\nMascotas a cargo del cliente:");
            printf("\nNOMBRE          TIPO    RAZA            EDAD    PESO    SEXO");
            contMascotas=0;
            contClientes++;
        }
        else
        {
            continue;
        }


        for(j=0; j<sizeMascotas; j++)
        {

            if(listaClientes[i].id==listadoMascotas[j].idDelDuenio && listadoMascotas[j].estado==1 )
            {
                printf("\n%s    \t",listadoMascotas[j].nombre);
                printf("%s\t",listadoMascotas[j].tipo);
                for(k=0; k<sizeRaza; k++)
                {
                    if(listadoMascotas[j].idRaza==listadoRazas[k].idRaza)
                    {
                        printf("%s   \t",listadoRazas[k].nombreRaza);
                        break;
                    }
                }

                printf("%d\t",listadoMascotas[j].edad);
                printf("%.2f\t",listadoMascotas[j].peso);
                printf("%c\t",listadoMascotas[j].sexo);
                contMascotas++;
            }

        }

        if(contMascotas==0)
        {
            printf("\nNO TIENE MASCOTAS.\n\n");
        }
        if(contClientes==0)
        {
            printf("\nNO TIENE MASCOTAS.\n\n");
        }
    }
    if(contClientes==0)
    {
        printf("\nNO TIENE CLIENTES CARGADOS.\n\n");
    }
    printf("\n\n");
    system("pause");

}



int altaClienteConLocalidad(eCliente listaClientes[],int sizeClientes,eLocalidad localidades[] ,int sizeLocalidad)
{
    int posicionLibre;
    int confirmacion;

    posicionLibre=buscarLibreArrayCliente(listaClientes,sizeClientes);

    system("cls");

    if(posicionLibre!=-1)

    {
        confirmacion=cargarCamposClienteConLocalidad(listaClientes,posicionLibre,localidades,sizeLocalidad);


        if (confirmacion==1)
        {
            listaClientes[posicionLibre].estado=1;
            return 1;
        }
        else
        {
            return 0;
        }


    }
    else
    {
        printf("No hay espacio.");
        return 0;
    }



}

int cargarCamposClienteConLocalidad(eCliente listaClientes[],int posicionLibre,eLocalidad localidades[] ,int sizeLocalidad)
{
    char entrada[10];
    char sexo;
    char opcion[5];
    int confirmacion;

    //CARGA NOMBRE
    printf("Ingrese nombre de el cliente: ");
    fflush(stdin);
    gets(listaClientes[posicionLibre].nombre);
    formatearNombres(listaClientes[posicionLibre].nombre);
    while(validarCadena(listaClientes[posicionLibre].nombre)==0)
    {
        system("cls");
        printf("Nombre invalido, reeingrese nombre: ");
        gets(listaClientes[posicionLibre].nombre);
        formatearNombres(listaClientes[posicionLibre].nombre);
        validarCadena(listaClientes[posicionLibre].nombre);

    }

    //CARGA APELLIDO
    printf("\nIngrese apellido del cliente :");
    fflush(stdin);
    gets(listaClientes[posicionLibre].apellido);
    formatearNombres(listaClientes[posicionLibre].apellido);

    while(validarCadena(listaClientes[posicionLibre].apellido)==0)
    {
        system("cls");
        printf("Apellido invalido, reeingrese el apellido: ");
        gets(listaClientes[posicionLibre].apellido);
        validarCadena(listaClientes[posicionLibre].apellido);
        validarTipoMascota(listaClientes[posicionLibre].apellido);
    }

    //CARGA LOCALIDAD
    printf("\nIngrese id de la localidad de residencia del cliente: \n");
    mostrarLocalidades(localidades,sizeLocalidad);
    fflush(stdin);
    listaClientes[posicionLibre].idLocalidad=getInt(entrada);

    //CARGA TELEFONO
    printf("\nIngrese telefono del cliente, el formato valido es XXXX-XXXX: ");
    fflush(stdin);
    gets(listaClientes[posicionLibre].telefono);

    while(validarTelefono(listaClientes[posicionLibre].telefono)==1)
    {
        system("cls");
        printf("Telefono invalido, el formato valido es XXXX-XXXX : ");
        gets(listaClientes[posicionLibre].telefono);
        validarTelefono(listaClientes[posicionLibre].telefono);

    }

    //CARGA EDAD
    printf("\nIngrese edad de el cliente: ");
    fflush(stdin);
    gets(entrada);
    listaClientes[posicionLibre].edad=getInt(entrada);

    //CARGA SEXO
    printf("\nIngrese sexo del cliente F/M: ");
    fflush(stdin);
    scanf("%c",&sexo);
    listaClientes[posicionLibre].sexo=getChar(sexo);

    while(validarSexoClientes(listaClientes[posicionLibre].sexo)==0)
    {
        printf("\n\nSexo invalido, ingrese F/M :");
        fflush(stdin);
        scanf("%c",&sexo);
        listaClientes[posicionLibre].sexo=getChar(sexo);
        validarSexoClientes(listaClientes[posicionLibre].sexo);
    }
    listaClientes[posicionLibre].sexo=toupper(listaClientes[posicionLibre].sexo);

    system("cls");

    printf("Ingrese 1 para confirmar.\n");
    printf("Ingrese 2 para salir.\n\n");
    printf("Opcion elegida: ");

    fflush(stdin);
    gets(opcion);

    confirmacion=validarIntEntreRangos(opcion,1,2);

    return confirmacion;


}


void listarClientesMascotasMismoTipo(eMascota listadoMascotas[],int sizeMascotas,eCliente listadoClientes [],int sizeClientes,eLocalidad localidades[],int sizeLocalidad)
{

    int i;
    int j;
    int l;
    int contPerros;
    int contGatos;
    int contRaros;
    int contClientes;

    printf("ID      NOMBRE          APELLIDO        LOCALIDAD       TELEFONO       EDAD   SEXO   \n");

    for(i=0; i<sizeClientes; i++)
    {

        contGatos=0;
        contPerros=0;
        contRaros=0;


        if(listadoClientes[i].estado==1)
        {
            contClientes++;
            for(j=0; j<sizeMascotas; j++)
            {
                if(listadoClientes[i].id==listadoMascotas[j].idDelDuenio)
                {
                    if(strcmp(listadoMascotas[j].tipo,"Perro")==0)
                    {
                        contPerros++;
                    }
                    else
                    {
                        if(strcmp(listadoMascotas[j].tipo,"Gato")==0)
                        {
                            contGatos++;
                        }
                        else
                        {
                            contRaros++;
                        }
                    }


                }
            }

            if((contPerros>0 && contGatos==0 && contRaros==0) || (contGatos>0 && contRaros==0 && contPerros==0) || (contRaros>0 && contGatos==0 && contPerros==0))
            {
                printf("%d\t",listadoClientes[i].id);
                printf("%s   \t",listadoClientes[i].nombre);
                printf("%s   \t",listadoClientes[i].apellido);

                 for(l=0;l<sizeLocalidad;l++)
                {
                    if(listadoClientes[i].idLocalidad==localidades[i].idLocalidad)
                    {
                        printf("%s   \t",localidades[i].descripcion);
                          break;
                    }
                }

                printf("%s\t",listadoClientes[i].telefono);
                printf("%d\t",listadoClientes[i].edad);
                printf("%c\t\n",listadoClientes[i].sexo);
            }
        }
        else
        {
            continue;
        }


    }

    if(contClientes==0)
    {
        printf("NO HAY CLIENTES CARGADOS\n\n");
    }
    system("pause");

}
