// "Simulacion.h"
#pragma once
#include "factura.h"
#include "cola_clientes.h"

namespace ProyectoUnegTienda {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace Factura_Reportes;

    public ref class Simulacion : public System::Windows::Forms::Form
    {
    public:
        Simulacion(void)
        {
            InitializeComponent();
        }

    protected:
        ~Simulacion()
        {
            if (components)
            {
                delete components;
            }
        }


        private: Random^ random;
    private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
    private: System::Windows::Forms::Panel^ panel1;

    private: System::Windows::Forms::Label^ label3;

    private: System::Windows::Forms::Label^ label4;



    private: System::Windows::Forms::Label^ label5;


    private: System::Windows::Forms::Label^ label2;

           
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::Label^ label7;

    private: System::Collections::Generic::List<Label^>^ etiquetasClientes;


    private:
        System::Windows::Forms::Timer^ timer_carrito1;
        System::Windows::Forms::Timer^ timer_carrito2;
        System::Windows::Forms::Timer^ timer_carrito3;
        System::Windows::Forms::Timer^ timer_carrito4;
        System::Windows::Forms::Timer ^ timer_carrito5;
        System::Windows::Forms::Timer ^ timer_carrito6;
        System::Windows::Forms::Timer^ timerCronometro;
        System::Windows::Forms::Timer^ timer_gestion_de_clientes;
        System::Windows::Forms::Timer^ timer_MoverClientesAlFinal;
        System::Windows::Forms::Timer^ timer_creacion_factura;

        
        int segundosTranscurridos;
        int contador_carrito1;
        int contador_carrito2;
        int contador_carrito3;
        int contador_carrito4;
        int contador_carrito5;
        int contador_carrito6;
        int Precio_total_para_factura;
        int indice_producto_mas_vendido;
       


    private: System::Windows::Forms::Label^ label10;

    private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
    private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel3;
    private: System::Windows::Forms::Label^ label8;
    private: System::Windows::Forms::Label^ label9;


    private: System::Windows::Forms::Label^ label11;
    private: System::Windows::Forms::Label^ label12;
    private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel4;
    private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel5;
    private: System::Windows::Forms::Label^ puestoEnCola;
    private: System::Windows::Forms::Label^ puestoEnCola2;
    private: System::Windows::Forms::Label^ puestoEnCola3;
    private: System::Windows::Forms::Label^ puestoEnCola4;
    private: System::Windows::Forms::Label^ puestoEnCola5;
    private: System::Windows::Forms::Label^ puestoEnCola6;
    private: bool isPaused = false; //para controlar la pausa de la simulacion
    private: System::Windows::Forms::Button^ pausarOreanudarButton;
    private: System::Windows::Forms::Button^ cerrarProgramaButton;


    private: System::ComponentModel::IContainer^ components;


           void InitializeComponent(void)
           {
               this->components = (gcnew System::ComponentModel::Container());
               System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Simulacion::typeid));
               this->timerCronometro = (gcnew System::Windows::Forms::Timer(this->components));
               this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
               this->label3 = (gcnew System::Windows::Forms::Label());
               this->label4 = (gcnew System::Windows::Forms::Label());
               this->label5 = (gcnew System::Windows::Forms::Label());
               this->label2 = (gcnew System::Windows::Forms::Label());
               this->label7 = (gcnew System::Windows::Forms::Label());
               this->label10 = (gcnew System::Windows::Forms::Label());
               this->panel1 = (gcnew System::Windows::Forms::Panel());
               this->cerrarProgramaButton = (gcnew System::Windows::Forms::Button());
               this->label8 = (gcnew System::Windows::Forms::Label());
               this->label6 = (gcnew System::Windows::Forms::Label());
               this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
               this->flowLayoutPanel4 = (gcnew System::Windows::Forms::FlowLayoutPanel());
               this->label11 = (gcnew System::Windows::Forms::Label());
               this->flowLayoutPanel5 = (gcnew System::Windows::Forms::FlowLayoutPanel());
               this->label12 = (gcnew System::Windows::Forms::Label());
               this->label9 = (gcnew System::Windows::Forms::Label());
               this->flowLayoutPanel3 = (gcnew System::Windows::Forms::FlowLayoutPanel());
               this->puestoEnCola = (gcnew System::Windows::Forms::Label());
               this->puestoEnCola2 = (gcnew System::Windows::Forms::Label());
               this->puestoEnCola3 = (gcnew System::Windows::Forms::Label());
               this->puestoEnCola4 = (gcnew System::Windows::Forms::Label());
               this->puestoEnCola5 = (gcnew System::Windows::Forms::Label());
               this->puestoEnCola6 = (gcnew System::Windows::Forms::Label());
               this->pausarOreanudarButton = (gcnew System::Windows::Forms::Button());
               this->flowLayoutPanel1->SuspendLayout();
               this->panel1->SuspendLayout();
               this->flowLayoutPanel2->SuspendLayout();
               this->flowLayoutPanel4->SuspendLayout();
               this->flowLayoutPanel5->SuspendLayout();
               this->flowLayoutPanel3->SuspendLayout();
               this->SuspendLayout();
               // 
               // timerCronometro
               // 
               this->timerCronometro->Interval = 1000;
               this->timerCronometro->Tick += gcnew System::EventHandler(this, &Simulacion::ActualizarCronometro);
               // 
               // flowLayoutPanel1
               // 
               this->flowLayoutPanel1->BackColor = System::Drawing::Color::BurlyWood;
               this->flowLayoutPanel1->Controls->Add(this->label3);
               this->flowLayoutPanel1->Controls->Add(this->label4);
               this->flowLayoutPanel1->Controls->Add(this->label5);
               this->flowLayoutPanel1->Location = System::Drawing::Point(0, -1);
               this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
               this->flowLayoutPanel1->Size = System::Drawing::Size(794, 251);
               this->flowLayoutPanel1->TabIndex = 1;
               this->flowLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Simulacion::flowLayoutPanel1_Paint);
               // 
               // label3
               // 
               this->label3->AutoSize = true;
               this->label3->BackColor = System::Drawing::Color::OrangeRed;
               this->label3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
               this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label3->ForeColor = System::Drawing::SystemColors::ButtonFace;
               this->label3->Location = System::Drawing::Point(3, 0);
               this->label3->Name = L"label3";
               this->label3->Size = System::Drawing::Size(74, 18);
               this->label3->TabIndex = 1;
               this->label3->Text = L"Carrito #1 \n";
               this->label3->Click += gcnew System::EventHandler(this, &Simulacion::label3_Click);
               // 
               // label4
               // 
               this->label4->AutoSize = true;
               this->label4->BackColor = System::Drawing::Color::ForestGreen;
               this->label4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
               this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
               this->label4->Location = System::Drawing::Point(83, 0);
               this->label4->Name = L"label4";
               this->label4->Size = System::Drawing::Size(74, 18);
               this->label4->TabIndex = 2;
               this->label4->Text = L"Carrito #2 \n";
               this->label4->Click += gcnew System::EventHandler(this, &Simulacion::label4_Click);
               // 
               // label5
               // 
               this->label5->AutoSize = true;
               this->label5->BackColor = System::Drawing::Color::DodgerBlue;
               this->label5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
               this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label5->ForeColor = System::Drawing::SystemColors::ButtonFace;
               this->label5->Location = System::Drawing::Point(163, 0);
               this->label5->Name = L"label5";
               this->label5->Size = System::Drawing::Size(74, 18);
               this->label5->TabIndex = 3;
               this->label5->Text = L"Carrito #3 \n";
               this->label5->Click += gcnew System::EventHandler(this, &Simulacion::label5_Click);
               // 
               // label2
               // 
               this->label2->AutoSize = true;
               this->label2->BackColor = System::Drawing::Color::DarkOrchid;
               this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
               this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label2->ForeColor = System::Drawing::SystemColors::ButtonFace;
               this->label2->Location = System::Drawing::Point(3, 0);
               this->label2->Name = L"label2";
               this->label2->Size = System::Drawing::Size(74, 18);
               this->label2->TabIndex = 0;
               this->label2->Text = L"Carrito #4 \n";
               this->label2->Click += gcnew System::EventHandler(this, &Simulacion::label2_Click);
               // 
               // label7
               // 
               this->label7->AutoSize = true;
               this->label7->BackColor = System::Drawing::Color::Crimson;
               this->label7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
               this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label7->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
               this->label7->Location = System::Drawing::Point(83, 0);
               this->label7->Name = L"label7";
               this->label7->Size = System::Drawing::Size(74, 18);
               this->label7->TabIndex = 4;
               this->label7->Text = L"Carrito #5 \n";
               this->label7->Click += gcnew System::EventHandler(this, &Simulacion::label7_Click);
               // 
               // label10
               // 
               this->label10->AutoSize = true;
               this->label10->BackColor = System::Drawing::Color::DarkCyan;
               this->label10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
               this->label10->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label10->ForeColor = System::Drawing::SystemColors::ButtonFace;
               this->label10->Location = System::Drawing::Point(163, 0);
               this->label10->Name = L"label10";
               this->label10->Size = System::Drawing::Size(74, 18);
               this->label10->TabIndex = 7;
               this->label10->Text = L"Carrito #6 \n";
               this->label10->Click += gcnew System::EventHandler(this, &Simulacion::label10_Click);
               // 
               // panel1
               // 
               this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
               this->panel1->BackColor = System::Drawing::Color::Sienna;
               this->panel1->Controls->Add(this->cerrarProgramaButton);
               this->panel1->Controls->Add(this->label8);
               this->panel1->Location = System::Drawing::Point(0, 574);
               this->panel1->Name = L"panel1";
               this->panel1->Size = System::Drawing::Size(1075, 152);
               this->panel1->TabIndex = 2;
               this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Simulacion::panel1_Paint);
               // 
               // cerrarProgramaButton
               // 
               this->cerrarProgramaButton->BackColor = System::Drawing::Color::DarkRed;
               this->cerrarProgramaButton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->cerrarProgramaButton->ForeColor = System::Drawing::Color::White;
               this->cerrarProgramaButton->Location = System::Drawing::Point(216, 92);
               this->cerrarProgramaButton->Margin = System::Windows::Forms::Padding(2);
               this->cerrarProgramaButton->Name = L"cerrarProgramaButton";
               this->cerrarProgramaButton->Size = System::Drawing::Size(589, 34);
               this->cerrarProgramaButton->TabIndex = 2;
               this->cerrarProgramaButton->Text = L"Detener Simulación";
               this->cerrarProgramaButton->UseVisualStyleBackColor = false;
               this->cerrarProgramaButton->Click += gcnew System::EventHandler(this, &Simulacion::CerrarPrograma);
               // 
               // label8
               // 
               this->label8->AutoSize = true;
               this->label8->BackColor = System::Drawing::Color::Snow;
               this->label8->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label8->Location = System::Drawing::Point(545, 23);
               this->label8->Name = L"label8";
               this->label8->Size = System::Drawing::Size(228, 55);
               this->label8->TabIndex = 1;
               this->label8->Text = L"00:00:00";
               this->label8->Click += gcnew System::EventHandler(this, &Simulacion::label8_Click);
               // 
               // label6
               // 
               this->label6->AutoSize = true;
               this->label6->BackColor = System::Drawing::Color::DarkOrange;
               this->label6->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
               this->label6->Font = (gcnew System::Drawing::Font(L"Copperplate Gothic Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label6->ForeColor = System::Drawing::Color::Black;
               this->label6->Location = System::Drawing::Point(1090, 9);
               this->label6->Name = L"label6";
               this->label6->Size = System::Drawing::Size(161, 20);
               this->label6->TabIndex = 3;
               this->label6->Text = L"Cola de Clientes";
               this->label6->TextAlign = System::Drawing::ContentAlignment::TopRight;
               this->label6->Click += gcnew System::EventHandler(this, &Simulacion::label6_Click);
               // 
               // flowLayoutPanel2
               // 
               this->flowLayoutPanel2->BackColor = System::Drawing::Color::Moccasin;
               this->flowLayoutPanel2->Controls->Add(this->flowLayoutPanel4);
               this->flowLayoutPanel2->Controls->Add(this->flowLayoutPanel5);
               this->flowLayoutPanel2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
               this->flowLayoutPanel2->Location = System::Drawing::Point(752, -1);
               this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
               this->flowLayoutPanel2->Size = System::Drawing::Size(323, 598);
               this->flowLayoutPanel2->TabIndex = 4;
               this->flowLayoutPanel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Simulacion::flowLayoutPanel2_Paint);
               // 
               // flowLayoutPanel4
               // 
               this->flowLayoutPanel4->BackColor = System::Drawing::Color::DarkSeaGreen;
               this->flowLayoutPanel4->Controls->Add(this->label11);
               this->flowLayoutPanel4->Font = (gcnew System::Drawing::Font(L"Haettenschweiler", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->flowLayoutPanel4->Location = System::Drawing::Point(3, 3);
               this->flowLayoutPanel4->Name = L"flowLayoutPanel4";
               this->flowLayoutPanel4->Size = System::Drawing::Size(320, 201);
               this->flowLayoutPanel4->TabIndex = 5;
               this->flowLayoutPanel4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Simulacion::flowLayoutPanel4_Paint);
               // 
               // label11
               // 
               this->label11->AutoSize = true;
               this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label11->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
               this->label11->Location = System::Drawing::Point(3, 0);
               this->label11->Name = L"label11";
               this->label11->Size = System::Drawing::Size(191, 17);
               this->label11->TabIndex = 3;
               this->label11->Text = L"En espera para vaciar carrito...";
               this->label11->Click += gcnew System::EventHandler(this, &Simulacion::label11_Click);
               // 
               // flowLayoutPanel5
               // 
               this->flowLayoutPanel5->BackColor = System::Drawing::Color::LightSteelBlue;
               this->flowLayoutPanel5->Controls->Add(this->label12);
               this->flowLayoutPanel5->Location = System::Drawing::Point(3, 210);
               this->flowLayoutPanel5->Name = L"flowLayoutPanel5";
               this->flowLayoutPanel5->Size = System::Drawing::Size(320, 426);
               this->flowLayoutPanel5->TabIndex = 6;
               // 
               // label12
               // 
               this->label12->AutoSize = true;
               this->label12->BackColor = System::Drawing::Color::LightSteelBlue;
               this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label12->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
               this->label12->Location = System::Drawing::Point(3, 0);
               this->label12->Name = L"label12";
               this->label12->Size = System::Drawing::Size(161, 17);
               this->label12->TabIndex = 4;
               this->label12->Text = L"En Espera para Facturar...";
               this->label12->Click += gcnew System::EventHandler(this, &Simulacion::label12_Click);
               // 
               // label9
               // 
               this->label9->AutoSize = true;
               this->label9->BackColor = System::Drawing::Color::DarkRed;
               this->label9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
               this->label9->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label9->ForeColor = System::Drawing::SystemColors::Control;
               this->label9->Location = System::Drawing::Point(1102, 614);
               this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
               this->label9->Name = L"label9";
               this->label9->Size = System::Drawing::Size(127, 19);
               this->label9->TabIndex = 2;
               this->label9->Text = L"Clientes en cola:";
               this->label9->Click += gcnew System::EventHandler(this, &Simulacion::label9_Click);
               // 
               // flowLayoutPanel3
               // 
               this->flowLayoutPanel3->BackColor = System::Drawing::Color::BurlyWood;
               this->flowLayoutPanel3->Controls->Add(this->label2);
               this->flowLayoutPanel3->Controls->Add(this->label7);
               this->flowLayoutPanel3->Controls->Add(this->label10);
               this->flowLayoutPanel3->Location = System::Drawing::Point(0, 256);
               this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
               this->flowLayoutPanel3->Size = System::Drawing::Size(805, 341);
               this->flowLayoutPanel3->TabIndex = 5;
               this->flowLayoutPanel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Simulacion::flowLayoutPanel3_Paint);
               // 
               // puestoEnCola
               // 
               this->puestoEnCola->BackColor = System::Drawing::Color::DarkOrange;
               this->puestoEnCola->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
               this->puestoEnCola->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->puestoEnCola->ForeColor = System::Drawing::SystemColors::ButtonFace;
               this->puestoEnCola->Location = System::Drawing::Point(1116, 50);
               this->puestoEnCola->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
               this->puestoEnCola->Name = L"puestoEnCola";
               this->puestoEnCola->Size = System::Drawing::Size(104, 57);
               this->puestoEnCola->TabIndex = 4;
               this->puestoEnCola->Text = L"ElementoDeCola1";
               this->puestoEnCola->Visible = false;
               // 
               // puestoEnCola2
               // 
               this->puestoEnCola2->BackColor = System::Drawing::Color::DarkOrange;
               this->puestoEnCola2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
               this->puestoEnCola2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->puestoEnCola2->ForeColor = System::Drawing::SystemColors::ButtonFace;
               this->puestoEnCola2->Location = System::Drawing::Point(1116, 156);
               this->puestoEnCola2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
               this->puestoEnCola2->Name = L"puestoEnCola2";
               this->puestoEnCola2->Size = System::Drawing::Size(104, 57);
               this->puestoEnCola2->TabIndex = 6;
               this->puestoEnCola2->Text = L"ElementoDeCola2";
               this->puestoEnCola2->Visible = false;
               // 
               // puestoEnCola3
               // 
               this->puestoEnCola3->BackColor = System::Drawing::Color::DarkOrange;
               this->puestoEnCola3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
               this->puestoEnCola3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->puestoEnCola3->ForeColor = System::Drawing::SystemColors::ButtonFace;
               this->puestoEnCola3->Location = System::Drawing::Point(1116, 226);
               this->puestoEnCola3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
               this->puestoEnCola3->Name = L"puestoEnCola3";
               this->puestoEnCola3->Size = System::Drawing::Size(104, 57);
               this->puestoEnCola3->TabIndex = 7;
               this->puestoEnCola3->Text = L"ElementoDeCola3";
               this->puestoEnCola3->Visible = false;
               this->puestoEnCola3->Click += gcnew System::EventHandler(this, &Simulacion::puestoEnCola3_Click);
               // 
               // puestoEnCola4
               // 
               this->puestoEnCola4->BackColor = System::Drawing::Color::DarkOrange;
               this->puestoEnCola4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
               this->puestoEnCola4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->puestoEnCola4->ForeColor = System::Drawing::SystemColors::ButtonFace;
               this->puestoEnCola4->Location = System::Drawing::Point(1116, 297);
               this->puestoEnCola4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
               this->puestoEnCola4->Name = L"puestoEnCola4";
               this->puestoEnCola4->Size = System::Drawing::Size(104, 57);
               this->puestoEnCola4->TabIndex = 8;
               this->puestoEnCola4->Text = L"ElementoDeCola4";
               this->puestoEnCola4->Visible = false;
               // 
               // puestoEnCola5
               // 
               this->puestoEnCola5->BackColor = System::Drawing::Color::DarkOrange;
               this->puestoEnCola5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
               this->puestoEnCola5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->puestoEnCola5->ForeColor = System::Drawing::SystemColors::ButtonFace;
               this->puestoEnCola5->Location = System::Drawing::Point(1116, 371);
               this->puestoEnCola5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
               this->puestoEnCola5->Name = L"puestoEnCola5";
               this->puestoEnCola5->Size = System::Drawing::Size(104, 57);
               this->puestoEnCola5->TabIndex = 9;
               this->puestoEnCola5->Text = L"ElementoDeCola1";
               this->puestoEnCola5->Visible = false;
               // 
               // puestoEnCola6
               // 
               this->puestoEnCola6->BackColor = System::Drawing::Color::DarkOrange;
               this->puestoEnCola6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
               this->puestoEnCola6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->puestoEnCola6->ForeColor = System::Drawing::SystemColors::ButtonFace;
               this->puestoEnCola6->Location = System::Drawing::Point(1116, 440);
               this->puestoEnCola6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
               this->puestoEnCola6->Name = L"puestoEnCola6";
               this->puestoEnCola6->Size = System::Drawing::Size(104, 57);
               this->puestoEnCola6->TabIndex = 10;
               this->puestoEnCola6->Text = L"puestoEnCola6";
               this->puestoEnCola6->Visible = false;
               // 
               // pausarOreanudarButton
               // 
               this->pausarOreanudarButton->BackColor = System::Drawing::Color::DarkBlue;
               this->pausarOreanudarButton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->pausarOreanudarButton->ForeColor = System::Drawing::Color::White;
               this->pausarOreanudarButton->Location = System::Drawing::Point(263, 24);
               this->pausarOreanudarButton->Name = L"pausarOreanudarButton";
               this->pausarOreanudarButton->Size = System::Drawing::Size(228, 55);
               this->pausarOreanudarButton->TabIndex = 2;
               this->pausarOreanudarButton->Text = L"Pausar";
               this->pausarOreanudarButton->UseVisualStyleBackColor = false;
               // 
               // Simulacion
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
                   static_cast<System::Int32>(static_cast<System::Byte>(0)));
               this->ClientSize = System::Drawing::Size(1264, 681);
               this->ControlBox = false;
               this->Controls->Add(this->puestoEnCola6);
               this->Controls->Add(this->puestoEnCola5);
               this->Controls->Add(this->puestoEnCola4);
               this->Controls->Add(this->puestoEnCola3);
               this->Controls->Add(this->puestoEnCola2);
               this->Controls->Add(this->label9);
               this->Controls->Add(this->panel1);
               this->Controls->Add(this->flowLayoutPanel2);
               this->Controls->Add(this->puestoEnCola);
               this->Controls->Add(this->label6);
               this->Controls->Add(this->flowLayoutPanel1);
               this->Controls->Add(this->flowLayoutPanel3);
               this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
               this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
               this->Margin = System::Windows::Forms::Padding(2);
               this->MaximumSize = System::Drawing::Size(1280, 720);
               this->MinimumSize = System::Drawing::Size(1280, 720);
               this->Name = L"Simulacion";
               this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
               this->Text = L"Simulación";
               this->Load += gcnew System::EventHandler(this, &Simulacion::Simulacion_Load);
               this->flowLayoutPanel1->ResumeLayout(false);
               this->flowLayoutPanel1->PerformLayout();
               this->panel1->ResumeLayout(false);
               this->panel1->PerformLayout();
               this->flowLayoutPanel2->ResumeLayout(false);
               this->flowLayoutPanel4->ResumeLayout(false);
               this->flowLayoutPanel4->PerformLayout();
               this->flowLayoutPanel5->ResumeLayout(false);
               this->flowLayoutPanel5->PerformLayout();
               this->flowLayoutPanel3->ResumeLayout(false);
               this->flowLayoutPanel3->PerformLayout();
               this->ResumeLayout(false);
               this->PerformLayout();

           }

         

