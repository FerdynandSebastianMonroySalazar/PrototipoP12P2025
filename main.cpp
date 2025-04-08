//Programa IV Serie parcial II Programacion I Programa de ligas de campeonato fut
//Fecha: 08/04/2025 Lugar: UMG Sede Portales
//Alumno: Ferdynand Sebastian Monroy Salazar carné: 9959-24-14049

#include <iostream>
#include "liga.h"
#include <vector>

int main() {
    std::vector<std::string> nombresLigas = {
        "Liga Nacional",
        "Liga de Ascenso",
        "Liga Segunda Division"
    };

    std::vector<Liga> ligas;
    for (const auto& nombre : nombresLigas) {
        ligas.push_back(Liga(nombre));
    }

    char continuar = 's';
    Liga mejorLigaGlobal("Ninguna");
    float mejorPromedioGlobal = 0.0f;

    while (continuar == 's' || continuar == 'S') {
        //Aqui se generan los datos para las ligas
        for (auto& liga : ligas) {
            liga.generarDatosAleatorios();
        }

        //Se muestran los datos y las estadisticas
        for (const auto& liga : ligas) {
            liga.mostrarDatos();
            std::cout << "\nEstadisticas de " << liga.getNombre() << ":\n";
            std::cout << "Puntuacion mas alta: " << liga.getPuntuacionMasAlta() << "\n";
            std::cout << "Puntuacion mas baja: " << liga.getPuntuacionMasBaja() << "\n";
            std::cout << "Promedio: " << liga.getPromedio() << "\n\n";
        }

        //Se calcula la mejor liga
        Liga mejorLiga = ligas[0];
        for (const auto& liga : ligas) {
            if (liga.getPromedio() > mejorLiga.getPromedio()) {
                mejorLiga = liga;
            }
        }

        std::cout << "\nMEJOR LIGA DE ESTE CAMPEONATO:\n";
        std::cout << "Nombre: " << mejorLiga.getNombre() << "\n";
        std::cout << "Promedio: " << mejorLiga.getPromedio() << "\n\n";

        // Actualizar la mejor liga global
        if (mejorLiga.getPromedio() > mejorPromedioGlobal) {
            mejorPromedioGlobal = mejorLiga.getPromedio();
            mejorLigaGlobal = mejorLiga;
        }

        std::cout << "¿Desea realizar otro campeonato? (s/n): ";
        std::cin >> continuar;
    }

    //Aqui se muestra la mejor liga
    std::cout << "\nMEJOR LIGA DE TODO EL CAMPEONATO:\n";
    std::cout << "Nombre: " << mejorLigaGlobal.getNombre() << "\n";
    std::cout << "Promedio: " << mejorPromedioGlobal << "\n";

    return 0;
}
