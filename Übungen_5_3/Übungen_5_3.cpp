#include <iostream>
#include <iostream>
#include <ctime>
#include "Header.h"

using namespace std;

char Feld[27][52];
char Player = 'P';
char Gegner = 'E';
bool tot = false;

int main()
{
    srand(static_cast<unsigned>(time(0)));
    while (tot==false) {

        for (int i = 0; i <= 26; i++) {
            for (int j = 0; j <= 51; j++) {
                Feld[i][j] = ' ';
            }
        }

        for (int i = 0; i <= 26; i++) {
            Feld[i][0] = '|';
            Feld[i][51] = '|';
        }

        for (int j = 0; j <= 51; j++) {
            Feld[0][j] = '-';
            Feld[26][j] = '-';
        }
        // leeres Spielfeld

            int p1 = ZufallszahlI(1, 26);
            int p2 = ZufallszahlI(1, 51);
            int e1 = ZufallszahlI(1, 26);
            int e2 = ZufallszahlI(1, 51);

        if(e1 != e2 && p1 != p2){
            Feld[ZufallszahlI(1, 26)][ZufallszahlI(1, 51)] = 'P';
            Feld[ZufallszahlI(1, 26)][ZufallszahlI(1, 51)] = 'E';
        }
        else {
            int p1 = ZufallszahlI(1, 26);
            int p2 = ZufallszahlI(1, 51);
            int e1 = ZufallszahlI(1, 26);
            int e2 = ZufallszahlI(1, 51);
        }
        // Spieler und Enemie auf Random Pos. aber nicht die selben



        for (int i = 0; i <= 26; i++) {
            for (int j = 0; j <= 51; j++) {
                cout << Feld[i][j];
            }
            cout << endl;
        }
        // Spielfeld ausgabe

        tot = true;
    }
}

