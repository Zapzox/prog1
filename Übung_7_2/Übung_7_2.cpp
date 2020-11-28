#include <iostream>
#include <cmath>
#include <thread>        
#include <chrono> 
#include "Roboter.h"
using namespace std;

int main()
{
	srand(static_cast<unsigned>(time(0)));

	char Feld[22];
	bool leer = false;
	int Runden = 0;
	int Reg1 = 0;
	int Reg2 = 0;
	bool RMove = true;
	bool CMove = true;

	cout << "Legen sie die Anzahl der Runden fest: ";
	cin >> Runden;

	leeresFeld(Feld);

	Roboter R2D2(40, ZufallszahlI(1,20), "R2D2", Feld);
	Roboter C3PO(40, ZufallszahlI(1, 20), "C3PO", Feld);
	
	Ausgabe(Feld);

	while (Runden != 0) {

		if (RMove == true) {
			R2D2.move(R2D2, Feld);
		}
		if (CMove == true) {
			C3PO.move(C3PO, Feld);
		}
		
		if (CMove == true && RMove == true) {
			int rech1 = C3PO.Position - R2D2.Position;
			int rech2 = C3PO.Position - R2D2.Position;

			if (rech1 >= 2|| rech2 >= 2) {
				cout << "C3PO: " << C3PO.reden(C3PO) <<endl;
				cout << "C3PO Energie: " << C3PO.Energiewert << endl;
				cout << "R2D2: " << R2D2.reden(R2D2) << endl;
				cout << "R2D2 Energie: " << R2D2.Energiewert << endl;
			}
		}

		if (C3PO.Energiewert == 0) {
			CMove = false;
			Reg1++;
		}
		if (Reg1 == 6) {
			Reg1 = 0;
			CMove = true;
			C3PO.setEn(40);
		}

		if(R2D2.Energiewert == 0){
			RMove = false;
			Reg2++;
		}
		if (Reg2 == 6) {
			Reg2 = 0;
			RMove = true;
			R2D2.setEn(40);
		}

		std::this_thread::sleep_for(std::chrono::seconds(1));
		Runden--;
		Ausgabe(Feld);
	}
	return 0;
}

