// ConsoleApplication1.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
using namespace std;

int main()
{
    int a = 0;
    int Oben;
    int Unten;
    bool Prim;
     // zählt die Anzahl der Teiler

    cout << "Bitte geben sie ihre Untergrenze ein: \n";
    cin >> Unten;

    cout << "Bitte geben sie ihre Obergrenze ein: \n";
    cin >> Oben;

    while (Unten < Oben) {
        a = 0;
        for (int teiler = 1; teiler <= Unten; teiler++) {
            if (Unten % teiler == 0) {
                a++;
            }
        }

        if (a == 2) {
            cout << Unten << ", ";   
        }
        Unten++;
    }
    return 0;
}


