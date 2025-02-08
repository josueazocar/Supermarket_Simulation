#include "factura.h"

int id_carrito_factura;

void obtener_cliente_en_cola(std::queue<Tienda::clientes>& cola_clientes) {
    if (!cola_clientes.empty()) {
        id_carrito_factura = cola_clientes.front().carrito_id;
    }
}

void quitar_total_productos(System::Windows::Forms::Label^ label, int& total_productos, int nro_carrito) {
    label->Text = "Carrito #" + nro_carrito + "\n";
    total_productos = 0;
}
