#include <iostream>
#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <cstdlib>
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
bool countdown = false;
int timer = 10;
int ctimer = 10;

void leeresFeld() {
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
}

void Ausgabe() {
	system("cls");
    for (int i = 0; i <= 26; i++) {
        for (int j = 0; j <= 51; j++) {
            cout << Feld[i][j];
        }
        cout << endl;
    }
}

bool GameStart() {
	char a;
	cout << "Willkommen bei Bomberman!" << endl << endl << "Wollen Sie das Spiel starten?" << endl << "Geben Sie y fuer 'JA' und n fuer 'NEIN' ein." << endl;
	cin >> a;
	if (a=='y') {
		return true;
	}
	else if (a=='n') {
		return false;
	}
}

void GameOver() {
	system("cls");
	cout << "GAME OVER";
	tot = true;
	this_thread::sleep_for(chrono::seconds(5));
}

void Win() {
	system("cls");
	cout << "YOU WON";
	gew = true;
	this_thread::sleep_for(chrono::seconds(5));
}

bool check(bool t1, bool t2) {
	if (t1 != 26 && t1 != 0 && t2 != 51 && t2 != 0) {
		return true;
	}
	else {
		return false;
	}
}

bool crash(int e1, int e2, int p1, int p2) {
	if (e1 == p1 && e2 == p2) {
		return true;
	}
	else {
		return false;
	}
}

void pCheck(int p1, int p2, bool coll, bool bhit) {
	if (coll == false && bhit == false) {
		Feld[p1][p2] = 'P';
	}
	else {
		GameOver();
	}
}

void eCheck(int e1, int e2, bool coll, bool bhit) {
	if (coll == false && bhit == false) {
		Feld[e1][e2] = 'E';
	}
	else {
		if (bhit == false) {
			GameOver();
		}
		else {
			Win();
		}
	}
}

