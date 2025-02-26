#include "Simulacion.h"
#include "pila.h"
#include "cola_clientes.h"
#include <string.h>
#include <random>
#include <ctime>
#include <set>
#include <cstring>
#include <string>
#include <msclr/marshal_cppstd.h> // Para la conversión entre std::string y System::String
#include "MenuForm.h"

using namespace ProyectoUnegTienda;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace Factura_Reportes;

const int num_carritos = 6; // Número total de carritos

void Simulacion::EmpezarSimulacion()
{
	// Reiniciar variables y valores en cola_clientes y pila
	ReiniciarColaClientes();
	ReiniciarPila();
	

	// Obtener los valores parametrizables de los controles de la ventana principal
	tiempoMoverAlfinal = valorVolverEntero;
	tiempo_generacionMinimo = valorTminimoEntero;
	tiempo_generacionMaximo = valorTmaximoEntero;

	// Detener y limpiar los temporizadores existentes
	if (timer_creacion_factura != nullptr) timer_creacion_factura->Stop();
	if (timer_carrito1 != nullptr) timer_carrito1->Stop();
	if (timer_carrito2 != nullptr) timer_carrito2->Stop();
	if (timer_carrito3 != nullptr) timer_carrito3->Stop();
	if (timer_carrito4 != nullptr) timer_carrito4->Stop();
	if (timer_carrito5 != nullptr) timer_carrito5->Stop();
	if (timer_carrito6 != nullptr) timer_carrito6->Stop();
	if (timer_gestion_de_clientes != nullptr) timer_gestion_de_clientes->Stop();
	if (timer_MoverClientesAlFinal != nullptr) timer_MoverClientesAlFinal->Stop();

	// Inicializa el contador_carrito1
	contador_carrito1 = 0;
	contador_carrito2 = 0;
	contador_carrito3 = 0;
	contador_carrito4 = 0;
	contador_carrito5 = 0;
	contador_carrito6 = 0;
	Precio_total_para_factura = 0;
	indice_producto_mas_vendido = 0;

	// Inicializa los valores booleanos
	std::fill(std::begin(carritos_utilizados), std::end(carritos_utilizados), false);
	std::fill(std::begin(carritos_llenos), std::end(carritos_llenos), false);
	std::fill(std::begin(SeñaldeFuncionamiento), std::end(SeñaldeFuncionamiento), false);
	std::fill(std::begin(clientePagando), std::end(clientePagando), false);

	// Inicializa y empieza el temporizador 
	inicializarArticulos();
	std::srand(static_cast<unsigned>(std::time(nullptr))); // Inicializar el generador de números aleatorios

	// Configura el temporizador de creación de facturas
	timer_creacion_factura = gcnew System::Windows::Forms::Timer();
	timer_creacion_factura->Interval = 2100;
	timer_creacion_factura->Tick += gcnew EventHandler(this, &Simulacion::Creacion_de_factura);
	timer_creacion_factura->Start();

	// Configura el primer temporizador
	timer_carrito1 = gcnew System::Windows::Forms::Timer();
	tiempoCarrito[0] = tiempo_aletorio();
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
	timer_gestion_de_clientes->Interval = tiempo_aletorio_clientes(tiempo_generacionMinimo, tiempo_generacionMaximo);
	timer_gestion_de_clientes->Tick += gcnew EventHandler(this, &Simulacion::GestionarClientes);
	timer_gestion_de_clientes->Start();

	pausarOreanudarButton->Click += gcnew System::EventHandler(this, &Simulacion::pausarOreanudarButton_click);
	pausarOreanudarButton->BringToFront();

	panel1->Controls->Add(this->pausarOreanudarButton);

	timer_MoverClientesAlFinal = gcnew System::Windows::Forms::Timer();
	timer_MoverClientesAlFinal->Interval = 1000;
	timer_MoverClientesAlFinal->Tick += gcnew EventHandler(this, &Simulacion::MoverClientesAlFinal);
	timer_MoverClientesAlFinal->Start();
	etiquetasClientes = gcnew System::Collections::Generic::List<Label^>();


	System::Diagnostics::Debug::WriteLine("Temporizadores iniciados.");
}

// Función que se llama cuando se carga el formulario, inicia la simulación
System::Void Simulacion::Simulacion_Load(System::Object^ sender, System::EventArgs^ e) {
	EmpezarSimulacion(); // Iniciar la simulación al cargar el formulario 
	System::Diagnostics::Debug::WriteLine("Simulacion_Load llamado.");
	this->segundosTranscurridos = 0;
	this->timerCronometro->Start();
}

