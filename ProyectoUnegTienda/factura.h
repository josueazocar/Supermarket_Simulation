// factura.h
#pragma once
#ifndef FACTURA_H
#define FACTURA_H

#include "pila.h"
#include <vcclr.h>
#include <Windows.h>
#include <algorithm>
#include <string>
#include <fstream>
#include <msclr/marshal_cppstd.h> // Para conversión de String^ a std::string
#include <stack>
#include "cola_clientes.h"
#include <queue>

extern int total_de_ventas;
extern int id_carrito_factura;
extern std::string stock_mas_bajo;

namespace Factura_Reportes {
    void Crear_reporte_factura(System::Windows::Forms::Label^ label);
    void Mostrar_reportes();
    void EliminarReportesFacturas();
}
void obtener_cliente_en_cola(std::queue<Tienda::clientes>& cola_clientes);
void quitar_total_productos(System::Windows::Forms::Label^ label, int& total_productos, int nro_carrito);
#endif // FACTURA_H

