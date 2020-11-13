#include <iostream>
#include <iostream>
#include <ctime>
using namespace std;

char Feld[32][22];
char Player = 'P';
char Gegner = 'E';


int main()
{

    for (int i = 0; i <= 31; i++) {
        Feld[i][0] = '|';
        for (int j = 0; j <= 21; j++) {
            Feld[i][j] = ' ';
            Feld[0][j] = '-';
        }
    }

    for (int i = 0; i <= 32; i++) {
        for (int j = 0; j <= 22; j++) {
            cout << Feld[i][j];
        }
        cout << endl;
    }
}

