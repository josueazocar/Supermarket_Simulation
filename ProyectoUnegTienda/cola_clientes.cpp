#include "cola_clientes.h"
#include "pila.h"

int indice1;
int indice_random;
int tamano;
int tiempo_generacionMinimo = 10000; //tiempo en segundos
int tiempo_generacionMaximo = 20000; //tiempo en segundos
int ReferenciaCliente=0;
std::vector<bool> carritos_llenos(6, false);
std::vector<bool> carritos_utilizados(6, false);
std::vector<bool> SeñaldeFuncionamiento(6, false);

std::set<int> indices_usados;

// Inicialización de variables globales
Tienda::clientes cliente[6];
std::queue<Tienda::clientes> cola_clientes;


// Generador de números aleatorios para el tiempo de generación de clientes
std::uniform_int_distribution<int> tiempo_clientes(tiempo_generacionMinimo, tiempo_generacionMaximo); // intervalo minimo y maximo para la generacion de clientes
std::uniform_int_distribution<int> rangoAleatorio(0, 29);


// Función para generar un cliente aleatorio
void seleccionarDatosAleatorio(std::set<int>& indices_usados) {
    do {
        indice1 = rangoAleatorio(rng);
    } while (indices_usados.find(indice1) != indices_usados.end());
    indices_usados.insert(indice1);
    indice_random = indice1;
}
    std::string obtenerNombreAleatorio() {
        std::string nombres[30] = {
            "Juan Pérez", "María Gómez", "Carlos Rodríguez", "Ana Torres", "Luis Martínez",
            "Laura Sánchez", "Pedro Díaz", "Sofía López", "Javier Morales", "Isabel Castro",
            "Diego Romero", "Valentina Silva", "Andrés Ortega", "Camila Ruiz", "Fernando Jiménez",
            "Gabriela Mendoza", "Ricardo Herrera", "Natalia Vargas", "Samuel Ríos", "Lucía Cordero",
            "Alejandro Salazar", "Claudia Paredes", "Miguel Ángel Fernández", "Patricia León", "David Castillo",
            "Mariana Salas", "Cristian Soto", "Elena Aguirre", "Hugo Peña", "Silvia Bravo"
        };

        return nombres[indice_random];
    }

    std::string obtenerCedulaAleatoria() {
        std::string cedulas[30] = {
            "V-12345678", "V-87654321", "V-23456789", "V-98765432", "V-34567890",
            "V-09876543", "V-45678901", "V-10987654", "V-56789012", "V-21098765",
            "V-67890123", "V-32109876", "V-78901234", "V-43210987", "V-89012345",
            "V-54321098", "V-90123456", "V-65432109", "V-01234567", "V-76543210",
            "V-13579246", "V-24681357", "V-35792468", "V-46813579", "V-57924680",
            "V-68035791", "V-79146802", "V-80257913", "V-91368024", "V-02479135"
        };

        return cedulas[indice_random];
    }

    std::string obtenerTelefonoAleatorio() {
        std::string telefonos[30] = {
            "0412-1234567", "0414-2345678", "0416-3456789", "0412-9876543", "0414-8765432",
            "0416-7654321", "0412-6543210", "0414-5432109", "0416-4321098", "0412-3210987",
            "0414-2109876", "0416-1098765", "0412-0987654", "0414-9876543", "0416-8765432",
            "0412-7654321", "0414-6543210", "0416-5432109", "0412-4321098", "0414-3210987",
            "0416-2109876", "0412-1098765", "0414-0987654", "0416-9876543", "0412-8765432",
            "0414-7654321", "0416-6543210", "0412-5432109", "0414-4321098", "0416-3210987"
        };
        return telefonos[indice_random];
    }

    void AsignacionDatos(int indice_cliente) {
        seleccionarDatosAleatorio(indices_usados);
        cliente[indice_cliente].nombres = obtenerNombreAleatorio();
        cliente[indice_cliente].cedula = obtenerCedulaAleatoria();
        cliente[indice_cliente].telefono = obtenerTelefonoAleatorio();
		cliente[indice_cliente].carrito_id = indice_cliente;
    }

   int TamanoCola() {

       tamano = cola_clientes.size();
       return tamano;
    }

bool verificarCarritoLleno(int indice_carrito) {
    return  carritos_llenos[indice_carrito];
}

void AgregarClienteCola(int indice_carrito) {
            if (verificarCarritoLleno(indice_carrito)) {
                cola_clientes.push(cliente[indice_carrito]);
                std::cout << "Carrito lleno, cliente agregado a la cola." << std::endl;
            }
}

void QuitarClienteCola(int indice_carrito) {
    if (!verificarCarritoLleno(indice_carrito)) {
        if (!cola_clientes.empty()) {
            cola_clientes.pop();
            std::cout << "Carrito vacio, cliente a salido de la cola." << std::endl;
        }
    }
}

int tiempo_aletorio_clientes() {
    return tiempo_clientes(rng);
}



        
    


