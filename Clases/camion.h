#ifndef CAMION_H
#define CAMION_H

#include "vehiculo.h"

class camion : public vehiculo {
    protected:
    
    public:
        camion(int vruedas, std::string vmarca, bool vremoto, int vfecha_fabriacion, int vunidades);
        ~camion();
};


#endif  