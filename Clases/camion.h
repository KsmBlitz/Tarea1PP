#ifndef CAMION_H
#define CAMION_H

#include "vehiculo.h"

class camion : public vehiculo {
    protected:
    
    public:
        camion(std::string vmarca, std::string vremoto, int vfecha_fabriacion, int vunidades);
        virtual ~camion() override;
        int calcular_valor() override;
};


#endif  