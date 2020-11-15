#include <iostream>
#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include <conio.h>
#include <ctype.h>
#include "Header.h"

using namespace std;

char Feld[27][52];
char Player = 'P';
char Gegner = 'E';
char Bombe = 'X';
bool planted = false;
bool tot = false;
bool gew = false;
bool unt = false;
int timer = 100;

void Ausgabe() {
	system("cls");
    for (int i = 0; i <= 26; i++) {
        for (int j = 0; j <= 51; j++) {
            cout << Feld[i][j];
        }
        cout << endl;
    }
	timer -= 1;
}

void GameOver() {
	system("cls");
	cout << "GAME OVER";
	tot = true;
	this_thread::sleep_for(chrono::seconds(1));
}

void Win() {
	system("cls");
	cout << "YOU WON";
	gew = true;
	this_thread::sleep_for(chrono::seconds(1));
}

bool check(bool t1, bool t2) {
	if (t1 != 26 && t1 != 0 && t2 != 51 && t2 != 0) {
		return true;
	}
	else {
		return false;
	}
}

void Explode(int b1,int b2) {
	int ex1 = b1;
	int ex2 = b2;
	//this_thread::sleep_for(chrono::seconds(3));
	if (check(b1, b2) == true) {
		Feld[b1][b2] = 'O';
		b1 -= 1;
	}
	if (check(b1, b2) == true) {
		Feld[b1][b2] = 'O';
		b1 -= 1;
	}
	if (check(b1, b2) == true) {
		Feld[b1][b2] = 'O';
		b1 = ex1;
		b1 += 1;
	}
	if (check(b1, b2) == true) {
		Feld[b1][b2] = 'O';
		b1 += 1;
	}
	if (check(b1, b2) == true) {
		Feld[b1][b2] = 'O';
		b1 = ex1;
		b2 -= 1;
	}
	if (check(b1, b2) == true) {
		Feld[b1][b2] = 'O';
		b2 -= 1;
	}
	if (check(b1, b2) == true) {
		Feld[b1][b2] = 'O';
		b2 = ex2;
		b2 += 1;
	}
	if (check(b1, b2) == true) {
		Feld[b1][b2] = 'O';
		b2 += 1;
	}
	if (check(b1, b2) == true) {
		Feld[b1][b2] = 'O';
	}
	Ausgabe();
}

int main()
{

	int p1 = 0;
	int p2 = 0;
	int e1 = 0;
	int e2 = 0;
	int b1 = 0;
	int b2 = 0;


    srand(static_cast<unsigned>(time(0)));


    for (int i = 0; i <= 26; i++) {
        for (int j = 0; j <= 51; j++) {
            Feld[i][j] = ' ';
        }
    }

    for (int i = 0; i <= 26; i++) {
        Feld[i][0] = '|';
        Feld[i][51] = '|';
    }

    for (int j = 0; j <= 51; j++) {
        Feld[0][j] = '-';
        Feld[26][j] = '-';
    }
    // leeres Spielfeld

	while (unt == false) {
		if(e1!=p1 || e2!=p2){
			Feld[p1][p2] = 'P';
			Feld[e1][e2] = 'E';
			unt = true;
			break;
		}
		else {
			p1 = ZufallszahlI(1, 25);
			p2 = ZufallszahlI(1, 50);
			e1 = ZufallszahlI(1, 25);
			e2 = ZufallszahlI(1, 50);
			unt = false;
		}
	}
    // Spieler und Enemie auf Random Pos. aber nicht die selben

	

	while (tot == false && gew == false) {
		if (e1 != p1 || e2 != p2) {

			int press = _kbhit();
			if (press == true) {
				char input = _getch();
				if (p1 != 26 && p1 != 0 && p2 != 51 && p2 != 0) {
					if (input == 'w') {
						if (p1 != 1) {
							Feld[p1][p2] = ' ';
							p1 -= 1;
							Feld[p1][p2] = 'P';
						}
						if (planted == true) {
							Feld[b1][b2] = 'X';
						}
					}
					else if (input == 'a') {
						if (p2 != 1) {
							Feld[p1][p2] = ' ';
							p2 -= 1;
							Feld[p1][p2] = 'P';
						}
						if (planted == true) {
							Feld[b1][b2] = 'X';
						}
					}
					else if (input == 's') {
						if (p1 != 25) {
							Feld[p1][p2] = ' ';
							p1 += 1;
							Feld[p1][p2] = 'P';
						}
						if (planted == true) {
							Feld[b1][b2] = 'X';
						}
					}
					else if (input == 'd') {
						if (p2 != 50) {
							Feld[p1][p2] = ' ';
							p2 += 1;
							Feld[p1][p2] = 'P';
						}
						if (planted == true) {
							Feld[b1][b2] = 'X';
						}
					}
					else if (input == ' ') {
						
						planted = true;
						b1 = p1;
						b2 = p2;
						if (timer == 0) {
							Explode(b1, b2);
						}
					}
				}
			}
			//Player movement und Bomb planted

			

				//this_thread::sleep_for(chrono::seconds(1));
			if (e1 != 26 && e1 != 0 && e2 != 51 && e2 != 0) {

				int r = ZufallszahlI(1, 4);

				switch (r) {
				case 1:
					if (e1 != 1) {
						Feld[e1][e2] = ' ';
						e1 -= 1;
						Feld[e1][e2] = 'E';
						break;
					}
				case 2:
					if (e2 != 50) {
						Feld[e1][e2] = ' ';
						e2 += 1;
						Feld[e1][e2] = 'E';
						break;
					}
				case 3:
					if (e1 != 25) {
						Feld[e1][e2] = ' ';
						e1 += 1;
						Feld[e1][e2] = 'E';
						break;
					}
				case 4:
					if (e2 != 1) {
						Feld[e1][e2] = ' ';
						e2 -= 1;
						Feld[e1][e2] = 'E';
						break;
					}
				}
			}
			// Enemie movement

			Ausgabe();
		}
		else {
			GameOver();
		}
	}
}

