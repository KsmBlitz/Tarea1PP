#ifndef VENTA_H
#define VENTA_H

#include <string>
#include <vector>
#include "vehiculo.h"
#include "accesorio.h"

class venta {
    private:
        std::string run;
        std::vector<vehiculo*> listaVehiculos;
        std::vector<accesorio*> listaAccesorios;
        int totalVehiculos = calcularTotalVehiculos();
        int totalAccesorios = calcularTotalAccesorios();
        float descuento = calcularDescuento();
        int totalVenta = (1-descuento) * (totalVehiculos + totalAccesorios); ;
    public:
        venta(std::string vrun);
        ~venta();
        int calcularTotalVehiculos();
        int calcularTotalAccesorios();
        int calcularDescuento();
        void agregar_vehiculo(vehiculo* vehiculo);
        void agregar_accesorio(accesorio* accesorio);
        
};



#endif