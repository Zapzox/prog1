#include <iostream>
#include <windows.h>
#include <iomanip>

#include "Spielfeld.h"

using namespace std;

int main()
{
	srand(static_cast<unsigned>(time(0)));
	//Umlaute in der Konsole
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);

	int Schwierigkeitsgrad = 0;
	Spielfeld *Anzeige = nullptr;

	cout << setfill(' ');
	cout << "Willkommen bei Minesweeper!" << endl << endl
		<< "Wählen Sie einen Schwierigkeitsgrad / Modi:" << endl << endl
		<< setw(9) << left << "     Stufe " << "|" << setw(9) << right << "Minen" << "|" << setw(9) << right << "Größe" << "|" << endl
		<< setw(9) << left << "(1) Leicht " << "|" << setw(9) << right << "10" << "|" << setw(9) << right << "9x9" << "|" << endl
		<< setw(9) << left << "(2) Mittel " << "|" << setw(9) << right << "40" << "|" << setw(9) << right << "16x16" << "|" << endl
		<< setw(9) << left << "(3) Schwer " << "|" << setw(9) << right << "99" << "|" << setw(9) << right << "16x24" << "|" << endl
		<< setw(9) << left << "(4) Custom " << "|" << setw(9) << right << "?" << "|" << setw(9) << right << "?" << "|" << endl << endl
		<< "Eingabe: ";
	cin >> Schwierigkeitsgrad;

	switch (Schwierigkeitsgrad) {
	case 1:
		Anzeige = new Spielfeld(9, 9, 10);
		break;
	case 2:
		Anzeige = new Spielfeld(16, 16, 40);
		break;
	case 3:
		Anzeige = new Spielfeld(20, 20, 99);
		break;
	case 4:
		bool RichtigeEingabe = false;
		int Minen = 0;
		int x = 0;
		int y = 0;
		int Rechnung = 0;
		//X-Achse Eingabe
		while (RichtigeEingabe == false) {
			system("cls");
			cout << "X-Achse (Maximal 24, Minimal 2)" << endl
				<< "Eingabe: ";
			cin >> x;
			if (x >= 2 && x <= 24){
				RichtigeEingabe = true;
			}
			else {
				system("cls");
				cout << "Falsche Eingabe!" << endl
					<< "Versuche es erneut" << endl;
				system("PAUSE");
			}
		}
		RichtigeEingabe = false;
		//Y-Achse Eingabe
		while (RichtigeEingabe == false) {
			system("cls");
			cout << "Y-Achse (Maximal 24, Minimal 2)" << endl
				<< "Eingabe: ";
			cin >> y;
			if (y >= 2 && y<=24) {
				RichtigeEingabe = true;
			}
			else {
				system("cls");
				cout << "Falsche Eingabe!" << endl
					<< "Versuche es erneut" << endl;
				system("PAUSE");
			}
		}
		RichtigeEingabe = false;
		//Minen Eingabe
		while (RichtigeEingabe == false) {
			system("cls");
			cout << "Minen (Maximal die Hälfte der entstehenden Felder, Minimal 1)" << endl
				<< "Eingabe: ";
			cin >> Minen;
			//Felderanzahl
			Rechnung = (x * y) / 2;
			if (Rechnung >= Minen && Minen > 0) {
				RichtigeEingabe = true;
			}
			else {
				system("cls");
				cout << "Falsche Eingabe!" << endl
					<< "Versuche es erneut" << endl;
				system("PAUSE");
			}
		}
		//Spielfeld generieren
		Anzeige = new Spielfeld(x, y, Minen);
		
		break;
	}


	long Stopuhr = 0;
	
}
