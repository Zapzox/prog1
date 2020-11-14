#include <iostream>
#include <iostream>
#include <ctime>
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

        for (int i = 0; i <= 26; i++) {
            for (int j = 0; j <= 51; j++) {
                cout << Feld[i][j];
            }
            cout << endl;
        }
    }
}

