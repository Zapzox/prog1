#include <iostream>
#include <iostream>
#include <ctime>
using namespace std;

int arr1[101];
int arr2[101];
float mi = 0;
int mo = 0;
int t = 0;

int ZufallszahlI(int untereGrenze, int obereGrenze)
{
    return (rand() % (obereGrenze - untereGrenze + 1)) + untereGrenze;
}

int main()
{
    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < 101; i++) {
        arr1[i] = ZufallszahlI(1, 10);
        switch (arr1[i]) {
        case 1: arr2[0] += 1;
            break;
        case 2: arr2[1] += 1;
            break;
        case 3: arr2[2] += 1;
            break;
        case 4: arr2[3] += 1;
            break;
        case 5: arr2[4] += 1;
            break;
        case 6: arr2[5] += 1;
            break;
        case 7: arr2[6] += 1;
            break;
        case 8: arr2[7] += 1;
            break;
        case 9: arr2[8] += 1;
            break;
        case 10: arr2[9] += 1;
            break;
        }
    }
    for (int k = 0; k < 10; k++) {
        cout << k + 1 << ": " << arr2[k] << "mal" << endl;
    }

    for (int i = 0; i < 101; i++) {
        mi += arr1[i];
    }
    cout << "Mittelwert:"<< mi / 100 << endl;
   
    int max = 1;
    int e = 1;
    for (int j = 0; j < 10; j++) {
        if (max < arr2[j]) {
            max = arr2[j];
            e = j + 1;
        }
    }
    cout << "Modalwert:" << e << endl;

    return 0;
}
