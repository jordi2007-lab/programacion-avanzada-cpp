#include <gtest/gtest.h>

#include "tarifa.h"

// Tarifa del estacionamiento de visitas de la universidad. Las cuatro
// carpetas version_a a version_d tienen cada una su tarifa.h con una
// implementacion distinta de la misma funcion:
//
//     int tarifaEnCentavos(int minutos)
//
// Lo que tiene que cumplir:
// - Con minutos negativos lanza std::invalid_argument.
// - Hasta 15 minutos, inclusive, no se cobra.
// - Desde el minuto 16, se cobran 50 centavos por cada hora o fraccion,
//   contadas desde el minuto 0: 16 minutos son una hora, 60 minutos son
//   una hora, 61 minutos son dos horas.
// - Ninguna estadia cuesta mas de 500 centavos.
//
// Escribe aqui tus pruebas a partir de esta descripcion, antes de abrir
// cualquier tarifa.h. Compila el mismo archivo contra cada version
// cambiando la carpeta de -I:
//
//     g++ -std=c++20 -Wall -Wextra -g -I ejercicio3/version_a ejercicio3/test_tarifa.cpp -lgtest_main -lgtest -pthread -o bin/test_tarifa_a
//     ./bin/test_tarifa_a

TEST(Tarifa, MinutosNegativosLanzaExcepcion){
    EXPECT_THROW(tarifaEnCentavos(-1), std::invalid_argument);
    EXPECT_THROW(tarifaEnCentavos(-50), std::invalid_argument);
}

TEST(Tarifa, Hasta15MinutosEsGratis){
    EXPECT_EQ(tarifaEnCentavos(0), 0);
    EXPECT_EQ(tarifaEnCentavos(1), 0);
    EXPECT_EQ(tarifaEnCentavos(15), 0);
}

TEST(Tarifa, CobraPorHoraOFraccionDesdeElMinuto16){
    EXPECT_EQ(tarifaEnCentavos(16), 50);
    EXPECT_EQ(tarifaEnCentavos(30), 50);
    EXPECT_EQ(tarifaEnCentavos(60), 50);

    EXPECT_EQ(tarifaEnCentavos(61), 100);
    EXPECT_EQ(tarifaEnCentavos(120), 100);

    EXPECT_EQ(tarifaEnCentavos(121), 150);
}

TEST(Tarifa, MaximoCobroEs500Centavos){
    EXPECT_EQ(tarifaEnCentavos(540), 450);
    EXPECT_EQ(tarifaEnCentavos(541), 500);
    EXPECT_EQ(tarifaEnCentavos(600), 500);
    EXPECT_EQ(tarifaEnCentavos(601), 500); 
    EXPECT_EQ(tarifaEnCentavos(1000), 500);
    EXPECT_EQ(tarifaEnCentavos(1440), 500);
}