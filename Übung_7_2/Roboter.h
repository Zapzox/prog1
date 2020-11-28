#pragma once
using namespace std;

void leeresFeld(char Feld[]);
void Ausgabe(char Feld[]);
int ZufallszahlI(int untereGrenze, int obereGrenze);
bool borderR(int Position, char Feld[]);
bool borderL(int Position, char Feld[]);

class Roboter
{
public:
	int Energiewert;
	int Position;
	string Name;
	Roboter(int en, int pos, string name, char Feld[]);
	void move(Roboter Roboter, char Feld[]);
	void setEn(int en);
	int getEn();
	int getPos();
	void PosClear(Roboter Roboter, char Feld[]);
	string getName();
	string reden(Roboter);
	
//private:
};

