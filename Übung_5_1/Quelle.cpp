#include <iostream>
#include <ctime>

int ZufallszahlI(int untereGrenze, int obereGrenze)
{
    return (rand() % (obereGrenze - untereGrenze + 1)) + untereGrenze;
}

int ZufallszahlN(int untereGrenze, int obereGrenze)
{
    int e = (rand() % (obereGrenze - untereGrenze + 1)) + untereGrenze;
    int f = (rand() % (obereGrenze - untereGrenze + 1)) + untereGrenze;
    int g = (rand() % (obereGrenze - untereGrenze + 1)) + untereGrenze;
    return (e + f + g) / 3;
}

float ZufallszahlF1(float untereGrenze, int obereGrenze)
{
    return (rand() % obereGrenze) / untereGrenze;
}

float ZufallszahlF2(float untereGrenze, int obereGrenze)
{
    return ((obereGrenze - untereGrenze) * ((float)rand() / RAND_MAX)) + untereGrenze;
}
