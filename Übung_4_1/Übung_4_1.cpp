#include <iostream>
using namespace std;

int main()
{
    std::locale::global(std::locale("German_germany.UTF-8"));

    int i = 0;
    cout << "Bitte geben sie die Jahreszahl an, die Geprüft werden soll." << endl;
    cout << "Eingabe:";
    cin >> i;
    cout << endl;


    int c = 0;
    int r = i % 4;

    if (r == 0) {
        r = i % 100;
        if (r == 0) {
            r = i%400;
            if (r == 0) {
                c = 1;
            }
            else if (r > 0) {
                c = 2;
            }
        }else if (r > 0){
            c = 1;
        }
    }
    else {
        c = 2;
    }

    switch (c) {
    case 1:
        cout << i << " ist ein Schaltjahr!" << endl;
        break;
    case 2:
        cout << i << " ist kein Schaltjahr!" << endl;
        break;
    }
 
    return 0;

}
