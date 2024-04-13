#include "reportes.h"

std::ifstream archivoClientes(){
    std::ifstream archivo("Clientes.txt");
    if (!archivo.is_open()){
        std::cerr << "Error: archivo \"Clientes.csv\" no fue encontrado" << std::endl;
        exit(1);
    }
    return archivo;
}


void reporteDiario(){
    int max_cant_vehiculos = -1;
    int max_cant_accesorios = -1;
    int total_vehiculos = 0;
    int total_accesorios = 0;
    int cant_clientes = 0;
    int ventas_totales = 0;
    std::ifstream archivo = archivoClientes();
    std::string linea, nombre_cliente_vehiculos, nombre_cliente_accesorios;
    std::vector<std::string> infoCliente;

    // Leer el archivo línea por línea
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string valor;
        while (std::getline(ss, valor, ',')) {
            infoCliente.push_back(valor);
        }
        cant_clientes++;
        ventas_totales += std::stoi(infoCliente[7]);

        total_accesorios += std::stoi(infoCliente[3]);
        total_vehiculos += std::stoi(infoCliente[2]);
        //El vector almacena la informacion de en orden 0: Nombre; 1: Run ....
        //Se utiliza stoi para transformar el string en int y poder comparar
        if (std::stoi(infoCliente[2]) > max_cant_vehiculos){
            max_cant_vehiculos = std::stoi(infoCliente[2]);
            nombre_cliente_vehiculos = infoCliente[0];
        }
        if (std::stoi(infoCliente[3]) > max_cant_accesorios) {
            max_cant_accesorios = std::stoi(infoCliente[3]);
            nombre_cliente_accesorios = infoCliente[0];
        }
        infoCliente.clear();
    }
    archivo.close();

    std::cout << "\n#### REPORTE DIARIO ####\n";
    if (max_cant_accesorios == -1) {
        std::cout << "\nNo se han comprado accesorios";
    } else {
        std::cout << "\nEl cliente que mas compro accesorios es: " << nombre_cliente_accesorios;
        std::cout << "\nCon un total de: " << max_cant_accesorios;
        std::cout << "\nTotal de accesorios comprados: " << total_accesorios << "\n";
    }

    if (max_cant_vehiculos == -1) {
        std::cout << "\nNo se han comprado vehiculos";
    } else {
        std::cout << "\nEl cliente que mas compro vehiculos es: "<< nombre_cliente_vehiculos;
        std::cout << "\nCon un total de: "<< max_cant_vehiculos;
        std::cout << "\nTotal de vehiculos comprados: " << total_vehiculos << "\n";
    }

    if (cant_clientes != 0) {
        std::cout << "\nLa venta promedio por cliente es de: " << ventas_totales/cant_clientes << "\n";
    } else {
        std::cout << "\nNo se encuentran ventas registradas\n";
    }  
}

void promedioDeVentas(){
    std::ifstream archivo = archivoClientes();
    std::string linea, valor;
    std::vector<std::string> infoCliente;
    int cant_clientes = 0;
    int ventas_totales = 0;
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        while (std::getline(ss, valor, ',')) {
            infoCliente.push_back(valor);
        }
        cant_clientes++;
        ventas_totales += std::stoi(infoCliente[7]);
        infoCliente.clear();
    }
    archivo.close();
    std::cout << "\n\n#### REPORTE PROMEDIO DE VENTAS ####\n";
    if (cant_clientes != 0) {
        std::cout << "\nLa venta promedio por cliente es de: " << ventas_totales/cant_clientes << "\n";
    } else {
        std::cout << "\nNo se encuentran ventas registradas\n";
    } 
}

void vehiculosComprados(){

    int total_vehiculos = 0;
    int total_accesorios = 0;
    std::ifstream archivo = archivoClientes();
    std::string linea, valor;
    std::vector<std::string> infoCliente;

    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        while (std::getline(ss, valor, ',')) {
            infoCliente.push_back(valor);
        }
        total_accesorios += std::stoi(infoCliente[3]);
        total_vehiculos += std::stoi(infoCliente[2]);
        infoCliente.clear();
        
    }
    archivo.close();

    std::cout << "\n#### REPORTE ARTICULOS COMPRADOS ####\n";
    if (total_accesorios == 0) {
        std::cout << "\nNo se han comprado accesorios";
    } else {
        std::cout << "\nTotal de accesorios comprados: " << total_accesorios << "\n";
    }

    if (total_vehiculos == 0) {
        std::cout << "\nNo se han comprado vehiculos";
    } else {
        std::cout << "\nTotal de vehiculos comprados: " << total_vehiculos << "\n";
    }
}