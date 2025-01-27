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
		int cantidad;
    };
}

// Declaraciones de funciones
int tiempo_aletorio();
int numeroaleatorio();
int numeroaleatorio_for();
const char* seleccionarNombreAleatorio(std::set<int>& indices_utilizados);
void inicializarArticulos();
void seleccionar_indice_random(std::set<int>& indices_utilizados);
void agregarProductoAlCarrito(std::stack<Tienda::productos>& carrito, std::set<int>& indices_utilizados, int& total_productos);
void mostrarcarrito(std::stack<Tienda::productos>& carrito, System::Windows::Forms::Label^ label_2, System::Windows::Forms::Label^ label);
void mostrar_total_productos(System::Windows::Forms::Label^ label, int& total_productos);

// Declaración de variables globales
extern Tienda::productos articulos[10];
extern std::stack<Tienda::productos> carrito;
extern std::stack<Tienda::productos> carrito2;
extern std::stack<Tienda::productos> carrito3;
extern std::stack<Tienda::productos> carrito4;
extern std::stack<Tienda::productos> carrito5;
extern std::stack<Tienda::productos> carrito6;
extern std::mt19937 rng;
extern std::uniform_int_distribution<int> cantidad;
extern std::uniform_int_distribution<int> cantidad_for;
extern std::uniform_int_distribution<int> distribucion;
extern std::uniform_int_distribution<int> tiempo_seleccion;
extern std::set<int> indices_utilizados;
extern std::set<int> indices_utilizados2;
extern std::set<int> indices_utilizados3;
extern std::set<int> indices_utilizados4;
extern std::set<int> indices_utilizados5;
extern std::set<int> indices_utilizados6;
extern int total_productos[6];
#endif // PILA_H
