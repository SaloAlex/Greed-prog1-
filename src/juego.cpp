#include "Juego.h"
#include "Estadisticas.h"
#include "rlutil.h"
#include <iostream>
#include <string>

using namespace std;

// Lanza los dados y guarda los resultados en el array dados[]
void lanzarDados(int dados[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        dados[i] = rand() % 6 + 1; // Cada dado tiene un valor entre 1 y 6
    }
}

// Juega una ronda para un jugador y calcula su puntaje total
int jugarRonda(string& nombreJugador) {
    int puntaje = 0;
    int dados[5];
    int dadoBloqueador1 = rand() % 6 + 1; // Bloquea un n�mero al azar
    int dadoBloqueador2 = rand() % 6 + 1; // Bloquea otro n�mero al azar
    cout << "Turno de " << nombreJugador <<endl;
    cout << "Dados bloqueadores: " << dadoBloqueador1 << " y " << dadoBloqueador2 <<endl;

    char continuar;
    int dadosDisponibles = 5; // Inicialmente, se lanzan 5 dados

    do {
        lanzarDados(dados, dadosDisponibles); // Lanzamos los dados disponibles
        int sumaRonda = 0;
        bool todosIguales = true; // Comprobamos si todos los dados son iguales

        // Contar dados v�lidos (no bloqueados)
        int dadosValidos = 0;
        for (int i = 0; i < dadosDisponibles; i++) {
            cout << "Dado " << i + 1 << ": " << dados[i] << endl;

            if (dados[i] != dadoBloqueador1 && dados[i] != dadoBloqueador2) {
                sumaRonda += dados[i];
                dadosValidos++; // Contamos los dados v�lidos

                // Verificar si todos los dados v�lidos son iguales
                if (dadosValidos > 1 && dados[i] != dados[i - 1]) {
                    todosIguales = false;
                }
            }
        }

        // Si todos los dados v�lidos son iguales y hay al menos 2 dados v�lidos, duplicamos el puntaje
        bool puntosDuplicados = false;
        if (todosIguales && dadosValidos >= 2) {
            sumaRonda *= 2;
            puntosDuplicados = true; // Activar la condici�n de volver a tirar
            cout << "�Todos los dados v�lidos son iguales! �Tu puntaje de esta tirada ha sido duplicado a " << sumaRonda
                      << " puntos! Est�s obligado a volver a tirar.\n";
        }

        puntaje += sumaRonda;
        cout << "Puntaje acumulado de la ronda: " << puntaje << " puntos.\n";

        int nuevosDadosDisponibles = 0; // Se inicializa en 0 para contar dados sin bloquear
        for (int i = 0; i < dadosDisponibles; i++) {
            if (dados[i] != dadoBloqueador1 && dados[i] != dadoBloqueador2) {
                dados[nuevosDadosDisponibles++] = dados[i];
            }
        }

        // Si no quedan dados disponibles, terminamos la ronda
        dadosDisponibles = nuevosDadosDisponibles;
        if (dadosDisponibles == 0) {
            cout << "Te has quedado sin dados disponibles en esta ronda." << endl;
            puntaje = 0; // El puntaje de la ronda se pierde
            break;
        }

        // Si los puntos no se duplicaron, preguntar al jugador si quiere volver a tirar
        if (!puntosDuplicados) {
            cout << "�Desea tirar otra vez los dados disponibles? (s/n): ";
            cin >> continuar;
        } else {
            // Obliga al jugador a continuar si los puntos fueron duplicados
            continuar = 's';
            cout << "Debido a que tus puntos se duplicaron, est�s obligado a tirar de nuevo.\n";
        }

    } while (continuar == 's');

    return puntaje;
}

// Modo de juego para un solo jugador, donde se juegan varias rondas
void modoUnJugador() {
    string nombre;
    cout << "Ingrese su nombre: ";
    cin >> nombre;
    int puntajeTotal = 0;

    for (int i = 1; i <= 3; i++) {
       cout << "Ronda " << i << " para " << nombre <<endl;
        puntajeTotal += jugarRonda(nombre);
        cout << "Puntaje acumulado de " << nombre << " despu�s de la ronda " << i << ": " << puntajeTotal <<endl;
        rlutil::anykey();
    }

    registrarPuntajeJugador1(puntajeTotal, nombre);
}

// Modo de juego para dos jugadores, donde ambos compiten en varias rondas
void modoDosJugadores() {
    string nombre1, nombre2;
    cout << "Ingrese el nombre del Jugador 1: ";
    cin >> nombre1;
    cout << "Ingrese el nombre del Jugador 2: ";
    cin >> nombre2;

    int puntajeTotal1 = 0, puntajeTotal2 = 0;

    for (int ronda = 1; ronda <= 3; ronda++) {
        cout << "Ronda " << ronda << ":\n";
        rlutil::setColor(rlutil::LIGHTBLUE);
        cout << "Turno de " << nombre1 << endl;
        int puntajeRonda1 = jugarRonda(nombre1);
        puntajeTotal1 += puntajeRonda1;
        cout << nombre1 << " - Puntaje acumulado: " << puntajeTotal1 << endl;
        rlutil::resetColor();

        rlutil::anykey();

        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "Turno de " << nombre2 <<endl;
        int puntajeRonda2 = jugarRonda(nombre2);
        puntajeTotal2 += puntajeRonda2;
        cout << nombre2 << " - Puntaje acumulado: " << puntajeTotal2 << endl;
        rlutil::resetColor();

        rlutil::anykey();
    }

    registrarPuntajeJugadores(puntajeTotal1, puntajeTotal2, nombre1, nombre2);
    rlutil::anykey();
}
