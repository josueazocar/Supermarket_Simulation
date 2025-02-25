#include "cola_clientes.h"
#include "pila.h"
#include "MenuForm.h"
#include <cstdlib> // Para std::rand y std::srand
#include <ctime>   // Para std::time

int indice1;
int indice_random;
int tamano;
int tiempo_generacionMinimo;
int tiempo_generacionMaximo;
int ReferenciaCliente=0;
int tiempoMoverAlfinal;
int NumeroClientesAtendidos = 0;
int NumeroClientesRecibidos = 0;
int NumeroClientesDevueltos = 0; //variables utilizadas como contadores para los reportes

int tiempoCarrito[6] = { 0,0,0,0,0,0 }; //Contiene la cantidad de segundos aleatoria en que el carrito (n) se ejecuta
int CronometroCarrito[6] = { 0,0,0,0,0,0 }; //Cronometriza la cantidad de tiempo en que el carrito esta en ejecuacion hasta que es vaciado
int num_ejecuciones[6] = { 0,0,0,0,0,0 }; //Contiene la cantidad de veces que se ha ejecutado el carrito (n)

std::vector<bool> carritos_llenos(6, false);
std::vector<bool> carritos_utilizados(6, false);
std::vector<bool> SeñaldeFuncionamiento(6, false);
std::vector<bool> clientePagando(6, false);
std::set<int> indices_usados;

// Inicialización de variables globales
Tienda::clientes cliente[6];
std::queue<Tienda::clientes> cola_clientes;


// Generador de números aleatorios para el tiempo de generación de clientes
std::uniform_int_distribution<int> rangoAleatorio(0, 49);


// Función para generar un cliente aleatorio
void seleccionarDatosAleatorio(std::set<int>& indices_usados) {

    if (indices_usados.size() >= 49) {
        indices_usados.clear();  // Reiniciamos el conjunto
    }

    do {
        indice1 = rangoAleatorio(rng);
    } while (indices_usados.find(indice1) != indices_usados.end());
    indices_usados.insert(indice1);
    indice_random = indice1;
}
    std::string obtenerNombreAleatorio() {
        std::string nombres[50] = {
            "Juan Perez", "Maria Gomez", "Carlos Rodriguez", "Ana Torres", "Luis Martinez",
            "Laura Sanchez", "Pedro Diaz", "Sofia Lopez", "Javier Morales", "Isabel Castro",
            "Diego Romero", "Valentina Silva", "Andres Ortega", "Camila Ruiz", "Fernando Jimenez",
            "Gabriela Mendoza", "Ricardo Herrera", "Natalia Vargas", "Samuel Rios", "Lucia Cordero",
            "Alejandro Salazar", "Claudia Paredes", "Miguel Angel Fernandez", "Patricia Leon", "David Castillo",
            "Mariana Salas", "Cristian Soto", "Elena Aguirre", "Hugo Silva", "Silvia Bravo", 
            "Raul Mendez", "Adriana Guzman", "Jose Luis Navarro", "Daniela Rojas", "Roberto Vega",
            "Veronica Medina", "Arturo Delgado", "Carmen Vega", "Oscar Ponce", "Beatriz Campos",
            "Manuel Rivas", "Lorena Miranda", "Francisco Montes", "Alicia Solis", "Guillermo Naranjo",
            "Rosa Maria Delgado", "Enrique Campos", "Teresa Orozco", "Jorge Mendez", "Alejandra Rios"
        };

        return nombres[indice_random];
    }

    std::string obtenerCedulaAleatoria() {
        std::string cedulas[50] = {
          "V-12345678", "V-27654321", "V-23456789", "V-28765432", "V-34567890",
          "V-09876543", "V-15678901", "V-10987654", "V-16789012", "V-21098765",
          "V-27890123", "V-32109876", "V-18901234", "V-13210987", "V-29012345",
          "V-34321098", "V-20123456", "V-15432109", "V-01234567", "V-26543210",
          "V-13579246", "V-24681357", "V-33792468", "V-16813579", "V-37924680",
          "V-18035791", "V-29146802", "V-30257913", "V-31368024", "V-02479135",
          "V-11223344", "V-22334455", "V-33445566", "V-44556677", "V-15667788",
          "V-18778899", "V-17889900", "V-12990011", "V-23001122", "V-07112233",
          "V-10203040", "V-20304050", "V-30405060", "V-40506070", "V-20607080",
          "V-27708090", "V-25809010", "V-10901020", "V-11020304", "V-01020304"
        };

        return cedulas[indice_random];
    }

    std::string obtenerTelefonoAleatorio() {
        std::string telefonos[50] = {
        "0412-1234567", "0414-2345678", "0416-3456789", "0412-9876543", "0414-8765432",
        "0416-7654321", "0412-6543210", "0414-5432109", "0416-4321098", "0412-3210987",
        "0414-2109876", "0416-1098765", "0412-0987654", "0414-9876543", "0416-8765432",
        "0412-7654321", "0414-6543210", "0416-5432109", "0412-4321098", "0414-3210987",
        "0416-2109876", "0412-1098765", "0414-0987654", "0416-9876543", "0412-8765432",
        "0414-7654321", "0416-6543210", "0412-5432109", "0414-4321098", "0416-3210987",
        "0412-1122334", "0414-2233445", "0416-3344556", "0412-4455667", "0414-5566778",
        "0416-6677889", "0412-7788990", "0414-8899001", "0416-9900112", "0412-0011223",
        "0414-1020304", "0416-2030405", "0412-3040506", "0414-4050607", "0416-5060708",
        "0412-6070809", "0414-7080901", "0416-8090102", "0412-9102030", "0414-0102030"
        };
        return telefonos[indice_random];
    }


    void AsignacionDatos(int indice_cliente, System::Windows::Forms::Label^ label) {

        NumeroClientesRecibidos++;
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
    NumeroClientesAtendidos++;
    clientePagando[indice_carrito] = false;
    carritos_llenos[indice_carrito] = false;
    carritos_utilizados[indice_carrito] = false;
    SeñaldeFuncionamiento[indice_carrito] = false;

    if (!verificarCarritoLleno(indice_carrito)) {
        if (!cola_clientes.empty()) {
            cola_clientes.pop();
            std::cout << "Carrito vacio, cliente a salido de la cola." << std::endl;
        }
    }
}

int tiempo_aletorio_clientes(int tiempo_generacionMinimo,int tiempo_generacionMaximo) {
    std::uniform_int_distribution<int> tiempo_clientes(tiempo_generacionMinimo, tiempo_generacionMaximo);
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
    NumeroClientesDevueltos++;
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
        
    


