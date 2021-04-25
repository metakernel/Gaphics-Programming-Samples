// Copyright © 2021 Vincent Roy

// Graphics-MathAlgo.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "GraphicsMath.h"
#include <string>

#define PRINTTEST(DESC,RESULT) std::cout << DESC << ": " << RESULT << '\n'

void VectorLogTest();

int main()
{
    VectorLogTest();
}

void VectorLogTest()
{
    NoSIMDVector3D v1(10.f, 2.f, 7.f);
    NoSIMDVector3D v2(2.f, 8.f, 3.f);

    v1 += v2;
    PRINTTEST(" Vector addition: V1(10, 2, 7) += v2(2, 8, 3)", v1.ToString());

    NoSIMDVector3D v1Copy(v1);

    std::string isEqualsResult_v1v2 = (v1.Equals(v1, v2)) ? "true":"false";
    PRINTTEST(" Vector v1(12, 10, 10) and v2(2, 8, 3) are equals", isEqualsResult_v1v2);

    std::string isEqualResult_v1v1Copy = (v1 == v1Copy) ? "true" : "false";
    PRINTTEST("Vector v1(12, 10, 10) and v1Copy(12, 10, 10) are equals", isEqualResult_v1v1Copy);

    NoSIMDVector3D v3(1.f, 2.f, 3.f);
    PRINTTEST("The length of vector v3(1,2,3) is", std::to_string(v3.GetLength()));
}
