//
// Este archivo contiene las definiciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con las 
// declaraciones de auxiliares.h
//

#include <iostream>
#include <cmath>
#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;


                                             // ***Auxiliares Ejercicio (1)***

bool es_adyacente_valida(pos p, int i , int j, tablero t){
    int sub_sec_tablero = t[0].size();
    bool c_valida = coordenada_valida(p.first+i,t.size());
    bool c_valida2 = coordenada_valida(p.second+j,sub_sec_tablero);
    return c_valida && c_valida2 && (i!= 0||j!=0);
}

bool posicion_valida(pos p, int n) {
    bool c_valida1 = coordenada_valida(p.first, n);
    bool c_valida2 = coordenada_valida(p.second, n);
    return c_valida1 && c_valida2;
}

bool coordenada_valida(int c, int n) {
    return 0 <= c && c < n;
}



int cantidad_minas(tablero t){
    int suma = 0;
    for (int i = 0; i < t.size(); ++i) {
        for (int j = 0; j < t.size(); ++j){
            if(t[i][j]){
                suma++;
            }
        }
    }
    return suma;
}

/*
bool cantidad_minas_valida(tablero t){
    return (0< cantidad_minas(t) && cantidad_minas(t)< pow(t.size(),2));
}
*/
                                          // ***Auxiliares Ejercicio (2)***


bool hay_mina_en_posicion(pos p, tablero t){
    return t[p.first][p.second];
}


bool fue_jugada(pos p, jugadas j){
    int i = 0;
    bool jugada = false;
    while(i,j.size()){
        if (p == j[i].first){
            jugada = true;
        }
    }   i++;
    return jugada;
}


                                                 // ***Auxiliaries Ejercicio (3)***

                                                // ***Auxiliares Ejercicio (4)***

                                               // ***Auxiliares Ejercicio (5)***


bool hay_camino_libre(pos p, jugadas j, banderitas b, tablero t){
    return (!hay_mina_en_posicion(p,t)&& minasAdyacentes(t,p)==0);
}

bool son_posiciones_adyacentes(pos p, pos q){
    float mod1 = p.first - q.first;
    float mod2 = p.second - q.second;
    return sqrt(mod1)<=1 && sqrt(mod2)<=1 && (p!=q);
}

void solo_agrega_posiciones_descubiertas(pos p, jugadas j){
    pos pos_original (p.first,p.second);
    int mina = 0;
    jugada pos_final (pos_original, mina);
    j.push_back(pos_final);
}

void descubre_solo_posicion_jugada(pos p, jugadas j){
    pos pos_original (p.first,p.second);
    int mina = 0;
    jugada pos_final (pos_original, mina);
    j.push_back(pos_final);
}


                                    // ***Auxiliares Ejercicio (6)***



bool es_adyacente_a121(pos p, jugadas j){
    return es_121_vertical(p,j) || es_121_horizontal(p,j);
}

bool es_121_vertical(pos p, jugadas j){
    pos vertical1(p.first-1,p.second);
    pos vertical2(p.first +1, p.second);
    jugada jugada1(vertical1,1);
    jugada jugada2(vertical2, 1);
    jugada original(p,2);
    bool verifica_jugada1 = jugada_hecha(jugada1,j);
    bool verifica_jugada2 = jugada_hecha(jugada2,j);
    bool verifica_original = jugada_hecha(original, j);
    return verifica_jugada1 && verifica_jugada2 && verifica_original;
}


bool es_121_horizontal(pos p, jugadas j){
    pos horizontal1 (p.first, p.second-1);
    pos horizontal2(p.first,p.second+1);
    jugada juego1(horizontal1,1);
    jugada juego2(horizontal2,1);
    jugada original(p,2);
    bool verifica_juego1 = jugada_hecha(juego1,j);
    bool verifica_juego2 = jugada_hecha(juego2,j);
    bool verifica_original = jugada_hecha(original, j);
    return verifica_juego1 && verifica_juego2 && verifica_original;
}


bool jugada_hecha(jugada a_hacer, jugadas j){
    for (int i = 0; i < j.size(); ++i) {
        if (a_hacer == j[i]){
            return true;
        }
    }
    return false;
}

bool posicion_sin_banderita_sin_jugar(pos p, jugadas j, banderitas b, tablero t){
    bool sin_bandera = es_banderita(p,b);
    bool sin_jugar = fue_jugada(p,j);
    return sin_bandera && sin_jugar;
}

bool es_banderita(pos p, banderitas b){
    for (int i = 0; i < b.size(); ++i) {
        if(p == b[i]){
            return true;
        }
    }
    return false;
}











/*int cant_descubiertas_auto_desde(pos p, jugadas j, jugadas j0, banderitas b, tablero t){
}
bool mantiene_jugadas(jugadas js0, jugadas js){

}
bool incluye_jugada_actual(tablero t, jugadas j, pos p){
}
bool es_camino_libre(pos p, jugadas j, banderitas b, tablero t){
}
*/
