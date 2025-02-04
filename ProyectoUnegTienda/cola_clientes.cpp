#include "cola_clientes.h"
#include "pila.h"

std::vector<bool> carritos_llenos(6, false);
std::vector<bool> carritos_utilizados(6, false);

// Generador de números aleatorios para el tiempo de generación de clientes
std::uniform_int_distribution<int> tiempo_generacion(240, 360); // 4 a 6 minutos

// Función para generar un cliente aleatorio
Tienda::clientes generarClienteAleatorio() {
    Tienda::clientes cliente;
    strcpy_s(cliente.nombres, "Cliente Aleatorio");
    strcpy_s(cliente.cedula, "123456789");
    strcpy_s(cliente.telefono, "04141234567");
    cliente.carrito_id = -1; // Inicialmente sin carrito asignado
    return cliente;
}

// Función para asignar un carrito a un cliente
static bool asignarCarritoACliente(Tienda::clientes& cliente, std::stack<Tienda::productos> carrito[], std::vector<bool>& carritos_utilizados) {
    for (size_t i = 0; i < carritos_utilizados.size(); ++i) {
        if (!carritos_utilizados[i]) {
            // Asignar carrito vacío al cliente y marcarlo como utilizado
            carritos_utilizados[i] = true;
            cliente.carrito_id = static_cast<int>(i); // Guardar el ID del carrito asignado en el cliente
            return true;
        }
    }
    return false; // No hay carritos vacíos disponibles
}


bool verificarCarritoLleno(int indice_carrito) {
    return  carritos_llenos[indice_carrito];
}

void manejarClientes(std::stack<Tienda::productos> carrito[], std::vector<bool>& carritos_utilizados, int total_productos[]) {
    while (true) {
        // Generar un cliente aleatorio
        Tienda::clientes cliente = generarClienteAleatorio();

        // Intentar asignar un carrito al cliente
        if (asignarCarritoACliente(cliente, carrito, carritos_utilizados)) {
            std::cout << "Cliente asignado a un carrito y agregado a la cola." << std::endl;
        }
        else {
            std::cout << "No hay carritos vacíos disponibles para el cliente." << std::endl;
        }

        // Verificar si el carrito del cliente está lleno
        for (int i = 0; i < 6; ++i) {
            if (verificarCarritoLleno(i)) {
                Tienda::cola_clientes.push(cliente);
                std::cout << "Carrito lleno, cliente agregado a la cola." << std::endl;
                break;
            }
        }

        // Esperar un tiempo aleatorio antes de generar el próximo cliente
        std::this_thread::sleep_for(std::chrono::seconds(tiempo_generacion(rng)));
    }
}

