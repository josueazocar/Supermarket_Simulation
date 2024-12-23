#include "Simulacion.h"

using namespace ProyectoUnegTienda;

void Simulacion::EmpezarSimulacion()
{
    // Implementa tu l�gica de simulaci�n aqu�
    this->simulacionTexto->Text = "Simulaci�n en progreso...";
    for (int i = 0; i < 100; i++)
    {
        // Simular algo
        System::Threading::Thread::Sleep(50); // Dormir por 50ms para simular el proceso
    }
    this->simulacionTexto->Text = "Simulaci�n completada";
}
