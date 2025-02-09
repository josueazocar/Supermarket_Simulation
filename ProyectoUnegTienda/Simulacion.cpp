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

    
    // Inicializa el contador_carrito1
    contador_carrito1 = 0;
    contador_carrito2 = 0;
    contador_carrito3 = 0;
    contador_carrito4 = 0;
    contador_carrito5 = 0;
    contador_carrito6 = 0;
    Precio_total_para_factura = 0;

    timer_creacion_factura = gcnew System::Windows::Forms::Timer();
    timer_creacion_factura->Interval = 2000;
    timer_creacion_factura->Tick += gcnew EventHandler(this, &Simulacion::Creacion_de_factura);
    timer_creacion_factura->Start();

    // Configura el primer temporizador
    timer_carrito1 = gcnew System::Windows::Forms::Timer();
    tiempoCarrito[0]= tiempo_aletorio();
    timer_carrito1->Interval = tiempoCarrito[0];
    timer_carrito1->Tick += gcnew EventHandler(this, &Simulacion::llenado_de_carrito);
   // timer_carrito1->Tick += gcnew EventHandler(this, &Simulacion::Creacion_de_factura);
    timer_carrito1->Start();

    // Configura el segundo temporizador con un retraso de 5 segundos
    timer_carrito2 = gcnew System::Windows::Forms::Timer();
    tiempoCarrito[1] = tiempo_aletorio();
    timer_carrito2->Interval = tiempoCarrito[1];
    timer_carrito2->Tick += gcnew EventHandler(this, &Simulacion::llenado_de_carrito2);
    timer_carrito2->Start();

    // Configura el tercer temporizador con un retraso de 10 segundos
    timer_carrito3 = gcnew System::Windows::Forms::Timer();
    tiempoCarrito[2] = tiempo_aletorio();
    timer_carrito3->Interval = tiempoCarrito[2];
    timer_carrito3->Tick += gcnew EventHandler(this, &Simulacion::llenado_de_carrito3);
    timer_carrito3->Start();

    // Configura el cuarto temporizador con un retraso de 15 segundos
    timer_carrito4 = gcnew System::Windows::Forms::Timer();
    tiempoCarrito[3] = tiempo_aletorio();
    timer_carrito4->Interval = tiempoCarrito[3];
    timer_carrito4->Tick += gcnew EventHandler(this, &Simulacion::llenado_de_carrito4);
    timer_carrito4->Start();

    // Configura el quinto temporizador con un retraso de 20 segundos
    timer_carrito5 = gcnew System::Windows::Forms::Timer();
    tiempoCarrito[4] = tiempo_aletorio();
    timer_carrito5->Interval = tiempoCarrito[4]; // 21000 ms = 21 segundos (1 segundo + 20 segundos de retraso)
    timer_carrito5->Tick += gcnew EventHandler(this, &Simulacion::llenado_de_carrito5);
    timer_carrito5->Start();

    // Configura el sexto temporizador con un retraso de 25 segundos
    timer_carrito6 = gcnew System::Windows::Forms::Timer();
    tiempoCarrito[5] = tiempo_aletorio();
    timer_carrito6->Interval = tiempoCarrito[5];
    timer_carrito6->Tick += gcnew EventHandler(this, &Simulacion::llenado_de_carrito6);
    timer_carrito6->Start();

    timer_gestion_de_clientes = gcnew System::Windows::Forms::Timer();
    timer_gestion_de_clientes->Interval = tiempo_aletorio_clientes();
    timer_gestion_de_clientes->Tick += gcnew EventHandler(this, &Simulacion::GestionarClientes);
    timer_gestion_de_clientes->Start();

    timer_MoverClientesAlFinal = gcnew System::Windows::Forms::Timer();
    timer_MoverClientesAlFinal->Interval = 1000;
    timer_MoverClientesAlFinal->Tick += gcnew EventHandler(this, &Simulacion::MoverClientesAlFinal);
    timer_MoverClientesAlFinal->Start();

    System::Diagnostics::Debug::WriteLine("Temporizadores iniciados.");
}

System::Void Simulacion::Simulacion_Load(System::Object^ sender, System::EventArgs^ e) {
    EmpezarSimulacion(); // Iniciar la simulación al cargar el formulario 
    System::Diagnostics::Debug::WriteLine("Simulacion_Load llamado.");
    this->segundosTranscurridos = 0;
    this->timerCronometro->Start();
}


