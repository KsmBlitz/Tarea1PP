#include "venta.h"

venta::venta(std::string vrun){
    this->run = vrun;
}

int venta::calcularTotalVehiculos(){
    int total = 0;
    for (vehiculo* vehiculo_actual : this->listaVehiculos){
        total += vehiculo_actual->calcular_valor_total();
    }
    return total;
}

int venta::calcularTotalAccesorios(){
    int total = 0;
    for (accesorio* accesorio_actual : this->listaAccesorios){
        total += accesorio_actual->calcular_valor_total();
    }
    return total;
}

int venta::calcularDescuento(){
    int unidades = this->listaVehiculos.size();
    if (unidades > 10000) {
        return 0.1;
    } else if (unidades >= 5000) {
        return 0.05;
    } else if (unidades >= 1000) {
        return 0.03;
    } else {
        return 0.01;
    }
}

void venta::agregar_vehiculo(vehiculo* vehiculo){
    this->listaVehiculos.push_back(vehiculo);
}

void venta::agregar_accesorio(accesorio* accesorio){
    this->listaAccesorios.push_back(accesorio);
}