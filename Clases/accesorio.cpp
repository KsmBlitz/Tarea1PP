#include "accesorio.h"


accesorio::~accesorio(){

}

//Utilizar una V antes del nombre de la variable para diferenciar entre valores ya existentes y valores nuevos
accesorio::accesorio(std::string vnombre, int vunidades){
    this->nombre = vnombre;
    this->unidades = vunidades;
    this->precio = this->calcular_valor();
}

void accesorio::mostrarse(){
    std::cout << "\n\nNombre: " << this->nombre << "\nUnidades: " << this->unidades;
    std::cout << "\nPrecio: " << this->calcular_valor_total();
}

int accesorio::getUnidades(){
    return this->unidades;
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