System::Void Simulacion::MoverClientesAlFinal(System::Object^ sender, System::EventArgs^ e) {

	if (CronometroCarrito[0] >= tiempoMoverAlfinal) {
		moverClienteAlFinal(0);
		CronometroCarrito[0] = 0;
		num_ejecuciones[0] = 0;
	} else 
		if (CronometroCarrito[1] >= tiempoMoverAlfinal) {
			moverClienteAlFinal(1);
			CronometroCarrito[1] = 0;
            num_ejecuciones[1] = 0;
		}
		else
			if (CronometroCarrito[2] >= tiempoMoverAlfinal) {
				moverClienteAlFinal(2);
				CronometroCarrito[2] = 0;
                num_ejecuciones[2] = 0;
			}
			else
				if (CronometroCarrito[3] >= tiempoMoverAlfinal) {
					moverClienteAlFinal(3);
					CronometroCarrito[3] = 0;
                    num_ejecuciones[3] = 0;
				}
				else
					if (CronometroCarrito[4] >= tiempoMoverAlfinal) {
						moverClienteAlFinal(4);
						CronometroCarrito[4] = 0;
                        num_ejecuciones[4] = 0;
					}
					else
						if (CronometroCarrito[5] >= tiempoMoverAlfinal) {
							moverClienteAlFinal(5);
							CronometroCarrito[5] = 0;
                            num_ejecuciones[5] = 0;
						}

    int cantidadClientes = TamanoCola(); // Implementa esta función para obtener la cantidad de clientes en la cola
    label9->Text = "Clientes en cola: " + cantidadClientes;
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

        if (SeñaldeFuncionamiento[0] == true && contador_carrito1 < 10) {
            carritos_utilizados[0] = true;

                agregarProductoAlCarrito(carrito[0], indices_utilizados, total_productos[0]);
                mostrarcarrito2(carrito[0], label3, 1);
                contador_carrito1++;
            
        }
        else {
            if (contador_carrito1 == 10) {
                mostrar_total_productos(label3, total_productos[0]);
                contador_carrito1++;
                carritos_llenos[0] = true;
                AsignacionDatos(0);
                AgregarClienteCola(0);
            }


        }
            TiempoClienteEnCola(0);
    }


System::Void Simulacion::llenado_de_carrito2(System::Object^ sender, System::EventArgs^ e) {
   
    if (SeñaldeFuncionamiento[1] == true && contador_carrito2 < 10) {
        carritos_utilizados[1] = true;
   
            agregarProductoAlCarrito(carrito[1], indices_utilizados2, total_productos[1]);
            mostrarcarrito2(carrito[1], label4, 2);
            contador_carrito2++;
    }
        else {
            if (contador_carrito2 == 10) {
                mostrar_total_productos(label4, total_productos[1]);
                contador_carrito2++;
                carritos_llenos[1] = true;
                AsignacionDatos(1);
                AgregarClienteCola(1);
            }
            
        }
    TiempoClienteEnCola(1);
    }




System::Void Simulacion::llenado_de_carrito3(System::Object^ sender, System::EventArgs^ e) {
   
    if (SeñaldeFuncionamiento[2] == true && contador_carrito3 < 10) {
        carritos_utilizados[2] = true;


            agregarProductoAlCarrito(carrito[2], indices_utilizados3, total_productos[2]);
            mostrarcarrito2(carrito[2], label5, 3);
            contador_carrito3++;

    } else {
        if (contador_carrito3 == 10) {
            mostrar_total_productos(label5, total_productos[2]);
            contador_carrito3++;
            carritos_llenos[2] = true;
            AsignacionDatos(2);
            AgregarClienteCola(2);
        }
           
    }
    TiempoClienteEnCola(2);
}


System::Void Simulacion::llenado_de_carrito4(System::Object^ sender, System::EventArgs^ e) {
 
    if (SeñaldeFuncionamiento[3] == true && contador_carrito4 < 10) {
        carritos_utilizados[3] = true;


            agregarProductoAlCarrito(carrito[3], indices_utilizados4, total_productos[3]);
            mostrarcarrito2(carrito[3], label2, 4);
            contador_carrito4++;

    }
        else {
            if (contador_carrito4 == 10) {
                mostrar_total_productos(label2, total_productos[3]);
                contador_carrito4++;
                carritos_llenos[3] = true;
                AsignacionDatos(3);
                AgregarClienteCola(3);

            }
            
        }

    TiempoClienteEnCola(3);
}


