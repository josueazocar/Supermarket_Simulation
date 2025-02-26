#pragma once
#include "Simulacion.h"

extern int valorVolverEntero;
extern int valorTminimoEntero;
extern int valorTmaximoEntero;

namespace ProyectoUnegTienda {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MenuForm : public System::Windows::Forms::Form
	{
	public:

		MenuForm(void)
		{
			InitializeComponent();
			
		}

	protected:
	
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ SalirButton;
	public: System::Windows::Forms::NumericUpDown^ TminimoClientes;
	private: System::Windows::Forms::RadioButton^ TiempoSegundos;
	private: System::Windows::Forms::RadioButton^ TiempoMinutos;
	public: System::Windows::Forms::NumericUpDown^ TmaximoClientes;
	private: System::Windows::Forms::NumericUpDown^ TmaximoDelvolver;
	private: System::Windows::Forms::Label^ texto;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	protected:

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::Windows::Forms::Button^ empezarSimulacionBoton;
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuForm::typeid));
			this->SalirButton = (gcnew System::Windows::Forms::Button());
			this->TminimoClientes = (gcnew System::Windows::Forms::NumericUpDown());
			this->TiempoSegundos = (gcnew System::Windows::Forms::RadioButton());
			this->TiempoMinutos = (gcnew System::Windows::Forms::RadioButton());
			this->TmaximoClientes = (gcnew System::Windows::Forms::NumericUpDown());
			this->TmaximoDelvolver = (gcnew System::Windows::Forms::NumericUpDown());
			this->texto = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			empezarSimulacionBoton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TminimoClientes))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TmaximoClientes))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TmaximoDelvolver))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// empezarSimulacionBoton
			// 
			empezarSimulacionBoton->Anchor = System::Windows::Forms::AnchorStyles::None;
			empezarSimulacionBoton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			empezarSimulacionBoton->BackColor = System::Drawing::Color::LightGreen;
			empezarSimulacionBoton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			empezarSimulacionBoton->Cursor = System::Windows::Forms::Cursors::Hand;
			empezarSimulacionBoton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			empezarSimulacionBoton->Font = (gcnew System::Drawing::Font(L"Castellar", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			empezarSimulacionBoton->ForeColor = System::Drawing::SystemColors::ControlText;
			empezarSimulacionBoton->Location = System::Drawing::Point(155, 228);
			empezarSimulacionBoton->Name = L"empezarSimulacionBoton";
			empezarSimulacionBoton->Size = System::Drawing::Size(322, 43);
			empezarSimulacionBoton->TabIndex = 0;
			empezarSimulacionBoton->Text = L"Empezar Simulación";
			empezarSimulacionBoton->UseVisualStyleBackColor = false;
			empezarSimulacionBoton->Click += gcnew System::EventHandler(this, &MenuForm::EmpezarFormularioClick);
			// 
			// SalirButton
			// 
			this->SalirButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SalirButton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->SalirButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->SalirButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->SalirButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->SalirButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->SalirButton->Font = (gcnew System::Drawing::Font(L"Castellar", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SalirButton->Location = System::Drawing::Point(155, 280);
			this->SalirButton->Name = L"SalirButton";
			this->SalirButton->Size = System::Drawing::Size(322, 37);
			this->SalirButton->TabIndex = 1;
			this->SalirButton->Text = L"Salir";
			this->SalirButton->UseVisualStyleBackColor = false;
			this->SalirButton->Click += gcnew System::EventHandler(this, &MenuForm::Salir);
			// 
			// TminimoClientes
			// 
			this->TminimoClientes->Location = System::Drawing::Point(119, 12);
			this->TminimoClientes->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, 0 });
			this->TminimoClientes->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->TminimoClientes->Name = L"TminimoClientes";
			this->TminimoClientes->Size = System::Drawing::Size(77, 20);
			this->TminimoClientes->TabIndex = 3;
			this->TminimoClientes->Tag = L"";
			this->TminimoClientes->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 240, 0, 0, 0 });
			this->TminimoClientes->ValueChanged += gcnew System::EventHandler(this, &MenuForm::TminimoClientes_ValueChanged);
			// 
			// TiempoSegundos
			// 
			this->TiempoSegundos->Appearance = System::Windows::Forms::Appearance::Button;
			this->TiempoSegundos->AutoSize = true;
			this->TiempoSegundos->Checked = true;
			this->TiempoSegundos->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TiempoSegundos->Location = System::Drawing::Point(353, 182);
			this->TiempoSegundos->Name = L"TiempoSegundos";
			this->TiempoSegundos->Size = System::Drawing::Size(81, 25);
			this->TiempoSegundos->TabIndex = 4;
			this->TiempoSegundos->TabStop = true;
			this->TiempoSegundos->Text = L"SEGUNDOS";
			this->TiempoSegundos->UseVisualStyleBackColor = true;
			this->TiempoSegundos->CheckedChanged += gcnew System::EventHandler(this, &MenuForm::TiempoSegundos_CheckedChanged);
			// 
			// TiempoMinutos
			// 
			this->TiempoMinutos->Appearance = System::Windows::Forms::Appearance::Button;
			this->TiempoMinutos->AutoSize = true;
			this->TiempoMinutos->BackColor = System::Drawing::Color::Cornsilk;
			this->TiempoMinutos->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TiempoMinutos->Location = System::Drawing::Point(202, 182);
			this->TiempoMinutos->Name = L"TiempoMinutos";
			this->TiempoMinutos->Size = System::Drawing::Size(70, 25);
			this->TiempoMinutos->TabIndex = 5;
			this->TiempoMinutos->Text = L"MINUTOS";
			this->TiempoMinutos->UseVisualStyleBackColor = false;
			this->TiempoMinutos->CheckedChanged += gcnew System::EventHandler(this, &MenuForm::TiempoMinutos_CheckedChanged);
			// 
			// TmaximoClientes
			// 
			this->TmaximoClientes->Location = System::Drawing::Point(119, 32);
			this->TmaximoClientes->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, 0 });
			this->TmaximoClientes->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->TmaximoClientes->Name = L"TmaximoClientes";
			this->TmaximoClientes->Size = System::Drawing::Size(77, 20);
			this->TmaximoClientes->TabIndex = 6;
			this->TmaximoClientes->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, 0 });
			this->TmaximoClientes->ValueChanged += gcnew System::EventHandler(this, &MenuForm::TmaximoClientes_ValueChanged);
			// 
			// TmaximoDelvolver
			// 
			this->TmaximoDelvolver->Location = System::Drawing::Point(119, 13);
			this->TmaximoDelvolver->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 600, 0, 0, 0 });
			this->TmaximoDelvolver->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->TmaximoDelvolver->Name = L"TmaximoDelvolver";
			this->TmaximoDelvolver->Size = System::Drawing::Size(78, 20);
			this->TmaximoDelvolver->TabIndex = 7;
			this->TmaximoDelvolver->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 600, 0, 0, 0 });
			this->TmaximoDelvolver->ValueChanged += gcnew System::EventHandler(this, &MenuForm::TmaximoDelvolver_ValueChanged);
			// 
			// texto
			// 
			this->texto->AutoSize = true;
			this->texto->BackColor = System::Drawing::Color::Chocolate;
			this->texto->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->texto->Location = System::Drawing::Point(202, 14);
			this->texto->Name = L"texto";
			this->texto->Size = System::Drawing::Size(318, 15);
			this->texto->TabIndex = 8;
			this->texto->Text = L"Tiempo minimo para el ingreso de los clientes";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Chocolate;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(202, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(318, 15);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Tiempo maximo para el ingreso de los clientes";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(201, 15);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(336, 15);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Tiempo para regresar al cliente al final de la cola";
			this->label2->Click += gcnew System::EventHandler(this, &MenuForm::label2_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->texto);
			this->groupBox1->Controls->Add(this->TmaximoClientes);
			this->groupBox1->Controls->Add(this->TminimoClientes);
			this->groupBox1->Location = System::Drawing::Point(-2, 338);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(623, 62);
			this->groupBox1->TabIndex = 11;
			this->groupBox1->TabStop = false;
			this->groupBox1->Enter += gcnew System::EventHandler(this, &MenuForm::groupBox1_Enter);
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::Color::ForestGreen;
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->TmaximoDelvolver);
			this->groupBox2->Location = System::Drawing::Point(-2, 393);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(665, 41);
			this->groupBox2->TabIndex = 12;
			this->groupBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-2, -4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(635, 470);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 13;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MenuForm::pictureBox1_Click);
			// 
			// MenuForm
			// 
			this->AcceptButton = empezarSimulacionBoton;
			this->AutoScaleDimensions = System::Drawing::SizeF(5, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->ClientSize = System::Drawing::Size(619, 431);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->TiempoMinutos);
			this->Controls->Add(this->TiempoSegundos);
			this->Controls->Add(this->SalirButton);
			this->Controls->Add(empezarSimulacionBoton);
			this->Controls->Add(this->pictureBox1);
			this->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MenuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Carrito de Compras (inicio)";
			this->Load += gcnew System::EventHandler(this, &MenuForm::MenuForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TminimoClientes))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TmaximoClientes))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TmaximoDelvolver))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MenuForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

		   // accion que se realiza al hacer click en el boton de empezar simulacion
	private: System::Void EmpezarFormularioClick(System::Object^ sender, System::EventArgs^ e) { //boton de iniciar simulacion

		if (TiempoSegundos->Checked == true) {

			System::Decimal valorTminimo = this->TminimoClientes->Value;
			valorTminimoEntero = System::Decimal::ToInt32(valorTminimo);
			valorTminimoEntero = valorTminimoEntero * 1000;  //Convertir los segundos en milisegundos

			System::Decimal valorTmaximo = this->TmaximoClientes->Value;
			valorTmaximoEntero = System::Decimal::ToInt32(valorTmaximo);
			valorTmaximoEntero = valorTmaximoEntero * 1000;

			System::Decimal valorVolver = this->TmaximoDelvolver->Value;
			valorVolverEntero = System::Decimal::ToInt32(valorVolver);
			valorVolverEntero = valorVolverEntero * 1000;
		}

		if (TiempoMinutos->Checked == true) {
			System::Decimal valorTminimo = this->TminimoClientes->Value;
			valorTminimoEntero = System::Decimal::ToInt32(valorTminimo);
			valorTminimoEntero = valorTminimoEntero * 60000;  //Convertir los minutos en milisegundos

			System::Decimal valorTmaximo = this->TmaximoClientes->Value;
			valorTmaximoEntero = System::Decimal::ToInt32(valorTmaximo);
			valorTmaximoEntero = valorTmaximoEntero * 60000;

			System::Decimal valorVolver = this->TmaximoDelvolver->Value;
			valorVolverEntero = System::Decimal::ToInt32(valorVolver);
			valorVolverEntero = valorVolverEntero * 60000;
		}

		this->Hide();
		Simulacion^ simulationForm = gcnew Simulacion();
		simulationForm->ShowDialog();
		if (!this->IsDisposed) {
			this->Show();
		}

	}
	private: System::Void Salir(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}

	private: System::Void TiempoSegundos_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

		if (TiempoSegundos->Checked == true) {  //Si el boton de los segundos esta encendido entonces...
			this->TminimoClientes->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->TminimoClientes->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 240, 0, 0, 0 });
			this->TmaximoClientes->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->TmaximoClientes->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, 0 });
			this->TmaximoDelvolver->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->TmaximoDelvolver->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 600, 0, 0, 0 });

			System::Decimal valorTminimo = this->TminimoClientes->Value;
			valorTminimoEntero = System::Decimal::ToInt32(valorTminimo);
			valorTminimoEntero = valorTminimoEntero * 1000;  //Convertir los segundos en milisegundos

			System::Decimal valorTmaximo = this->TmaximoClientes->Value;
			valorTmaximoEntero = System::Decimal::ToInt32(valorTmaximo);
			valorTmaximoEntero = valorTmaximoEntero * 1000;

			System::Decimal valorVolver = this->TmaximoDelvolver->Value;
			valorVolverEntero = System::Decimal::ToInt32(valorVolver);
			valorVolverEntero = valorVolverEntero * 1000;
		}
	}

	private: System::Void TminimoClientes_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void TiempoMinutos_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

		if (TiempoMinutos->Checked == true) { //Si el boton de los minutos esta encendido entonces...
			this->TminimoClientes->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->TminimoClientes->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			this->TmaximoClientes->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->TmaximoClientes->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 6, 0, 0, 0 });
			this->TmaximoDelvolver->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->TmaximoDelvolver->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });

			System::Decimal valorTminimo = this->TminimoClientes->Value;
			valorTminimoEntero = System::Decimal::ToInt32(valorTminimo);
			valorTminimoEntero = valorTminimoEntero * 60000;  //Convertir los minutos en milisegundos

			System::Decimal valorTmaximo = this->TmaximoClientes->Value;
			valorTmaximoEntero = System::Decimal::ToInt32(valorTmaximo);
			valorTmaximoEntero = valorTmaximoEntero * 60000;

			System::Decimal valorVolver = this->TmaximoDelvolver->Value;
			valorVolverEntero = System::Decimal::ToInt32(valorVolver);
			valorVolverEntero = valorVolverEntero * 60000;
		}
	}
	private: System::Void TmaximoClientes_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void TmaximoDelvolver_ValueChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
