// pila.h
#ifndef PILA_H
#define PILA_H

#include <iostream>
#include <string.h>
#include <random>
#include <ctime>
#include <set>
#include <stack>
#include <cstring>

namespace Tienda {
    struct productos {
        char nombres[25];
        int precio;
        char descripcion[100];
        int stock;
        int id;
        int vendidos;
    };
}

// Declaraciones de funciones
int numeroaleatorio();
int numeroaleatorio_for();
const char* seleccionarNombreAleatorio(std::set<int>& indices_utilizados);
void inicializarArticulos();
void seleccionar_indice_random(std::set<int>& indices_utilizados);
void agregarProductoAlCarrito();
void mostrarcarrito(std::stack<Tienda::productos>& carrito, System::Windows::Forms::Label^ label10_2, System::Windows::Forms::Label^ label10);

// Declaración de variables globales
extern Tienda::productos articulos[10];
extern std::stack<Tienda::productos> carrito;
extern std::mt19937 rng;
extern std::uniform_int_distribution<int> cantidad;
extern std::uniform_int_distribution<int> cantidad_for;
extern std::uniform_int_distribution<int> distribucion;

#endif // PILA_H
