#pragma once
//Deklaration

namespace Statistik {
	class Rechner {

	public:
		Rechner();
		void SetterArr(long Eingabe[], int l�nge);
		int AnzahlArr(long Eingabe[], int l�nge, int wert);

	
		void GeoM(long Eingabe[], int l�nge);
		void Mod(long Eingabe[], int l�nge);

		void Ausgabe(long Eingabe[], int l�nge);

	};
}