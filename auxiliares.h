
//
// Este archivo contiene las declaraciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con el código
// de esas mismas funciones, que estará en auxiliares.cpp
//

#pragma once   // esta línea es para que el archivo se incluya una sola vez

#include "definiciones.h"

// **(1)**

int cantidad_minas(tablero t);
int numero_minas_adyacentes(tablero t, pos p);

bool posicion_valida(pos p, int n);
bool coordenada_valida(int c, int n);
bool cantidad_minas_valida(tablero t);
bool es_adyacente_valida(pos p, int i , int j, tablero t);

// **(2)**

int minas_pisadas(jugadas j, tablero t);

bool fue_jugada(pos p, jugadas j);
bool jugadas_no_repetidas(jugadas j);
bool es_banderita(pos p, banderitas b);
bool hay_mina_en_posicion(pos p, tablero t);

void saca_banderita(pos ps, banderitas& bs);
void planta_banderita(pos ps_plantar, banderitas& bs);

// **(3)**

bool juego_perdido(tablero t, jugadas js);

// **(4)**

bool juego_ganado(tablero t, jugadas js);

// **(5)**

int cant_descubiertas_auto_desde(pos p, jugadas j, jugadas j0, banderitas b, tablero t);

bool son_posiciones_adyacentes(pos p, pos q);
bool mantiene_jugadas(jugadas js0, jugadas js);
bool incluye_jugada_actual(tablero t, jugadas j, pos p);
bool es_camino_libre(pos p, jugadas j, banderitas b, tablero t);
bool hay_camino_libre(pos p0, jugadas j0, banderitas b, tablero t);

void descubre_solo_posicion_jugada(pos p, jugadas j);
void descubre_multiples_posiciones(pos pos_jugada, jugadas j, banderitas b, tablero t);
void solo_agrega_posiciones_descubiertas(pos p, jugadas j);


// **(6)**

bool es_121_vertical(pos p, jugadas j);
bool es_adyacente_a121(pos p, jugadas j);
bool es_121_horizontal(pos p, jugadas j);
bool jugada_hecha(jugada a_hacer, jugadas j);
bool hay_posicion_sugerible(pos p, jugadas j, banderitas b, tablero t);
bool posicion_sin_banderita_sin_jugar(pos p, jugadas j, banderitas b, tablero t);
