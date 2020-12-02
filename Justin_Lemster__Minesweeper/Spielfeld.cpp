#include <iostream>
#include<stdio.h>
#include<math.h>
#include "Spielfeld.h"

using namespace std;

Spielfeld::Spielfeld(int x, int y, int m) {
	m_laengeX = x;
	m_laengeY = y;
	m_MinenAnz = m;
	x += 2;
	y += 2;
	//2D Array Anzeige erstellen
	string** Anz = new (string * [x]);
	for (int i = 0; i < x; i++) {
		Anz[i] = new string[y];
	}
	leeresFeld(x, y, Anz);
	Ausgabenfeld(x, y, Anz);

	//2D Array Mine erstellen
	string** Mine = new string * [x];
	for (int j = 0; j < x; j++) {
		Mine[j] = new string[y];
	}
	leeresFeld(x, y, Mine);
	Minenfeld(x, y, m, Mine);
}

char** Spielfeld::getArray() {
	return Feld;
}

int Spielfeld::getLaengeX() {
	return m_laengeX;
}

void Spielfeld::leeresFeld(int x, int y, string** Feld) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			Feld[i][j] = '.';
		}
	}
}

void Spielfeld::Ausgabenfeld(int x, int y, string**Feld) {
	char alph = 'A';
	
	//linke obere Ecke -> leer
	Feld[0][0] = ' ';
	Feld[0][1] = ' ';
	Feld[1][0] = ' ';
	Feld[1][1] = '|';
	//erste Zeile -> Alphabet / zweite Zeile -> '-' 
	for (int i = 2; i < y; i++) {
		Feld[0][i] = alph;
		alph++;
		Feld[1][i] = '-';
	}
	alph = 'A';
	//erste Spalte -> Zahlen / zweite Spalte -> '|'
	for (int i = 2; i < x; i++) {
		Feld[i][0] = alph;
		alph++;
		Feld[i][1] = '|';
	}

	for (int i = 2; i < x; i++) {
		for (int j = 2; j < y; j++) {
			Feld[i][j] = '#';
		}
	}

	for (int i = 2; i < x; i++) {
		for (int j = 2; j < y; j++) {
			Feld[i][j] = '#';
		}
	}

	Ausgabe(x,y,Feld);
}

void Spielfeld::Minenfeld(int x, int y, int m, string** Feld) {
	int f1 = 0;
	int f2 = 0;
	while (m!=0) {
		f1 = ZufallszahlI(2,x-1);
		f2 = ZufallszahlI(2,y-1);
			if (Feld[f1][f2] != "X") {
				Feld[f1][f2] = 'X';
				m--;
			}
	}
	Ausgabe(x,y,Feld);
	cout << endl;

	for (int i = 2; i < x; i++) {
		for (int j = 2; j < x; j++) {
			if (Feld[i][j]!="X") {
				Feld[i][j] = getMinZahl(i, j, Feld);
			}
		}
	}
	Ausgabe(x,y,Feld);
}

string Spielfeld::getMinZahl(int x, int y, string** Feld) {
	int anz = 0;
	int maxY = m_laengeX + 2;
	int maxX = m_laengeY + 2;

	cout << "X: " << x << "Y: " << y<< endl;

	int xL = x - 1;
	int yL = y - 1;

	for (int i = 0;i < 3 ;i++) {
		cout << xL << endl;
		cout << endl;
		for (int j = 0; j < 3; j++) {
			if (2 <= xL && xL < maxX && 2 <= yL && yL < maxY) {
				if (Feld[xL][yL] == "X") {
					anz++;
				}
			}
			cout << yL << endl;
			yL++;
		}
		cout << endl << endl;
		yL = y - 1;
		xL++;
	}

	cout << "-----------------------------------" << endl;

	string umwandlung;

	switch (anz) {
	case 0:
		umwandlung = ".";
		break;
	case 1:
		umwandlung = "a";
		break;
	case 2:
		umwandlung = "b";
		break;
	case 3:
		umwandlung = "c";
		break;
	case 4:
		umwandlung = "d";
		break;
	case 5:
		umwandlung = "e";
		break;
	case 6:
		umwandlung = "f";
		break;
	case 7:
		umwandlung = "g";
		break;
	case 8:
		umwandlung = "h";
		break;
	}
	return umwandlung;
}

int ZufallszahlI(int untereGrenze, int obereGrenze)
{
	return (rand() % (obereGrenze - untereGrenze + 1)) + untereGrenze;
}

void Spielfeld::Ausgabe(int x, int y, string**Feld) {
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			cout << Feld[i][j];
		}
		cout << endl;
	}
}
