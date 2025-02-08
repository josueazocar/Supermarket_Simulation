#include "Simulacion.h"
#include "pila.h"
#include "cola_clientes.h"
#include <iostream>
#include <string.h>
#include <random>
#include <ctime>
#include <set>
#include <cstring>
#include "factura.h"
#include <string>
#include <msclr/marshal_cppstd.h> // Para la conversión entre std::string y System::String

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
    contador7 = 0;
    Precio_total = 0;

    timer_creacion_factura = gcnew System::Windows::Forms::Timer();
    timer_creacion_factura->Interval = 2000;
    timer_creacion_factura->Tick += gcnew EventHandler(this, &Simulacion::Creacion_de_factura);
    timer_creacion_factura->Start();

    // Configura el primer temporizador
    timer = gcnew System::Windows::Forms::Timer();
    timer->Interval = tiempo_aletorio();
    timer->Tick += gcnew EventHandler(this, &Simulacion::llenado_de_carrito);
   // timer->Tick += gcnew EventHandler(this, &Simulacion::Creacion_de_factura);
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

    timer_gestion_de_clientes = gcnew System::Windows::Forms::Timer();
    timer_gestion_de_clientes->Interval = tiempo_aletorio_clientes();
    timer_gestion_de_clientes->Tick += gcnew EventHandler(this, &Simulacion::GestionarClientes);
    timer_gestion_de_clientes->Start();

    System::Diagnostics::Debug::WriteLine("Temporizadores iniciados.");
}

System::Void Simulacion::Simulacion_Load(System::Object^ sender, System::EventArgs^ e) {
    EmpezarSimulacion(); // Iniciar la simulación al cargar el formulario 
    System::Diagnostics::Debug::WriteLine("Simulacion_Load llamado.");
    this->segundosTranscurridos = 0;
    this->timerCronometro->Start();
}

System::Void Simulacion::GestionarClientes(System::Object^ sender, System::EventArgs^ e) {

    if (carritos_utilizados[0] == false) {
        SeñaldeFuncionamiento[0] = true;
    }
    else
        if (carritos_utilizados[1] == false) {
            SeñaldeFuncionamiento[1] = true;
        }
        else
            if (carritos_utilizados[2] == false) {
                SeñaldeFuncionamiento[2] = true;
            }
            else
                if (carritos_utilizados[3] == false) {
                    SeñaldeFuncionamiento[3] = true;
                }
                else
                    if (carritos_utilizados[4] == false) {
                        SeñaldeFuncionamiento[4] = true;
                    }
                    else
                        if (carritos_utilizados[5] == false) {
                            SeñaldeFuncionamiento[5] = true;
                        }


}



    System::Void Simulacion::llenado_de_carrito(System::Object ^ sender, System::EventArgs ^ e) {

        if (SeñaldeFuncionamiento[0] == true && contador < 10) {
            carritos_utilizados[0] = true;

                agregarProductoAlCarrito(carrito[0], indices_utilizados, total_productos[0]);
                mostrarcarrito2(carrito[0], label3, 1);
                contador++;
            
        }
        else {
            if (contador == 10) {
                mostrar_total_productos(label3, total_productos[0]);
                contador++;
                carritos_llenos[0] = true;
                AsignacionDatos(0);
                AgregarClienteCola(0);
            }


        }
        int cantidadClientes = TamanoCola(); // Implementa esta función para obtener la cantidad de clientes en la cola
        label9->Text = "Clientes en cola: " + cantidadClientes;
    }


System::Void Simulacion::llenado_de_carrito2(System::Object^ sender, System::EventArgs^ e) {
   
    if (SeñaldeFuncionamiento[1] == true && contador2 < 10) {
        carritos_utilizados[1] = true;
   
            agregarProductoAlCarrito(carrito[1], indices_utilizados2, total_productos[1]);
            mostrarcarrito2(carrito[1], label4, 2);
            contador2++;
    }
        else {
            if (contador2 == 10) {
                mostrar_total_productos(label4, total_productos[1]);
                contador2++;
                carritos_llenos[1] = true;
                AsignacionDatos(1);
                AgregarClienteCola(1);
            }
            
        }

    }




System::Void Simulacion::llenado_de_carrito3(System::Object^ sender, System::EventArgs^ e) {
   
    if (SeñaldeFuncionamiento[2] == true && contador3 < 10) {
        carritos_utilizados[2] = true;


            agregarProductoAlCarrito(carrito[2], indices_utilizados3, total_productos[2]);
            mostrarcarrito2(carrito[2], label5, 3);
            contador3++;

    } else {
        if (contador3 == 10) {
            mostrar_total_productos(label5, total_productos[2]);
            contador3++;
            carritos_llenos[2] = true;
            AsignacionDatos(2);
            AgregarClienteCola(2);
        }
           
    }
}


