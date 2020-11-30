#include <iostream>
#include <cmath>
#include "Rechner.h"
using namespace std;
using namespace Statistik;

int main() {
	long Eingabe[] = { 1,3,2,3,5,3,4 };

    /*long dataArray[] = { 1,3,2,3,5,3};
    int sizeArray = (sizeof(dataArray) / sizeof(long));

    for (int k = 0; k < sizeArray; k++) {
        cout << dataArray[k] << ",";
    }
    cout << endl;

    for (int j = 0; j < sizeArray; j++)
    {
        int min = dataArray[j];
        int place = j;
        int temp = 0;
        for (int i = j; i < sizeArray; i++)
        {
            if (min > dataArray[i])
            {
                min = dataArray[i];
                place = i;
            }
        }
        temp = dataArray[j];
        dataArray[j] = min;
        dataArray[place] = temp;
    }

    for (int k = 0; k < sizeArray; k++) {
        cout << dataArray[k] << ",";
    }*/

	int länge = (sizeof(Eingabe) / sizeof(long));
	Rechner einRechner;
	einRechner.SetterArr(Eingabe, länge);
}
