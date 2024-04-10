#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include <iostream>
#include <map>
#include "../Valores/valores.h"

class vehiculo{
    protected:
        int ruedas; //cantidad de ruedas
        std::string marca; //nombre de la marca
        bool remoto; //si tiene control remoto o no
        int anio_fabricacion; //año de fabricacion 
        int valor_vehiculo = calcular_valor(); 
        int valor_articulos = 0;
        int unidades; //cantidad de unidades del mismo tipo
        
    public:
        vehiculo(int vruedas, std::string vmarca, bool vremoto, int vanio_fabriacion, int vunidades);
        ~vehiculo();
        virtual int calcular_valor();
        int calcular_valor_total();
        void mostrarse();
};

#endif