System::Void Simulacion::llenado_de_carrito5(System::Object^ sender, System::EventArgs^ e) {

       
    if (SeñaldeFuncionamiento[4] == true && contador_carrito5 < 10) {
        carritos_utilizados[4] = true;


            agregarProductoAlCarrito(carrito[4], indices_utilizados5, total_productos[4]);
            mostrarcarrito2(carrito[4], label7, 5);
            contador_carrito5++;

    }
        else {
            if (contador_carrito5 == 10) {
                mostrar_total_productos(label7, total_productos[4]);
                contador_carrito5++;
                carritos_llenos[4] = true;
                AsignacionDatos(4);
                AgregarClienteCola(4);
            }
       
        }
    TiempoClienteEnCola(4);
}


System::Void Simulacion::llenado_de_carrito6(System::Object^ sender, System::EventArgs^ e) {
  
    if (SeñaldeFuncionamiento[5] == true && contador_carrito6 < 10) {
        carritos_utilizados[5] = true;
            agregarProductoAlCarrito(carrito[5], indices_utilizados6, total_productos[5]);
            mostrarcarrito2(carrito[5], label10, 6);
            contador_carrito6++;
    }
        else {
            if (contador_carrito6 == 10) {
                mostrar_total_productos(label10, total_productos[5]);
                contador_carrito6++;
                carritos_llenos[5] = true;
                AsignacionDatos(5);
                AgregarClienteCola(5);
            }
            
        }
	TiempoClienteEnCola(5);
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

           
           
            if (contador_carrito1 == 11) {

                clientePagando[id_carrito_factura] = true;
                ReferenciaCliente = ReferenciaCliente++;
                label12->Text = "FACTURA: " + "\n" + "DATOS DEL CLIENTE : " + "\n" + "REFERENCIA: " + ReferenciaCliente + "\n" + "CEDULA: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].cedula) +
                    "\n" + "NOMBRE: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].nombres) + "\n" +
                    "TELEFONO: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].telefono) +"\n" + "_________________________" +"\n" + "\n";
                    
                contador_carrito1++;
            }
              

            label12->Text +=  gcnew System::String(producto.nombres) + ".........." + producto.cantidad + " x " +
                producto.precio + "Bs\n";

            
		    Precio_total_para_factura += producto.cantidad * producto.precio;

            //Eliminar el producto del carrito
            carrito[id_carrito_factura].pop();
        }
        else {
            if (contador_carrito1==12) {
                label12->Text = label12->Text +"                      Total: "+ Precio_total_para_factura + "Bs";
                Precio_total_para_factura = 0;
				QuitarClienteCola(id_carrito_factura);
                indices_utilizados.clear();
                contador_carrito1=0;
            }
            quitar_total_productos(label3, total_productos[0], 1);
            label11->Text = "En espera para vaciar carrito...";
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

            if (contador_carrito2 == 11) {
                clientePagando[id_carrito_factura] = true;
                ReferenciaCliente = ReferenciaCliente++;
                label12->Text = "FACTURA: " + "\n" + "DATOS DEL CLIENTE : " + "\n" + "REFERENCIA: " + ReferenciaCliente + "\n" + "CEDULA: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].cedula) +
                    "\n" + "NOMBRE: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].nombres) + "\n" +
                    "TELEFONO: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].telefono) + "\n" + "_________________________" + "\n" + "\n";

                contador_carrito2++;
            }

            label12->Text += gcnew System::String(producto.nombres) + ".........." + producto.cantidad + " x " +
                producto.precio + "Bs\n";

            Precio_total_para_factura += producto.cantidad * producto.precio;

            //Eliminar el producto del carrito
            carrito[id_carrito_factura].pop();

        }
        else {
            if (contador_carrito2 == 12) {
                label12->Text = label12->Text + "                      Total: " + Precio_total_para_factura + "Bs";
                Precio_total_para_factura = 0;
                QuitarClienteCola(id_carrito_factura);
                indices_utilizados2.clear();
                contador_carrito2=0;
            }
            quitar_total_productos(label4, total_productos[1], 2);
            label11->Text = "En espera para vaciar carrito...";
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
            if (contador_carrito3 == 11) {
                clientePagando[id_carrito_factura] = true;
                ReferenciaCliente = ReferenciaCliente++;
                label12->Text = "FACTURA: " + "\n" + "DATOS DEL CLIENTE : " + "\n" + "REFERENCIA: " + ReferenciaCliente + "\n" + "CEDULA: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].cedula) +
                    "\n" + "NOMBRE: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].nombres) + "\n" +
                    "TELEFONO: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].telefono) + "\n" + "_________________________" + "\n" + "\n";

                contador_carrito3++;
            }

            label12->Text += gcnew System::String(producto.nombres) + ".........." + producto.cantidad + " x " +
                producto.precio + "Bs\n";

            Precio_total_para_factura += producto.cantidad * producto.precio;

            //Eliminar el producto del carrito
            carrito[id_carrito_factura].pop();
        }
        else {
            if (contador_carrito3 == 12) {
                label12->Text = label12->Text + "                      Total: " + Precio_total_para_factura + "Bs";
                Precio_total_para_factura = 0;
                QuitarClienteCola(id_carrito_factura);
                indices_utilizados3.clear();
                contador_carrito3=0;
            }
            quitar_total_productos(label5, total_productos[2], 3);
            label11->Text = "En espera para vaciar carrito...";
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

            if (contador_carrito4 == 11) {
                clientePagando[id_carrito_factura] = true;
                ReferenciaCliente = ReferenciaCliente++;
                label12->Text = "FACTURA: " + "\n" + "DATOS DEL CLIENTE : " + "\n" + "REFERENCIA: " + ReferenciaCliente + "\n" + "CEDULA: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].cedula) +
                    "\n" + "NOMBRE: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].nombres) + "\n" +
                    "TELEFONO: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].telefono) + "\n" + "_________________________" + "\n" + "\n";

                contador_carrito4++;
            }

            label12->Text += gcnew System::String(producto.nombres) + ".........." + producto.cantidad + " x " +
                producto.precio + "Bs\n";

            Precio_total_para_factura += producto.cantidad * producto.precio;

            //Eliminar el producto del carrito
            carrito[id_carrito_factura].pop();
        }
        else {
            if (contador_carrito4 == 12) {
                label12->Text = label12->Text + "                      Total: " + Precio_total_para_factura + "Bs";
                Precio_total_para_factura = 0;
                QuitarClienteCola(id_carrito_factura);
                indices_utilizados4.clear();
                contador_carrito4=0;
            }
            quitar_total_productos(label2, total_productos[3], 4);
            label11->Text = "En espera para vaciar carrito...";
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

            if (contador_carrito5 == 11) {
                clientePagando[id_carrito_factura] = true;
                ReferenciaCliente = ReferenciaCliente++;
                label12->Text = "FACTURA: " + "\n" + "DATOS DEL CLIENTE : " + "\n" + "REFERENCIA: " + ReferenciaCliente + "\n" + "CEDULA: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].cedula) +
                    "\n" + "NOMBRE: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].nombres) + "\n" +
                    "TELEFONO: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].telefono) + "\n" + "_________________________" + "\n" + "\n";

                contador_carrito5++;
            }

            label12->Text += gcnew System::String(producto.nombres) + ".........." + producto.cantidad + " x " +
                producto.precio + "Bs\n";

            Precio_total_para_factura += producto.cantidad * producto.precio;

            //Eliminar el producto del carrito
            carrito[id_carrito_factura].pop();
        }
        else {
            if (contador_carrito5 == 12) {
                label12->Text = label12->Text + "                      Total: " + Precio_total_para_factura + "Bs";
                Precio_total_para_factura = 0;
                QuitarClienteCola(id_carrito_factura);
                indices_utilizados5.clear();
                contador_carrito5=0;
            }
            quitar_total_productos(label7, total_productos[4], 5);
            label11->Text = "En espera para vaciar carrito...";
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

            if (contador_carrito6 == 11) {
                clientePagando[id_carrito_factura] = true;
                ReferenciaCliente = ReferenciaCliente++;
                label12->Text = "FACTURA: " + "\n" + "DATOS DEL CLIENTE : " + "\n" + "REFERENCIA: " + ReferenciaCliente + "\n" + "CEDULA: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].cedula) +
                    "\n" + "NOMBRE: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].nombres) + "\n" +
                    "TELEFONO: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].telefono) + "\n" + "_________________________" + "\n" + "\n";

                contador_carrito6++;
            }

            label12->Text += gcnew System::String(producto.nombres) + ".........." + producto.cantidad + " x " +
                producto.precio + "Bs\n";

            Precio_total_para_factura += producto.cantidad * producto.precio;

            //Eliminar el producto del carrito
            carrito[id_carrito_factura].pop();
	}
        else {
            if (contador_carrito6 == 12) {
                label12->Text = label12->Text + "                     Total: " + Precio_total_para_factura + "Bs";
                Precio_total_para_factura = 0;
                QuitarClienteCola(id_carrito_factura);
                indices_utilizados6.clear();
                contador_carrito6=0;
            }
            quitar_total_productos(label10, total_productos[5], 6);
            label11->Text = "En espera para vaciar carrito...";
        }
    }
}