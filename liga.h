#ifndef LIGA_H
#define LIGA_H

#include <string>
#include <vector>

class Liga {
private:
    std::string nombre;
    std::vector<std::string> equipos;
    std::vector<std::vector<int>> puntuaciones; //Puntuaciones por año [2020-2023]

public:
    //Constructor
    Liga(std::string nombre);

    //Aqui se muestra la implementacion de los getters
    std::string getNombre() const;
    std::vector<std::string> getEquipos() const;
    std::vector<std::vector<int>> getPuntuaciones() const;

    //Aqui se muestra la implementacion de los setters
    void setNombre(std::string nombre);

   //Metodos
    void generarDatosAleatorios();
    void mostrarDatos() const;
    int getPuntuacionMasAlta() const;
    int getPuntuacionMasBaja() const;
    float getPromedio() const;
};

#endif // LIGA_H
