#ifndef VENTA_H
#define VENTA_H

#include "vehiculo.h"
#include "accesorio.h"
#include "automovil.h"
#include "moto.h"
#include "camion.h"
#include "../Valores/valores.h"

class venta {
    private:
        std::string nombre;
        std::string run;
        std::vector<vehiculo*> listaVehiculos;
        std::vector<accesorio*> listaAccesorios;
        int totalVehiculos = calcularValorTotalVehiculos();
        int totalAccesorios = calcularValorTotalAccesorios();
        int cantidadVehiculos = calcularCantidadTotalVehiculos();
        int cantidadAccesorios = calcularCantidadTotalAccesorios();
        float descuento = calcularDescuento();
        int totalVenta = totalVehiculos*descuento + totalAccesorios; ;
    public:
        venta();
        ~venta();
        int calcularValorTotalVehiculos();
        int calcularValorTotalAccesorios();

        int calcularCantidadTotalVehiculos();
        int calcularCantidadTotalAccesorios();

        int calcularDescuento();
        void setRun(std::string vrun);
        void setNombre(std::string vnombre);
        void agregar_vehiculo(vehiculo* vvehiculo);
        void agregar_accesorio(accesorio* vaccesorio);

        int creacionVehiculo(int opcion, std::string marca, std::string remoto, int unidades);
        void menuVentaVehiculo();

        void menuVentaAccesorio();

        void finalizarCompra();

        void opcionAContinuacion();

        void imprimirArchivo();

        void limpiarBoleta();
        
};

#endif