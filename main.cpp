//Clases
#include "classmaster.h"

int main(){

    std::map<std::string,int> valores_autos = cargar_valores_autos();

    for (auto it = valores_autos.begin(); it != valores_autos.end(); ++it){
        std::cout << it->first << ": " << it->second << "\n";
    }

    return 0;
}