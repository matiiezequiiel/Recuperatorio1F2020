typedef struct
{
   char provincia[30];
   int codPostal;
   char descripcion[30];
   int idLocalidad;

} eLocalidad;

void hardcodearLocalidad(eLocalidad listaLocalidades[],int sizeLocalidades);
void mostrarLocalidades(eLocalidad listaLocalidades[],int sizeLocalidades);
