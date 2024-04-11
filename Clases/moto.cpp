#include "moto.h"

//Utilizar una V antes del nombre de la variable para diferenciar entre valores ya existentes y valores nuevos
moto::moto(std::string vmarca,bool vremoto,int vanio_fabricacion, int vunidades) :
    vehiculo(vmarca, vremoto, vanio_fabricacion, vunidades) {
        this->ruedas = 2;
        this->valor_vehiculo = calcular_valor();
    }

int moto::calcular_valor(){
    std::map<std::string,int> valores = cargar_valores_motos();
    for (auto it = valores.begin(); it != valores.end(); ++it){
        if (it->first == this->marca){
            return it->second;
        }
    }
    return -1;
}