System::Void Simulacion::MoverClientesAlFinal(System::Object^ sender, System::EventArgs^ e) {

	
	for (int i = 0; i < num_carritos; ++i) {
		if (CronometroCarrito[i] >= tiempoMoverAlfinal) { //Si el tiempo que lleva el cliente con el carrito es mayor o igual al limite entonces...
			moverClienteAlFinal(i);
			CronometroCarrito[i] = 0;
			num_ejecuciones[i] = 0;
		}
	}

	int cantidadClientes = TamanoCola(); // Implementa esta función para obtener la cantidad de clientes en la cola
	ActualizarVisualizacionCola(); // Asegúrate de actualizar la visualización de la cola
	label9->Text = "Clientes en cola: " + cantidadClientes;
}

System::Void Simulacion::GestionarClientes(System::Object^ sender, System::EventArgs^ e) {

	if (stock_se_termino() == false) { // Si hay stock disponible
		for (int i = 0; i < num_carritos; i++) { 
			if (!carritos_utilizados[i]) { // Si el carrito no está siendo utilizado
				SeñaldeFuncionamiento[i] = true; // Activar la señal de funcionamiento
				carritos_utilizados[i] = true;
				break;
			}
		}
	}
}

//Funcion que se encarga de llenar y mostrar el carrito 1 y de ingresar el cliente a la cola al finalizar
System::Void Simulacion::llenado_de_carrito(System::Object^ sender, System::EventArgs^ e) {

	if (SeñaldeFuncionamiento[0] == true && contador_carrito1 < 10) {
		carritos_utilizados[0] = true;
		if (contador_carrito1 < 1) {  //Validacion para que la asignacion se realice una sola vez por activacion
			AsignacionDatos(0, label3);
		}
		agregarProductoAlCarrito(carrito[0], indices_utilizados, total_productos[0]);
		mostrarcarrito(carrito[0], label3, 1);
		contador_carrito1++;

	}
	else {
		if (contador_carrito1 == 10) {
			mostrar_total_productos(label3, total_productos[0]);
			contador_carrito1++; //Incrementar el contador para que no se vuelva a ejecutar
			carritos_llenos[0] = true;
			AgregarClienteCola(0);
		}
	}
	TiempoClienteEnCola(0);
}

//Funcion que se encarga de llenar y mostrar el carrito 2 y de ingresar el cliente a la cola al finalizar
System::Void Simulacion::llenado_de_carrito2(System::Object^ sender, System::EventArgs^ e) {

	if (SeñaldeFuncionamiento[1] == true && contador_carrito2 < 10) {
		carritos_utilizados[1] = true;
		if (contador_carrito2 < 1) { //Validacion para que la asignacion se realice una sola vez por activacion
			AsignacionDatos(1, label4);

		}
		agregarProductoAlCarrito(carrito[1], indices_utilizados2, total_productos[1]);
		mostrarcarrito(carrito[1], label4, 2);
		contador_carrito2++;
	}
	else {
		if (contador_carrito2 == 10) {
			mostrar_total_productos(label4, total_productos[1]);
			contador_carrito2++; //Incrementar el contador para que no se vuelva a ejecutar
			carritos_llenos[1] = true;
			AgregarClienteCola(1);
		}
	}
	TiempoClienteEnCola(1);
}

//Funcion que se encarga de llenar y mostrar el carrito 3 y de ingresar el cliente a la cola al finalizar
System::Void Simulacion::llenado_de_carrito3(System::Object^ sender, System::EventArgs^ e) {

	if (SeñaldeFuncionamiento[2] == true && contador_carrito3 < 10) {
		carritos_utilizados[2] = true;
		if (contador_carrito3 < 1) { //Validacion para que la asignacion se realice una sola vez por activacion
			AsignacionDatos(2, label5);
		}
		agregarProductoAlCarrito(carrito[2], indices_utilizados3, total_productos[2]);
		mostrarcarrito(carrito[2], label5, 3);
		contador_carrito3++;
	}
	else {
		if (contador_carrito3 == 10) {
			mostrar_total_productos(label5, total_productos[2]);
			contador_carrito3++; //Incrementar el contador para que no se vuelva a ejecutar
			carritos_llenos[2] = true;
			AgregarClienteCola(2);
		}
	}
	TiempoClienteEnCola(2);
}

