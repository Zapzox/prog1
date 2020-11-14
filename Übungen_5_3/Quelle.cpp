#include <iostream>
#include <ctime>

int ZufallszahlI(int untereGrenze, int obereGrenze)
{
    return (rand() % (obereGrenze - untereGrenze + 1)) + untereGrenze;
}