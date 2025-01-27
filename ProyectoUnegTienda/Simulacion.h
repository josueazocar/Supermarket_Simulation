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


    private: System::ComponentModel::IContainer^ components;


           void InitializeComponent(void)
           {
               this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
               this->label3 = (gcnew System::Windows::Forms::Label());
               this->label3_2 = (gcnew System::Windows::Forms::Label());
               this->label4 = (gcnew System::Windows::Forms::Label());
               this->label4_2 = (gcnew System::Windows::Forms::Label());

               this->label5 = (gcnew System::Windows::Forms::Label());
               this->label5_2 = (gcnew System::Windows::Forms::Label());

               this->label2 = (gcnew System::Windows::Forms::Label());
               this->label2_2 = (gcnew System::Windows::Forms::Label());

               this->label7 = (gcnew System::Windows::Forms::Label());
               this->label7_2 = (gcnew System::Windows::Forms::Label());

               this->label10 = (gcnew System::Windows::Forms::Label());
               this->label10_2 = (gcnew System::Windows::Forms::Label());
               this->panel1 = (gcnew System::Windows::Forms::Panel());
               this->label1 = (gcnew System::Windows::Forms::Label());
               this->label6 = (gcnew System::Windows::Forms::Label());
               this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
               this->flowLayoutPanel3 = (gcnew System::Windows::Forms::FlowLayoutPanel());
               this->flowLayoutPanel1->SuspendLayout();
               this->panel1->SuspendLayout();
               this->flowLayoutPanel3->SuspendLayout();
               this->SuspendLayout();
               // 
               // flowLayoutPanel1
               // 
               this->flowLayoutPanel1->BackColor = System::Drawing::Color::Snow;
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
               this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
                   static_cast<System::Int32>(static_cast<System::Byte>(192)));
               this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label3->Location = System::Drawing::Point(3, 0);
               this->label3->Name = L"label3";
               this->label3->Size = System::Drawing::Size(100, 96);
               this->label3->TabIndex = 1;
               this->label3->Text = L"Cliente: #1 \n";
               this->label3->Click += gcnew System::EventHandler(this, &Simulacion::label3_Click);
               // 
               // label4
               // 
               this->label4->AutoSize = true;
               this->label4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                   static_cast<System::Int32>(static_cast<System::Byte>(192)));
               this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label4->Location = System::Drawing::Point(109, 0);
               this->label4->Name = L"label4";
               this->label4->Size = System::Drawing::Size(100, 96);
               this->label4->TabIndex = 2;
               this->label4->Text = L"Cliente: #2 \n";
               this->label4->Click += gcnew System::EventHandler(this, &Simulacion::label4_Click);
               // 
               // label5
               // 
               this->label5->AutoSize = true;
               this->label5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
                   static_cast<System::Int32>(static_cast<System::Byte>(255)));
               this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label5->Location = System::Drawing::Point(215, 0);
               this->label5->Name = L"label5";
               this->label5->Size = System::Drawing::Size(100, 96);
               this->label5->TabIndex = 3;
               this->label5->Text = L"Cliente: #3 \n";
               this->label5->Click += gcnew System::EventHandler(this, &Simulacion::label5_Click);
               // 
               // label2
               // 
               this->label2->AutoSize = true;
               this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
                   static_cast<System::Int32>(static_cast<System::Byte>(255)));
               this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label2->Location = System::Drawing::Point(3, 0);
               this->label2->Name = L"label2";
               this->label2->Size = System::Drawing::Size(100, 96);
               this->label2->TabIndex = 0;
               this->label2->Text = L"Cliente: #4 \n";
               this->label2->Click += gcnew System::EventHandler(this, &Simulacion::label2_Click);
               // 
               // label7
               // 
               this->label7->AutoSize = true;
               this->label7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                   static_cast<System::Int32>(static_cast<System::Byte>(192)));
               this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label7->Location = System::Drawing::Point(109, 0);
               this->label7->Name = L"label7";
               this->label7->Size = System::Drawing::Size(100, 96);
               this->label7->TabIndex = 4;
               this->label7->Text = L"Cliente: #5 \n";
               this->label7->Click += gcnew System::EventHandler(this, &Simulacion::label7_Click);
               // 
               // label10
               // 
               this->label10->AutoSize = true;
               this->label10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                   static_cast<System::Int32>(static_cast<System::Byte>(255)));
               this->label10->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label10->Location = System::Drawing::Point(215, 0);
               this->label10->Name = L"label10";
               this->label10->Size = System::Drawing::Size(11, 16);
               this->label10->TabIndex = 7;
               this->label10->Text = L"Carrito #6 \n";
               this->label10->Click += gcnew System::EventHandler(this, &Simulacion::label10_Click);
               // 
               // panel1
               // 
               this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
               this->panel1->BackColor = System::Drawing::Color::Sienna;
               this->panel1->Controls->Add(this->label1);
               this->panel1->Location = System::Drawing::Point(0, 469);
               this->panel1->Name = L"panel1";
               this->panel1->Size = System::Drawing::Size(1075, 211);
               this->panel1->TabIndex = 2;
               this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Simulacion::panel1_Paint);
               // 
               // label1
               // 
               this->label1->AutoSize = true;
               this->label1->Location = System::Drawing::Point(498, 49);
               this->label1->Name = L"label1";
               this->label1->Size = System::Drawing::Size(35, 13);
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
               this->label6->Location = System::Drawing::Point(1146, 9);
               this->label6->Name = L"label6";
               this->label6->Size = System::Drawing::Size(115, 17);
               this->label6->TabIndex = 3;
               this->label6->Text = L"Cola de Clientes";
               this->label6->TextAlign = System::Drawing::ContentAlignment::TopRight;
               this->label6->Click += gcnew System::EventHandler(this, &Simulacion::label6_Click);
               // 
               // flowLayoutPanel2
               // 
               this->flowLayoutPanel2->BackColor = System::Drawing::Color::Moccasin;
               this->flowLayoutPanel2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
               this->flowLayoutPanel2->Location = System::Drawing::Point(752, -1);
               this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
               this->flowLayoutPanel2->Size = System::Drawing::Size(323, 546);
               this->flowLayoutPanel2->TabIndex = 4;
               this->flowLayoutPanel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Simulacion::flowLayoutPanel2_Paint);
               // 
               // flowLayoutPanel3
               // 
               this->flowLayoutPanel3->BackColor = System::Drawing::Color::White;
               this->flowLayoutPanel3->Controls->Add(this->label2);
               this->flowLayoutPanel3->Controls->Add(this->label7);
               this->flowLayoutPanel3->Controls->Add(this->label10);
               this->flowLayoutPanel3->Location = System::Drawing::Point(0, 264);
               this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
               this->flowLayoutPanel3->Size = System::Drawing::Size(805, 281);
               this->flowLayoutPanel3->TabIndex = 5;
               this->flowLayoutPanel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Simulacion::flowLayoutPanel3_Paint);
               // 
               // Simulacion
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->BackColor = System::Drawing::Color::Black;
               this->ClientSize = System::Drawing::Size(1264, 681);
               this->Controls->Add(this->panel1);
               this->Controls->Add(this->flowLayoutPanel2);
               this->Controls->Add(this->label6);
               this->Controls->Add(this->flowLayoutPanel1);
               this->Controls->Add(this->flowLayoutPanel3);
               this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
               this->Margin = System::Windows::Forms::Padding(2);
               this->Name = L"Simulacion";
               this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
               this->Text = L"Simulación";
               this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
               this->Load += gcnew System::EventHandler(this, &Simulacion::Simulacion_Load);
               this->flowLayoutPanel1->ResumeLayout(false);
               this->flowLayoutPanel1->PerformLayout();
               this->panel1->ResumeLayout(false);
               this->panel1->PerformLayout();
               this->flowLayoutPanel3->ResumeLayout(false);
               this->flowLayoutPanel3->PerformLayout();
               this->ResumeLayout(false);
               this->PerformLayout();

           }

         

        public:
            void EmpezarSimulacion();
        private: System::Void Simulacion_Load(System::Object^ sender, System::EventArgs^ e);
     
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
private: System::Void OnTimedEvent2(System::Object^ sender, System::EventArgs^ e);
private: System::Void OnTimedEvent3(System::Object^ sender, System::EventArgs^ e);
private: System::Void OnTimedEvent4(System::Object^ sender, System::EventArgs^ e);
private: System::Void OnTimedEvent5(System::Object^ sender, System::EventArgs^ e);
private: System::Void OnTimedEvent6(System::Object^ sender, System::EventArgs^ e);

private: System::Void OnTimedEvent(System::Object^ sender, System::EventArgs^ e);

private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
    
}
private: System::Void flowLayoutPanel3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}
