#include <iostream>
using namespace std;

int main()
{
    int d = 0;
    int a = 8;
    cout << "Bitte geben sie eine Dezimalzahl zwischen [0,128] ein.";
    cin >> d;

    int i = 0;
    int aus[8];

    while (d > 0) {
        aus[i] = d % 2;
        d /= 2;
        i++;
    }

    i--;

    for (int a = i; a >= 0; a--) {
       cout << " " << aus[a];
    }

    return 0;
}


