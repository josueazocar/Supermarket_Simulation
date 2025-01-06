#pragma once
#include <iostream>
#include <string>
#include "Simulacion.h"

using namespace std;
using namespace ProyectoUnegTienda;

class cliente {

private:
    string nombre;
    Simulacion^ simulacion;

public:
    cliente(string nombre, Simulacion^ simulacion) {
        this->nombre = nombre;
        this->simulacion = simulacion;
    }

    ~cliente() {

    }

    string getNombre() {
        return nombre;
    }

    void saludar() {
        String^ mensaje = gcnew String(("Hola, " + nombre + "!").c_str());
        simulacion->ActualizarTexto(mensaje);
    }
};