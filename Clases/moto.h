#ifndef MOTO_H
#define MOTO_H

#include "vehiculo.h"


class moto : public vehiculo{
    protected:

    public:
        moto(std::string vmarca,bool vremoto,int vanio_fabriacion, int vunidades);
        ~moto();
        int calcular_valor() override;
};

#endif