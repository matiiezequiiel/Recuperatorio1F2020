#include"Clientes.h"
#include"Mascotas.h"
#include"Raza.h"
#include"Validaciones.h"

typedef struct
{
    int idCliente;
    int cantidadMascotas;
    char nombre[10];

} eClienteMascota;


//MOSTRAR

/** \brief Muestra listado de mascotas con sus respectivos dueños.
 *
 * \param eMascota[] Array de mascotas.
 * \param int Tamaño de el array de mascotas.
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array de clientes.
 * \return void
 *
 */
void mostrarMascotas(eMascota[],int,eCliente[],int,eRaza[],int); //OPCION 2



/** \brief Muestra listado de clientes con sus respectivos animales.
 *
 * \param eMascota[] Array de mascotas.
 * \param int Tamaño de el array de mascotas.
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array de clientes.
 * \return void
 *
 */
void mostrarClientesConSusAnimales(eCliente[],int,eMascota[],int,eRaza listadoRazas[],int sizeRaza); //OPCION 3



/** \brief Muestra listado de mascotas por tipo.
 *
 * \param eMascota[] Array de mascotas.
 * \param int Tamaño de el array de mascotas.
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array de clientes.
 * \return void
 *
 */
void mostrarMascotasPorTipo(eMascota[],int,eCliente[],int,eRaza[],int); //OPCION 9

/** \brief Muestra listado de clientes con mas de una mascota.
 *
 * \param eMascota[] Array de mascotas.
 * \param int Tamaño de el array de mascotas.
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array de clientes.
 * \return void
 *
 */
void listarClientesConMasUnaMascota(eMascota[],int,eCliente[],int); //OPCION 11

/** \brief Mostrar listado de mascotas por un tipo especifico elegido por el usuario.
 *
 * \param Array de mascotas
 * \param Tamaño del array.
 * \return
 *
 */
void mostrarMascotasPorTipoElegido(eMascota[],int,eRaza[],int); //OPCION 13


/** \brief Listar las mascotas que tengan mas de 3 años.
 *
 * \param eMascota[] Array de mascotas
 * \param sizeMascotas int Size de mascotas
 * \param eCliente[] Array de clientes
 * \param int Size de clientes
 * \param eRaza[] Array de raza
 * \param int Size raza
 * \return void
 *
 */
void listarMascotasMas3Anios(eMascota [],int sizeMascotas,eCliente[],int,eRaza[],int);//OPCION 12


/** \brief LISTA DE CLIENTES CON MASCOTAS DEL MISMO SEXO
 *
 * \param eMascota[] Array de mascotas
 * \param int Size de mascotas
 * \param eCliente[] Array de clientes
 * \param int Size de clientes
 * \return void
 *
 */
void listarClientesMascotasMismoSexo(eMascota[],int,eCliente[],int); //OPCION 19





//ALTA MASCOTA

/** \brief Alta de mascota.
 *
 * \param eMascota[] Array de mascotas.
 * \param int Tamaño de el array de mascotas.
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array de clientes.
 * \return void
 *
 */
int altaMascota(eMascota[],int,eCliente[],int,eRaza[],int); //OPCION 4


/** \brief Carga campos respectivos a una mascota.
 *
 * \param eMascota[] Array de mascotas.
 * \param int Tamaño de el array de mascotas.
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array de clientes.
 * \return void
 *
 */
int cargarCamposMascota(eMascota[],int,eCliente[],int,eRaza[],int);



//MODIFICACION DE MASCOTA


/** \brief Modificar datos de una mascota.
 *
 * \param eCliente[] Array de mascotas.
 * \param int Tamaño de array.
 * \param int ID unico de la mascota a modificar.
 * \return int 1 modificacion correcta, 0 modificacion cancelada.
 *
 */
int modificarMascota(eMascota[],int,int,eRaza[],int,eCliente[],int);//OPCION 6


/** \brief Muestra menu para elegir que campos quiere modificar de la mascota.
 *
 * \param eCliente[] Array de mascotas.
 * \param int Tamaño de array.
 * \return int 1 modificacion correcta, 0 modificacion cancelada.
 *
 */
int menuModificaciones(eMascota[],int,eRaza[],int,eCliente[],int);




//BAJA CLIENTE

/** \brief Baja de un cliente con sus respectivas mascotas.
 *
 * \param eMascota[] Array de mascotas.
 * \param int Tamaño de el array de mascotas.
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array de clientes.
 * \param int ID UNICO de el cliente a dar de baja
 * \return void
 *
 */
int bajaClienteConSusMascotas(eMascota[],int,eCliente[],int,int);//OPCION 8



//SORT

/** \brief Muestra listado de clientes con mascotas de mas de 3 años.
 *
 * \param eMascota[] Array de mascotas.
 * \param int Tamaño de el array de mascotas.
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array de clientes.
 * \return void
 *
 */

void ordenarClientesPorCantMascotas(eMascota[],int,eCliente[],int);//OPCION 14


/** \brief Ordena y lista clientes por cantidad de mascotas y nombre.
 *
 * \param eMascota[] Array de mascotas.
 * \param int Tamaño de el array de mascotas.
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array de clientes.
 * \return void
 *
 */
void ordenarClientesPorCantMascotasYnombre(eMascota[],int,eCliente[],int);//OPCION 15




