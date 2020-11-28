#include <iostream>
#include <cmath>
#include "Rechner.h"
using namespace std;
using namespace Statistik;

//Eigentliche Funktionen

Rechner::Rechner() {

}

void Rechner::SetterArr(long Eingabe[], int länge) {
	Ausgabe(Eingabe, länge);
	GeoM(Eingabe,länge);
	Mod(Eingabe, länge);
}

void Rechner::Ausgabe(long Eingabe[], int länge) {
	cout << "Array[";
	for (int j = 1; j < länge; j++) {
		cout << *Eingabe << ",";
		Eingabe++;	
	}
	cout << *Eingabe;
	cout << "]"<< endl;
}

void Rechner::GeoM(long Eingabe[], int länge) {
	double mul = 1;
	for (int i = 0; i < länge; i++) {
		mul *= *Eingabe;
		Eingabe++;
	}
	cout << endl;
	//Formel
	cout << "geometrischer Mittelwert:"<<pow(mul , 1.0 / länge) << endl;
}

void Rechner::Mod(long Eingabe[], int länge) {
	long* Anf = Eingabe;
	int EWert = *Eingabe;
	int EAnz = AnzahlArr(Eingabe, länge, *Eingabe);

	for (int i = 0; i < länge; i++) {
		
		Eingabe++;
		int e2 = AnzahlArr(Eingabe, länge, *Eingabe);

		if (EAnz < e2) {
			EAnz = e2;
			EWert = *Eingabe;
		}
	}
	cout << "Modalwert ist die Zahl: " << EWert << " (x" << EAnz << "mal)" <<endl;

}
int Rechner::AnzahlArr(long Test[], int länge, int wert) {
	int anz = 0;
	for (int j = 0; j < länge; j++) {
		if (wert == *Test) {
			anz++;
		}
		Test++;
	}
	return anz;
}
