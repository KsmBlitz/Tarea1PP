#include "venta.h"


venta::venta(){
}


void venta::setRun(std::string vrun){
    this->run = vrun;
}
void venta::setNombre(std::string vnombre){
    this->nombre = vnombre;
}


int venta::calcularValorTotalVehiculos(){
    int total = 0;
    for (vehiculo* vehiculo_actual : this->listaVehiculos){
        total += vehiculo_actual->calcular_valor_total();
    }
    return total;
}
int venta::calcularValorTotalAccesorios(){
    int total = 0;
    for (accesorio* accesorio_actual : this->listaAccesorios){
        total += accesorio_actual->calcular_valor_total();
    }
    return total;
}
int venta::calcularValorDescuentoVehiculos(){
    return this->totalVehiculos - (this->totalVehiculos*this->descuento);
}

int venta::calcularCantidadTotalVehiculos(){
    int total = 0;
    for (vehiculo* vehiculo_actual : this->listaVehiculos){
        total += vehiculo_actual->getUnidades();
    }
    return total;
}
int venta::calcularCantidadTotalAccesorios(){
    int total = 0;
    for (accesorio* accesorio_actual : this->listaAccesorios){
        total += accesorio_actual->getUnidades();
    }
    return total;
}


double venta::calcularDescuento(){
    int unidades = 0;
    for (vehiculo* vehiculo_actual : this->listaVehiculos){
        unidades += vehiculo_actual->getUnidades();
    }
    if (unidades > 10000) {
        return 0.1;
    } else if (unidades >= 5000) {
        return 0.05;
    } else if (unidades >= 1000) {
        return 0.03;
    } else {
        return 0.01;
    }
}


void venta::agregar_vehiculo(vehiculo* vehiculo){
    this->listaVehiculos.push_back(vehiculo);
}
void venta::agregar_accesorio(accesorio* accesorio){
    this->listaAccesorios.push_back(accesorio);
}


int venta::creacionVehiculo(int opcion, std::string marca, std::string remoto, int unidades){
    vehiculo* vehiculo_a_comprar = nullptr;
    int confirmacion = 0;
    if (opcion == 1) {
        vehiculo_a_comprar = new automovil(marca, remoto, 2024, unidades);
    }else if (opcion == 2) {
        vehiculo_a_comprar = new moto(marca, remoto, 2024, unidades);
    }else {
        vehiculo_a_comprar = new camion(marca, remoto, 2024, unidades);
    }

    do {
        vehiculo_a_comprar->mostrarse();
        std::cout << "\n\nEsta informacion es correcta?\n"<<"1.si\n2.no";
        std::cout << "\nOpcion: ";
        std::cin >> confirmacion;
        if (confirmacion != 1 && confirmacion != 2) {
            std::cout << "\n\nFavor de seleccionar una opcion valida";
            confirmacion = 0;
        }
    } while (confirmacion == 0);

    if (confirmacion == 1) {
        this->agregar_vehiculo(vehiculo_a_comprar);
        return 1;
    } else {
        return 0;
    }
}
void venta::menuVentaVehiculo(){
    //Parte de la creacion de menu y muestra de valores
    std::map<std::string,int> valores;
    std::string tipoVehiculo;
    int opcion;
    do {
        std::cout << "\n Que vehiculo desea comprar?\n" << "1. Auto\n2. Moto\n3. Camion";
        std::cout << "\n Opcion: ";
        std::cin >> opcion;
        switch (opcion) {
        case 1:
            valores = cargar_valores_autos();
            tipoVehiculo = "Autos";
            break;
        case 2:
            valores = cargar_valores_motos();
            tipoVehiculo = "Motos";
            break;
        case 3:
            valores = cargar_valores_camiones();
            tipoVehiculo = "Camiones";  
            break;
        default:
            std::cout << "\nFAVOR DE SELECCIONAR UN VALOR ADECUADO (1, 2 o 3)\n";
            opcion = 0;
            break;
        }
    } while (opcion == 0);
    
    
    //Proceso seleccion de vehiculo
    int confirmacion = 0;
    do {
        //Seleccion de marca del vehiculo
        std::cout << "\n\n Valores de "<< tipoVehiculo << " por Marca: \n";
        mostrarPrecios(valores);
        std::string marca = "";

        do {
            std::cout << "\nEscriba la marca a comprar: ";
            std::cin >> marca;
            if (!enStock(valores, marca)){
                std::cout << "\n\nFavor de escoger una marca dentro de nuestro stock\n\n";
                marca = "";
            } 
        } while (marca == "");
    
        //Seleccion de las unidades del vehiculo
        int unidades = 0;
        do {
            std::cout << "\nCuantas unidades de "<< tipoVehiculo << " " << marca << " quiere?";
            std::cout << "\nunidades: ";
            std::cin >> unidades;
            if (unidades <= 0) {
                std::cout << "\n\nFavor escoger una cantidad valida\n\n";
                unidades = 0;
            }
        } while (unidades <= 0);
        
        //Seleccion control remoto del vehiculo
        int remoto = 0;
        do {
            std::cout << "\nDesea su vehiculo a control remoto?" <<"\n1.si\n2.no";
            std::cout << "\nOpcion: ";
            std::cin >> remoto;
            if (remoto != 1 && remoto != 2) {
                std::cout << "\n\nFavor escoger una opcion valida\n\n";
                remoto = 0;
            }
        } while (remoto == 0);
        std::string strremoto = "";
        if (remoto == 1) {
            strremoto = "si";
        } else {
            strremoto = "no";
        }
        
        confirmacion = this->creacionVehiculo(opcion, marca, strremoto, unidades);

    } while (confirmacion == 0);

    std::cout << "\nSe ha agregado exitosamente el vehiculo a la lista";
    
    
    this->opcionAContinuacion();
}


