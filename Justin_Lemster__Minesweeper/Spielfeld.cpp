#include <iostream>
#include<stdio.h>
#include<math.h>
#include "Spielfeld.h"

using namespace std;

Spielfeld::Spielfeld(int x, int y, int m) {
	int m_laengeX = x;
	int m_laengeY = y;
	int m_MinenAnz = m;
	x += 1;
	y += 1;
	//2D Array Anzeige erstellen
	char** Anz = new char* [x];
	for (int i = 0; i < x; i++) {
		Anz[i] = new char[y];
	}
	Ausgabenfeld(x, y, Anz);

	//2D Array Mine erstellen
	char** Mine = new char* [x];
	for (int i = 0; i < x; i++) {
		Mine[i] = new char[y];
	}
	Minenfeld(x, y, m, Mine);
}

char** Spielfeld::getArray() {
	return Feld;
}

int Spielfeld::getLaengeX() {
	return m_laengeX;
}

void Spielfeld::Ausgabenfeld(int x, int y, char **Feld) {
	char alph = 'A';
	
	//linke obere Ecke -> leer
	Feld[0][0] = ' ';
	Feld[0][1] = ' ';
	Feld[1][0] = ' ';
	Feld[1][1] = '|';
	//erste Zeile -> Alphabet / zweite Zeile -> '-' 
	for (int i = 2; i < x; i++) {
		Feld[0][i] = alph;
		alph++;
		Feld[1][i] = '-';
	}
	alph = 'A';
	//erste Spalte -> Zahlen / zweite Spalte -> '|'
	for (int i = 2; i < y; i++) {
		Feld[i][0] = alph;
		alph++;
		Feld[i][1] = '|';
	}

	for (int i = 2; i < y; i++) {
		for (int j = 2; j < x; j++) {
			Feld[i][j] = '#';
		}
	}

	for (int i = 2; i < y; i++) {
		for (int j = 2; j < x; j++) {
			Feld[i][j] = '#';
		}
	}

	Ausgabe(x,Feld);
}

void Spielfeld::Minenfeld(int x, int y, int m, char** Feld) {
	int f1 = 0;
	int f2 = 0;
	while (m!=0) {
		f1 = ZufallszahlI(2,x);
		f2 = ZufallszahlI(2,y);
			if (Feld[f1][f2]!='X') {
				Feld[f1][f2] = 'X';
				m--;
			}
	}
	Ausgabe(x, Feld);

	for (int i = 2; i < y; i++) {
		for (int j = 2; j < x; j++) {
			if (Feld[i][j]!='X') {
				getMinZahl(i, j, Feld);
			}
		}
	}

	Ausgabe(x, Feld);
}

int Spielfeld::getMinZahl(int x, int y,char** Feld) {
	int anz = 0;
	int c1 = x - 1;
	int c2 = y - 1;

	for (int i = 0; i < 3; i++) {
		c1 += i;
		for (int j = 0; j < 3; j++) {
			c2 += j;
			if (Feld[c1][c2] == 'X') {
				anz++;
			}
			c2 = y;
		}
	}
	return anz;
}

int ZufallszahlI(int untereGrenze, int obereGrenze)
{
	return (rand() % (obereGrenze - untereGrenze + 1)) + untereGrenze;
}

void Spielfeld::Ausgabe(int laengeX, char **Feld) {
	for (int i = 0; i < laengeX; i++) {
		cout << Feld[i]<< endl;
	}
}
