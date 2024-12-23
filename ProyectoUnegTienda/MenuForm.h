#pragma once
#include "Simulacion.h"

namespace ProyectoUnegTienda {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MenuForm
	/// </summary>
	public ref class MenuForm : public System::Windows::Forms::Form
	{
		public:
			MenuForm(void)
			{
				InitializeComponent();
				//
				//TODO: Add the constructor code here
				//
			}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~MenuForm()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Button^ empezarSimulacionBoton;
		protected:

		private:
			/// <summary>
			/// Required designer variable.
			/// </summary>
			System::ComponentModel::Container ^components;

	#pragma region Windows Form Designer generated code
			/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>
			void InitializeComponent(void)
			{
				this->empezarSimulacionBoton = (gcnew System::Windows::Forms::Button());
				this->SuspendLayout();
				// 
				// empezarSimulacionBoton
				// 
				this->empezarSimulacionBoton->Location = System::Drawing::Point(420, 118);
				this->empezarSimulacionBoton->Name = L"empezarSimulacionBoton";
				this->empezarSimulacionBoton->Size = System::Drawing::Size(212, 122);
				this->empezarSimulacionBoton->TabIndex = 0;
				this->empezarSimulacionBoton->Text = L"Empezar Simulación";
				this->empezarSimulacionBoton->UseVisualStyleBackColor = true;
				this->empezarSimulacionBoton->Click += gcnew System::EventHandler(this, &MenuForm::EmpezarFormularioClick);
				// 
				// MenuForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(1053, 401);
				this->Controls->Add(this->empezarSimulacionBoton);
				this->Name = L"MenuForm";
				this->Text = L"Menú del formulario";
				this->Load += gcnew System::EventHandler(this, &MenuForm::MenuForm_Load);
				this->ResumeLayout(false);

			}
	#pragma endregion
		private: System::Void MenuForm_Load(System::Object^ sender, System::EventArgs^ e) {
		}

	
		 // accion que se realiza al hacer click en el boton de empezar simulacion
		private: System::Void EmpezarFormularioClick(System::Object^ sender, System::EventArgs^ e) {

			this->Hide(); 
			 Simulacion^ simulationForm = gcnew Simulacion();
			simulationForm->ShowDialog(); 
			this->Show();

		}
	};
}
