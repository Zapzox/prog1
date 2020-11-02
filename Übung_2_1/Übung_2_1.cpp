
#include <iostream>
using namespace std;

int main()
{
    std::locale::global(std::locale("German_germany.UTF-8"));

    cout << "Datentyp bool benötigt " << sizeof(bool) << " Byte " "und kann Werte im Bereich [0,1] abspeichern" << endl;
    cout << "Datentyp char benötigt " << sizeof(char) << " Byte " "und kann Werte im Bereich [" << CHAR_MIN << " , " << CHAR_MAX << "] abspeichern" << endl;
    cout << "Datentyp unsigned char benötigt " << sizeof(unsigned char) << " Byte " "und kann Werte im Bereich [0" << " , " << UCHAR_MAX << "] abspeichern" << endl;
    cout << "Datentyp signed char benötigt " << sizeof(signed char) << " Byte "  "und kann Werte im Bereich ["<< SCHAR_MIN << " , " << SCHAR_MAX << "] abspeichern" << endl;
    cout << "Datentyp short benötigt " << sizeof(short) << " Byte " "und kann Werte im Bereich [" << SHRT_MIN << " , " << SHRT_MAX << "] abspeichern" << endl;
    cout << "Datentyp unsigned short benötigt " << sizeof(unsigned short) << " Byte " "und kann Werte im Bereich [0" << " , " << USHRT_MAX << "] abspeichern" << endl;
    cout << "Datentyp int benötigt " << sizeof(int) << " Byte " "und kann Werte im Bereich [" << INT_MIN << " , " << INT_MAX << "] abspeichern" << endl;
    cout << "Datentyp unsigned int benötigt " << sizeof(unsigned int) << " Byte " "und kann Werte im Bereich [0" << " , " << UINT_MAX << "] abspeichern" << endl;
    cout << "Datentyp long benötigt " << sizeof(long) << " Byte " "und kann Werte im Bereich [" << LONG_MIN << " , " << LONG_MAX << "] abspeichern" << endl;
    cout << "Datentyp unsigned long benötigt " << sizeof(unsigned long) << " Byte " "und kann Werte im Bereich [0" << " , " << ULONG_MAX << "] abspeichern" << endl;
    cout << "Datentyp long long benötigt " << sizeof(unsigned long long) << " Byte " "und kann Werte im Bereich [" << LLONG_MIN << " , " << LLONG_MAX << "] abspeichern" << endl;
    cout << "Datentyp unsigned long long benötigt " << sizeof(unsigned long long) << " Byte" "und kann Werte im Bereich [0" << " , " << ULLONG_MAX << "] abspeichern" << endl;
    cout << "Datentyp float benötigt " << sizeof(float) << " Byte " "und kann Werte im Bereich [" << FLT_MIN << " , " << FLT_MAX << "] abspeichern" << endl;
    cout << "Datentyp double benötigt " << sizeof(double) << " Byte " "und kann Werte im Bereich [ "<< DBL_MIN << " , " << DBL_MAX << "] abspeichern" << endl;

    return 0;
}
