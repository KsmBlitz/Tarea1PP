#ifndef ACCESORIO_H
#define ACCESORIO_H

#include "../Valores/valores.h"
#include <string>

class accesorio {
    private:
    std::string nombre;
    int precio = calcular_valor();
    int unidades;

    public:
    accesorio(std::string nombre, int unidades);
    ~accesorio();
    void mostrarse();
    int calcular_valor();
    int calcular_valor_total();
    int getUnidades();

};


#endif