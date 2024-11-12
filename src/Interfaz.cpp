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
        rlutil::cls();  // Limpiamos la pantalla para que el men£ sea m s visible
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
        cout << "Seleccione una opci¢n: ";
        rlutil::resetColor();

        // Aseguramos que el usuario elija una opci¢n v lida
        while (!(cin >> opcion) || opcion < 0 || opcion > 4) {
            cout << "Entrada inv lida. Intente de nuevo: ";
            cin.clear();  // Limpiamos el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignoramos el resto de la l¡nea
        }

        rlutil::cls();  // Limpiamos pantalla antes de mostrar el contenido de la opci¢n elegida
        switch (opcion) {
            case 1:
                modoUnJugador();  // Ejecuta el modo para un jugador
                break;
            case 2:
                modoDosJugadores();  // Ejecuta el modo para dos jugadores
                break;
            case 3:
                mostrarEstadisticas();  // Muestra las estad¡sticas del juego
                break;
            case 4:
                mostrarCreditos();  // Muestra los cr‚ditos del equipo
                break;
            case 0:
                rlutil::setColor(rlutil::LIGHTRED);
                cout << "Saliendo del juego...\n";
                rlutil::resetColor();
                break;
            default:
                rlutil::setColor(rlutil::RED);
                cout << "Opci¢n no v lida. Intente de nuevo.\n";
                rlutil::resetColor();
                rlutil::anykey();
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
    rlutil::anykey();
}
