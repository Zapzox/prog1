#pragma once
//Deklaration

class Rechner {

public:
	Rechner();
	void SetterArr(int Eingabe[], int l�nge);

private:
	void GeoM(int Eingabe[], int l�nge);
	void Mod(int Eingabe[], int l�nge);
	void Ausgabe(int Eingabe[], int l�nge);

};