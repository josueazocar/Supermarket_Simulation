// factura.h
#ifndef FACTURA_H
#define FACTURA_H

#include "pila.h"
#include <stack>
#include "cola_clientes.h"
#include <queue>

extern int id_carrito_factura;

void obtener_cliente_en_cola(std::queue<Tienda::clientes>& cola_clientes);
void quitar_total_productos(System::Windows::Forms::Label^ label, int& total_productos, int nro_carrito);



#endif // FACTURA_H

