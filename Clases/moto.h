#ifndef MOTO_H
#define MOTO_H

#include "vehiculo.h"


class moto : public vehiculo{
    protected:
        int pedales; //cantidad de pedales
        int espejos; //cantidad de espejos

    public:
        moto(int vruedas,std::string vmarca,bool vremoto,int vanio_fabriacion,int vpedales,int vespejos);
        ~moto();
};

#endif