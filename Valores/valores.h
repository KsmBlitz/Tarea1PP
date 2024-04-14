#ifndef VALORES_H
#define VALORES_H


#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>

std::map<std::string, int> cargar_valores(std::string filename);

std::map<std::string, int> cargar_valores_autos();

std::map<std::string, int> cargar_valores_motos();

std::map<std::string, int> cargar_valores_camiones();

std::map<std::string, int> cargar_valores_accesorios();

bool enStock(std::map<std::string, int> valores, std::string marca);

void mostrarPrecios(std::map<std::string,int> valores);


#endif