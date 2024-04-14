#ifndef AUTOMOVIL_H
#define AUTOMOVIL_H

#include "vehiculo.h"

class automovil : public vehiculo {
    protected:

    public:
        automovil(std::string vmarca, std::string vremoto, int vanio_fabriacion, int vunidades);
        virtual ~automovil() override;
        int calcular_valor() override;
};

#endif