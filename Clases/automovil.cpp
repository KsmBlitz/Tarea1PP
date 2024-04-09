#include "automovil.h"


//Utilizar una V antes del nombre de la variable para diferenciar entre valores ya existentes y valores nuevos
automovil::automovil(int vruedas, std::string vmarca, bool vremoto, int vanio_fabriacion, int vpuertas, int vluces) : 
	vehiculo(vruedas, vmarca, vremoto, vanio_fabriacion) {
		this->puertas = vpuertas;
		this->luces = vluces;
	}

int vehiculo::calcular_valor(){

    std::map<std::string,int> valores = cargar_valores_autos();
    for (auto it = valores.begin(); it != valores.end(); ++it){
        if (it->first == this->marca){
            return it->second;
        }
    }
    return -1;
}