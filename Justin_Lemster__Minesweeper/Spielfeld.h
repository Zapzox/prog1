#include <iostream>
#include <string>
#pragma once

using namespace std;

int ZufallszahlI(int untereGrenze, int obereGrenze);

class Spielfeld
{
public:
	int m_laengeX;
	int m_laengeY;
	int m_MinenAnz;
	char** Feld;

	Spielfeld(int x, int y, int m);
	char** getArray();
	int getLaengeX();
	string getMinZahl(int x, int y, string** Feld);

	void leeresFeld(int x, int y, string** Feld);
	void Ausgabenfeld(int x, int y, string** Feld);
	void Minenfeld(int x, int y, int m, string** Feld);
	void Ausgabe(int x, int y, string**Feld);
};

