//
// Este archivo contiene las definiciones de las funciones que implementan los ejercicios
//

#include <iostream>

#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"
#include "bits/stdc++.h"

using namespace std;

        // ** EJERCICIO minasAdyacentes **

int minasAdyacentes(tablero& t, pos p) {
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


        // ** EJERCICIO plantarBanderita **

void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {
    int i = 0;
    if (!fue_jugada(p,j) && !es_banderita(p,b)) {
        b.push_back(p);
    }else {
        b.erase(b.begin() + i);
    }
}

       // **EJERCICIO perdio**

bool perdio(tablero& t, jugadas& j) {
    for (int i = 0; i < j.size(); ++i)
        if (hay_mina_en_posicion(j[i].first, t)) {
            return true;
        }
    return false;
}


       // ** EJERCICIO gano **

bool gano(tablero& t, jugadas& j) {
    int i = 0;
    while(i < j.size()){
        if (posicion_valida(j[i].first,t.size()) && hay_mina_en_posicion(j[i].first,t) == false){
            return false;
        }
        i++;
    }
    return true;
}

       // ** EJERCICIO jugarPlus **
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {
    if (hay_camino_libre(p, j, b, t)) {
        for (int i = 0; i < j.size(); ++i) {
            if (son_posiciones_adyacentes(p, j[i].first) && !fue_jugada(p, j)) {
                descubre_solo_posicion_jugada(p, j);
                solo_agrega_posiciones_descubiertas(j[i].first, j);
            }
        }
        if (!fue_jugada(p, j) && minasAdyacentes(t, p) >= 1) {
            descubre_solo_posicion_jugada(p, j);
        }
    }
}



      // ** EJERCICIO sugerirAutomatico121 **

bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
    return posicion_sin_banderita_sin_jugar(p,j,b,t) && es_adyacente_a121(p,j);
}
