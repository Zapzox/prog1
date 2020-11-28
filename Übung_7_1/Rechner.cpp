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
	int term = 2;

	while (term != 0) {
		int wert = *Eingabe;
		int term = AnzahlArr(Eingabe, l�nge, wert);
		cout << *Eingabe << term;
		Eingabe++;
		term--;
	}
	
	/*int EWert = 0;
	int EAnz = 0;
	int term = AnzahlArr(Eingabe, l�nge, *Eingabe);

		while (term != 0) {
		int e1 = 0;
		int e2 = 0;

			e1 = AnzahlArr(Eingabe, l�nge, *Eingabe);
			e2 = AnzahlArr(Eingabe, l�nge, *Eingabe++);
			if (e1 < e2) {
				EAnz = e2;
				EWert = *Eingabe++;
				cout << EWert << endl;
			}
			else {
				EAnz = e1;
				EWert = *Eingabe;
				cout << EWert << endl;
			}
			Eingabe++;
		}
		cout << "Zahl:" << EWert << " Anzahl:" << EAnz << endl;
	}



	/*long* Anf = Eingabe;
	int max = *Eingabe;
	Eingabe++;
	int max2 = *Eingabe;
	int erg = 0;
	int e1 = 0;
	int e2 = 0;

	Eingabe = Anf;
	for (int k = 0; k < l�nge; k++) {
		for (int j = 0; j < l�nge; j++) {
			if (max == *Eingabe) {
				e1++;
				cout << max << ":" << e1 << endl;
				Eingabe++;
			}
		}
		Eingabe = Anf;
		for (int j = 0; j < l�nge; j++) {
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
int Rechner::AnzahlArr(long Test[], int l�nge, int wert) {
	int anz = 0;
	for (int j = 0; j < l�nge; j++) {
		if (wert == *Test) {
			anz++;
		}
		Test++;
	}
	cout << wert << " : " << anz << endl;
	return anz;
}
