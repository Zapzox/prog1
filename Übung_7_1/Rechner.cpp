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
	int EWert = 0;
	int EAnz = 0;

	for (int k = 0; k < länge; k++) {
		if (AnzahlArr(Eingabe, länge, *Eingabe) == 0) {
			cout << "Zahl:" << EWert << " Anzahl:" << EAnz << endl;
		}
		else {
			int e1 = AnzahlArr(Eingabe, länge, *Eingabe);
			int e2 = AnzahlArr(Eingabe, länge, *Eingabe++);
			if (e1 < e2) {
				EAnz = e2;
				EWert = *Eingabe++;
			}
			else {
				EAnz = e1;
				EWert = *Eingabe;
			}
			Eingabe++;
		}
	}
	/*long* Anf = Eingabe;
	int max = *Eingabe;
	Eingabe++;
	int max2 = *Eingabe;
	int erg = 0;
	int e1 = 0;
	int e2 = 0;

	Eingabe = Anf;
	for (int k = 0; k < länge; k++) {
		for (int j = 0; j < länge; j++) {
			if (max == *Eingabe) {
				e1++;
				cout << max << ":" << e1 << endl;
				Eingabe++;
			}
		}
		Eingabe = Anf;
		for (int j = 0; j < länge; j++) {
				if (max2 == *Eingabe) {
					e2++;
					cout << "E2:" << e2 << endl;
					Eingabe++;
				}
		}
		Eingabe = Anf;
		if (e1 < e2) {
			max = max2;
			e1 = e2;
			erg = e2;
			e1 = 0;
			e2 = 0;
		}
		else {
			erg = e1;
			e1 = 0;
			e2 = 0;
		}
	}*/
	
}

int Rechner::AnzahlArr(long Eingabe[], int länge, int wert) {
	int anz = 0;
	cout << Eingabe << " : " << *Eingabe<< endl;
	for (int j = 0; j < länge; j++) {
		if (wert == *Eingabe) {
			anz++;
		}
		Eingabe++;
	}
	cout << anz << endl;
	return anz;
}
