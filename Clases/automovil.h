#ifndef AUTOMOVIL_H
#define AUTOMOVIL_H

#include "vehiculo.h"

class automovil : public vehiculo {
    protected:

    public:
        automovil(int vruedas, std::string vmarca, bool vremoto, int vanio_fabriacion, int vunidades);
        ~automovil();
        int calcular_valor() override;
};

#endif