System::Void Simulacion::llenado_de_carrito4(System::Object^ sender, System::EventArgs^ e) {
 
    if (SeñaldeFuncionamiento[3] == true && contador4 < 10) {
        carritos_utilizados[3] = true;


            agregarProductoAlCarrito(carrito[3], indices_utilizados4, total_productos[3]);
            mostrarcarrito2(carrito[3], label2, 4);
            contador4++;

    }
        else {
            if (contador4 == 10) {
                mostrar_total_productos(label2, total_productos[3]);
                contador4++;
                carritos_llenos[3] = true;
                AsignacionDatos(3);
                AgregarClienteCola(3);

            }
            
        }
}


System::Void Simulacion::llenado_de_carrito5(System::Object^ sender, System::EventArgs^ e) {

       
    if (SeñaldeFuncionamiento[4] == true && contador5 < 10) {
        carritos_utilizados[4] = true;


            agregarProductoAlCarrito(carrito[4], indices_utilizados5, total_productos[4]);
            mostrarcarrito2(carrito[4], label7, 5);
            contador5++;

    }
        else {
            if (contador5 == 10) {
                mostrar_total_productos(label7, total_productos[4]);
                contador5++;
                carritos_llenos[4] = true;
                AsignacionDatos(4);
                AgregarClienteCola(4);
            }
       
        }
}


System::Void Simulacion::llenado_de_carrito6(System::Object^ sender, System::EventArgs^ e) {
  
    if (SeñaldeFuncionamiento[5] == true && contador6 < 10) {
        carritos_utilizados[5] = true;
            agregarProductoAlCarrito(carrito[5], indices_utilizados6, total_productos[5]);
            mostrarcarrito2(carrito[5], label10, 6);
            contador6++;
    }
        else {
            if (contador6 == 10) {
                mostrar_total_productos(label10, total_productos[5]);
                contador6++;
                carritos_llenos[5] = true;
                AsignacionDatos(5);
                AgregarClienteCola(5);
            }
            
        }
}

