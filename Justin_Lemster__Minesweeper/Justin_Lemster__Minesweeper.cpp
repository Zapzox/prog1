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
		//Zeiger für das Spielfeld wird erstellt um dieses dann dynamisch zu erstellen
		Spielfeld* Anzeige = nullptr;
		//Menü zur Außwahl des Schwierigkeitsgrades
		cout << setfill(' ');
		cout << "Willkommen bei Minesweeper!" << endl << endl
			<< "Wählen Sie einen Schwierigkeitsgrad / Modi:" << endl << endl
			<< setw(9) << left << "     Stufe " << "|" << setw(9) << right << "Minen" << "|" << setw(9) << right << "Größe" << "|" << endl
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
			//Falls die Parameter falsch eingegeben werden -> wird wiederhohlt
			bool RichtigeEingabe = false;
			// Variablen für die custom Eingabe der einzelen Parameter
			int Minen = 0;
			int x = 0;
			int y = 0;
			// Speichern der halben Minenanzahl
			int Rechnung = 0;
			//X-Achse Eingabe
			while (RichtigeEingabe == false) {
				system("cls");
				cout << "X-Achse (Maximal 26, Minimal 2)" << endl
					<< "Eingabe: ";
				cin >> x;
				// x muss größer 1 sein und kleiner als 27
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
				// y muss größer 1 sein und kleiner als 27
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
				cout << "Minen (Maximal die Hälfte der entstehenden Felder, Minimal 1)" << endl
					<< "Eingabe: ";
				cin >> Minen;
				//Hälfte der Felderanzahl wird gepeichert
				Rechnung = (x * y) / 2;
				// Minen muss größer als 0 sein und höchstens die Hälfte der Felder sein
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

		char Zeile = 0;
		char Spalte = 0;
		int unaufgedeckteFelder = 0;
		//Variable start wird auf die aktielle Zeit gesetzt
		std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
		//Gameloop solange das Spiel nicht gewonne oder verloren laufe weiter
		while (Anzeige->getGameOver() == false && Anzeige->getWin() == false) {
			bool eingabe = false;
			while (eingabe == false) {
				cout << endl << "|Geben sie die Koordinaten von einem Feld an|"
					<< endl << "Zeile: ";
				cin >> Zeile;

				cout << "Spalte: ";
				cin >> Spalte;
				cout << endl;
				//wenn die Eingabe richtig ist gehe aus der while schleife raus
				if (Zeile == 'a' || Spalte == 'a' || Zeile == 'b' || Spalte == 'b' || Zeile == 'c' || Spalte == 'c' || Zeile == 'd' || Spalte == 'd' || 
					Zeile == 'e' || Spalte == 'e' || Zeile == 'f' || Spalte == 'f' || Zeile == 'g' || Spalte == 'g' || Zeile == 'h' || Spalte == 'h' || 
					Zeile == 'i' || Spalte == 'i' || Zeile == 'j' || Spalte == 'j' || Zeile == 'k' || Spalte == 'k' || Zeile == 'l' || Spalte == 'l' || 
					Zeile == 'm' || Spalte == 'm' || Zeile == 'n' || Spalte == 'n' || Zeile == 'o' || Spalte == 'o' || Zeile == 'p' || Spalte == 'p' || 
					Zeile == 'q' || Spalte == 'q' || Zeile == 'r' || Spalte == 'r' || Zeile == 's' || Spalte == 's' || Zeile == 't' || Spalte == 't' || 
					Zeile == 'u' || Spalte == 'u' || Zeile == 'v' || Spalte == 'v' || Zeile == 'w' || Spalte == 'w' || Zeile == 'x' || Spalte == 'x' || 
					Zeile == 'y' || Spalte == 'y' || Zeile == 'z' || Spalte == 'z') {
					eingabe = true;
				}
				system("cls");
				//gibt das Array Anzeige aus
				//getLaenge gibt die größe des Spielfeldes aus (mit 2 Feldern extra für Beschriftung und Grenze)
				Anzeige->Ausgabe(Anzeige->getLaengeX(), Anzeige->getLaengeY(), Anzeige->getAnzeige());
			}
			//Aufruf der Eingabe Funktion mit den umgewandelten Parametern und den Arrays Anzeige und Mine
			//EingabeUmwandeln -> wandelt Buchstaben in Zahlen um 
			Anzeige->Eingabe(Anzeige->EingabeUmwandeln(Zeile), Anzeige->EingabeUmwandeln(Spalte), Anzeige->getAnzeige(), Anzeige->getMinen());
			Anzeige->Ausgabe(Anzeige->getLaengeX(), Anzeige->getLaengeY(), Anzeige->getAnzeige());
			//läuft das genze Array Anzeige durch und zählt für jedes # unaufgedeckteFelder hoch
			for (int i = 0; i < Anzeige->getLaengeX(); ++i) {
				for (int j = 0; j < Anzeige->getLaengeY(); ++j) {
					if (Anzeige->getAnzeige()[i][j] == "#") {
						unaufgedeckteFelder++;
					}
				}
			}
			//wenn genau so viele unaufgedeckte Felder vorhanden sind wie Minen, dann hat man gewonnen
			if (unaufgedeckteFelder == Anzeige->getMinenAnz()) {
				Anzeige->setWin(true);
			}
			unaufgedeckteFelder = 0;
		}
		//Variable ende wird auf die aktielle Zeit gesetzt
		std::chrono::high_resolution_clock::time_point ende = std::chrono::high_resolution_clock::now();
		std::chrono::high_resolution_clock::duration diff = ende - start;
		//speichern der Zeit
		int ms = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
		int s = std::chrono::duration_cast<std::chrono::seconds>(diff).count();
		int m = std::chrono::duration_cast<std::chrono::minutes>(diff).count();

		char erneut;
		//für falsche Eingaben
		bool falsch  = true;
		//Wenn gewonnen, dann gebe Die benötigte Zeit aus und frage nach einem erneuten Versuch
		if (Anzeige->getWin() == true) {
			while (falsch == true) {
				system("cls");
				cout << endl << "|Glückwunsch du hast es geschafft|"
					<< endl << endl << "Deine benötigte Zeit (Minuten/Sekunden/Millisekunden): " << m << "." << s << "." << ms
					<< endl << endl << "Möchtest du erneut spielen? (y/n): ";
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
					<< endl << endl << "Möchtest du erneut spielen? (y/n): ";
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