public:
    void EmpezarSimulacion();
    private: System::Void Simulacion_Load(System::Object^ sender, System::EventArgs^ e);

private: System::Void ActualizarCronometro(System::Object^ sender, System::EventArgs^ e) {
    this->segundosTranscurridos++;
    TimeSpan^ tiempo = TimeSpan::FromSeconds(this->segundosTranscurridos);
    this->label8->Text = String::Format("{0:D2}:{1:D2}:{2:D2}", tiempo->Hours, tiempo->Minutes, tiempo->Seconds);
}
     
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void flowLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void flowLayoutPanel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void llenado_de_carrito2(System::Object^ sender, System::EventArgs^ e);
private: System::Void llenado_de_carrito3(System::Object^ sender, System::EventArgs^ e);
private: System::Void llenado_de_carrito4(System::Object^ sender, System::EventArgs^ e);
private: System::Void llenado_de_carrito5(System::Object^ sender, System::EventArgs^ e);
private: System::Void llenado_de_carrito6(System::Object^ sender, System::EventArgs^ e);
private: System::Void GestionarClientes(System::Object^ sender, System::EventArgs^ e);
private: System::Void llenado_de_carrito(System::Object^ sender, System::EventArgs^ e);
private: System::Void MoverClientesAlFinal(System::Object^ sender, System::EventArgs^ e);
private: System::Void ActualizarVisualizacionCola();
private: System::Void pausarOreanudarButton_click(System::Object^ sender, System::EventArgs^ e);
private: System::Void PausarTemporizadores();
private: System::Void ReanudarTemporizadores();

