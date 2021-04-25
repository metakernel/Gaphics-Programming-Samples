// Copyright © 2021 Vincent Roy

// Graphics-MathAlgo.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "NoSIMDVector3D.h"
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
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
