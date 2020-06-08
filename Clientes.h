typedef struct
{
    char nombre [20];
    char apellido [20];
    char localidad [20];
    int idLocalidad;
    char telefono[10];
    int edad;
    char sexo;
    int id;
    int estado;

} eCliente;

//INICIALIZACION DE CLIENTES
void hardcodearClientes(eCliente[],int);
void initClientes(eCliente[],int);

//MOSTRAR

/** \brief Muestra clientes activos con sus respectivos datos.
 *
 * \param Array de clientes.
 * \param Tamaño del array.
 * \return
 *
 */

void mostrarClientes(eCliente[],int); //OPCION 1


/** \brief Muestro el porcentaje que tengo de mujeres entre el total de clientes
 *
 * \param eCliente[] Array de clientes
 * \param int Size clientes
 * \return void
 *
 */
void porcentajeMujeresEntreClientes(eCliente[],int);//OPCION 18





//ALTA

/** \brief Alta de cliente.
 *
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array.
 * \return int 1 alta correcta, 0 alta cancelada.
 *
 */
int altaCliente(eCliente[],int); //OPCION 7


/** \brief Busca posicion libre en array de clientes para su posterior carga.
 *
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array.
 * \return int Posicion libre, -1 no hay espacio.
 *
 */
int buscarLibreArrayCliente(eCliente[],int);


/** \brief Carga campos correspondiente a al alta de un cliente.
 *
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array.
 * \return int 1 carga correcta,0 carga cancelada.
 *
 */
int cargarCamposCliente(eCliente[],int);






//MODIFICACION

/** \brief Modificar datos de un cliente.
 *
 * \param eCliente[] Array de clientes.
 * \param int Tamaño de array.
 * \param int ID unico del cliente a modificar.
 * \return int 1 modificacion correcta, 0 modificacion cancelada.
 *
 */
int modificarCliente(eCliente[],int,int);//OPCION 10


/** \brief Muestra menu para elegir que campos quiere modificar del cliente.
 *
 * \param eCliente[] Array de clientes.
 * \param int Tamaño de array.
 * \return int 1 modificacion correcta, 0 modificacion cancelada.
 *
 */
int menuModificacionesCliente(eCliente[],int);

