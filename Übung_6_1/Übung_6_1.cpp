#include <iostream>

using namespace std;

int main()
{
    int eineVariable = 100;
    int* AdresseDerVariable = nullptr;
    AdresseDerVariable = &eineVariable;

    cout << "eineVariable:" << eineVariable << endl << "AdresseDerVariable:" << *AdresseDerVariable;
    cout << endl;
    cout << "eineVariable:" << &eineVariable << endl << "AdresseDerVariable:" << &AdresseDerVariable;
    cout << endl;

    int &ReferenzEinerVariable = eineVariable;
    ReferenzEinerVariable += 20;

    cout << "ReferenzEinerVariable:" << ReferenzEinerVariable << endl << "eineVariable:" << eineVariable;
    cout << endl;
    cout << "ReferenzEinerVariable:" << &ReferenzEinerVariable << endl << "eineVariable:" << &eineVariable;
    cout << endl;

    return 0;
}
