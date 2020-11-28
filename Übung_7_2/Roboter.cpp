#include <iostream>
#include <cmath>
using namespace std;
#include "Roboter.h"

Roboter::Roboter(int en, int pos, string name, char Feld[]) {
	Energiewert = en;
	Position = pos;
	Name = name;
	Feld[pos] = Name[0];
}

void Roboter::setEn(int en) {
	Energiewert = en;
}

int Roboter::getEn() {
	return Energiewert;
}

int Roboter::getPos() {
	return Position;
}

string Roboter::getName() {
	return Name;
}

string Roboter::reden(Roboter) {
	int c = ZufallszahlI(0, 2);
	switch (c) {
	case 0:
		Energiewert -= 5;
		return "Beleidigung";
		break;
	case 1:
	case 2:
		return "Servus!";
		break;
	}
}

void Roboter::move(Roboter Roboter, char Feld[]) {
	int c = ZufallszahlI(0, 2);
	switch (c) {
	case 0:
		break;
	case 1:
		if (borderR(Position, Feld) == false) {
			Roboter.PosClear(Roboter, Feld);
			Position += 1;
			Feld[Position] = Name[0];
			Energiewert -= 5;
		}
		break;
	case 2:
		if (borderL(Position, Feld) == false) {
			Roboter.PosClear(Roboter, Feld);
			Position -= 1;
			Feld[Position] = Name[0];
			Energiewert -= 5;
		}
		break;
	}
}

bool borderR(int Position, char Feld[]) {
	int pos = Position;
	pos += 1;

	if (Feld[pos] == '|') {
		return true;
	}
	else {
		return false;
	}
}

bool borderL(int Position, char Feld[]) {
	int pos = Position;
	pos -= 1;


	if (Feld[pos] == '|') {
		return true;
	}
	else {
		return false;
	}
}

void Roboter::PosClear(Roboter Roboter, char Feld[]) {
	Feld[Position] = ' ';
}

int ZufallszahlI(int untereGrenze, int obereGrenze)
{
	return (rand() % (obereGrenze - untereGrenze + 1)) + untereGrenze;
}

void leeresFeld(char Feld[]) {
	Feld[0] = '|';
	Feld[21] = '|';
	for (int i = 1; i <= 20; i++) {
		Feld[i] = ' ';
	}
}

void Ausgabe(char Feld[]) {
	//system("cls");
	for (int i = 0; i <= 21; i++) {
		cout << *Feld;
		Feld++;
	}
	cout << endl;
}