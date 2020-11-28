#include <iostream>
#include <cmath>
using namespace std;
#include "Roboter.h"

Roboter::Roboter(int en, int pos, string name) {
	int Energiewert = en;
	int Position = pos;
	string Name = name;
}

void leeresFeld(char Feld[]) {
	Feld[0] = '|';
	cout << Feld[0] << endl;
	Feld[11] = '|';
	for (int i = 1; i <= 10; i++) {
		Feld[i]= ' ';
	}
}

int ZufallszahlI(int untereGrenze, int obereGrenze)
{
	return (rand() % (obereGrenze - untereGrenze + 1)) + untereGrenze;
}

void Ausgabe(char Feld[]) {
	system("cls");
	for (int i = 0; i <= 11; i++) {
		cout << Feld[i];
	}
}