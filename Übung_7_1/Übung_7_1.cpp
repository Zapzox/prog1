#include <iostream>
#include <cmath>
#include "Rechner.h"
using namespace std;
using namespace Statistik;

int main() {
	long Eingabe[] = { 4,3,3,2,1 };
	int l�nge = (sizeof(Eingabe) / sizeof(int));
	Rechner einRechner;
	//einRechner.SetterArr(Eingabe, l�nge);
	//einRechner.Mod(Eingabe, l�nge);
	einRechner.AnzahlArr(Eingabe, l�nge, *Eingabe);

}
