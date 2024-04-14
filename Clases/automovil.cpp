#include "automovil.h"


//Utilizar una V antes del nombre de la variable para diferenciar entre valores ya existentes y valores nuevos
automovil::automovil(std::string vmarca, std::string vremoto, int vanio_fabriacion, int vunidades) : 
	vehiculo(vmarca, vremoto, vanio_fabriacion, vunidades) {
        this->ruedas = 4;
        this->valor_vehiculo = calcular_valor();
	}

automovil::~automovil(){
    
}

int automovil::calcular_valor(){
    std::map<std::string,int> valores = cargar_valores_autos();
    for (auto it = valores.begin(); it != valores.end(); ++it){
        if (it->first == this->marca){
            return it->second;
        }
    }
    return -1;
}