#include "valores.h"

std::map<std::string, int> cargar_valores(std::string filename){
    std::map<std::string,int> valores;
    std::string linea;
    std::ifstream archivo(filename.c_str());
    if (!archivo.is_open()) {
        std::cerr << "Error: " << filename << " no se encontro";
        exit(-1);
    }
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string clave, marca;
        int valor;
        std::getline(ss, clave,':');
        marca = clave;    
        ss >> valor;       
        
        valores[clave] = valor;
    }
    archivo.close();
    return valores;
}

//Cargar Precios de Autos
std::map<std::string, int> cargar_valores_autos(){
    std::string archivo = "Valores/precios_autos.txt"; //PATH del archivo donde se alojaran los precios
    std::map<std::string,int> valores_autos = cargar_valores(archivo);
    return valores_autos;
}

//Cargar Precios de Motos
std::map<std::string, int> cargar_valores_motos(){
    std::string archivo = "Valores/precios_motos.txt"; //PATH del archivo donde se alojaran los precios
    std::map<std::string,int> valores_motos = cargar_valores(archivo);

    return valores_motos;
}

//Cargar Precios de Camiones
std::map<std::string, int> cargar_valores_camiones(){
    std::string archivo = "Valores/precios_camiones.txt"; //PATH del archivo donde se alojaran los precios
    std::map<std::string,int> valores_camiones = cargar_valores(archivo);

    return valores_camiones;
}

//Cargar Precios de Accesorios
std::map<std::string, int> cargar_valores_accesorios(){
    std::string archivo = "Valores/precios_accesorios.txt"; //PATH del archivo donde se alojaran los precios
    std::map<std::string,int> valores_accesorios = cargar_valores(archivo);

    return valores_accesorios;
}

//Retorna false o true si la marca existe dentro del mapa
bool enStock(std::map<std::string, int> valores, std::string marca){
    for (auto it = valores.begin(); it != valores.end(); ++it){
        if (it->first == marca){
            return true;
        }
    }
    return false;
}


//Mostrar Precios de Vehiculos
void mostrarPreciosVehiculos(std::map<std::string,int> valores){
    //Recorrer el mapa y mostrar los valores en el formato "NombreMarca: $Precio"
    for (auto it = valores.begin(); it != valores.end(); ++it){
        std::cout << it->first <<": $" << it->second << "\n";
    }
}

//Mostrar Precios de Accesorios
void mostrarPreciosAccesorios(){

}