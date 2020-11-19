#define _USE_MATH_DEFINES 
#include <iostream>
#include <math.h>  

using namespace std;

float GB(float g) {
	float e;
	e = g / 360 * 2 * M_PI;
	return e;
}

float BG(float b) {
	float e;
	e = b / M_PI * 180;
	return e;
}

int main()
{
	std::locale::global(std::locale("German_germany.UTF-8"));

	int a;
	cout << "|Winkelmaß von Grad nach Bogenmaß umrechnen|" << endl << endl 
		 << "In welche Richtung wollen Sie umrechnen?" << endl 
		 << "(1) Grad --> Bogenmaß" << endl << "(2) Bogenmaß --> Gradmaß" << endl;
	cin >> a;

	if (a == 1) {
		float g;

		system("cls");
		cout << "Grad --> Bogenmaß" << endl << endl
			<< "Geben Sie ihren Winkel ein:" << endl;
		cin >> g;

		cout << "Winkel im Bogenmaß:" << GB(g) << "°";
	}
	else if (a == 2) {
		float b;

		system("cls");
		cout << "Bogenmaß --> Gradmaß" << endl << endl
			<< "Geben Sie ihren Winkel ein:" << endl;
		cin >> b;

		cout << "Winkel im Gradmaß:" << BG(b) << "°";
	}
}
