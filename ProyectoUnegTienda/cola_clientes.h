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
#include <thread> // Asegúrate de incluir esta cabecera

namespace Tienda {
	struct clientes {
		char nombres[25];
		char cedula[10];
		char telefono[11];
		int carrito_id; // ID del carrito asignado al cliente
	};
	static std::queue<clientes> cola_clientes;
}




extern std::vector<bool> carritos_llenos;
extern std::vector<bool> carritos_utilizados;

// Declaraciones de funciones


#endif // COLA_CLIENTES_H