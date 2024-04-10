#include "accesorio.h"

//Utilizar una V antes del nombre de la variable para diferenciar entre valores ya existentes y valores nuevos
accesorio::accesorio(std::string vnombre, int vunidades){
    this->nombre = vnombre;
    this->unidades = vunidades;
}

int accesorio::calcular_valor(){
    std::map<std::string,int> valores = cargar_valores_accesorios();
    for (auto it = valores.begin(); it != valores.end(); ++it){
        if (it->first == this->nombre){
            return it->second;
        }
    }
    return -1;
}

int accesorio::calcular_valor_total(){
    return this->precio * this->unidades;
}