#include <iostream>
#include <ctime>
#include "Header.h"

using namespace std;

int main()
{
    srand(static_cast<unsigned>(time(0)));
    cout << ZufallszahlI(-4,-3) << endl;
    cout << ZufallszahlF1(100.f,101) << endl;
    cout << ZufallszahlF2(-1.5f,3) << endl;
    cout << ZufallszahlN(-1,1);
}
