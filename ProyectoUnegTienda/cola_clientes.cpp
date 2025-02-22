#include "cola_clientes.h"
#include "pila.h"
#include <cstdlib> // Para std::rand y std::srand
#include <ctime>   // Para std::time

int indice1;
int indice_random;
int tamano;
int tiempo_generacionMinimo = 10000; 
int tiempo_generacionMaximo = 20000; 
int ReferenciaCliente=0;
int tiempoMoverAlfinal = 100000;

int tiempoCarrito[6] = { 0,0,0,0,0,0 };
int CronometroCarrito[6] = { 0,0,0,0,0,0 };
int num_ejecuciones[6] = { 0,0,0,0,0,0 };

std::vector<bool> carritos_llenos(6, false);
std::vector<bool> carritos_utilizados(6, false);
std::vector<bool> SeñaldeFuncionamiento(6, false);
std::vector<bool> clientePagando(6, false);
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

    std::string generarColorAleatorio() {
        const char* colores[] = { "Black", "Navy", "DarkGreen", "Maroon", "Purple", "Teal", "Olive", "DarkSlateGray", "DarkRed", "DarkBlue" };
        int num_colores = sizeof(colores) / sizeof(colores[0]);
        int indice = std::rand() % num_colores;
        return colores[indice];
    }

    void AsignacionDatos(int indice_cliente, System::Windows::Forms::Label^ label) {
        seleccionarDatosAleatorio(indices_usados);
        cliente[indice_cliente].nombres = obtenerNombreAleatorio();
        cliente[indice_cliente].cedula = obtenerCedulaAleatoria();
        cliente[indice_cliente].telefono = obtenerTelefonoAleatorio();
		cliente[indice_cliente].carrito_id = indice_cliente;

        if (label) {

            System::Drawing::Color bgColor = label->BackColor;
            cliente[indice_cliente].color = std::to_string(bgColor.ToArgb());

        }

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
    clientePagando[indice_carrito] = false;
    carritos_llenos[indice_carrito] = false;
    carritos_utilizados[indice_carrito] = false;
    SeñaldeFuncionamiento[indice_carrito] == false;

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

void TiempoClienteEnCola (int indice) {

    if (SeñaldeFuncionamiento[indice] == true && clientePagando[indice] == false) {

        num_ejecuciones[indice]++;
        CronometroCarrito[indice] = num_ejecuciones[indice] * tiempoCarrito[indice];
    }
    else {
        num_ejecuciones[indice] = 0;
    }
}

void moverClienteAlFinal(int carrito_id) {
    std::queue<Tienda::clientes> cola_temporal;
    Tienda::clientes cliente_encontrado;
    bool encontrado = false;

    // Buscar el cliente y mover los demás a la cola temporal
    while (!cola_clientes.empty()) {
        Tienda::clientes cliente_actual = cola_clientes.front();
        cola_clientes.pop();

        if (cliente_actual.carrito_id == carrito_id && !encontrado) {
            cliente_encontrado = cliente_actual;
            encontrado = true;
        }
        else {
            cola_temporal.push(cliente_actual);
        }
    }

    // Restaurar la cola original y agregar el cliente al final
    while (!cola_temporal.empty()) {
        cola_clientes.push(cola_temporal.front());
        cola_temporal.pop();
    }

    if (encontrado) {
        cola_clientes.push(cliente_encontrado);
    }
}
void ReiniciarColaClientes() {
    // Reiniciar variables globales
    indice1 = 0;
    indice_random = 0;
    tamano = 0;
    ReferenciaCliente = 0;
    std::fill(std::begin(tiempoCarrito), std::end(tiempoCarrito), 0);
    std::fill(std::begin(CronometroCarrito), std::end(CronometroCarrito), 0);
    std::fill(std::begin(num_ejecuciones), std::end(num_ejecuciones), 0);
    std::fill(std::begin(carritos_llenos), std::end(carritos_llenos), false);
    std::fill(std::begin(carritos_utilizados), std::end(carritos_utilizados), false);
    std::fill(std::begin(SeñaldeFuncionamiento), std::end(SeñaldeFuncionamiento), false);
    std::fill(std::begin(clientePagando), std::end(clientePagando), false);
    indices_usados.clear();
    while (!cola_clientes.empty()) {
        cola_clientes.pop();
    }
}
        
    


