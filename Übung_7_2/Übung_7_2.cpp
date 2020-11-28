#include <iostream>
#include <cmath>
#include "Roboter.h"
using namespace std;

int main()
{
    srand(static_cast<unsigned>(time(0)));

    char Feld[11];
    leeresFeld(Feld);

    Roboter R2D2(40, 2, "R2D2");
    Roboter C3PO(40, 7, "C3PO");

    Ausgabe(Feld);
}
