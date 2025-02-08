// cola_clientes.h
#ifndef COLA_CLIENTES_H
#define COLA_CLIENTES_H

#include <iostream>
#include <string.h>
#include <random>
#include <ctime>
#include <set>
#include <stack>
#include <cstring>
#include <queue>
#include <chrono>
#include <cstdlib>
#include <thread> // Asegúrate de incluir esta cabecera
#include "pila.h"
#include <string>

namespace Tienda {
	struct clientes {
		std:: string nombres;
		std:: string cedula;
		std:: string telefono;
		int carrito_id; // ID del carrito asignado al cliente
	};
}

extern int ReferenciaCliente;

extern Tienda::clientes cliente[6];
extern std::queue<Tienda::clientes> cola_clientes;

extern std::mt19937 rng;
extern std::vector<bool> carritos_llenos;
extern std::vector<bool> carritos_utilizados;
extern std::vector<bool> SeñaldeFuncionamiento;
extern std::uniform_int_distribution<int> tiempo_cliente;
extern std::uniform_int_distribution<int> rangoAleatorio;
extern std::set<int> indices_usados;


// Declaraciones de funciones
void seleccionarDatosAleatorio(std::set<int>& indices_usados);
bool verificarCarritoLleno(int indice_carrito);
void AgregarClienteCola(int indice_carrito);
std::string obtenerNombreAleatorio();
std::string obtenerCedulaAleatoria();
std::string obtenerTelefonoAleatorio();
void AsignacionDatos(int indice_cliente);
int TamanoCola();
int tiempo_aletorio_clientes();
void QuitarClienteCola(int indice_carrito);
#endif // COLA_CLIENTES_H