#include <iostream>
#include <windows.h>
#include <thread>        
#include <chrono> 
#include <iomanip>
#include <conio.h>
#include <ctype.h>

#include "Spielfeld.h"

using namespace std;

int main()
{
	srand(static_cast<unsigned>(time(0)));
	//Umlaute in der Konsole
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);

	int Schwierigkeitsgrad = 0;
	bool nochmal = true;

	while (nochmal == true) {
		system("cls");
		Spielfeld* Anzeige = nullptr;

		cout << setfill(' ');
		cout << "Willkommen bei Minesweeper!" << endl << endl
			<< "W�hlen Sie einen Schwierigkeitsgrad / Modi:" << endl << endl
			<< setw(9) << left << "     Stufe " << "|" << setw(9) << right << "Minen" << "|" << setw(9) << right << "Gr��e" << "|" << endl
			<< setw(9) << left << "(1) Leicht " << "|" << setw(9) << right << "10" << "|" << setw(9) << right << "9x9" << "|" << endl
			<< setw(9) << left << "(2) Mittel " << "|" << setw(9) << right << "40" << "|" << setw(9) << right << "16x16" << "|" << endl
			<< setw(9) << left << "(3) Schwer " << "|" << setw(9) << right << "150" << "|" << setw(9) << right << "26x26" << "|" << endl
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
			Anzeige = new Spielfeld(26, 26, 150);
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
				cout << "X-Achse (Maximal 26, Minimal 2)" << endl
					<< "Eingabe: ";
				cin >> x;
				if (x >= 2 && x <= 26) {
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
				cout << "Y-Achse (Maximal 26, Minimal 2)" << endl
					<< "Eingabe: ";
				cin >> y;
				if (y >= 2 && y <= 26) {
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
				cout << "Minen (Maximal die H�lfte der entstehenden Felder, Minimal 1)" << endl
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

		int test = 0;
		char Zeile = 0;
		char Spalte = 0;
		int unaufgedeckteFelder = 0;
		std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

		while (Anzeige->getGameOver() == false && Anzeige->getWin() == false) {

			cout << endl << "|Geben sie die Koordinaten von einem Feld an|"
				<< endl << "Zeile: ";
			cin >> Zeile;

			cout << endl << "Spalte: ";
			cin >> Spalte;
			cout << endl;

			Anzeige->Eingabe(Anzeige->EingabeUmwandeln(Zeile), Anzeige->EingabeUmwandeln(Spalte), Anzeige->getAnzeige(), Anzeige->getMinen());

			Anzeige->Ausgabe(Anzeige->getLaengeX(), Anzeige->getLaengeY(), Anzeige->getAnzeige());

			for (int i = 0; i < Anzeige->getLaengeX(); ++i) {
				for (int j = 0; j < Anzeige->getLaengeY(); ++j) {
					if (Anzeige->getAnzeige()[i][j] == "#") {
						unaufgedeckteFelder++;
					}
				}
				cout << endl;
			}

			if (unaufgedeckteFelder == Anzeige->getMinenAnz()) {
				Anzeige->setWin(true);
			}
			unaufgedeckteFelder = 0;
		}

		std::chrono::high_resolution_clock::time_point ende = std::chrono::high_resolution_clock::now();
		std::chrono::high_resolution_clock::duration diff = ende - start;
		int ms = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
		int s = std::chrono::duration_cast<std::chrono::seconds>(diff).count();
		int m = std::chrono::duration_cast<std::chrono::minutes>(diff).count();

		char erneut;
		bool falsch  = true;

		if (Anzeige->getWin() == true) {
			while (falsch == true) {
				system("cls");
				cout << endl << "|Gl�ckwunsch du hast es geschafft|"
					<< endl << endl << "Deine ben�tigte Zeit (Minuten/Sekunden/Millisekunden): " << m << "." << s << "." << ms
					<< endl << endl << "M�chtest du erneut spielen? (y/n): ";
				cin >> erneut;
				if (erneut == 'y') {
					nochmal = true;
					falsch = false;
				}
				else if (erneut == 'n') {
					nochmal = false;
					falsch = false;
				}
				else if (erneut != 'y' && erneut != 'n') {
					system("cls");
					cout << "Falsche Eingabe!" << endl
						<< "Versuche es erneut" << endl;
					system("PAUSE");
					falsch = true;
				}
			}
		}
		else if (Anzeige->getGameOver() == true) {
			while (falsch == true) {
				system("cls");
				cout << endl << "|Du hast eine Bombe erwischt|"
					<< endl << endl << "M�chtest du erneut spielen? (y/n): ";
				cin >> erneut;
				if (erneut == 'y') {
					nochmal = true;
					falsch = false;
				}
				else if (erneut == 'n') {
					nochmal = false;
					falsch = false;
				}
				else if (erneut != 'y' && erneut != 'n') {
					system("cls");
					cout << "Falsche Eingabe!" << endl
						<< "Versuche es erneut" << endl;
					system("PAUSE");
					falsch = true;
				}
			}
		}
	}
}
