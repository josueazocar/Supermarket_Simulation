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
    contador2 = 0;
    contador3 = 0;
    contador4 = 0;
    contador5 = 0;
    contador6 = 0;
   

    // Configura el primer temporizador
    timer = gcnew System::Windows::Forms::Timer();
    timer->Interval = 1000; // 1000 ms = 1 segundo
    timer->Tick += gcnew EventHandler(this, &Simulacion::OnTimedEvent);
    timer->Start();

    // Configura el segundo temporizador
    timer2 = gcnew System::Windows::Forms::Timer();
    timer2->Interval = 1000; // 1000 ms = 1 segundo
    timer2->Tick += gcnew EventHandler(this, &Simulacion::OnTimedEvent2);
    timer2->Start();

    // Configura el segundo temporizador
    timer3 = gcnew System::Windows::Forms::Timer();
    timer3->Interval = 1000; // 1000 ms = 1 segundo
    timer3->Tick += gcnew EventHandler(this, &Simulacion::OnTimedEvent3);
    timer3->Start();

    // Configura el segundo temporizador
    timer4 = gcnew System::Windows::Forms::Timer();
    timer4->Interval = 1000; // 1000 ms = 1 segundo
    timer4->Tick += gcnew EventHandler(this, &Simulacion::OnTimedEvent4);
    timer4->Start();

    // Configura el segundo temporizador
    timer5 = gcnew System::Windows::Forms::Timer();
    timer5->Interval = 1000; // 1000 ms = 1 segundo
    timer5->Tick += gcnew EventHandler(this, &Simulacion::OnTimedEvent5);
    timer5->Start();

    // Configura el segundo temporizador
    timer6 = gcnew System::Windows::Forms::Timer();
    timer6->Interval = 1000; // 1000 ms = 1 segundo
    timer6->Tick += gcnew EventHandler(this, &Simulacion::OnTimedEvent6);
    timer6->Start();

    System::Diagnostics::Debug::WriteLine("Temporizadores iniciados.");
}

System::Void Simulacion::Simulacion_Load(System::Object^ sender, System::EventArgs^ e) {
    EmpezarSimulacion(); // Iniciar la simulación al cargar el formulario 
    System::Diagnostics::Debug::WriteLine("Simulacion_Load llamado.");
}

System::Void Simulacion::OnTimedEvent(System::Object^ sender, System::EventArgs^ e) {
    if (contador < 10) {
        agregarProductoAlCarrito(carrito, indices_utilizados, total_productos[0]);
        mostrarcarrito(carrito, label10_2, label10);
        contador++;
    }
    else {
        timer->Stop(); // Detener el temporizador después de 10 iteraciones
        mostrar_total_productos(label10, total_productos[0]);
    }
}

System::Void Simulacion::OnTimedEvent2(System::Object^ sender, System::EventArgs^ e) {
    if (contador2 < 10) {
        agregarProductoAlCarrito(carrito2, indices_utilizados2, total_productos[1]);
        mostrarcarrito(carrito2, label3_2, label3);
        contador2++;
    }
    else {
        timer2->Stop(); // Detener el temporizador después de 10 iteraciones
        mostrar_total_productos(label3, total_productos[1]);
    }
}

System::Void Simulacion::OnTimedEvent3(System::Object^ sender, System::EventArgs^ e) {
    if (contador3 < 10) {
        agregarProductoAlCarrito(carrito3, indices_utilizados3, total_productos[2]);
        mostrarcarrito(carrito3, label4_2, label4);
        contador3++;
    }
    else {
        timer3->Stop(); // Detener el temporizador después de 10 iteraciones
        mostrar_total_productos(label4, total_productos[2]);
    }
}

System::Void Simulacion::OnTimedEvent4(System::Object^ sender, System::EventArgs^ e) {
    if (contador4 < 10) {
        agregarProductoAlCarrito(carrito4, indices_utilizados4, total_productos[3]);
        mostrarcarrito(carrito4, label5_2, label5);
        contador4++;
    }
    else {
        timer4->Stop(); // Detener el temporizador después de 10 iteraciones
        mostrar_total_productos(label5, total_productos[3]);
    }
}

System::Void Simulacion::OnTimedEvent5(System::Object^ sender, System::EventArgs^ e) {
    if (contador5 < 10) {
        agregarProductoAlCarrito(carrito5, indices_utilizados5, total_productos[4]);
        mostrarcarrito(carrito5, label2_2, label2);
        contador5++;
    }
    else {
        timer5->Stop(); // Detener el temporizador después de 10 iteraciones
        mostrar_total_productos(label2, total_productos[4]);
    }
}

System::Void Simulacion::OnTimedEvent6(System::Object^ sender, System::EventArgs^ e) {
    if (contador6 < 10) {
        agregarProductoAlCarrito(carrito6, indices_utilizados6, total_productos[5]);
        mostrarcarrito(carrito6, label7_2, label7);
        contador6++;
    }
    else {
        timer6->Stop(); // Detener el temporizador después de 10 iteraciones
        mostrar_total_productos(label7, total_productos[5]);
    }
}
