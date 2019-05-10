#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <vector>
#include "Fight.h"
using namespace std;

SCENARIO("Se crea la arena"){
    GIVEN("Nombre de archivo de texto"){
        Arena prueba("peleas.txt");
        WHEN("Se crea con un parámetro de tipo string"){
            THEN("Se carga eñ archivo de texto con 18 líneas, se leen las lineas y se almacenan en un vector"){
                REQUIRE(prueba.Actions_Size() == 18);

            }
        }
        WHEN("Se ejecuta"){
            THEN("Se crean tres peleas"){
                REQUIRE(prueba.Get_npeleas() == 3);
                CHECK(prueba.Peleas_Size() == prueba.Get_npeleas());
                CHECK(prueba.Get_Winner(0) == "BL");
                //Con eso se comprueba que él programa funciona correctamente. Solo faltarían los destructores.
            }
        }
    }
}