System::Void Simulacion::Creacion_de_factura(System::Object^ sender, System::EventArgs^ e) {
    obtener_cliente_en_cola(cola_clientes);
   // label11->Text = id_carrito_factura.ToString();

    if ((id_carrito_factura == 0) && (carritos_llenos[0] == true)) {
       
        if (!carrito[id_carrito_factura].empty()) {

            label11->Text = label3->Text;
            // Almacenar temporalmente el producto a eliminar
            auto& producto = carrito[id_carrito_factura].top();

            // 1. Actualizar label3 (carrito) - Eliminar el elemento
            // Crear nuevo texto sin el producto actual
            System::String^ nuevoTextoCarrito = label3->Text->Replace(
                producto.cantidad + " " +
                gcnew System::String(producto.nombres) + " " +
                producto.precio + "Bs\n", "");
            label3->Text = nuevoTextoCarrito;
            label11->Text = label3->Text;
            //Actualizar label12 (factura) - Agregar el elemento

           
           
            if (contador == 11) {

                ReferenciaCliente = ReferenciaCliente++;
                label12->Text = "FACTURA: " + "\n" + "DATOS DEL CLIENTE : " + "\n" + "REFERENCIA: " + ReferenciaCliente + "\n" + "CEDULA: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].cedula) +
                    "\n" + "NOMBRE: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].nombres) + "\n" +
                    "TELEFONO: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].telefono) +"\n" + "_________________________" +"\n" + "\n";
                    
                contador++;
            }
              

            label12->Text +=  gcnew System::String(producto.nombres) + ".........." + producto.cantidad + " x " +
                producto.precio + "Bs\n";

            
		    Precio_total += producto.cantidad * producto.precio;

            //Eliminar el producto del carrito
            carrito[id_carrito_factura].pop();
        }
        else {
            if (contador==12) {
                label12->Text = label12->Text +"                      Total: "+ Precio_total + "Bs";
                Precio_total = 0;
                carritos_llenos[id_carrito_factura] = false;
                carritos_utilizados[id_carrito_factura] = false;
				QuitarClienteCola(id_carrito_factura);
                indices_utilizados.clear();
                contador=0;
            }
            quitar_total_productos(label3, total_productos[0], 1);
            label11->Text = "";
        }

	} else if ((id_carrito_factura == 1) && (carritos_llenos[1] == true)) {
	
        if (!carrito[id_carrito_factura].empty()) {
            label11->Text = label4->Text;
            // Almacenar temporalmente el producto a eliminar
            auto& producto = carrito[id_carrito_factura].top();

            // 1. Actualizar label3 (carrito) - Eliminar el elemento
            // Crear nuevo texto sin el producto actual
            System::String^ nuevoTextoCarrito = label4->Text->Replace(
                producto.cantidad + " " +
                gcnew System::String(producto.nombres) + " " +
                producto.precio + "Bs\n",
                ""
            );
            label4->Text = nuevoTextoCarrito;
            label11->Text = label4->Text;
            //Actualizar label12 (factura) - Agregar el elemento

            if (contador2 == 11) {
                ReferenciaCliente = ReferenciaCliente++;
                label12->Text = "FACTURA: " + "\n" + "DATOS DEL CLIENTE : " + "\n" + "REFERENCIA: " + ReferenciaCliente + "\n" + "CEDULA: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].cedula) +
                    "\n" + "NOMBRE: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].nombres) + "\n" +
                    "TELEFONO: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].telefono) + "\n" + "_________________________" + "\n" + "\n";

                contador2++;
            }

            label12->Text += gcnew System::String(producto.nombres) + ".........." + producto.cantidad + " x " +
                producto.precio + "Bs\n";

            Precio_total += producto.cantidad * producto.precio;

            //Eliminar el producto del carrito
            carrito[id_carrito_factura].pop();

        }
        else {
            if (contador2 == 12) {
                label12->Text = label12->Text + "                      Total: " + Precio_total + "Bs";
                Precio_total = 0;
                carritos_llenos[id_carrito_factura] = false;
                carritos_utilizados[id_carrito_factura] = false;
                QuitarClienteCola(id_carrito_factura);
                indices_utilizados2.clear();
                contador2=0;
            }
            quitar_total_productos(label4, total_productos[1], 2);
            label11->Text = "";
        }
    }
    else if ((id_carrito_factura == 2) && (carritos_llenos[2] == true)) {
		

        if (!carrito[id_carrito_factura].empty()) {
            label11->Text = label5->Text;
            // Almacenar temporalmente el producto a eliminar
            auto& producto = carrito[id_carrito_factura].top();

            // 1. Actualizar label3 (carrito) - Eliminar el elemento
            // Crear nuevo texto sin el producto actual
            System::String^ nuevoTextoCarrito = label5->Text->Replace(
                producto.cantidad + " " +
                gcnew System::String(producto.nombres) + " " +
                producto.precio + "Bs\n",
                ""
            );
            label5->Text = nuevoTextoCarrito;
            label11->Text = label5->Text;
            //Actualizar label12 (factura) - Agregar el elemento
            if (contador3 == 11) {
                ReferenciaCliente = ReferenciaCliente++;
                label12->Text = "FACTURA: " + "\n" + "DATOS DEL CLIENTE : " + "\n" + "REFERENCIA: " + ReferenciaCliente + "\n" + "CEDULA: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].cedula) +
                    "\n" + "NOMBRE: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].nombres) + "\n" +
                    "TELEFONO: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].telefono) + "\n" + "_________________________" + "\n" + "\n";

                contador3++;
            }

            label12->Text += gcnew System::String(producto.nombres) + ".........." + producto.cantidad + " x " +
                producto.precio + "Bs\n";

            Precio_total += producto.cantidad * producto.precio;

            //Eliminar el producto del carrito
            carrito[id_carrito_factura].pop();
        }
        else {
            if (contador3 == 12) {
                label12->Text = label12->Text + "                      Total: " + Precio_total + "Bs";
                Precio_total = 0;
                carritos_llenos[id_carrito_factura] = false;
                carritos_utilizados[id_carrito_factura] = false;
                QuitarClienteCola(id_carrito_factura);
                indices_utilizados3.clear();
                contador3=0;
            }
            quitar_total_productos(label5, total_productos[2], 3);
            label11->Text = "";
        }
	} else if ((id_carrito_factura == 3) && (carritos_llenos[3] == true)) {
	
        if (!carrito[id_carrito_factura].empty()) {
            label11->Text = label2->Text;
            // Almacenar temporalmente el producto a eliminar
            auto& producto = carrito[id_carrito_factura].top();

            // 1. Actualizar label3 (carrito) - Eliminar el elemento
            // Crear nuevo texto sin el producto actual
            System::String^ nuevoTextoCarrito = label2->Text->Replace(
                producto.cantidad + " " +
                gcnew System::String(producto.nombres) + " " +
                producto.precio + "Bs\n",
                ""
            );
            label2->Text = nuevoTextoCarrito;
            label11->Text = label2->Text;
            //Actualizar label12 (factura) - Agregar el elemento

            if (contador4 == 11) {
                ReferenciaCliente = ReferenciaCliente++;
                label12->Text = "FACTURA: " + "\n" + "DATOS DEL CLIENTE : " + "\n" + "REFERENCIA: " + ReferenciaCliente + "\n" + "CEDULA: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].cedula) +
                    "\n" + "NOMBRE: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].nombres) + "\n" +
                    "TELEFONO: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].telefono) + "\n" + "_________________________" + "\n" + "\n";

                contador4++;
            }

            label12->Text += gcnew System::String(producto.nombres) + ".........." + producto.cantidad + " x " +
                producto.precio + "Bs\n";

            Precio_total += producto.cantidad * producto.precio;

            //Eliminar el producto del carrito
            carrito[id_carrito_factura].pop();
        }
        else {
            if (contador4 == 12) {
                label12->Text = label12->Text + "                      Total: " + Precio_total + "Bs";
                Precio_total = 0;
                carritos_llenos[id_carrito_factura] = false;
                carritos_utilizados[id_carrito_factura] = false;
                QuitarClienteCola(id_carrito_factura);
                indices_utilizados4.clear();
                contador4=0;
            }
            quitar_total_productos(label2, total_productos[3], 4);
            label11->Text = "";
        }

	} else if ((id_carrito_factura == 4) && (carritos_llenos[4] == true)) {

        if (!carrito[id_carrito_factura].empty()) {
            label11->Text = label7->Text;
            // Almacenar temporalmente el producto a eliminar
            auto& producto = carrito[id_carrito_factura].top();

            // 1. Actualizar label3 (carrito) - Eliminar el elemento
            // Crear nuevo texto sin el producto actual
            System::String^ nuevoTextoCarrito = label7->Text->Replace(
                producto.cantidad + " " +
                gcnew System::String(producto.nombres) + " " +
                producto.precio + "Bs\n",
                ""
            );
            label7->Text = nuevoTextoCarrito;
            label11->Text = label7->Text;
            //Actualizar label12 (factura) - Agregar el elemento

            if (contador5 == 11) {
                ReferenciaCliente = ReferenciaCliente++;
                label12->Text = "FACTURA: " + "\n" + "DATOS DEL CLIENTE : " + "\n" + "REFERENCIA: " + ReferenciaCliente + "\n" + "CEDULA: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].cedula) +
                    "\n" + "NOMBRE: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].nombres) + "\n" +
                    "TELEFONO: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].telefono) + "\n" + "_________________________" + "\n" + "\n";

                contador5++;
            }

            label12->Text += gcnew System::String(producto.nombres) + ".........." + producto.cantidad + " x " +
                producto.precio + "Bs\n";

            Precio_total += producto.cantidad * producto.precio;

            //Eliminar el producto del carrito
            carrito[id_carrito_factura].pop();
        }
        else {
            if (contador5 == 12) {
                label12->Text = label12->Text + "                      Total: " + Precio_total + "Bs";
                Precio_total = 0;
                carritos_llenos[id_carrito_factura] = false;
                carritos_utilizados[id_carrito_factura] = false;
                QuitarClienteCola(id_carrito_factura);
                indices_utilizados5.clear();
                contador5=0;
            }
            quitar_total_productos(label7, total_productos[4], 5);
            label11->Text = "";
        }
	} else if ((id_carrito_factura == 5) && (carritos_llenos[5] == true)) {
		

        if (!carrito[id_carrito_factura].empty()) {
            label11->Text = label10->Text;
            // Almacenar temporalmente el producto a eliminar
            auto& producto = carrito[id_carrito_factura].top();

            // 1. Actualizar label3 (carrito) - Eliminar el elemento
            // Crear nuevo texto sin el producto actual
            System::String^ nuevoTextoCarrito = label10->Text->Replace(
                producto.cantidad + " " +
                gcnew System::String(producto.nombres) + " " +
                producto.precio + "Bs\n",
                ""
            );
            label10->Text = nuevoTextoCarrito;
            label11->Text = label10->Text;
            //Actualizar label12 (factura) - Agregar el elemento

            if (contador6 == 11) {
                ReferenciaCliente = ReferenciaCliente++;
                label12->Text = "FACTURA: " + "\n" + "DATOS DEL CLIENTE : " + "\n" + "REFERENCIA: " + ReferenciaCliente + "\n" + "CEDULA: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].cedula) +
                    "\n" + "NOMBRE: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].nombres) + "\n" +
                    "TELEFONO: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].telefono) + "\n" + "_________________________" + "\n" + "\n";

                contador6++;
            }

            label12->Text += gcnew System::String(producto.nombres) + ".........." + producto.cantidad + " x " +
                producto.precio + "Bs\n";

            Precio_total += producto.cantidad * producto.precio;

            //Eliminar el producto del carrito
            carrito[id_carrito_factura].pop();
	}
        else {
            if (contador6 == 12) {
                label12->Text = label12->Text + "                     Total: " + Precio_total + "Bs";
                Precio_total = 0;
                carritos_llenos[id_carrito_factura] = false;
                carritos_utilizados[id_carrito_factura] = false;
                QuitarClienteCola(id_carrito_factura);
                indices_utilizados6.clear();
                contador6=0;
            }
            quitar_total_productos(label10, total_productos[5], 6);
            label11->Text = "";
        }
    }
}