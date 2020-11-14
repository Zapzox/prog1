#include <iostream>
#include <iostream>
#include <ctime>
#include "Header.h"

using namespace std;

char Feld[27][52];
char Player = 'P';
char Gegner = 'E';
bool tot = false;
bool gew = false;

void Ausgabe() {
    for (int i = 0; i <= 26; i++) {
        for (int j = 0; j <= 51; j++) {
            cout << Feld[i][j];
        }
        cout << endl;
    }
}

void GameOver() {
	Ausgabe();
	cout << "GAME OVER";
}

int main()
{
    srand(static_cast<unsigned>(time(0)));


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

    int p1 = ZufallszahlI(1, 25);
    int p2 = ZufallszahlI(1, 50);
    int e1 = ZufallszahlI(1, 25);
    int e2 = ZufallszahlI(1, 50);

    if (e1 != e2 && p1 != p2) {
        Feld[p1][p2] = 'P';
        Feld[e1][e2] = 'E';
    }
    else {
        int p1 = ZufallszahlI(1, 25);
        int p2 = ZufallszahlI(1, 50);
        int e1 = ZufallszahlI(1, 25);
        int e2 = ZufallszahlI(1, 50);
    }
    // Spieler und Enemie auf Random Pos. aber nicht die selben

	while (tot == false) {
		while (gew == false) {
			if (e1 != p1 || e2 != p2) {

				Feld[e1][e2] = ' ';
				int r = ZufallszahlI(1, 4);

				switch (r) {
				case 1:
					e1 -= 1;
					if (e1 != 26 && e1 != 0 && e2 != 51 && e2 != 0) {
						Feld[e1][e2] = 'E';
						break;
					}
					else {
						e1 += 1;
						break;
					}
				case 2:
					e2 += 1;
					if (e1 != 26 && e1 != 0 && e2 != 51 && e2 != 0) {
						Feld[e1][e2] = 'E';
						break;
					}
					else {
						e2 -= 1;
						break;
					}
				case 3:
					e1 += 1;
					if (e1 != 26 && e1 != 0 && e2 != 51 && e2 != 0) {
						Feld[e1][e2] = 'E';
						break;
					}
					else {
						e1 -= 1;
						break;
					}
				case 4:
					e2 -= 1;
					if (e1 != 26 && e1 != 0 && e2 != 51 && e2 != 0) {
						Feld[e1][e2] = 'E';
						break;
					}
					else {
						e2 += 1;
						break;
					}
				}
				system("cls");

				Ausgabe();
			}
			else {
				GameOver();
			}
		}

		tot = true;
	}
}