//Funcion que se encarga de llenar y mostrar el carrito 4 y de ingresar el cliente a la cola al finalizar
System::Void Simulacion::llenado_de_carrito4(System::Object^ sender, System::EventArgs^ e) {

	if (SeñaldeFuncionamiento[3] == true && contador_carrito4 < 10) {
		carritos_utilizados[3] = true;

		if (contador_carrito4 < 1) { //Validacion para que la asignacion se realice una sola vez por activacion
			AsignacionDatos(3, label2);
		}
		agregarProductoAlCarrito(carrito[3], indices_utilizados4, total_productos[3]);
		mostrarcarrito(carrito[3], label2, 4);
		contador_carrito4++;

	}
	else {
		if (contador_carrito4 == 10) {
			mostrar_total_productos(label2, total_productos[3]);
			contador_carrito4++; //Incrementar el contador para que no se vuelva a ejecutar
			carritos_llenos[3] = true;
			AgregarClienteCola(3);

		}
	}

	TiempoClienteEnCola(3);
}

//Funcion que se encarga de llenar y mostrar el carrito 5 y de ingresar el cliente a la cola al finalizar
System::Void Simulacion::llenado_de_carrito5(System::Object^ sender, System::EventArgs^ e) {


	if (SeñaldeFuncionamiento[4] == true && contador_carrito5 < 10) {
		carritos_utilizados[4] = true;

		if (contador_carrito5 < 1) { //Validacion para que la asignacion se realice una sola vez por activacion
			AsignacionDatos(4, label7);
		}

		agregarProductoAlCarrito(carrito[4], indices_utilizados5, total_productos[4]);
		mostrarcarrito(carrito[4], label7, 5);
		contador_carrito5++;
	}
	else {
		if (contador_carrito5 == 10) {
			mostrar_total_productos(label7, total_productos[4]);
			contador_carrito5++; //Incrementar el contador para que no se vuelva a ejecutar
			carritos_llenos[4] = true;
			AgregarClienteCola(4);
		}
	}
	TiempoClienteEnCola(4);
}

//Funcion que se encarga de llenar y mostrar el carrito 6 y de ingresar el cliente a la cola al finalizar
System::Void Simulacion::llenado_de_carrito6(System::Object^ sender, System::EventArgs^ e) {

	if (SeñaldeFuncionamiento[5] == true && contador_carrito6 < 10) {

		if (contador_carrito6 < 1) { //Validacion para que la asignacion se realice una sola vez por activacion
			AsignacionDatos(5, label10);
		}

		carritos_utilizados[5] = true;
		agregarProductoAlCarrito(carrito[5], indices_utilizados6, total_productos[5]);
		mostrarcarrito(carrito[5], label10, 6);
		contador_carrito6++;
	}
	else {
		if (contador_carrito6 == 10) {
			mostrar_total_productos(label10, total_productos[5]);
			contador_carrito6++; //Incrementar el contador para que no se vuelva a ejecutar
			carritos_llenos[5] = true;
			AgregarClienteCola(5);
		}

	}
	TiempoClienteEnCola(5);
}

