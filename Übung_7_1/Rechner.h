#pragma once
//Deklaration

namespace Statistik {
	class Rechner {

	public:
		Rechner();
		void SetterArr(long Eingabe[], int länge);

	private:
		void GeoM(long Eingabe[], int länge);
		void Mod(long Eingabe[], int länge);
		int AnzahlArr(long Eingabe[], int länge, int wert);
		void Ausgabe(long Eingabe[], int länge);

	};
}