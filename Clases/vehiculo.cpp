#include "vehiculo.h"

//Utilizar una V antes del nombre de la variable para diferenciar entre valores ya existentes y valores nuevos
vehiculo::vehiculo(std::string vmarca,int vremoto, int vanio_fabricacion, int vunidades){
    this->marca = vmarca;
    if (vremoto == 1) {
        this->remoto = "si";
    } else {
        this->remoto = "no";
    }
    this->anio_fabricacion = vanio_fabricacion;
    this->unidades = vunidades;
}

void vehiculo::mostrarse(){
    std::cout <<"Marca: "<< this->marca << "\nRuedas: " << this->ruedas;
    std::cout <<"\nControl remoto: " << this->remoto << "\nUnidades: " << this->ruedas;
    std::cout <<"\nPrecio: " << this->calcular_valor_total();
}

int vehiculo::calcular_valor(){
    return 0;
}

int vehiculo::calcular_valor_total(){
    return this->valor_vehiculo * this->unidades;
}