#pragma once

int ZufallszahlI(int untereGrenze, int obereGrenze);

class Spielfeld
{
public:
	int m_laengeX = 0;
	int m_laengeY = 0;
	int m_MinenAnz = 0;
	char** Feld;

	Spielfeld(int x, int y, int m);
	char** getArray();
	int getLaengeX();
	int getMinZahl(int x, int y, char** Feld);
	void Ausgabenfeld(int x, int y, char** Feld);
	void Minenfeld(int x, int y, int m, char** Feld);
	void Ausgabe(int laengeX,char** Feld);
};

