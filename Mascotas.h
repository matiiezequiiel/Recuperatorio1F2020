
typedef struct
{
    char nombre[20];
    char tipo[20];
    int idRaza;
    int edad;
    float peso;
    char sexo;
    int idMascota;
    int idDelDuenio;
    int estado;

} eMascota;

//INICIALIZACION

void hardcodearMascotas(eMascota[],int);

/** \brief Inicializa array de mascotas para posterior carga.
 *
 * \param eCliente[] Array de mascotas.
 * \param int Tamaño del array.
 * \return void
 *
 */
void initMascotas(eMascota[],int);




//MOSTRAR

/** \brief Muestra promedio de edad de las mascotas.
 *
 * \param eMascota[] Array de mascotas
 * \param int Tamaño del array.
 * \return void
 *
 */
void promedioEdadMascotas(eMascota[],int);//OPCION 16


/** \brief Muestra promedio de edad de las mascotas por tipo.
 *
 * \param eMascota[] Array de mascotas
 * \param int Tamaño del array.
 * \return void
 *
 */
void promedioEdadMascotaPorTipo(eMascota[],int);//OPCION 17




//ALTA

/** \brief Busca posicion libre en array de clientes para su posterior carga.
 *
 * \param eCliente[] Array de clientes.
 * \param int Tamaño del array.
 * \return int Posicion libre, -1 no hay espacio.
 *
 */
int buscarLibreArrayMascota(eMascota[],int);




//BAJA

/** \brief Baja logica de una mascota.
 *
 * \param eMascota[] Array de mascotas.
 * \param int Tamaño del array de mascotas.
 * \param int ID UNICO de la mascota a dar de baja.
 * \return int 1 baja correcta, 0 baja cancelada.
 *
 */
int bajaMascota(eMascota[],int,int); //OPCION 5




