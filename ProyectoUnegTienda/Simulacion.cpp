#include "Simulacion.h"

using namespace ProyectoUnegTienda;

void Simulacion::EmpezarSimulacion()
{
    // Implementa tu lógica de simulación aquí
    this->simulacionTexto->Text = "Simulación en progreso...";
    for (int i = 0; i < 100; i++)
    {
        // Simular algo
        System::Threading::Thread::Sleep(50); // Dormir por 50ms para simular el proceso
    }
    this->simulacionTexto->Text = "Simulación completada";
}
