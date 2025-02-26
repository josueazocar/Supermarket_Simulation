// pila.h
#ifndef PILA_H
#define PILA_H

#include <algorithm>
#include <string.h>
#include <random>
#include <ctime>
#include <set>
#include <stack>
#include <cstring>
#include <thread>
#include <chrono>

// Declaracion del Struct para poder almacenar los datos de cada producto
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
void mostrarcarrito(const std::stack<Tienda::productos>& carrito, System::Windows::Forms::Label^ label, int nro_carrito);
int tiempo_aletorio();
int numeroaleatorio();
void inicializarArticulos();
void seleccionar_indice_random(std::set<int>& indices_utilizados);
void agregarProductoAlCarrito(std::stack<Tienda::productos>& carrito, std::set<int>& indices_utilizados, int& total_productos);
bool stock_se_termino();
void mostrar_total_productos(System::Windows::Forms::Label^ label, int& total_productos);
void ReiniciarPila();

// Declaraci�n de variables globales
extern Tienda::productos articulos[10];
extern std::stack<Tienda::productos> carrito[6];
extern std::mt19937 rng;
extern std::uniform_int_distribution<int> cantidad;
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
