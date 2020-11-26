#include <iostream>
#include <cmath>
#include "Rechner.h"
using namespace std;

//Eigentliche Funktionen

Rechner::Rechner() {

}

void Rechner::SetterArr(int Eingabe[], int l�nge) {
	Ausgabe(Eingabe, l�nge);
	GeoM(Eingabe,l�nge);
	Mod(Eingabe, l�nge);
}

void Rechner::Ausgabe(int Eingabe[], int l�nge) {
	cout << "Array[";
	for (int j = 1; j < l�nge; j++) {
		cout << *Eingabe << ",";
		Eingabe++;	
	}
	cout << *Eingabe;
	cout << "]"<< endl;
}

void Rechner::GeoM(int Eingabe[], int l�nge) {
	double mul = 1;
	for (int i = 0; i < l�nge; i++) {
		mul *= *Eingabe;
		Eingabe++;
	}
	cout << endl;
	//Formel
	cout << "geometrischer Mittelwert:"<<pow(mul , 1.0 / l�nge) << endl;
}

void Rechner::Mod(int Eingabe[], int l�nge) {
	int max = -64;
	int e = 1;
	for (int j = 0; j < l�nge; j++) {
		if (max < *Eingabe) {
			max = *Eingabe;
			e = j + 1;
			Eingabe++;
		}
	}
	cout << "Modalwert:" << max;
}