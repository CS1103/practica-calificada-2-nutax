#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <vector>
#include "Fight.h"
using namespace std;

SCENARIO("Se crea la arena"){
    GIVEN("Nombre de archivo de texto"){
        Arena prueba("peleas.txt");
        WHEN("Se carga eñ archivo de texto"){
            THEN("Se leen las lineas, se almacenan en un vector de tipo  y se crean dos peleas"){
                REQUIRE(prueba.Get_npeleas() == 2);
                CHECK(prueba.Peleas().size() == prueba.Get_npeleas());
            }
        }
    }
}