#ifndef CAMION_H
#define CAMION_H

#include "vehiculo.h"

class camion : public vehiculo {
    protected:
        int cajas; //cantidad de cajas
        int ejes; //cantidad de ejes
    public:
        camion(int vruedas, std::string vmarca, bool vremoto, int vfecha_fabriacion, int vcajas, int vejes);
        ~camion();
};


#endif  