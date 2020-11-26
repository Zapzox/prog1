#include <iostream>
#include <cmath>
#include "Rechner.h"
using namespace std;

//Eigentliche Funktionen

Rechner::Rechner() {

}

void Rechner::SetterArr(int Eingabe[], int länge) {
	Ausgabe(Eingabe, länge);
	GeoM(Eingabe,länge);
	Mod(Eingabe, länge);
}

void Rechner::Ausgabe(int Eingabe[], int länge) {
	cout << "Array[";
	for (int j = 1; j < länge; j++) {
		cout << *Eingabe << ",";
		Eingabe++;	
	}
	cout << *Eingabe;
	cout << "]"<< endl;
}

void Rechner::GeoM(int Eingabe[], int länge) {
	double mul = 1;
	for (int i = 0; i < länge; i++) {
		mul *= *Eingabe;
		Eingabe++;
	}
	cout << endl;
	//Formel
	cout << "geometrischer Mittelwert:"<<pow(mul , 1.0 / länge) << endl;
}

void Rechner::Mod(int Eingabe[], int länge) {
	int max = -64;
	int e = 1;
	for (int j = 0; j < länge; j++) {
		if (max < *Eingabe) {
			max = *Eingabe;
			e = j + 1;
			Eingabe++;
		}
	}
	cout << "Modalwert:" << max;
}