
//Clases
#include "Clases/automovil.h"
#include "Clases/moto.h"
#include "Clases/camion.h"

int main(){

    moto* test1 = new moto(2, "Honda", false, 2020, 2, 2);
    test1->mostrarse();

    return 0;
}

