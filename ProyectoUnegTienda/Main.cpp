#include "MenuForm.h"
//#include "Form1.h" // Asegúrate de incluir Form1 si lo vas a utilizar

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

   //Inicializando el menu del proyecto
    ProyectoUnegTienda::MenuForm menuForm;

	//Correr el menu
    Application::Run(% menuForm);
    return 0;
}
