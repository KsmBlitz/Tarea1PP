#ifndef MOTO_H
#define MOTO_H

#include "vehiculo.h"


class moto : public vehiculo{
    protected:

    public:
        moto(std::string vmarca,std::string vremoto,int vanio_fabriacion, int vunidades);
        virtual ~moto() override;
        int calcular_valor() override;
};

#endif