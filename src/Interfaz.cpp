#include "Interfaz.h"
#include "rlutil.h"
#include "Juego.h"
#include "Estadisticas.h"
#include <iostream>
#include <limits>
using namespace std;

// Funci¢n para mostrar el men£ principal del juego
void mostrarMenu() {
    int opcion;
    do {
        rlutil::cls();  // Limpiamos la pantalla para que el menú sea más visible
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "=================\n";
        cout << "      GREED      \n";
        cout << "=================\n";
        rlutil::resetColor();
        cout << "1 - MODO UN JUGADOR\n";
        cout << "2 - MODO DOS JUGADORES\n";
        cout << "3 - ESTADISTICAS\n";
        cout << "4 - CREDITOS\n";
        cout << "0 - SALIR\n";
        rlutil::setColor(rlutil::CYAN);
        cout << "Seleccione una opción: ";
        rlutil::resetColor();

        cin >> opcion;  // El usuario ingresa la opción

        rlutil::cls();  // Limpiamos pantalla
        switch (opcion) {
            case 1: // Ejecuta el modo para un jugador
                modoUnJugador();
                break;
            case 2: // Ejecuta el modo para dos jugadores
                modoDosJugadores();
                break;
            case 3: // Muestra las estadísticas
                mostrarEstadisticas();
                break;
            case 4: // Muestra los créditos
                mostrarCreditos();
                break;
            case 0: // Sale del juego
                rlutil::setColor(rlutil::LIGHTRED);
                cout << "Saliendo del juego...\n";
                rlutil::resetColor();
                break;
            default:
                rlutil::setColor(rlutil::RED);
                cout << "Opción no válida. Intente de nuevo.\n";
                rlutil::resetColor();
                rlutil::anykey();  // Esperamos que el usuario presione una tecla
        }
    } while (opcion != 0);
}

// Funci¢n para mostrar los cr‚ditos del equipo
void mostrarCreditos() {
    rlutil::cls();
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Grupo 17: Programacion 1 UTN\n";
    cout << "32109 1 - Franco Nicol s Favale\n";
    cout << "32111 2 - Alexander David Salomon\n";
    cout << "24509 3 - Ignacio Gregoroff\n";
    rlutil::resetColor();
    cout << "Presiona cualquier tecla para regresar al men£.\n";
    rlutil::anykey();  // Pausa para que el usuario pueda leer los cr‚ditos antes de regresar
}
