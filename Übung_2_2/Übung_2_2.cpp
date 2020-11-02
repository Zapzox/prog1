#define _USE_MATH_DEFINES // Abrufbar über M_PI
#include <iostream>
#include <math.h>         // Abrufbar über M_PI

using namespace std;

int main()
{
	double pi = 2 * asin(1.0);// Abrufbar über pi

	double rad = 1.3;
	double umf = 2 * M_PI * rad;
	double vol = (4.0 / 3.0) * M_PI * pow(rad, 3);
	double ober = 4.0 * M_PI * pow(rad, 2);

	std::locale::global(std::locale("German_germany.UTF-8"));

	cout << "Eine Kugel mit dem Radius "<< rad << " hat eine(n):" << endl;
	cout << "Umfang: " << umf << endl;
	cout << "Volumen: " << vol << endl;
	cout << "Oberfläche: " << ober << endl;

	return 0;
}

