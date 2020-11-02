#include <iostream>				// io anstatt s
using namespace std;			//ist damit vor cout kein std:: muss

int main()
{
    std::string ZahlAlsString;
    int ZahlAlsZahl;

    while (true) //oder was auch immmer
    {
        char ziffer;
        cin >> ziffer;
        ZahlAlsString += ziffer;
        stringstream Str;
        if (Str << ZahlAlsString); //ggf exeption
        if (Str >> ZahlAlsZahl); //ggf exeption
    }
}
