#include "Interfaz.h"
#include "Juego.h"
#include <ctime>
#include <cstdlib>

int main() {
    srand(static_cast<unsigned int>(time(0)));
    testLanzarDados();  // Llamada de prueba
    mostrarMenu();
    return 0;
}
