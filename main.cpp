//Clases
#include "Clases\venta.h"


int main(){
    venta* boleta = new venta();
    int opcion;
    while(true){
        std::cout << "\nMenu Principal:\n";
        std::cout << "1. Venta de Vehiculos\n";
        std::cout << "2. Venta de Accesorios\n";
        std::cout << "3. Promedio de Ventas\n";
        std::cout << "4. Cantidad de Vehiculos Comprados\n";
        std::cout << "5. Salir\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            boleta->menuVentaVehiculo();
            break;
        case 2:
            boleta->menuVentaAccesorio();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            std::cout << "\nSaliendo del programa...";
            return 0;
        default:
            std::cout << "\nOpcion invalida. Intente nuevamente.";
        }
    }

    return 0;
}