#include "Juego.h"
#include <iostream>
using namespace std;

// Esta funci¢n es solo para probar que lanzarDados funcione bien
// Llama a lanzarDados, muestra los valores generados, y se puede quitar en la versi¢n final
void testLanzarDados() {
    int dados[5];
    lanzarDados(dados, 5);  // Llamamos a lanzarDados para llenar el array con valores aleatorios
    cout << "Prueba de lanzarDados: ";
    for (int i = 0; i < 5; i++) {
        cout << dados[i] << " ";  // Mostramos el valor de cada dado
    }
    cout << endl;  // Salto de l¡nea para mayor claridad en la salida
}
