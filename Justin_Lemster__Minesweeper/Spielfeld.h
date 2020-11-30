#pragma once
class Spielfeld
{
public:
	int m_laengeX = 0;
	int m_laengeY = 0;
	int m_MinenAnz = 0;

	Spielfeld();
	Spielfeld(int x, int y, int m);
	void Ausgabe();
};

