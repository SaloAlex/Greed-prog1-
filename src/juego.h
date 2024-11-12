#pragma once

#include <string>

using namespace std;

// Lanza los dados y guarda los resultados en el array dado[] con la cantidad de lanzamientos que especifiquemos.
void lanzarDados(int dados[], int cantidad);

// Juega una ronda para un jugador espec�fico y devuelve el puntaje obtenido en esa ronda.
int jugarRonda(string& nombreJugador);

// Modo de juego para un solo jugador, donde se juegan varias rondas.
void modoUnJugador();

// Modo de juego para dos jugadores, donde ambos compiten en varias rondas.
void modoDosJugadores();

// Esta funci�n es para probar el funcionamiento de lanzarDados. Puede eliminarse en la versi�n final.
void testLanzarDados();
