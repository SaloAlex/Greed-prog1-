#include "Estadisticas.h"
#include <string>
#include <iostream>
#include "rlutil.h"

using namespace std;

// Guardamos el nombre del jugador con el puntaje m s alto
static string mejorJugador;
static int puntajeMaximo = 0;        // Almacena el puntaje m ximo
static int puntajeJugador1 = 0;      // Guarda el puntaje del Jugador 1
static int puntajeJugador2 = 0;      // Guarda el puntaje del Jugador 2

// Esta funci¢n guarda el puntaje del Jugador 1 en el modo de un solo jugador.
// Si el puntaje es mayor que el m ximo registrado, lo actualiza.
void registrarPuntajeJugador1(int puntaje, string& nombre) {
    puntajeJugador1 = puntaje;
    if (puntaje > puntajeMaximo) {
        puntajeMaximo = puntaje;
        mejorJugador = nombre;
    }
}

// Esta funci¢n guarda los puntajes de ambos jugadores en el modo de dos jugadores.
// Compara los puntajes y actualiza el m ximo si es necesario.
void registrarPuntajeJugadores(int puntaje1, int puntaje2, string& nombre1, string& nombre2) {
    puntajeJugador1 = puntaje1;
    puntajeJugador2 = puntaje2;
    if (puntaje1 > puntajeMaximo) {
        puntajeMaximo = puntaje1;
        mejorJugador = nombre1;
    }
    if (puntaje2 > puntajeMaximo) {
        puntajeMaximo = puntaje2;
        mejorJugador = nombre2;
    }
}

// Esta funci¢n muestra los puntajes de ambos jugadores y el puntaje m s alto registrado.
void mostrarEstadisticas() {
    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);
    cout << "Puntaje Jugador 1: " << puntajeJugador1 << " puntos\n";
    cout << "Puntaje Jugador 2: " << puntajeJugador2 << " puntos\n";
    cout << "Mejor jugador: " << mejorJugador << " con " << puntajeMaximo << " puntos\n";
    rlutil::resetColor();
    rlutil::anykey();
}
