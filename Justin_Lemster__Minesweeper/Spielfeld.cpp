#include <iostream>
#include<stdio.h>
#include<math.h>
#include <thread>        
#include <chrono> 
#include "Spielfeld.h"

using namespace std;
//Konstruktor
Spielfeld::Spielfeld(int x, int y, int m) {
	system("cls");
	m_GameOver = false;
	m_Win = false;
	m_laengeX = x;
	m_laengeY = y;
	m_MaxlaengeX = x + 2;
	m_MaxlaengeY = y + 2;
	m_MinenAnz = m;
	//m_MaxlaengeX und m_MaxlaengeY wurden erst später eingeführt, deswegen arbeite ich hier mit x und y 
	x += 2;
	y += 2;
	//2D Array Anzeige erstellen
	string** Anz = new (string * [x]);
	for (int i = 0; i < x; i++) {
		Anz[i] = new string[y];
	}
	//Array wird mit leeren Zeichen beschrieben und dann gefüllt. Der Pointer des 2D Arrays wird in einer Membervariable gespeichert
	leeresFeld(x, y, Anz);
	Ausgabenfeld(x, y, Anz);
	Anzeige = Anz;

	//2D Array Mine erstellen
	string** Mine = new string * [x];
	for (int j = 0; j < x; j++) {
		Mine[j] = new string[y];
	}
	//Array wird mit leeren Zeichen beschrieben und dann gefüllt. Der Pointer des 2D Arrays wird in einer Membervariable gespeichert
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

void Spielfeld::leeresFeld(int x, int y, string** Feld) {
	//geht das übergebene Array durch und setzt überall Punkte hin
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
	//füllt die Spielfläche mit # -> kennzeichnet die unaufgedeckten Felder
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
	//solange noch Minen vorhanden sind werden 2 Zufallszahlen erzeugt und wenn an dieser Stelle noch keine Mine ist wird dort einen hingesetzt
	while (m!=0) {
		f1 = ZufallszahlI(2,x-1);
		f2 = ZufallszahlI(2,y-1);
			if (Feld[f1][f2] != "X") {
				Feld[f1][f2] = 'X';
				m--;
			}
	}
	//ruft für jedes Feld, welches keine Mine ist getMinZahl auf
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
	//speichert die Werte des Feldes links oben 
	int xL = x - 1;
	int yL = y - 1;
	//geht alle 8 angrenzenden Fleder des übergebenen Feldes durch und zählt für jede vorhandene Mine anz hoch 
	for (int i = 0;i < 3 ;i++) {
		for (int j = 0; j < 3; j++) {
			if (2 <= xL && xL < m_MaxlaengeX && 2 <= yL && yL < m_MaxlaengeY) {
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
	// wandelt den int in einen Buchstaben um
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
	//wandelt char eingabe in einen int um, um auf die jeweilige Array-Position zuzugreifen
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
	//wenn in dem ausgewählten Feld eine Mine ist ist das Spiel verloren
	if (Minen[x][y] == "X") {
		m_GameOver = true;
	}
	//wenn keine Mine oder Punkt (leeres Feld) ausgewählt wurde (dann ist es eine "Zahl") wird diese einfach aufgedeckt 
	else if (Minen[x][y] != "X" && Minen[x][y] != ".") {
		Anzeige[x][y] = Minen[x][y];
	}
	//wenn das ausgewählte Feld ein leeres Feld ist wird dieses aufgedeckt und das dazugehörige Minenfeld auf * gesetzt um dieses als aufgedeckt zu kennzeichnen
	//anschließend wird für diese Feld Aufdecken aufgerufen
	else if (Minen[x][y] == ".") {
		Anzeige[x][y] = Minen[x][y];
		Minen[x][y] = "*";
		//kleiner Cheat für die Testläufe (Ausgabe des Minenfeldes) ^^
		//Ausgabe(x, y, Anzeige);
		Aufdecken(x,y,Anzeige,Minen);
	}

}


void Spielfeld::Aufdecken(int x, int y, string** Anzeige, string** Minen) {
	//speichert die Werte des Feldes links oben 
	int xL = x - 1;
	int yL = y - 1;
	//geht alle 8 angrenzenden Fleder des übergebenen Feldes durch und wenn eines keine Minen und nicht schon als aufgedeckt makiert ist wird für dieses Feld Eingabe aufgerufen
	//somit wird das Feld aufgedeckt und ggf. noch weiter angrenzende Fleder aufgedeckt nzw. erneut Aufdecken für diese aufgerufen
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (2 <= xL && xL < m_MaxlaengeX && 2 <= yL && yL < m_MaxlaengeY) {
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
 
int ZufallszahlI(int untereGrenze, int obereGrenze) {
	//gibt eine zufallszahl zwischen eine festgelegen Ober- und Untergrenze
	return (rand() % (obereGrenze - untereGrenze + 1)) + untereGrenze;
}

void Spielfeld::Ausgabe(int x, int y, string**Feld) {
	//cleart die Konsole
	system("cls");
	//gibt das übergebene 2D Array aus in der Konsole aus (eigentlich nur Anzeige)
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			cout << Feld[i][j];
		}
		cout << endl;
	}
}
