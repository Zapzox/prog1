#include <iostream>
#include <cmath>
#include "Rechner.h"
using namespace std;

int main() {
	int Eingabe[] = { 4,3,3,2,1 };

	Rechner einRechner;
	einRechner.SetterArr(Eingabe, (sizeof(Eingabe) / sizeof(int)));

}