void bCheck(int b1, int b2) {
	if (Feld[b1][b2]=='P') {
		GameOver();
	}
	else if(Feld[b1][b2] == 'E'){
		Win();
	}
	else if (Feld[b1][b2] == ' ') {
		Feld[b1][b2] = 'O';
	}
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void clear(int e1, int e2, int p1, int p2) {
	leeresFeld();
	Feld[e1][e2] = 'E';
	Feld[p1][p2] = 'P';
	Ausgabe();
}

void Explode(int b1,int b2) {
	int ex1 = b1;
	int ex2 = b2;
	//this_thread::sleep_for(chrono::seconds(3));
	if (check(b1, b2) == true) {
		bCheck(b1,b2);
		b1 -= 1;
	}
	if (check(b1, b2) == true) {
		bCheck(b1, b2);
		b1 -= 1;
	}
	if (check(b1, b2) == true) {
		bCheck(b1, b2);
		b1 = ex1;
		b1 += 1;
	}
	if (check(b1, b2) == true) {
		bCheck(b1, b2);
		b1 += 1;
	}
	if (check(b1, b2) == true) {
		bCheck(b1, b2);
		b1 = ex1;
		b2 -= 1;
	}
	if (check(b1, b2) == true) {
		bCheck(b1, b2);
		b2 -= 1;
	}
	if (check(b1, b2) == true) {
		bCheck(b1, b2);
		b2 = ex2;
		b2 += 1;
	}
	if (check(b1, b2) == true) {
		bCheck(b1, b2);
		b2 += 1;
	}
	if (check(b1, b2) == true) {
		bCheck(b1, b2);
	}
	planted = false;
	Ausgabe();

}

bool BombHit(int bh1, int bh2, int r) {
	r += 1;
	int bhc1 = bh1;
	int bhc2 = bh2;

	switch (r) {
	case 1: 
		bhc1++;
		break;
	case 2:
		bhc1--;
		break;
	case 3:
		bhc2++;
		break;
	case 4:
		bhc2--;
		break;
	case 5:
		return false;
	}


	if (Feld[bhc1][bhc2] == 'O') {
		return true;
	}
	else {
		BombHit(bh1, bh2, r);
	}
}

int main()
{
	if (GameStart() == true) {
		ShowConsoleCursor(false);

		int p1 = 0;
		int p2 = 0;
		int e1 = 0;
		int e2 = 0;
		int b1 = 0;
		int b2 = 0;


		srand(static_cast<unsigned>(time(0)));


		leeresFeld();
		// leeres Spielfeld

		while (unt == false) {
			if (e1 != p1 || e2 != p2) {
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

		Ausgabe();

		while (tot == false && gew == false) {
			int press = _kbhit();
			if (press == true) {
				if (crash(e1, e2, p1, p2) == false) {
					//cout << e1 << "=" << p1 << " | " << e2 << "=" << p2;
					char input = _getch();
					if (p1 != 26 && p1 != 0 && p2 != 51 && p2 != 0) {
						if (input == 'w') {
							if (p1 != 1) {
								Feld[p1][p2] = ' ';
								p1 -= 1;
								pCheck(p1, p2, crash(e1, e2, p1, p2), BombHit(p1, p2, 1));
							}
							if (planted == true) {
								Feld[b1][b2] = 'X';
							}
						}
						else if (input == 'a') {
							if (p2 != 1) {
								Feld[p1][p2] = ' ';
								p2 -= 1;
								pCheck(p1, p2, crash(e1, e2, p1, p2), BombHit(p1, p2, 1));
							}
							if (planted == true) {
								Feld[b1][b2] = 'X';
							}
						}
						else if (input == 's') {
							if (p1 != 25) {
								Feld[p1][p2] = ' ';
								p1 += 1;
								pCheck(p1, p2, crash(e1, e2, p1, p2), BombHit(p1, p2, 1));
							}
							if (planted == true) {
								Feld[b1][b2] = 'X';
							}
						}
						else if (input == 'd') {
							if (p2 != 50) {
								Feld[p1][p2] = ' ';
								p2 += 1;
								pCheck(p1, p2, crash(e1, e2, p1, p2), BombHit(p1, p2, 1));
							}
							if (planted == true) {
								Feld[b1][b2] = 'X';
							}
						}
						else if (input == ' ') {
							if (planted == false) {
								planted = true;
								b1 = p1;
								b2 = p2;
							}
						}
					}

					//Player movement und Bomb planted
					if (planted == true) {
						timer -= 1;
						if (timer == 0) {
							Explode(b1, b2);
							timer = 10;
							countdown = true;
						}
					}

					if (countdown == true) {
						ctimer -= 1;
						if (ctimer == 0) {
							countdown = false;
							clear(e1, e2, p1, p2);
							ctimer = 10;
						}
					}

					if (crash(e1, e2, p1, p2) == false) {
						//this_thread::sleep_for(chrono::seconds(1));
						if (e1 != 26 && e1 != 0 && e2 != 51 && e2 != 0) {

							int r = ZufallszahlI(1, 4);

							switch (r) {
							case 1:
								if (e1 != 1) {
									Feld[e1][e2] = ' ';
									e1 -= 1;
									eCheck(e1, e2, crash(e1, e2, p1, p2), BombHit(e1, e2, 1));
									break;
								}
							case 2:
								if (e2 != 50) {
									Feld[e1][e2] = ' ';
									e2 += 1;
									eCheck(e1, e2, crash(e1, e2, p1, p2), BombHit(e1, e2, 1));
									break;
								}
							case 3:
								if (e1 != 25) {
									Feld[e1][e2] = ' ';
									e1 += 1;
									eCheck(e1, e2, crash(e1, e2, p1, p2), BombHit(e1, e2, 1));
									break;
								}
							case 4:
								if (e2 != 1) {
									Feld[e1][e2] = ' ';
									e2 -= 1;
									eCheck(e1, e2, crash(e1, e2, p1, p2), BombHit(e1, e2, 1));
									break;
								}
							}
						}
					}
					else {
						GameOver();
					}
					// Enemie movement
					if (tot == false && gew == false) {
						Ausgabe();
					}
				}
				else {
					GameOver();
				}
			}
		}
	}
}

