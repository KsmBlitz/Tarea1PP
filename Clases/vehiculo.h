#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include <iostream>

class vehiculo{
    protected:
        int ruedas; //cantidad de ruedas
        std::string marca; //nombre de la marca
        bool remoto; //si tiene control remoto o no
        int anio_fabricacion; //año de fabricacion 
        int valor_vehiculo = calcular_valor();
        int valor_articulos = 0;
        
    public:
        vehiculo(int vruedas, std::string vmarca, bool vremoto, int vanio_fabriacion);
        int calcular_valor();
        void mostrarse();
};

#endif