/* Funcion de todo el proceso de Creacion de la factura, desde cuando se determina si un cliente
es apto o no, hasta cuando el proceso finaliza para empezar de nuevo (se ejecuta cada 2 segundos) */
System::Void Simulacion::Creacion_de_factura(System::Object^ sender, System::EventArgs^ e) {
	No_hay_Stock(sender, e);
	obtener_cliente_en_cola(cola_clientes);

	if ((id_carrito_factura == 0) && (carritos_llenos[0] == true)) {

		if (!carrito[id_carrito_factura].empty()) {

			label11->Text = label3->Text;
			// Almacenar temporalmente el producto a eliminar
			auto& producto = carrito[id_carrito_factura].top();

			// Crear nuevo texto sin el producto actual
			System::String^ nuevoTextoCarrito = label3->Text->Replace(
				producto.cantidad + " " +
				gcnew System::String(producto.nombres) + " " +
				producto.precio + "Bs\n", "");
			label3->Text = nuevoTextoCarrito;
			label11->Text = label3->Text;

			if (contador_carrito1 == 11) {

				clientePagando[id_carrito_factura] = true;
				ReferenciaCliente = ReferenciaCliente++;
				label12->Text = "FACTURA: " + "\n" + "DATOS DEL CLIENTE : " + "\n" + "REFERENCIA: " + ReferenciaCliente + "\n"
					+ "CEDULA: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].cedula) +
					"\n" + "NOMBRE: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].nombres) + "\n" +
					"TELEFONO: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].telefono) + "\n" + "_________________________" + "\n" + "\n";

				contador_carrito1++;
			}

			label12->Text += gcnew System::String(producto.nombres) + ".........." + producto.cantidad + " x " +
				producto.precio + "Bs\n";

			Precio_total_para_factura += producto.cantidad * producto.precio;

			//Eliminar el producto del carrito
			carrito[id_carrito_factura].pop();
		}
		else { // Al culminar el vaciado del carrito se totaliza la factura y se reinician los valores
			if (contador_carrito1 == 12) {
				label12->Text = label12->Text + "                      Total: " + Precio_total_para_factura + "Bs";
				Crear_reporte_factura(label12);
				total_de_ventas = Precio_total_para_factura + total_de_ventas;
				Precio_total_para_factura = 0;
				QuitarClienteCola(id_carrito_factura);
				indices_utilizados.clear();
				contador_carrito1 = 0;
			}
			quitar_total_productos(label3, total_productos[0], 1);
			label11->Text = "En espera para vaciar carrito...";
		}

	}
	else if ((id_carrito_factura == 1) && (carritos_llenos[1] == true)) {

		if (!carrito[id_carrito_factura].empty()) {
			label11->Text = label4->Text;
			// Almacenar temporalmente el producto a eliminar
			auto& producto = carrito[id_carrito_factura].top();

			// Crear nuevo texto sin el producto actual
			System::String^ nuevoTextoCarrito = label4->Text->Replace(
				producto.cantidad + " " +
				gcnew System::String(producto.nombres) + " " +
				producto.precio + "Bs\n",
				""
			);
			label4->Text = nuevoTextoCarrito;
			label11->Text = label4->Text;

			if (contador_carrito2 == 11) {
				clientePagando[id_carrito_factura] = true;
				ReferenciaCliente = ReferenciaCliente++;
				label12->Text = "FACTURA: " + "\n" + "DATOS DEL CLIENTE : " + "\n" + "REFERENCIA: " + ReferenciaCliente + "\n"
					+ "CEDULA: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].cedula) +
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
		else { // Al culminar el vaciado del carrito se totaliza la factura y se reinician los valores
			if (contador_carrito2 == 12) {
				label12->Text = label12->Text + "                      Total: " + Precio_total_para_factura + "Bs";
				Crear_reporte_factura(label12);
				total_de_ventas = Precio_total_para_factura + total_de_ventas;
				Precio_total_para_factura = 0;
				QuitarClienteCola(id_carrito_factura);
				indices_utilizados2.clear();
				contador_carrito2 = 0;
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

			// Crear nuevo texto sin el producto actual
			System::String^ nuevoTextoCarrito = label5->Text->Replace(
				producto.cantidad + " " +
				gcnew System::String(producto.nombres) + " " +
				producto.precio + "Bs\n",
				""
			);
			label5->Text = nuevoTextoCarrito;
			label11->Text = label5->Text;

			if (contador_carrito3 == 11) {
				clientePagando[id_carrito_factura] = true;
				ReferenciaCliente = ReferenciaCliente++;
				label12->Text = "FACTURA: " + "\n" + "DATOS DEL CLIENTE : " + "\n" + "REFERENCIA: " + ReferenciaCliente + "\n"
					+ "CEDULA: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].cedula) +
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
		else { // Al culminar el vaciado del carrito se totaliza la factura y se reinician los valores
			if (contador_carrito3 == 12) {
				label12->Text = label12->Text + "                      Total: " + Precio_total_para_factura + "Bs";
				Crear_reporte_factura(label12);
				total_de_ventas = Precio_total_para_factura + total_de_ventas;
				Precio_total_para_factura = 0;
				QuitarClienteCola(id_carrito_factura);
				indices_utilizados3.clear();
				contador_carrito3 = 0;
			}
			quitar_total_productos(label5, total_productos[2], 3);
			label11->Text = "En espera para vaciar carrito...";
		}
	}
	else if ((id_carrito_factura == 3) && (carritos_llenos[3] == true)) {

		if (!carrito[id_carrito_factura].empty()) {
			label11->Text = label2->Text;
			// Almacenar temporalmente el producto a eliminar
			auto& producto = carrito[id_carrito_factura].top();

			// Crear nuevo texto sin el producto actual
			System::String^ nuevoTextoCarrito = label2->Text->Replace(
				producto.cantidad + " " +
				gcnew System::String(producto.nombres) + " " +
				producto.precio + "Bs\n",
				""
			);
			label2->Text = nuevoTextoCarrito;
			label11->Text = label2->Text;

			if (contador_carrito4 == 11) {
				clientePagando[id_carrito_factura] = true;
				ReferenciaCliente = ReferenciaCliente++;
				label12->Text = "FACTURA: " + "\n" + "DATOS DEL CLIENTE : " + "\n" + "REFERENCIA: " + ReferenciaCliente + "\n"
					+ "CEDULA: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].cedula) +
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
		else { // Al culminar el vaciado del carrito se totaliza la factura y se reinician los valores
			if (contador_carrito4 == 12) {
				label12->Text = label12->Text + "                      Total: " + Precio_total_para_factura + "Bs";
				Crear_reporte_factura(label12);
				total_de_ventas = Precio_total_para_factura + total_de_ventas;
				Precio_total_para_factura = 0;
				QuitarClienteCola(id_carrito_factura);
				indices_utilizados4.clear();
				contador_carrito4 = 0;
			}
			quitar_total_productos(label2, total_productos[3], 4);
			label11->Text = "En espera para vaciar carrito...";
		}

	}
	else if ((id_carrito_factura == 4) && (carritos_llenos[4] == true)) {

		if (!carrito[id_carrito_factura].empty()) {
			label11->Text = label7->Text;
			// Almacenar temporalmente el producto a eliminar
			auto& producto = carrito[id_carrito_factura].top();

			// Crear nuevo texto sin el producto actual
			System::String^ nuevoTextoCarrito = label7->Text->Replace(
				producto.cantidad + " " +
				gcnew System::String(producto.nombres) + " " +
				producto.precio + "Bs\n",
				""
			);
			label7->Text = nuevoTextoCarrito;
			label11->Text = label7->Text;

			if (contador_carrito5 == 11) {
				clientePagando[id_carrito_factura] = true;
				ReferenciaCliente = ReferenciaCliente++;
				label12->Text = "FACTURA: " + "\n" + "DATOS DEL CLIENTE : " + "\n" + "REFERENCIA: " + ReferenciaCliente + "\n"
					+ "CEDULA: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].cedula) +
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
		else { // Al culminar el vaciado del carrito se totaliza la factura y se reinician los valores
			if (contador_carrito5 == 12) {
				label12->Text = label12->Text + "                      Total: " + Precio_total_para_factura + "Bs";
				Crear_reporte_factura(label12);
				total_de_ventas = Precio_total_para_factura + total_de_ventas;
				Precio_total_para_factura = 0;
				QuitarClienteCola(id_carrito_factura);
				indices_utilizados5.clear();
				contador_carrito5 = 0;
			}
			quitar_total_productos(label7, total_productos[4], 5);
			label11->Text = "En espera para vaciar carrito...";
		}
	}
	else if ((id_carrito_factura == 5) && (carritos_llenos[5] == true)) {

		if (!carrito[id_carrito_factura].empty()) {
			label11->Text = label10->Text;
			// Almacenar temporalmente el producto a eliminar
			auto& producto = carrito[id_carrito_factura].top();

			// Crear nuevo texto sin el producto actual
			System::String^ nuevoTextoCarrito = label10->Text->Replace(
				producto.cantidad + " " +
				gcnew System::String(producto.nombres) + " " +
				producto.precio + "Bs\n",
				""
			);
			label10->Text = nuevoTextoCarrito;
			label11->Text = label10->Text;

			if (contador_carrito6 == 11) {
				clientePagando[id_carrito_factura] = true;
				ReferenciaCliente = ReferenciaCliente++;
				label12->Text = "FACTURA: " + "\n" + "DATOS DEL CLIENTE : " + "\n" + "REFERENCIA: " + ReferenciaCliente + "\n"
					+ "CEDULA: " + msclr::interop::marshal_as<System::String^>(cliente[id_carrito_factura].cedula) +
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
		else { // Al culminar el vaciado del carrito se totaliza la factura y se reinician los valores
			if (contador_carrito6 == 12) {
				label12->Text = label12->Text + "                     Total: " + Precio_total_para_factura + "Bs";
				Crear_reporte_factura(label12);
				total_de_ventas = Precio_total_para_factura + total_de_ventas;
				Precio_total_para_factura = 0;
				QuitarClienteCola(id_carrito_factura);
				indices_utilizados6.clear();
				contador_carrito6 = 0;
			}
			quitar_total_productos(label10, total_productos[5], 6);
			label11->Text = "En espera para vaciar carrito...";
		}
	}
}

void Simulacion::ActualizarVisualizacionCola() {
	// Hacer todos los Labels invisibles inicialmente
	puestoEnCola->Visible = false;
	puestoEnCola2->Visible = false;
	puestoEnCola3->Visible = false;
	puestoEnCola4->Visible = false;
	puestoEnCola5->Visible = false;
	puestoEnCola6->Visible = false;

	// Crear nuevas etiquetas según el estado de la cola
	std::queue<Tienda::clientes> tempCola = cola_clientes;
	int labelIndex = 1;

	while (!tempCola.empty() && labelIndex <= 6) {
		Tienda::clientes cliente = tempCola.front();
		tempCola.pop();

		Label^ label;
		switch (labelIndex) {
		case 1: label = puestoEnCola; break;
		case 2: label = puestoEnCola2; break;
		case 3: label = puestoEnCola3; break;
		case 4: label = puestoEnCola4; break;
		case 5: label = puestoEnCola5; break;
		case 6: label = puestoEnCola6; break;
		}

		label->Text = gcnew String(cliente.nombres.c_str());
		int argbColor = std::stoi(cliente.color);
		label->BackColor = Color::FromArgb(argbColor);
		label->Visible = true; // Hacer visible el Label

		// Centrar el texto
		label->TextAlign = ContentAlignment::MiddleCenter;

		// Aumentar el tamaño de la fuente
		label->Font = gcnew System::Drawing::Font(label->Font->FontFamily, 12); // Cambia 12 por el tamaño de fuente deseado

		labelIndex++;
	}
}

System::Void Simulacion::pausarOreanudarButton_click(System::Object^ sender, System::EventArgs^ e) {
	if (isPaused) {
		ReanudarTemporizadores();
		pausarOreanudarButton->Text = "Pausar";
	}
	else {
		PausarTemporizadores();
		pausarOreanudarButton->Text = "Reanudar";
	}
	isPaused = !isPaused;
	System::Diagnostics::Debug::WriteLine("boton presionado.");
}

System::Void Simulacion::PausarTemporizadores() {
	timer_creacion_factura->Stop();
	timer_carrito1->Stop();
	timer_carrito2->Stop();
	timer_carrito3->Stop();
	timer_carrito4->Stop();
	timer_carrito5->Stop();
	timer_carrito6->Stop();
	timer_gestion_de_clientes->Stop();
	timer_MoverClientesAlFinal->Stop();
	timerCronometro->Stop(); // Pausar el cronómetro
	System::Diagnostics::Debug::WriteLine("Simulación pausada.");
}


System::Void Simulacion::ReanudarTemporizadores() {
	timer_creacion_factura->Start();
	timer_carrito1->Start();
	timer_carrito2->Start();
	timer_carrito3->Start();
	timer_carrito4->Start();
	timer_carrito5->Start();
	timer_carrito6->Start();
	timer_gestion_de_clientes->Start();
	timer_MoverClientesAlFinal->Start();
	timerCronometro->Start();
	System::Diagnostics::Debug::WriteLine("Simulación reanudada.");
}

// Funcion para obtener el producto mas vendido segun el stock (debe ser el mas bajo)
System::Void Simulacion::Producto_masvendido() {

	if (stock_se_termino()) {

		stock_mas_bajo = "Todos AGOTADOS!";

	}
	else if (NumeroClientesRecibidos > 0) {

		int max_ventas = articulos[0].stock;
		for (int i = 1; i < 10; i++) {
			if (articulos[i].stock < max_ventas) {
				max_ventas = articulos[i].stock;
				indice_producto_mas_vendido = i;
			}
		}

		stock_mas_bajo = std::string(articulos[indice_producto_mas_vendido].nombres);
	}
	else {
		stock_mas_bajo = "No hay ventas";
	}
}

// Función para cerrar el programa si no hay stock, la cola está vacía y no hay clientes haciendo compras
System::Void Simulacion::No_hay_Stock(System::Object^ sender, System::EventArgs^ e) {

	if (stock_se_termino() && TamanoCola() == 0 && clientes_haciendo_compras() == false) {
		CerrarPrograma(sender, e);
	}
}
