#ifndef AUTOMOVIL_H
#define AUTOMOVIL_H

#include "vehiculo.h"

class automovil : public vehiculo {
    protected:
        int puertas; //cantidad de puertas
        int luces; //cantidad de luces
    public:
        automovil(int vruedas, std::string vmarca, bool vremoto, int vanio_fabriacion, int vpuertas, int vluces);
};

#endif