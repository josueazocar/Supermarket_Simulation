#include "factura.h"
#include "cola_clientes.h"
#include "Simulacion.h"
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include <algorithm>
#include <Windows.h>

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace msclr::interop;
using namespace System::Drawing;

int id_carrito_factura;
int total_de_ventas=0;
std::string stock_mas_bajo;

namespace Factura_Reportes {
    ref class VisorFacturasForm : public Form
    {
    public:
        VisorFacturasForm(List<String^>^ archivos, int total_ventas, String^ nombre_producto, int NumeroClientesRecibidos, int NumeroClientesAtendidos, int NumeroClientesDevueltos) {
            InitializeComponent(archivos);
        }

    private:

        void InitializeComponent(List<String^>^ archivos) {

            Panel^ panelTotal = gcnew Panel();
            panelTotal->Dock = DockStyle::Bottom;
            panelTotal->Height = 30;
            panelTotal->BackColor = Color::LightGray;

            Label^ Texto_reportes = gcnew Label();
            Texto_reportes->Text = String::Format("TOTAL DE VENTAS: {0}Bs --- PRODUCTO MÁS VENDIDO: {1} --- RECIBIDOS EN TIENDA: {2} --- ATENDIDOS: {3} --- REGRESADOS AL FINAL DE LA COLA: {4}",
            total_de_ventas.ToString(), gcnew String(stock_mas_bajo.c_str()), NumeroClientesRecibidos.ToString(), NumeroClientesAtendidos.ToString(), NumeroClientesDevueltos.ToString());
            Texto_reportes->Font = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
            Texto_reportes->Dock = DockStyle::Fill;
            Texto_reportes->TextAlign = ContentAlignment::MiddleCenter;

            panelTotal->Controls->Add(Texto_reportes);
            this->Controls->Add(panelTotal); // Agregar al formulario

            this->Icon = gcnew System::Drawing::Icon(Application::StartupPath + L"\\imagenes\\carrito.ico");
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Text = "Visor de Facturas y Reportes";
            this->Size = System::Drawing::Size(1200, 600);
            this->StartPosition = FormStartPosition::CenterScreen;

            // Contenedor principal
            TableLayoutPanel^ mainTable = gcnew TableLayoutPanel();
            mainTable->Dock = DockStyle::Fill;
            mainTable->RowCount = 2;
            mainTable->ColumnCount = 5;

            // Configurar tamaño de columnas y filas
            for (int i = 0; i < 5; ++i) {
                mainTable->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 20));
            }
            for (int i = 0; i < 2; ++i) {
                mainTable->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
            }

            // Llenar con los datos
            int contador = 0;
            for each (String ^ archivo in archivos) {
                if (contador >= 10) break;

                String^ contenido = File::ReadAllText(archivo);
                Panel^ panel = CrearPanelFactura(Path::GetFileName(archivo), contenido);

                int fila = contador / 5;
                int columna = contador % 5;
                mainTable->Controls->Add(panel, columna, fila);

                ++contador;
            }

            this->Controls->Add(mainTable);
        }

        Panel^ CrearPanelFactura(String^ titulo, String^ contenido) {
            Panel^ panel = gcnew Panel();
            panel->Dock = DockStyle::Fill;
            panel->BorderStyle = BorderStyle::FixedSingle;
            panel->Padding = System::Windows::Forms::Padding(10);

            // Título
            Label^ lblTitulo = gcnew Label();
            lblTitulo->Text = titulo;
            lblTitulo->Font = gcnew System::Drawing::Font("Arial", 9, FontStyle::Bold);
            lblTitulo->Dock = DockStyle::Top;

            // Contenido
            TextBox^ txtContenido = gcnew TextBox();
            txtContenido->Multiline = true;
            txtContenido->Text = contenido;
            txtContenido->Dock = DockStyle::Fill;
            txtContenido->ReadOnly = true;
            txtContenido->ScrollBars = ScrollBars::Vertical;
            txtContenido->BackColor = Color::White;

            panel->Controls->Add(txtContenido);
            panel->Controls->Add(lblTitulo);

            return panel;
        }
    };

    static int CompararArchivosPorFecha(String^ a, String^ b) {
        return DateTime::Compare(
            File::GetCreationTime(b),
            File::GetCreationTime(a)
        );
    }

    void Crear_reporte_factura(Label^ label) {
        static int contador = 1;

        try {
            std::string nombre_archivo = "factura_" + std::to_string(contador) + ".txt";
            std::string contenido = marshal_as<std::string>(label->Text);

            std::ofstream archivo(nombre_archivo);
            if (archivo.is_open()) {
                archivo << contenido;
                archivo.close();
                contador++;
            }
        }
        catch (...) {} // Error silenciado
    }

    void Mostrar_reportes() {
        try {
            array<String^>^ todosArchivos = Directory::GetFiles(".", "factura_*.txt");

            // Verificar si no hay archivos
            if (todosArchivos->Length == 0) {
               MessageBox::Show( "No hay facturas para mostrar","Información",MessageBoxButtons::OK,MessageBoxIcon::Information);
            }

            List<String^>^ archivosOrdenados = gcnew List<String^>(todosArchivos);
            archivosOrdenados->Sort(gcnew Comparison<String^>(&CompararArchivosPorFecha));

            List<String^>^ ultimas10 = gcnew List<String^>();
            for (int i = 0; i < Math::Min(10, archivosOrdenados->Count); ++i) {
                ultimas10->Add(archivosOrdenados[i]);
            }

            Application::EnableVisualStyles();

            VisorFacturasForm^ visor = gcnew VisorFacturasForm(ultimas10, total_de_ventas, gcnew String(stock_mas_bajo.c_str()), NumeroClientesRecibidos, NumeroClientesAtendidos, NumeroClientesDevueltos);
            visor->ShowDialog();
        }
        catch (Exception^ e) {
            MessageBox::Show(
                "Error al leer facturas: " + e->Message,
                "Error",
                MessageBoxButtons::OK,
                MessageBoxIcon::Error
            );
        }
    }

    void EliminarReportesFacturas() {
        try {
            array<String^>^ archivos = Directory::GetFiles(".", "factura_*.txt");
            for each (String ^ archivo in archivos) {
                File::Delete(archivo);
            }

            // Resetear contador de facturas
            static int& contador = *new int(1);  // Acceder al contador estático
            contador = 1;
        }
        catch (...) {}
    }
}


void obtener_cliente_en_cola(std::queue<Tienda::clientes>& cola_clientes) {
    if (!cola_clientes.empty()) {
        id_carrito_factura = cola_clientes.front().carrito_id;
    }
}

void quitar_total_productos(System::Windows::Forms::Label^ label, int& total_productos, int nro_carrito) {
    label->Text = "Carrito #" + nro_carrito + "\n";
    total_productos = 0;
}
