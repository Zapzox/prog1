#include <iostream>
#include<stdio.h>
#include<math.h>
#include "Spielfeld.h"

Spielfeld::Spielfeld(int x, int y, int m) {
	int m_laengeX = x;
	int m_laengeY = y;
	int m_MinenAnz = m;
}

void Spielfeld::Ausgabenfeld(int x, int y) {
	//Vergrößerung für das Overlay
	x += 2;
	y += 2;

	char alph = 'A';
	char** Feld = new char*[x];

	for (int i = 0; i < x; i++) {
		Feld[i] = new char[y];
	}
	//linke obere Ecke -> leer
	Feld[0][0] = ' ';
	//erste Zeile -> Alphabet / zweite Zeile -> '-' 
	for (int i = 1; i < x; i++) {
		Feld[0][i] = alph;
		alph++;
		Feld[1][i] = '-';
	}
	//erste Spalte -> Zahlen / zweite Spalte -> '|'
	for (int i = 1; i < y; i++) {
		Feld[i][0] = i;
		Feld[i][1] = '|';
	}

	for (int i = 2; i < y; i++) {
		for (int j = 2; j < x; j++) {
		Feld[i][j] = '#';
	}

}

void Spielfeld::Minenfeld(int x, int y, int m) {


}

void Spielfeld::Ausgabe() {
	for (int i = 2; i < y; i++) {
		for (int j = 2; j < x; j++) {
			Feld[i][j] = '#';
		}
}
