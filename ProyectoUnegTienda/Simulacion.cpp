#include "Simulacion.h"
#include <iostream>
#include <string.h>
#include <random>
#include <ctime>



using namespace ProyectoUnegTienda;
int indice_aleatorio;

struct productos {
    char nombres[25];
    int precio;
    char descripcion[100];
    int stock;
    int id;
    int vendidos;
};

struct productos articulos[10];

std::mt19937 rng(static_cast<unsigned int>(std::time(0)));
std::uniform_int_distribution<int> cantidad(1, 5); // Rango de números aleatorios
std::uniform_int_distribution<int> distribucion(0, 7);

int numeroaleatorio() {
    return cantidad(rng);
}
const char* seleccionarNombreAleatorio() {
    indice_aleatorio = distribucion(rng);
    return articulos[indice_aleatorio].nombres;
}

void inicializarArticulos() {
    strcpy(articulos[0].nombres, "Harina Pan");
    articulos[0].precio = 50;
    strcpy(articulos[0].descripcion, "Harina de maíz precocida");
    articulos[0].stock = 50;
    articulos[0].id = 1;
    strcpy(articulos[1].nombres, "Arroz Mary");
    articulos[1].precio = 60;
    strcpy(articulos[1].descripcion, "Arroz blanco tipo I");
    articulos[1].stock = 50;
    articulos[1].id = 2;
    strcpy(articulos[2].nombres, "Leche La Campestre");
    articulos[2].precio = 120;
    strcpy(articulos[2].descripcion, "Leche en polvo");
    articulos[2].stock = 50;
    strcpy(articulos[3].nombres, "Champu Elvive");
    articulos[3].precio = 260;
    strcpy(articulos[3].descripcion, "Champu anticaspa");
    articulos[3].stock = 50;
    strcpy(articulos[4].nombres, "Jabon Las llaves");
    articulos[4].precio = 80;
    strcpy(articulos[4].descripcion, "Jabon para lavar");
    articulos[4].stock = 50;
    strcpy(articulos[5].nombres, "Crema dental");
    articulos[5].precio = 60;
    strcpy(articulos[5].descripcion, "Crema para lavarse los dientes");
    articulos[5].stock = 50;
    strcpy(articulos[6].nombres, "Jamon Plumrose");
    articulos[6].precio = 460;
    strcpy(articulos[6].descripcion, "Barra de jamon plumrose 2KL");
    articulos[6].stock = 50;
    strcpy(articulos[7].nombres, "Salchichas Plumrose");
    articulos[7].precio = 230;
    strcpy(articulos[7].descripcion, "Salchichas de pollo 400gr");
    articulos[7].stock = 50;
}

void Simulacion::EmpezarSimulacion()
{
    // Inicializa y empieza el temporizador 
    inicializarArticulos();
    label10->Text = "Cliente: #6\n" + numeroaleatorio() +" "+ gcnew System::String(seleccionarNombreAleatorio()) + "-> precio: "+ articulos[indice_aleatorio].precio + "Bs\n" + numeroaleatorio() +" "+ gcnew System::String(seleccionarNombreAleatorio()) + "-> precio: " + articulos[indice_aleatorio].precio + "Bs\n";
    System::Diagnostics::Debug::WriteLine("Temporizador iniciado.");
}

System::Void Simulacion::Simulacion_Load(System::Object^ sender, System::EventArgs^ e) {
    EmpezarSimulacion(); // Iniciar la simulación al cargar el formulario 
    System::Diagnostics::Debug::WriteLine("Simulacion_Load llamado."); 
}
