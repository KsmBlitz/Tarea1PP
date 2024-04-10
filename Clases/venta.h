#ifndef VENTA_H
#define VENTA_H

#include <string>
#include <vector>
#include "vehiculo.h"

class venta {
    private:
        std::string run;
        std::vector<vehiculo> listaVehiculos;
        int totalVehiculos;
        int totalAccesorios;
        float descuento;
        int totalVenta;
        int calcularCantidades();
    public:
        venta();
        ~venta();
        int calcularTotalVehiculos();
        
};



#endif