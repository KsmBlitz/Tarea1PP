#include "moto.h"

//Utilizar una V antes del nombre de la variable para diferenciar entre valores ya existentes y valores nuevos
moto::moto(int vruedas,std::string vmarca,bool vremoto,int vanio_fabricacion,int vpedales,int vespejos) :
    vehiculo(vruedas, vmarca, vremoto, vanio_fabricacion) {
        this->pedales = vpedales;
        this->espejos = vespejos;
    }

int vehiculo::calcular_valor(){

    std::map<std::string,int> valores = cargar_valores_motos();
    for (auto it = valores.begin(); it != valores.end(); ++it){
        if (it->first == this->marca){
            return it->second;
        }
    }
    return -1;
}

