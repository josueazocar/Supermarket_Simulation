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
				this->empezarSimulacionBoton->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->empezarSimulacionBoton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				this->empezarSimulacionBoton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
					static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
				this->empezarSimulacionBoton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
				this->empezarSimulacionBoton->Cursor = System::Windows::Forms::Cursors::Hand;
				this->empezarSimulacionBoton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->empezarSimulacionBoton->Font = (gcnew System::Drawing::Font(L"Castellar", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->empezarSimulacionBoton->Location = System::Drawing::Point(144, 322);
				this->empezarSimulacionBoton->Name = L"empezarSimulacionBoton";
				this->empezarSimulacionBoton->Size = System::Drawing::Size(322, 45);
				this->empezarSimulacionBoton->TabIndex = 0;
				this->empezarSimulacionBoton->Text = L"Empezar Simulación";
				this->empezarSimulacionBoton->UseVisualStyleBackColor = false;
				this->empezarSimulacionBoton->Click += gcnew System::EventHandler(this, &MenuForm::EmpezarFormularioClick);
				// 
				// MenuForm
				// 
				this->AcceptButton = this->empezarSimulacionBoton;
				this->AutoScaleDimensions = System::Drawing::SizeF(5, 15);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
					static_cast<System::Int32>(static_cast<System::Byte>(0)));
				this->ClientSize = System::Drawing::Size(619, 431);
				this->Controls->Add(this->empezarSimulacionBoton);
				this->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Name = L"MenuForm";
				this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				this->Text = L"Carrito de Compras (inicio)";
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
