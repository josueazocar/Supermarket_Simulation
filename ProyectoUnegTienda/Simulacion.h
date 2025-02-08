// "Simulacion.h"

#pragma once
namespace ProyectoUnegTienda {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

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
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label3_2;
    private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::Label^ label4_2;;

    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Label^ label5_2;

    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label2_2;
           
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::Label^ label7_2;

    private:
        System::Windows::Forms::Timer^ timer;
        System::Windows::Forms::Timer^ timer2;
        System::Windows::Forms::Timer^ timer3;
        System::Windows::Forms::Timer^ timer4;
        System::Windows::Forms::Timer ^ timer5;
        System::Windows::Forms::Timer ^ timer6;
        System::Windows::Forms::Timer^ timerCronometro;
        System::Windows::Forms::Timer^ timer_gestion_de_clientes;

        int segundosTranscurridos;
        int contador;
        int contador2;
        int contador3;
        int contador4;
        int contador5;
        int contador6;

    private: System::Windows::Forms::Label^ label10;
    private: System::Windows::Forms::Label^ label10_2;
    private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
    private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel3;
    private: System::Windows::Forms::Label^ label8;
    private: System::Windows::Forms::Label^ label9;


    private: System::ComponentModel::IContainer^ components;


           void InitializeComponent(void)
           {
               this->components = (gcnew System::ComponentModel::Container());
               this->timerCronometro = (gcnew System::Windows::Forms::Timer(this->components));
               this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
               this->label3 = (gcnew System::Windows::Forms::Label());
               this->label4 = (gcnew System::Windows::Forms::Label());
               this->label5 = (gcnew System::Windows::Forms::Label());
               this->label3_2 = (gcnew System::Windows::Forms::Label());
               this->label4_2 = (gcnew System::Windows::Forms::Label());
               this->label5_2 = (gcnew System::Windows::Forms::Label());
               this->label2 = (gcnew System::Windows::Forms::Label());
               this->label2_2 = (gcnew System::Windows::Forms::Label());
               this->label7 = (gcnew System::Windows::Forms::Label());
               this->label7_2 = (gcnew System::Windows::Forms::Label());
               this->label10 = (gcnew System::Windows::Forms::Label());
               this->label10_2 = (gcnew System::Windows::Forms::Label());
               this->panel1 = (gcnew System::Windows::Forms::Panel());
               this->label8 = (gcnew System::Windows::Forms::Label());
               this->label1 = (gcnew System::Windows::Forms::Label());
               this->label6 = (gcnew System::Windows::Forms::Label());
               this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
               this->label9 = (gcnew System::Windows::Forms::Label());
               this->flowLayoutPanel3 = (gcnew System::Windows::Forms::FlowLayoutPanel());
               this->flowLayoutPanel1->SuspendLayout();
               this->panel1->SuspendLayout();
               this->flowLayoutPanel2->SuspendLayout();
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
               this->flowLayoutPanel1->BackColor = System::Drawing::Color::Snow;
               this->flowLayoutPanel1->Controls->Add(this->label3);
               this->flowLayoutPanel1->Controls->Add(this->label4);
               this->flowLayoutPanel1->Controls->Add(this->label5);
               this->flowLayoutPanel1->Location = System::Drawing::Point(0, -2);
               this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
               this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
               this->flowLayoutPanel1->Size = System::Drawing::Size(1191, 386);
               this->flowLayoutPanel1->TabIndex = 1;
               this->flowLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Simulacion::flowLayoutPanel1_Paint);
               // 
               // label3
               // 
               this->label3->AutoSize = true;
               this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
                   static_cast<System::Int32>(static_cast<System::Byte>(192)));
               this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label3->Location = System::Drawing::Point(4, 0);
               this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
               this->label3->Name = L"label3";
               this->label3->Size = System::Drawing::Size(116, 24);
               this->label3->TabIndex = 1;
               this->label3->Text = L"Carrito: #1 \n";
               this->label3->Click += gcnew System::EventHandler(this, &Simulacion::label3_Click);
               // 
               // label4
               // 
               this->label4->AutoSize = true;
               this->label4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                   static_cast<System::Int32>(static_cast<System::Byte>(192)));
               this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label4->Location = System::Drawing::Point(128, 0);
               this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
               this->label4->Name = L"label4";
               this->label4->Size = System::Drawing::Size(116, 24);
               this->label4->TabIndex = 2;
               this->label4->Text = L"Carrito: #2 \n";
               this->label4->Click += gcnew System::EventHandler(this, &Simulacion::label4_Click);
               // 
               // label5
               // 
               this->label5->AutoSize = true;
               this->label5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
                   static_cast<System::Int32>(static_cast<System::Byte>(255)));
               this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label5->Location = System::Drawing::Point(252, 0);
               this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
               this->label5->Name = L"label5";
               this->label5->Size = System::Drawing::Size(116, 24);
               this->label5->TabIndex = 3;
               this->label5->Text = L"Carrito: #3 \n";
               this->label5->Click += gcnew System::EventHandler(this, &Simulacion::label5_Click);
               // 
               // label3_2
               // 
               this->label3_2->Location = System::Drawing::Point(0, 0);
               this->label3_2->Name = L"label3_2";
               this->label3_2->Size = System::Drawing::Size(100, 23);
               this->label3_2->TabIndex = 0;
               // 
               // label4_2
               // 
               this->label4_2->Location = System::Drawing::Point(0, 0);
               this->label4_2->Name = L"label4_2";
               this->label4_2->Size = System::Drawing::Size(100, 23);
               this->label4_2->TabIndex = 0;
               // 
               // label5_2
               // 
               this->label5_2->Location = System::Drawing::Point(0, 0);
               this->label5_2->Name = L"label5_2";
               this->label5_2->Size = System::Drawing::Size(100, 23);
               this->label5_2->TabIndex = 0;
               // 
               // label2
               // 
               this->label2->AutoSize = true;
               this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
                   static_cast<System::Int32>(static_cast<System::Byte>(255)));
               this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label2->Location = System::Drawing::Point(4, 0);
               this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
               this->label2->Name = L"label2";
               this->label2->Size = System::Drawing::Size(116, 24);
               this->label2->TabIndex = 0;
               this->label2->Text = L"Carrito: #4 \n";
               this->label2->Click += gcnew System::EventHandler(this, &Simulacion::label2_Click);
               // 
               // label2_2
               // 
               this->label2_2->Location = System::Drawing::Point(0, 0);
               this->label2_2->Name = L"label2_2";
               this->label2_2->Size = System::Drawing::Size(100, 23);
               this->label2_2->TabIndex = 0;
               // 
               // label7
               // 
               this->label7->AutoSize = true;
               this->label7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                   static_cast<System::Int32>(static_cast<System::Byte>(192)));
               this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label7->Location = System::Drawing::Point(128, 0);
               this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
               this->label7->Name = L"label7";
               this->label7->Size = System::Drawing::Size(116, 24);
               this->label7->TabIndex = 4;
               this->label7->Text = L"Carrito: #5 \n";
               this->label7->Click += gcnew System::EventHandler(this, &Simulacion::label7_Click);
               // 
               // label7_2
               // 
               this->label7_2->Location = System::Drawing::Point(0, 0);
               this->label7_2->Name = L"label7_2";
               this->label7_2->Size = System::Drawing::Size(100, 23);
               this->label7_2->TabIndex = 0;
               // 
               // label10
               // 
               this->label10->AutoSize = true;
               this->label10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                   static_cast<System::Int32>(static_cast<System::Byte>(255)));
               this->label10->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label10->Location = System::Drawing::Point(252, 0);
               this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
               this->label10->Name = L"label10";
               this->label10->Size = System::Drawing::Size(109, 24);
               this->label10->TabIndex = 7;
               this->label10->Text = L"Carrito #6 \n";
               this->label10->Click += gcnew System::EventHandler(this, &Simulacion::label10_Click);
               // 
               // label10_2
               // 
               this->label10_2->Location = System::Drawing::Point(0, 0);
               this->label10_2->Name = L"label10_2";
               this->label10_2->Size = System::Drawing::Size(100, 23);
               this->label10_2->TabIndex = 0;
               // 
               // panel1
               // 
               this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
               this->panel1->BackColor = System::Drawing::Color::Sienna;
               this->panel1->Controls->Add(this->label8);
               this->panel1->Controls->Add(this->label1);
               this->panel1->Location = System::Drawing::Point(0, 781);
               this->panel1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
               this->panel1->Name = L"panel1";
               this->panel1->Size = System::Drawing::Size(1612, 266);
               this->panel1->TabIndex = 2;
               this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Simulacion::panel1_Paint);
               // 
               // label8
               // 
               this->label8->AutoSize = true;
               this->label8->BackColor = System::Drawing::Color::Snow;
               this->label8->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label8->Location = System::Drawing::Point(3, 235);
               this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
               this->label8->Name = L"label8";
               this->label8->Size = System::Drawing::Size(112, 28);
               this->label8->TabIndex = 1;
               this->label8->Text = L"00:00:00";
               this->label8->Click += gcnew System::EventHandler(this, &Simulacion::label8_Click);
               // 
               // label1
               // 
               this->label1->AutoSize = true;
               this->label1->Location = System::Drawing::Point(747, 75);
               this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
               this->label1->Name = L"label1";
               this->label1->Size = System::Drawing::Size(51, 20);
               this->label1->TabIndex = 0;
               this->label1->Text = L"label1";
               // 
               // label6
               // 
               this->label6->AutoSize = true;
               this->label6->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
               this->label6->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label6->ForeColor = System::Drawing::Color::White;
               this->label6->Location = System::Drawing::Point(1719, 14);
               this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
               this->label6->Name = L"label6";
               this->label6->Size = System::Drawing::Size(170, 25);
               this->label6->TabIndex = 3;
               this->label6->Text = L"Cola de Clientes";
               this->label6->TextAlign = System::Drawing::ContentAlignment::TopRight;
               this->label6->Click += gcnew System::EventHandler(this, &Simulacion::label6_Click);
               // 
               // flowLayoutPanel2
               // 
               this->flowLayoutPanel2->BackColor = System::Drawing::Color::Moccasin;
               this->flowLayoutPanel2->Controls->Add(this->label9);
               this->flowLayoutPanel2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
               this->flowLayoutPanel2->Location = System::Drawing::Point(1128, -2);
               this->flowLayoutPanel2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
               this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
               this->flowLayoutPanel2->Size = System::Drawing::Size(484, 840);
               this->flowLayoutPanel2->TabIndex = 4;
               this->flowLayoutPanel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Simulacion::flowLayoutPanel2_Paint);
               // 
               // label9
               // 
               this->label9->AutoSize = true;
               this->label9->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
               this->label9->Location = System::Drawing::Point(3, 0);
               this->label9->Name = L"label9";
               this->label9->Size = System::Drawing::Size(51, 20);
               this->label9->TabIndex = 2;
               this->label9->Text = L"label9";
               this->label9->Click += gcnew System::EventHandler(this, &Simulacion::label9_Click);
               // 
               // flowLayoutPanel3
               // 
               this->flowLayoutPanel3->BackColor = System::Drawing::Color::White;
               this->flowLayoutPanel3->Controls->Add(this->label2);
               this->flowLayoutPanel3->Controls->Add(this->label7);
               this->flowLayoutPanel3->Controls->Add(this->label10);
               this->flowLayoutPanel3->Location = System::Drawing::Point(0, 406);
               this->flowLayoutPanel3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
               this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
               this->flowLayoutPanel3->Size = System::Drawing::Size(1208, 432);
               this->flowLayoutPanel3->TabIndex = 5;
               this->flowLayoutPanel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Simulacion::flowLayoutPanel3_Paint);
               // 
               // Simulacion
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->BackColor = System::Drawing::Color::Black;
               this->ClientSize = System::Drawing::Size(1896, 1048);
               this->Controls->Add(this->panel1);
               this->Controls->Add(this->flowLayoutPanel2);
               this->Controls->Add(this->label6);
               this->Controls->Add(this->flowLayoutPanel1);
               this->Controls->Add(this->flowLayoutPanel3);
               this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
               this->Name = L"Simulacion";
               this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
               this->Text = L"Simulación";
               this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
               this->Load += gcnew System::EventHandler(this, &Simulacion::Simulacion_Load);
               this->flowLayoutPanel1->ResumeLayout(false);
               this->flowLayoutPanel1->PerformLayout();
               this->panel1->ResumeLayout(false);
               this->panel1->PerformLayout();
               this->flowLayoutPanel2->ResumeLayout(false);
               this->flowLayoutPanel2->PerformLayout();
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

private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
    
}
private: System::Void flowLayoutPanel3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
