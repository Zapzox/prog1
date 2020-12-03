#include <iostream>
#include<stdio.h>
#include<math.h>
#include <thread>        
#include <chrono> 
#include "Spielfeld.h"

using namespace std;

Spielfeld::Spielfeld(int x, int y, int m) {
	system("cls");
	m_GameOver = false;
	m_Win = false;
	m_laengeX = x;
	m_laengeY = y;
	m_MaxlaengeX = x + 2;
	m_MaxlaengeY = y + 2;
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
	Anzeige = Anz;

	//2D Array Mine erstellen
	string** Mine = new string * [x];
	for (int j = 0; j < x; j++) {
		Mine[j] = new string[y];
	}
	leeresFeld(x, y, Mine);
	Minenfeld(x, y, m, Mine);
	Minen = Mine;
}

string** Spielfeld::getMinen() {
	return Minen;
}

int Spielfeld::getMinenAnz() {
	return m_MinenAnz;
}

string** Spielfeld::getAnzeige() {
	return Anzeige;
}

int Spielfeld::getLaengeX() {
	return m_MaxlaengeX;
}

int Spielfeld::getLaengeY() {
	return m_MaxlaengeY;
}

bool Spielfeld::getGameOver() {
	return m_GameOver;
}

bool Spielfeld::getWin() {
	return m_Win;
}

void Spielfeld::setWin(bool win) {
	m_Win = win;
}

void Spielfeld::Stopuhr() {
	while (m_Win == false && m_GameOver == false) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		m_Stopuhr += 1;
	}
}

int Spielfeld::getStopuhr() {
	return m_Stopuhr;
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

	for (int i = 2; i < x; i++) {
		for (int j = 2; j < y; j++) {
			if (Feld[i][j]!="X") {
				Feld[i][j] = getMinZahl(i, j, Feld);
			}
		}
	}
}

string Spielfeld::getMinZahl(int x, int y, string** Feld) {
	int anz = 0;
	int maxX = m_laengeX + 2;
	int maxY = m_laengeY + 2;

	int xL = x - 1;
	int yL = y - 1;

	for (int i = 0;i < 3 ;i++) {
		for (int j = 0; j < 3; j++) {
			if (2 <= xL && xL < maxX && 2 <= yL && yL < maxY) {
				if (Feld[xL][yL] == "X") {
					anz++;
				}
			}
			yL++;
		}
		yL = y - 1;
		xL++;
	}

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

int Spielfeld::EingabeUmwandeln(char um) {
	int f = 0;
	switch (um) {
	case 'a':
		f = 2;
		break;
	case 'b':
		f = 3;
		break;
	case 'c':
		f = 4;
		break;
	case 'd':
		f = 5;
		break;
	case 'e':
		f = 6;
		break;
	case 'f':
		f = 7;
		break;
	case 'g':
		f = 8;
		break;
	case 'h':
		f = 9;
		break;
	case 'i':
		f = 10;
		break;
	case 'j':
		f = 11;
		break;
	case 'k':
		f = 12;
		break;
	case 'l':
		f = 13;
		break;
	case 'm':
		f = 14;
		break;
	case 'n':
		f = 15;
		break;
	case 'o':
		f = 16;
		break;
	case 'p':
		f = 17;
		break;
	case 'q':
		f = 18;
		break;
	case 'r':
		f = 19;
		break;
	case 's':
		f = 20;
		break;
	case 't':
		f = 21;
		break;
	case 'u':
		f = 22;
		break;
	case 'v':
		f = 23;
		break;
	case 'w':
		f = 24;
		break;
	case 'x':
		f = 25;
		break;
	case 'y':
		f = 26;
		break;
	case 'z':
		f = 27;
		break;
	}
	return f;
}

void Spielfeld::Eingabe(int x, int y, string**Anzeige, string**Minen) {

	if (Minen[x][y] == "X") {
		m_GameOver = true;
	}
	else if (Minen[x][y] != "X" && Minen[x][y] != ".") {
		Anzeige[x][y] = Minen[x][y];
	}
	else if (Minen[x][y] == ".") {
		Anzeige[x][y] = Minen[x][y];
		Minen[x][y] = "*";
		//Ausgabe(x, y, Anzeige);
		Aufdecken(x,y,Anzeige,Minen);
	}

}


void Spielfeld::Aufdecken(int x, int y, string** Anzeige, string** Minen) {
	int maxX = m_laengeX + 2;
	int maxY = m_laengeY + 2;

	int xL = x - 1;
	int yL = y - 1;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (2 <= xL && xL < maxX && 2 <= yL && yL < maxY) {
				if (Minen[xL][yL] != "X" && Minen[xL][yL] != "*") {
					Eingabe(xL, yL, Anzeige, Minen);

				}
			}
			yL++;
		}
		yL = y - 1;
		xL++;
	}
}

void Spielfeld::checkWin(string** Anzeige, string** Minen) {
	bool nichtX = true;
	bool gleichX = true;

	for (int i = 0; i < m_MaxlaengeX; ++i) {
		for (int j = 0; j < m_MaxlaengeY; ++j) {
			if (nichtX == true && Anzeige[i][j] == "#") {
				if (Minen[i][j] == "X") {
					nichtX = true;
				}
				else {
					nichtX = false;
				}
			}
			if (gleichX == true && Anzeige[i][j] != "#") {
				if (Anzeige[i][j] == Minen[i][j]) {
					gleichX = true;
				}
				else {
					gleichX = false;
				}
			}
		}
	}

	if (nichtX == true && gleichX == true) {
		m_Win = true;
	}
}

int ZufallszahlI(int untereGrenze, int obereGrenze)
{
	return (rand() % (obereGrenze - untereGrenze + 1)) + untereGrenze;
}

void Spielfeld::Ausgabe(int x, int y, string**Feld) {
	system("cls");
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			cout << Feld[i][j];
		}
		cout << endl;
	}
}
