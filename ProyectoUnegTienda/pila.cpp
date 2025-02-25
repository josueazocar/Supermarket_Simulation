#include "pila.h"

int indice_aleatorio;
int indice;
int total_productos[6];
std::set<int> indices_utilizados;
std::set<int> indices_utilizados2;
std::set<int> indices_utilizados3;
std::set<int> indices_utilizados4;
std::set<int> indices_utilizados5;
std::set<int> indices_utilizados6;

// Inicialización de variables globales
Tienda::productos articulos[10];
std::stack<Tienda::productos> carrito[6];

std::mt19937 rng(static_cast<unsigned int>(std::time(0)));
std::uniform_int_distribution<int> cantidad(1, 5);
std::uniform_int_distribution<int> cantidad_for(1, 10);
std::uniform_int_distribution<int> distribucion(0, 9);
std::uniform_int_distribution<int> tiempo_seleccion(1000, 5000);
std::uniform_int_distribution<int> tiempo_seleccion_segundos(1, 5);

int tiempo_aletorio() {
    return tiempo_seleccion(rng);
}

int numeroaleatorio() {
    return cantidad(rng);
}

int numeroaleatorio_for() {
    return cantidad_for(rng);
}

const char* seleccionarNombreAleatorio(std::set<int>& indices_utilizados) {
    int indice;
    do {
        indice = distribucion(rng);
    } while (indices_utilizados.find(indice) != indices_utilizados.end());
    indices_utilizados.insert(indice);
    indice_aleatorio = indice;
    return articulos[indice].nombres;
}

void inicializarArticulos() {
    strcpy(articulos[0].nombres, "Harina Pan");
    articulos[0].precio = 50;
    strcpy(articulos[0].descripcion, "Harina de maíz precocida");
    articulos[0].stock = 35;
    articulos[0].id = 1;

    strcpy(articulos[1].nombres, "Arroz Mary");
    articulos[1].precio = 60;
    strcpy(articulos[1].descripcion, "Arroz blanco tipo I");
    articulos[1].stock = 35;
    articulos[1].id = 2;

    strcpy(articulos[2].nombres, "Leche La Campestre");
    articulos[2].precio = 120;
    strcpy(articulos[2].descripcion, "Leche en polvo");
    articulos[2].stock = 35;
    articulos[2].id = 3;

    strcpy(articulos[3].nombres, "Champu Elvive");
    articulos[3].precio = 260;
    strcpy(articulos[3].descripcion, "Champu anticaspa");
    articulos[3].stock = 35;
    articulos[3].id = 4;

    strcpy(articulos[4].nombres, "Jabon Las llaves");
    articulos[4].precio = 80;
    strcpy(articulos[4].descripcion, "Jabon para lavar");
    articulos[4].stock = 35;
    articulos[4].id = 5;

    strcpy(articulos[5].nombres, "Crema dental");
    articulos[5].precio = 60;
    strcpy(articulos[5].descripcion, "Crema para lavarse los dientes");
    articulos[5].stock = 35;
    articulos[5].id = 6;

    strcpy(articulos[6].nombres, "Jamon Plumrose");
    articulos[6].precio = 460;
    strcpy(articulos[6].descripcion, "Barra de jamon plumrose 2KL");
    articulos[6].stock = 35;
    articulos[6].id = 7;

    strcpy(articulos[7].nombres, "Salchichas Plumrose");
    articulos[7].precio = 230;
    strcpy(articulos[7].descripcion, "Salchichas de pollo 400gr");
    articulos[7].stock = 35;
    articulos[7].id = 8;

    strcpy(articulos[8].nombres, "Avena Quacker");
    articulos[8].precio = 280;
    strcpy(articulos[8].descripcion, "Avena en hojuelas 500gr");
    articulos[8].stock = 35;
    articulos[8].id = 9;

    strcpy(articulos[9].nombres, "Barra limpiadora Dove");
    articulos[9].precio = 130;
    strcpy(articulos[9].descripcion, "Barra de jabon dermolimpiador neutro");
    articulos[9].stock = 35;
    articulos[9].id = 10;
}

