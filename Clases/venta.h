#ifndef VENTA_H
#define VENTA_H

#include "vehiculo.h"
#include "accesorio.h"
#include "automovil.h"
#include "moto.h"
#include "camion.h"

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
        venta();
        ~venta();
        int calcularTotalVehiculos();
        int calcularTotalAccesorios();
        int calcularDescuento();
        void asignarRun(std::string vrun);
        void agregar_vehiculo(vehiculo* vvehiculo);
        void agregar_accesorio(accesorio* vaccesorio);

        int creacionVehiculo(int opcion, std::string marca, int remoto, int unidades);
        void menuVentaVehiculo();

        void menuVentaAccesorio();

        void finalizarCompra();

        void opcionAContinuacion();
        
};

#endif