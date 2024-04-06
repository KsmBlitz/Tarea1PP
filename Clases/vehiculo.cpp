#include "vehiculo.h"

int vehiculo::calcular_valor(){ //Corregir implementacion
    return 1000;
}

//Utilizar una V antes del nombre de la variable para diferenciar entre valores ya existentes y valores nuevos
vehiculo::vehiculo(int vruedas,std::string vmarca,bool vremoto, int vanio_fabricacion){
    this->ruedas = vruedas;
    this->marca = vmarca;
    this->remoto = vremoto;
    this->anio_fabricacion = vanio_fabricacion;
    this->valor_vehiculo = calcular_valor();
}

void vehiculo::mostrarse(){
    std::cout << this->marca << " " << this->anio_fabricacion << " " << this->valor_vehiculo << " " << this->ruedas;
}