void seleccionar_indice_random(std::set<int>& indices_utilizados) {
    do {
        indice = distribucion(rng);
    } while (indices_utilizados.find(indice) != indices_utilizados.end());
    indices_utilizados.insert(indice);
    indice_aleatorio = indice;
}


#include <algorithm> // Para std::min

void agregarProductoAlCarrito2(std::stack<Tienda::productos>& carrito,std::set<int>& indices_utilizados, int& total_productos) {

    // Seleccionar un índice no utilizado (asumiendo que seleccionar_indice_random actualiza 'indice')
    seleccionar_indice_random(indices_utilizados);

    // Verificar si el producto tiene stock disponible
    if (articulos[indice].stock <= 0) {
        return; // No hay stock, no se agrega nada
    }

    // Calcular la capacidad disponible en el carrito
    int capacidad_disponible = 30 - total_productos;
    if (capacidad_disponible <= 0) {
        return; // El carrito está lleno
    }

    // Calcular la cantidad máxima posible
    int cantidad = numeroaleatorio();
    cantidad = std::min(cantidad, articulos[indice].stock); // Limitar al stock
    cantidad = std::min(cantidad, capacidad_disponible);    // Limitar a la capacidad

    if (cantidad <= 0) {
        return; // No se puede agregar nada
    }

    // Crear una copia del producto para el carrito
    Tienda::productos producto_en_carrito = articulos[indice];
    producto_en_carrito.cantidad = cantidad; // Asignar la cantidad al producto del carrito

    // Actualizar el carrito y los registros
    carrito.push(producto_en_carrito);
    indices_utilizados.insert(indice);
    total_productos += cantidad;
    articulos[indice].stock -= cantidad; // Reducir el stock del inventario
}

void agregarProductoAlCarrito(std::stack<Tienda::productos>& carrito, std::set<int>& indices_utilizados, int& total_productos) {
    seleccionar_indice_random(indices_utilizados);
    articulos[indice].cantidad = numeroaleatorio();
    total_productos = total_productos + articulos[indice].cantidad;

    if (articulos[indice].stock < articulos[indice].cantidad) {
        articulos[indice].cantidad = articulos[indice].stock;
    }
    if (total_productos <= 30) {
        carrito.push(articulos[indice]);
        articulos[indice].stock = articulos[indice].stock - articulos[indice].cantidad;
    }
    else {
        total_productos = total_productos - articulos[indice].cantidad;
    }
}

void mostrarcarrito(const std::stack<Tienda::productos>& carrito, System::Windows::Forms::Label^ label, int nro_carrito) {
    System::String^ contenido = "Carrito #" + nro_carrito + "\n";
    std::stack<Tienda::productos> temp = carrito;

    while (!temp.empty()) {
        contenido += temp.top().cantidad + " " +
            gcnew System::String(temp.top().nombres) + " " +
            temp.top().precio + "Bs\n";
        temp.pop();
    }

    label->Text = contenido;
}

void mostrar_total_productos(System::Windows::Forms::Label^ label, int& total_productos) {
	label->Text = label->Text + total_productos + " productos en total";
}


void ReiniciarPila() {
    // Reiniciar variables globales
    indice_aleatorio = 0;
    indice = 0;
    std::fill(std::begin(total_productos), std::end(total_productos), 0);
    indices_utilizados.clear();
    indices_utilizados2.clear();
    indices_utilizados3.clear();
    indices_utilizados4.clear();
    indices_utilizados5.clear();
    indices_utilizados6.clear();

    // Vaciar los carritos
    for (int i = 0; i < 6; ++i) {
        while (!carrito[i].empty()) {
            carrito[i].pop();
        }
    }
}