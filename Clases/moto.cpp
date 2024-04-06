#include "moto.h"

//Utilizar una V antes del nombre de la variable para diferenciar entre valores ya existentes y valores nuevos
moto::moto(int vruedas,std::string vmarca,bool vremoto,int vanio_fabricacion,int vpedales,int vespejos) :
    vehiculo(vruedas, vmarca, vremoto, vanio_fabricacion) {
        this->pedales = pedales;
        this->espejos = espejos;
    }


