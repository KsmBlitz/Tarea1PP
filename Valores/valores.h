#ifndef VALORES_H
#define VALORES_H

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

std::map<std::string, int> cargar_valores(std::string filename);

std::map<std::string, int> cargar_valores_autos();

std::map<std::string, int> cargar_valores_motos();

std::map<std::string, int> cargar_valores_camiones();

std::map<std::string, int> cargar_valores_accesorios();

void mostrarPreciosVehiculos();

void mostrarPreciosAccesorios();

#endif