#pragma once

#include <string>

using namespace std;

// Guarda el puntaje para un jugador en el modo de un solo jugador.
void registrarPuntajeJugador1(int puntaje, string& nombre);

// Guarda los puntajes de ambos jugadores en el modo de dos jugadores.
void registrarPuntajeJugadores(int puntaje1, int puntaje2, string& nombre1,string& nombre2);

// Muestra en pantalla las estad�sticas actuales del juego, incluyendo los puntajes y el mejor jugador.
void mostrarEstadisticas();
