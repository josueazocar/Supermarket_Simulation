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
		std:: string color;
		int carrito_id; // ID del carrito asignado al cliente
	};
}

extern int ReferenciaCliente;
extern int tiempoCarrito[6];
extern int CronometroCarrito[6];
extern int num_ejecuciones[6];
extern int tiempoMoverAlfinal;

extern Tienda::clientes cliente[6];
extern std::queue<Tienda::clientes> cola_clientes;

extern std::mt19937 rng;
extern std::vector<bool> carritos_llenos;
extern std::vector<bool> clientePagando;
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
void ReiniciarColaClientes();
void AsignacionDatos(int indice_cliente, System::Windows::Forms::Label^ label);
int TamanoCola();
int tiempo_aletorio_clientes();
void QuitarClienteCola(int indice_carrito);
void TiempoClienteEnCola(int indice);
void moverClienteAlFinal(int carrito_id);

#endif // COLA_CLIENTES_H