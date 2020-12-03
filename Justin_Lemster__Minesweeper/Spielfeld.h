#include <iostream>
#include <string>
#pragma once

using namespace std;

int ZufallszahlI(int untereGrenze, int obereGrenze);

class Spielfeld
{
public:
	bool m_GameOver;
	bool m_Win;
	int m_laengeX;
	int m_laengeY;
	int m_MaxlaengeX;
	int m_MaxlaengeY;
	int m_MinenAnz;
	int m_Stopuhr;
	string** Anzeige;
	string** Minen;

	Spielfeld();
	Spielfeld(int x, int y, int m);
	string** getAnzeige();
	string** getMinen();
	int getLaengeX();
	int getLaengeY();
	int getStopuhr();
	int getMinenAnz();
	bool getGameOver();
	bool getWin();
	void setWin(bool win);
	void checkWin(string** Anzeige, string** Minen);
	string getMinZahl(int x, int y, string** Feld);
	void Eingabe(int x, int y, string** Anzeige, string** Minen);
	int EingabeUmwandeln(char um);
	void Aufdecken(int x, int y, string** Anzeige, string** Minen);
	void Stopuhr();

	void leeresFeld(int x, int y, string** Feld);
	void Ausgabenfeld(int x, int y, string** Feld);
	void Minenfeld(int x, int y, int m, string** Feld);
	void Ausgabe(int x, int y, string**Feld);
};

