//
// Este archivo contiene las definiciones de las funciones que implementan los ejercicios
//

#include <stdio.h>
#include <iostream>


#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

// ** EJERCICIO minasAdyacentes **

int minasAdyacentes(tablero& t, pos p) {
    return numero_minas_adyacentes(t,p);
}


// ** EJERCICIO plantarBanderita **

void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {
    if(es_banderita(p,b)){
        saca_banderita(p,b);
    }else{
        planta_banderita(p,b);
    }
}

// **EJERCICIO perdio**

bool perdio(tablero& t, jugadas& j) {
    juego_perdido(t,j);
}

// ** EJERCICIO gano **
bool gano(tablero& t, jugadas& j) {
    juego_ganado(t,j);
}

// ** EJERCICIO jugarPlus **
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {
    // ...
}


// ** EJERCICIO sugerirAutomatico121 **
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
    // ...
}