private: System::Void Producto_masvendido();

private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {   
}
private: System::Void flowLayoutPanel3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Creacion_de_factura(System::Object^ sender, System::EventArgs^ e);
private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label11_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Simulacion::No_hay_Stock(System::Object^ sender, System::EventArgs^ e);

private: System::Void label12_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void flowLayoutPanel4_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void puestoEnCola3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void CerrarPrograma(System::Object^ sender, System::EventArgs^ e) {
    // Detener todos los temporizadores
    if (timerCronometro != nullptr) timerCronometro->Stop();
    if (timer_carrito1 != nullptr) timer_carrito1->Stop();
    if (timer_carrito2 != nullptr) timer_carrito2->Stop();
    if (timer_carrito3 != nullptr) timer_carrito3->Stop();
    if (timer_carrito4 != nullptr) timer_carrito4->Stop();
    if (timer_carrito5 != nullptr) timer_carrito5->Stop();
    if (timer_carrito6 != nullptr) timer_carrito6->Stop();
    if (timer_gestion_de_clientes != nullptr) timer_gestion_de_clientes->Stop();
    if (timer_MoverClientesAlFinal != nullptr) timer_MoverClientesAlFinal->Stop();
    if (timer_creacion_factura != nullptr) timer_creacion_factura->Stop();

    // Liberar recursos asignados dinámicamente
    delete timerCronometro;
    delete timer_carrito1;
    delete timer_carrito2;
    delete timer_carrito3;
    delete timer_carrito4;
    delete timer_carrito5;
    delete timer_carrito6;
    delete timer_gestion_de_clientes;
    delete timer_MoverClientesAlFinal;
    delete timer_creacion_factura;

    // Restablecer variables
    segundosTranscurridos = 0;
    contador_carrito1 = 0;
    contador_carrito2 = 0;
    contador_carrito3 = 0;
    contador_carrito4 = 0;
    contador_carrito5 = 0;
    contador_carrito6 = 0;
    Precio_total_para_factura = 0;

    for (int i = 0; i < 6; i++) { //restablecer contadores en arreglos

        tiempoCarrito[i] = 0; //Contiene la cantidad de segundos aleatoria en que el carrito (n) se ejecuta
        CronometroCarrito[i] = 0;  //Cronometriza la cantidad de tiempo en que el carrito esta en ejecuacion hasta que es vaciado
		num_ejecuciones[i] = 0; //Contiene la cantidad de veces que se ha ejecutado el carrito (n)
    }

    // Cerrar el formulario
    this->Close();
    if (stock_se_termino()) {
        MessageBox::Show("No hay productos para vender", "Información", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    Producto_masvendido();
    Mostrar_reportes();
    EliminarReportesFacturas();
    
    //Reiniciar reportes
    total_de_ventas = 0;
    NumeroClientesAtendidos = 0;
    NumeroClientesRecibidos = 0;
    NumeroClientesDevueltos = 0; //variables utilizadas como contadores para los reportes
}
};
}
