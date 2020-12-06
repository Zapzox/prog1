#include <iostream>
#include <string>
#pragma once

using namespace std;

int ZufallszahlI(int untereGrenze, int obereGrenze);

class Spielfeld
{
public:
	//Membervariablen
	bool m_GameOver;
	bool m_Win;
	int m_laengeX;
	int m_laengeY;
	int m_MaxlaengeX;
	int m_MaxlaengeY;
	int m_MinenAnz;
	string** Anzeige;
	string** Minen;
	//Funktionen
	Spielfeld(int x, int y, int m);
	//getter und setter 
	string** getAnzeige();
	string** getMinen();
	int getLaengeX();
	int getLaengeY();
	int getMinenAnz();
	bool getGameOver();
	bool getWin();
	void setWin(bool win);
	string getMinZahl(int x, int y, string** Feld);
	//Funktionen f�r das erstellen der dynamischen Arrays
	void leeresFeld(int x, int y, string** Feld);
	void Ausgabenfeld(int x, int y, string** Feld);
	void Minenfeld(int x, int y, int m, string** Feld);
	//Funktionen f�r den Spielverlauf
	void Eingabe(int x, int y, string** Anzeige, string** Minen);
	int EingabeUmwandeln(char um);
	void Aufdecken(int x, int y, string** Anzeige, string** Minen);
	void Ausgabe(int x, int y, string**Feld);
};

