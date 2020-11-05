#include <iostream>
using namespace std;

int main()
{
    std::locale::global(std::locale("German_germany.UTF-8"));

    cout << "Willkommen beim DiceGame!" << endl << endl;
    cout << "Rules:" << endl;
    cout << "1. Bei einer 1 und 5 gibt es 2 Punkte" << endl;
    cout << "2. Bei einer ungeraden Zahl gibt es 0 Punkte" << endl;
    cout << "3. Bei einer 3 gibt es 1 Punktabzug" << endl;
    cout << "4. Habt Spaß! ^^" << endl << endl << endl << endl;

    int i = 0;
    cout << "Bitte geben sie die Anzahl der Durchläufe ein." << endl;
    cout << "Eingabe:";
    cin >> i;
    cout << endl << endl;
    cout << "Game Start!" << endl;
    int p = 0;

    while (i > 0) {
        int d = 0;
        cout << "Bitte geben sie eine Dezimalzahl zwischen [1,6] ein." << endl;
        cout << "Eingabe:";
        cin >> d;
        cout << endl;

        switch (d) {
        case 1:
        case 5:
            p += 2;
            break;
        case 3:
            p--;
            break;
        default:
            break;
        }
        i--;
        if (i > 0) {
            cout << "Punktestand:" << p << endl << endl;
        }
        }

    cout << "Endstand:" << p << endl;
}