void venta::opcionAContinuacion(){
    int opcion = 0;
    do {
        std::cout <<"\n\nQue desea hacer a continuacion\n" << "1.Comprar otro vehiculo\n2.Comprar accesorios\n3.Finalizar compra";
        std::cout <<"\nOpcion: ";
        std::cin >> opcion;
        if (opcion != 1 && opcion != 2 && opcion != 3) {
            std::cout << "\n\nFavor de escoger un valor valido\n\n";
            opcion = 0;
        }
    } while (opcion == 0);

    switch (opcion) {
    case 1:
        this->menuVentaVehiculo();
        break;
    
    case 2:
        this->menuVentaAccesorio();
        break;
    case 3:
        this->finalizarCompra();
        break;
    
    default:
        break;
    }

}


void venta::menuVentaAccesorio(){
    std::map<std::string,int> valores = cargar_valores_accesorios();
    accesorio* accesorio_actual = nullptr;
    //Menu de seleccion accesorio
    int confirmacion = 2;
    do {
        //Menu de nombre de accesorio
        
        std::string nombre_accesorio = "";
        do {
            std::cout << "\n";
            mostrarPrecios(valores);
            std::cout << "\nIngrese el nombre del accesorio a comprar: ";
            std::cin >> nombre_accesorio;
            if (!enStock(valores, nombre_accesorio)){
                std::cout << "\n\nFAVOR SELECCIONAR UN PRODUCTO VALIDO\n\n";
                nombre_accesorio = "";
            }
        } while (nombre_accesorio== "");

        //Menu de seleccion unidades
        int unidades = 0;
        do {
            std::cout << "\nCuantas unidades de "<< nombre_accesorio <<" quiere?";
            std::cout << "\nunidades: ";
            std::cin >> unidades;
            if (unidades <= 0) {
                std::cout << "\n\nFavor escoger una cantidad valida\n\n";
                unidades = 0;
            }
        } while (unidades <= 0);

        accesorio_actual = new accesorio(nombre_accesorio, unidades);

        //Menu de confirmacion
        do {
            accesorio_actual->mostrarse();  
            std::cout << "\n\nEsta informacion es correcta?\n1.si\n2.no\nopcion: ";
            std::cin >> confirmacion;
            if (confirmacion != 1 && confirmacion != 2){
                std::cout << "\n\nFAVOR DE SELECCIONAR UNA OPCION VALIDA\n\n";
                confirmacion = 0;
            }
        } while (confirmacion == 0);

    } while (confirmacion == 2);

    this->agregar_accesorio(accesorio_actual);
    std::cout << "\nSe ha agregado exitosamente un accesorio a la lista\n";
    this->opcionAContinuacion();
}


void venta::finalizarCompra(){
    std::string run;
    std::string nombre;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nIngrese nombre del cliente: ";
    std::getline(std::cin, nombre);
    this->setNombre(nombre);
    std::cout << "\nIngrese run cliente: ";
    std::getline(std::cin,run);
    this->setRun(run);

    this->imprimirArchivo(); 
}


void venta::actualizarInformacion(){
    this->totalVehiculos = this->calcularValorTotalVehiculos();
    this->totalAccesorios = this->calcularValorTotalAccesorios();
    this->cantidadVehiculos = this->calcularCantidadTotalVehiculos();
    this->cantidadAccesorios = this->calcularCantidadTotalAccesorios();
    this->descuento = this->calcularDescuento();
    this->totalVenta = this->totalAccesorios + this->calcularValorDescuentoVehiculos();
}


void venta::imprimirArchivo(){
    this->actualizarInformacion();
    std::ofstream archivo("Clientes.txt",std::ios::app);
    archivo << std::endl;
    archivo << this->nombre << ", ";
    archivo << this->run << ", "; 
    archivo << this->cantidadVehiculos << ", "; 
    archivo << this->cantidadAccesorios << ", ";
    archivo << this->totalVehiculos << ", ";
    archivo << this->totalAccesorios << ", ";
    archivo << this->calcularValorDescuentoVehiculos() << ", ";
    archivo << this->totalVenta;
    archivo.close();
    std::cout << "\n\nBoleta emitida exitosamete\n\n";
    this->limpiarBoleta();
}


void venta::limpiarBoleta(){
    this->nombre = "";
    this->run = "";
    for (accesorio* accesorio_actual : this->listaAccesorios){
        delete accesorio_actual;
    }
    for (vehiculo* vehiculo_actual : this->listaVehiculos){
        delete vehiculo_actual;
    }
    this->listaAccesorios.clear();
    this->listaVehiculos.clear();
    this->totalVehiculos = 0;
    this->totalAccesorios = 0;
    this->cantidadVehiculos = 0;
    this->cantidadAccesorios = 0;
    this->descuento = 0;
    this->totalVenta = 0;
}