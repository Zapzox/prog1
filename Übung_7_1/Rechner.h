#pragma once
//Deklaration

class Rechner {

public:
	Rechner();
	void SetterArr(int Eingabe[], int länge);

private:
	void GeoM(int Eingabe[], int länge);
	void Mod(int Eingabe[], int länge);
	void Ausgabe(int Eingabe[], int länge);

};