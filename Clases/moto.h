#ifndef MOTO_H
#define MOTO_H

#include "vehiculo.h"


class moto : public vehiculo{
    protected:

    public:
        moto(int vruedas,std::string vmarca,bool vremoto,int vanio_fabriacion, int vunidades);
        ~moto();
};

#endif