#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <vector>
#include "Fight.h"
using namespace std;

SCENARIO("Se crea la arena"){
    GIVEN("Nombre de archivo de texto"){
        Arena prueba("peleas.txt");
        WHEN("Se carga eñ archivo de texto con 18 líneas y 3 peleas"){
            THEN("Se leen las lineas, se almacenan en un vector de tipo  y se crean dos peleas"){
                REQUIRE(prueba.Actions_Size() == 18);
                REQUIRE(prueba.Get_npeleas() == 3);
                CHECK(prueba.Peleas_Size() == prueba.Get_npeleas());
                CHECK(prueba.Get_Winner(0) == "BL");
                //Con eso se comprueba que él programa funciona correctamente. Solo faltarían los destructores.
            }
        }
    }
}