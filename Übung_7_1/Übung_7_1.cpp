#include <iostream>
#include <cmath>
#include "Rechner.h"
using namespace std;
using namespace Statistik;

int main() {
	long Eingabe[] = { 4,3,3,2,1 };
	int länge = (sizeof(Eingabe) / sizeof(int));
	Rechner einRechner;
	//einRechner.SetterArr(Eingabe, länge);
	//einRechner.Mod(Eingabe, länge);
	einRechner.AnzahlArr(Eingabe, länge, *Eingabe);

}
