//
// Función de inicio que corre todos los tests. 
// NO MODIFICAR
//

#include <iostream>
#include "gtest/gtest.h"
#include "ejercicios.h"
#include "auxiliares.h"
using namespace std;


int main(int argc, char **argv) {
    std::cout << "Implementando TPI!!" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    pos pos1(0,2);
    tablero t (2);
    t = {{true,false,false,true},{false,true,true,false}};
    cout << minasAdyacentes(t,pos1) << endl;
    //return RUN_ALL_TESTS();;
    return 0;
}
