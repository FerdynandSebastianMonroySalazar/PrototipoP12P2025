#include "liga.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

Liga::Liga(std::string nombre) : nombre(nombre) {
    //Inicializar los equipos
    equipos = {"Equipo A", "Equipo B", "Equipo C", "Equipo D", "Equipo E"};
    //Numeros aleatorios
    std::srand(std::time(0));
}

std::string Liga::getNombre() const {
    return nombre;
}

std::vector<std::string> Liga::getEquipos() const {
    return equipos;
}

std::vector<std::vector<int>> Liga::getPuntuaciones() const {
    return puntuaciones;
}

void Liga::setNombre(std::string nombre) {
    this->nombre = nombre;
}
    //Tablas creadas
void Liga::generarDatosAleatorios() {
    puntuaciones.clear();
    for (int i = 0; i < 5; ++i) { //5 equipos
        std::vector<int> puntuacionesEquipo;
        for (int j = 0; j < 4; ++j) { //4 años (2020-2023)
            puntuacionesEquipo.push_back(std::rand() % 51); //La puntuacion entre 0-50
        }
        puntuaciones.push_back(puntuacionesEquipo);
    }
}

void Liga::mostrarDatos() const {
    std::cout << "\nDatos de la Liga: " << nombre << "\n";
    std::cout << "Equipo\t2020\t2021\t2022\t2023\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << equipos[i] << "\t";
        for (int j = 0; j < 4; ++j) {
            std::cout << puntuaciones[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

int Liga::getPuntuacionMasAlta() const {
    int max = 0;
    for (const auto& equipo : puntuaciones) {
        for (int puntuacion : equipo) {
            if (puntuacion > max) max = puntuacion;
        }
    }
    return max;
}

int Liga::getPuntuacionMasBaja() const {
    int min = 50;
    for (const auto& equipo : puntuaciones) {
        for (int puntuacion : equipo) {
            if (puntuacion < min) min = puntuacion;
        }
    }
    return min;
}

float Liga::getPromedio() const {
    int total = 0;
    int count = 0;
    for (const auto& equipo : puntuaciones) {
        for (int puntuacion : equipo) {
            total += puntuacion;
            count++;
        }
    }
    return count > 0 ? static_cast<float>(total) / count : 0.0f;
}

