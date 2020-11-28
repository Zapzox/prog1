#include <iostream>
using namespace std;

int main()
{

    int u = 0;
    cout << "Bitte geben sie die Untergrenze an" << endl;
    cout << "Eingabe:";
    cin >> u;
    cout << endl;

    int o = 0;
    cout << "Bitte geben sie die Obergrenze an" << endl;
    cout << "Eingabe:";
    cin >> o;
    cout << endl;

    if (u < 2) std::cout << "Zahl muss > 1 sein!" << std::endl;

    int i = 0;
    int zahlen[10000];
    
    while (u <= o) {
        bool is_prime = true;
        for (int i = 2; i < u; i++) {
            if ((u % i) == 0) is_prime = false;
        }

        i++;

        if (is_prime == true) {
            zahlen[i] = u;
        }
        u++;
    }
    
    for (int a = i; a >= 0; a--) {
        if (zahlen[a] > 0) {
            cout << " " << zahlen[a];
        }
    }
}

