#include <iostream>
#include <ctime>
#include "Header.h"

using namespace std;

int main()
{
    srand(static_cast<unsigned>(time(0)));

    //-------------------------------------------------------------
    int z1 = 0;
    int z2 = 0;

    cout << "Geben Sie ein Intervall an!" << endl << "von:";
    cin >> z1;
    cout << "bis:";
    cin >> z2;

    cout << ZufallszahlI(z1,z2) << endl;

    //-------------------------------------------------------------
    cout << ZufallszahlF1(100.f,101) << endl;

    //-------------------------------------------------------------
    float z3 = 0.0;
    int z4 = 0;

    cout << "Geben Sie ein Intervall an!" << endl << "von:";
    cin >> z3;
    cout << "bis:";
    cin >> z4;

    cout << ZufallszahlF2(z3,z4) << endl;

    //-------------------------------------------------------------
    cout << ZufallszahlN(-1,1);

    return 0;
}
