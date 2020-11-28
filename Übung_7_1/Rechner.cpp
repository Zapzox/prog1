#include <iostream>
#include <cmath>
#include "Rechner.h"
using namespace std;
using namespace Statistik;

//Eigentliche Funktionen

Rechner::Rechner() {

}

void Rechner::SetterArr(long Eingabe[], int l�nge) {
	Ausgabe(Eingabe, l�nge);
	GeoM(Eingabe,l�nge);
	Mod(Eingabe, l�nge);
}

void Rechner::Ausgabe(long Eingabe[], int l�nge) {
	cout << "Array[";
	for (int j = 1; j < l�nge; j++) {
		cout << *Eingabe << ",";
		Eingabe++;	
	}
	cout << *Eingabe;
	cout << "]"<< endl;
}

void Rechner::GeoM(long Eingabe[], int l�nge) {
	double mul = 1;
	for (int i = 0; i < l�nge; i++) {
		mul *= *Eingabe;
		Eingabe++;
	}
	cout << endl;
	//Formel
	cout << "geometrischer Mittelwert:"<<pow(mul , 1.0 / l�nge) << endl;
}

void Rechner::Mod(long Eingabe[], int l�nge) {
	long* Anf = Eingabe;
	int EWert = *Eingabe;
	int EAnz = AnzahlArr(Eingabe, l�nge, *Eingabe);

	for (int i = 0; i < l�nge; i++) {
		
		Eingabe++;
		int e2 = AnzahlArr(Eingabe, l�nge, *Eingabe);

		if (EAnz < e2) {
			EAnz = e2;
			EWert = *Eingabe;
		}
	}
	cout << "Modalwert ist die Zahl: " << EWert << " (x" << EAnz << "mal)" <<endl;

}
int Rechner::AnzahlArr(long Test[], int l�nge, int wert) {
	int anz = 0;
	for (int j = 0; j < l�nge; j++) {
		if (wert == *Test) {
			anz++;
		}
		Test++;
	}
	return anz;
}
