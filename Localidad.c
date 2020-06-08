void hardcodearLocalidad(eLocalidad listaLocalidades[],int sizeLocalidades)
{

    char provincia[3][30]= {"Buenos Aires","Santa Fe","La Pampa"};
    char descripcion[3][30]= {"Quilmes","Rosario","Santa Rosa",};
    int codPostal[3]= {2824,2545,30457};
    int idProvincia[3]= {1,2,3};
    int i;

    for(i=0; i<sizeLocalidades;i++)
    {

        strcpy(listaLocalidades[i].provincia,provincia[i]);
        strcpy(sizeLocalidades[i].descripcion,descripcion[i]);
        sizeLocalidades[i].codPostal=codPostal[i];
        sizeLocalidades[i].idProvincia=idProvincia[i];

    }


}
