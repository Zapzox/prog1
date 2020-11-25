#define _USE_MATH_DEFINES 
#include <iostream>
#include <math.h>  

using namespace std;

float ValGB(float G) {
	float e;
	e = G / 360 * 2 * M_PI;
	return e;
}

float ValBG(float B) {
	float e;
	e = B / M_PI * 180;
	return e;
}

void RefRefGB(float &RefG) {
	RefG = RefG / 360 * 2 * M_PI;
}

void RefRefBG(float &RefB) {
	RefB = RefB / M_PI * 180;
}

void RefZeiGB(float* ZeigG) {
	*ZeigG = *ZeigG / 360 * 2 * M_PI;
}

void RefZeiBG(float* ZeigB) {
	*ZeigB = *ZeigB / M_PI * 180;
}

int main()
{
	std::locale::global(std::locale("German_germany.UTF-8"));

		system("cls");

		int a;
		cout << "|Winkelmaß von Grad nach Bogenmaß umrechnen|" << endl << endl
			<< "In welche Richtung wollen Sie umrechnen?" << endl
			<< "(1) Grad --> Bogenmaß" << endl << "(2) Bogenmaß --> Gradmaß" << endl;
		cin >> a;

		if (a == 1) {
			float g1;

			system("cls");
			cout << "Grad --> Bogenmaß" << endl << endl
				<< "Geben Sie ihren Winkel ein:" << endl;
			cin >> g1;
			float g2 = g1;
			float g3 = g1;

			cout << "Winkel im Bogenmaß (Value):" << ValGB(g1) << "°" << endl;
			RefRefGB(g2);
			cout << "Winkel im Bogenmaß (Referenz):" << g2 << "°" << endl;
			RefZeiGB(&g3);
			cout << "Winkel im Bogenmaß (Zeiger):" << g3 << "°";

		}
		else if (a == 2) {
			float b1;

			system("cls");
			cout << "Bogenmaß --> Gradmaß" << endl << endl
				<< "Geben Sie ihren Winkel ein:" << endl;
			cin >> b1;
			float b2 = b1;
			float b3 = b1;

			cout << "Winkel im Gradmaß (Value):" << ValBG(b1) << "°" << endl;
			RefRefBG(b2);
			cout << "Winkel im Gradmaß (Referenz):" << b2 << "°" << endl;
			RefZeiBG(&b3);
			cout << "Winkel im Gradmaß (Zeiger)	:" << b3 << "°";
		}
	
	return 0;
}
