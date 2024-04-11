#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "../Valores/valores.h"

class vehiculo{
    protected:
        int ruedas; //cantidad de ruedas
        std::string marca; //nombre de la marca
        std::string remoto; //si tiene control remoto o no
        int anio_fabricacion; //año de fabricacion 
        int valor_vehiculo;
        int unidades; //cantidad de unidades del mismo tipo
        
    public:
        vehiculo(std::string vmarca, int vremoto, int vanio_fabriacion, int vunidades);
        ~vehiculo();
        virtual int calcular_valor();
        int calcular_valor_total();
        void mostrarse();
};

#endif