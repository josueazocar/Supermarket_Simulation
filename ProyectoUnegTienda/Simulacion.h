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

    private: System::Windows::Forms::Label^ simulacionTexto;
    private: System::ComponentModel::Container^ components;

           void InitializeComponent(void)
           {
               this->simulacionTexto = (gcnew System::Windows::Forms::Label());
               this->SuspendLayout();
               // prueba
               // simulacionTexto
               // 
               this->simulacionTexto->AutoSize = true;
               this->simulacionTexto->Location = System::Drawing::Point(376, 7);
               this->simulacionTexto->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
               this->simulacionTexto->Name = L"simulacionTexto";
               this->simulacionTexto->Size = System::Drawing::Size(58, 13);
               this->simulacionTexto->TabIndex = 0;
               this->simulacionTexto->Text = L"Simulación";
               this->simulacionTexto->Click += gcnew System::EventHandler(this, &Simulacion::simulacionTexto_Click);
               // 
               // Simulacion
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(1037, 369);
               this->Controls->Add(this->simulacionTexto);
               this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
               this->Name = L"Simulacion";
               this->Text = L"Simulación";
               this->Load += gcnew System::EventHandler(this, &Simulacion::Simulacion_Load_1);
               this->ResumeLayout(false);
               this->PerformLayout();

           }

    public:
        void EmpezarSimulacion();
    private: System::Void Simulacion_Load(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void Simulacion_Load_1(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void simulacionTexto_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    };
}


