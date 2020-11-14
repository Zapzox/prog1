#include <iostream>
#include <ctime>
using namespace std;

int ZufallszahlI(int untereGrenze, int obereGrenze)
{
    return (rand() % (obereGrenze - untereGrenze + 1)) + untereGrenze;
}
