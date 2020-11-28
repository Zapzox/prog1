#include <iostream>
#include <cmath>
#include "Rechner.h"
using namespace std;
using namespace Statistik;

int main() {
	long Eingabe[] = { 4,3,3,2,1 };

	Rechner einRechner;
	einRechner.SetterArr(Eingabe, (sizeof(Eingabe) / sizeof(int)));
	einRechner.SetterArr(Eingabe, (sizeof(Eingabe) / sizeof(int)));

}
