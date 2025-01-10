#include "Simulacion.h"
#include "pila.h"
#include <iostream>
#include <string.h>
#include <random>
#include <ctime>
#include <set>
#include <cstring>


using namespace ProyectoUnegTienda;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


void Simulacion::EmpezarSimulacion()
{
    // Inicializa y empieza el temporizador 
    inicializarArticulos();

    // Inicializa el contador
    contador = 0;

    // Configura el temporizador
    timer = gcnew System::Windows::Forms::Timer();
    timer->Interval = 1000; // 1000 ms = 1 segundo
    timer->Tick += gcnew EventHandler(this, &Simulacion::OnTimedEvent);
    timer->Start();


   /* std::set<int> indices_utilizados;
        for (int i=1;i<=10;i++) {
        label10_2->Text = numeroaleatorio() + " " + gcnew System::String(seleccionarNombreAleatorio(indices_utilizados)) + "-> precio: " + articulos[indice_aleatorio].precio + "Bs\n";
        label10->Text=label10->Text+label10_2->Text;
        }
*/

    System::Diagnostics::Debug::WriteLine("Temporizador iniciado.");
}

System::Void Simulacion::Simulacion_Load(System::Object^ sender, System::EventArgs^ e) {
    EmpezarSimulacion(); // Iniciar la simulación al cargar el formulario 
    System::Diagnostics::Debug::WriteLine("Simulacion_Load llamado."); 
}

System::Void Simulacion::OnTimedEvent(System::Object^ sender, System::EventArgs^ e) {
    if (contador < 10) {
        agregarProductoAlCarrito();
        mostrarcarrito(carrito, label10_2, label10);
        contador++;
    }
    else {
        timer->Stop(); // Detener el temporizador después de 10 iteraciones
    }
}