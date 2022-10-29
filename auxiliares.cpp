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

int numero_minas_adyacentes(tablero t, pos p){
    int suma = 0;
    for (int i = -1; i <=1 ; ++i) {
        for (int j = -1; j <=1 ; ++j) {
            if (es_adyacente_valida(p,i,j,t) && t[p.first +i][p.second+j]){
                suma++;
            }
        }
    }
    return suma;
}

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

bool cantidad_minas_valida(tablero t){
    return (0< cantidad_minas(t) && cantidad_minas(t)< pow(t.size(),2));
}

int cantidad_minas(tablero t){
    int suma = 0;
    for (int i = 0; i < t.size(); ++i) {
        for (int j = 0; j < t.size(); ++j){
            if(t[i][j]){
                suma++;
            }
            j++;
        }
        i++;
    }
    return suma;
}

                                          // ***Auxiliares Ejercicio (2)***

bool es_banderita(pos p, banderitas b){
    int i = 0;
    bool es_bandera = false;
    while(i<b.size()){
        if(p==b[i]){
            es_bandera = true;
        }
        i++;
    }
    return es_bandera;
}

void saca_banderita(pos ps, banderitas& bs){
    bs.push_back(ps);
    bs.pop_back();
}

void planta_banderita(pos ps_plantar, banderitas& bs){
    bs.push_back(ps_plantar);
}

int minas_pisadas(jugadas j, tablero t){
    int suma_minas = 0;
    for (int i = 0; i < j.size(); ++i) {
        if(hay_mina_en_posicion(j[i].first,t)){
            suma_minas++;
        }
    }
    return suma_minas;
}

bool hay_mina_en_posicion(pos p, tablero t){
    return t[p.first][p.second];
}

bool jugadas_no_repetidas(jugadas j){
    bool esta_jugada = false;
    for (int i = 0; i < j.size(); ++i) {
        for (int k = 0; k < j.size() && k !=i ; ++k) {
            esta_jugada = j[i].first == j[k].first;
        }
    }
    return esta_jugada;
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

bool juego_perdido(tablero t, jugadas js){
    for (int i = 0; i < js.size(); ++i) {
        return hay_mina_en_posicion(js[i].first,t);
    }
}
                                               // ***Auxiliares Ejercicio (4)***

bool juego_ganado(tablero t, jugadas js){
    bool gano = true;
    for (int i = 0; i < js.size(); ++i) {
        if(hay_mina_en_posicion(js[i].first,t)){
            return gano = false;
        }
    }
}
                                             // ***Auxiliares Ejercicio (5)***

void descubre_multiples_posiciones(pos pos_jugada, jugadas j, banderitas b, tablero t) {
    if (hay_camino_libre(pos_jugada, j, b, t)) {
        for (int i = 0; i < j.size(); ++i) {
            if (son_posiciones_adyacentes(pos_jugada, j[i].first) && !fue_jugada(pos_jugada, j)) {
                descubre_solo_posicion_jugada(pos_jugada, j);
                solo_agrega_posiciones_descubiertas(j[i].first, j);
            }
        }
        if (!fue_jugada(pos_jugada, j) && numero_minas_adyacentes(t, pos_jugada) >= 1) {
            descubre_solo_posicion_jugada(pos_jugada, j);
        }
    }
}

bool hay_camino_libre(pos p, jugadas j, banderitas b, tablero t){
    return (!hay_mina_en_posicion(p,t)&& numero_minas_adyacentes(t,p)==0);
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




/*int cant_descubiertas_auto_desde(pos p, jugadas j, jugadas j0, banderitas b, tablero t){
}
bool mantiene_jugadas(jugadas js0, jugadas js){

}
bool incluye_jugada_actual(tablero t, jugadas j, pos p){
}
bool es_camino_libre(pos p, jugadas j, banderitas b, tablero t){
}
*/
