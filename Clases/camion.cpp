#include "camion.h"

//Utilizar una V antes del nombre de la variable para diferenciar entre valores ya existentes y valores nuevos
camion::camion(int vruedas, std::string vmarca, bool vremoto, int vfecha_fabriacion, int vcajas, int vejes) :
    vehiculo(vruedas, vmarca, vremoto, vfecha_fabriacion){
        this->cajas = vcajas;
        this->ejes = vejes;
    }