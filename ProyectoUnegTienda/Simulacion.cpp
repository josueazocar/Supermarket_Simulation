#include "Simulacion.h"
#include "pila.h"
#include "cola_clientes.h"
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
    contador2 = 0;
    contador3 = 0;
    contador4 = 0;
    contador5 = 0;
    contador6 = 0;
   

    // Configura el primer temporizador
    timer = gcnew System::Windows::Forms::Timer();
    timer->Interval = tiempo_aletorio();
    timer->Tick += gcnew EventHandler(this, &Simulacion::llenado_de_carrito);
    timer->Start();

    // Configura el segundo temporizador con un retraso de 5 segundos
    timer2 = gcnew System::Windows::Forms::Timer();
    timer2->Interval = tiempo_aletorio();
    timer2->Tick += gcnew EventHandler(this, &Simulacion::llenado_de_carrito2);
    timer2->Start();

    // Configura el tercer temporizador con un retraso de 10 segundos
    timer3 = gcnew System::Windows::Forms::Timer();
    timer3->Interval = tiempo_aletorio();
    timer3->Tick += gcnew EventHandler(this, &Simulacion::llenado_de_carrito3);
    timer3->Start();

    // Configura el cuarto temporizador con un retraso de 15 segundos
    timer4 = gcnew System::Windows::Forms::Timer();
    timer4->Interval = tiempo_aletorio();
    timer4->Tick += gcnew EventHandler(this, &Simulacion::llenado_de_carrito4);
    timer4->Start();

    // Configura el quinto temporizador con un retraso de 20 segundos
    timer5 = gcnew System::Windows::Forms::Timer();
    timer5->Interval = tiempo_aletorio(); // 21000 ms = 21 segundos (1 segundo + 20 segundos de retraso)
    timer5->Tick += gcnew EventHandler(this, &Simulacion::llenado_de_carrito5);
    timer5->Start();

    // Configura el sexto temporizador con un retraso de 25 segundos
    timer6 = gcnew System::Windows::Forms::Timer();
    timer6->Interval = tiempo_aletorio();
    timer6->Tick += gcnew EventHandler(this, &Simulacion::llenado_de_carrito6);
    timer6->Start();

    System::Diagnostics::Debug::WriteLine("Temporizadores iniciados.");
}

System::Void Simulacion::Simulacion_Load(System::Object^ sender, System::EventArgs^ e) {
    EmpezarSimulacion(); // Iniciar la simulación al cargar el formulario 
    System::Diagnostics::Debug::WriteLine("Simulacion_Load llamado.");
    this->segundosTranscurridos = 0;
    this->timerCronometro->Start();
}

System::Void Simulacion::llenado_de_carrito(System::Object^ sender, System::EventArgs^ e) {
    if (contador < 10) {
        agregarProductoAlCarrito(carrito[0], indices_utilizados, total_productos[0]);
        mostrarcarrito(carrito[0], label3_2, label3);
        contador++;
    }
    else {
        timer->Stop(); // Detener el temporizador después de 10 iteraciones
        mostrar_total_productos(label3, total_productos[0]);
        carritos_llenos[0] = true;
        
    }
}

System::Void Simulacion::llenado_de_carrito2(System::Object^ sender, System::EventArgs^ e) { 
    if (contador2 < 10) {
        agregarProductoAlCarrito(carrito[1], indices_utilizados2, total_productos[1]);
        mostrarcarrito(carrito[1], label4_2, label4);
        contador2++;
    }
    else {
        timer2->Stop(); // Detener el temporizador después de 10 iteraciones
        mostrar_total_productos(label4, total_productos[1]);
        carritos_llenos[1] = true;
    }
}

System::Void Simulacion::llenado_de_carrito3(System::Object^ sender, System::EventArgs^ e) {
    if (contador3 < 10) {
        agregarProductoAlCarrito(carrito[2], indices_utilizados3, total_productos[2]);
        mostrarcarrito(carrito[2], label5_2, label5);
        contador3++;
    }
    else {
        timer3->Stop(); // Detener el temporizador después de 10 iteraciones
        mostrar_total_productos(label5, total_productos[2]);
        carritos_llenos[2] = true;
    }
}

System::Void Simulacion::llenado_de_carrito4(System::Object^ sender, System::EventArgs^ e) {
    if (contador4 < 10) {
        agregarProductoAlCarrito(carrito[3], indices_utilizados4, total_productos[3]);
        mostrarcarrito(carrito[3], label2_2, label2);
        contador4++;
    }
    else {
        timer4->Stop(); // Detener el temporizador después de 10 iteraciones
        mostrar_total_productos(label2, total_productos[3]);
        carritos_llenos[3] = true;
    }
}

System::Void Simulacion::llenado_de_carrito5(System::Object^ sender, System::EventArgs^ e) {
    if (contador5 < 10) {
        agregarProductoAlCarrito(carrito[4], indices_utilizados5, total_productos[4]);
        mostrarcarrito(carrito[4], label7_2, label7);
        contador5++;
    }
    else {
        timer5->Stop(); // Detener el temporizador después de 10 iteraciones
        mostrar_total_productos(label7, total_productos[4]);
        carritos_llenos[4] = true;
    }
}

System::Void Simulacion::llenado_de_carrito6(System::Object^ sender, System::EventArgs^ e) {
    if (contador6 < 10) {
        agregarProductoAlCarrito(carrito[5], indices_utilizados6, total_productos[5]);
        mostrarcarrito(carrito[5], label10_2, label10);
        contador6++;
    }
    else {
        timer6->Stop(); // Detener el temporizador después de 10 iteraciones
        mostrar_total_productos(label10, total_productos[5]);
        carritos_llenos[5] = true;
    }
}
