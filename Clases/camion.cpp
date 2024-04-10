#include "camion.h"

//Utilizar una V antes del nombre de la variable para diferenciar entre valores ya existentes y valores nuevos
camion::camion(int vruedas, std::string vmarca, bool vremoto, int vfecha_fabriacion, int vunidades) :
    vehiculo(vruedas, vmarca, vremoto, vfecha_fabriacion, vunidades){
    }

int vehiculo::calcular_valor(){

    std::map<std::string,int> valores = cargar_valores_camiones();
    for (auto it = valores.begin(); it != valores.end(); ++it){
        if (it->first == this->marca){
            return it->second;
        }
    }
    return -1;
}