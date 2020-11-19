#define _CRT_SECURE_NO_WARNINGS
#include "time.h"
#include <ctime>
#include <iostream>

using namespace std;


int main()
{
    int twoWeekRythm = 0;
    
    std::tm time_in = { 0, 0, 0, // second, minute, hour
        9, 10, 2016 - 1900 }; // 1-based day, 0-based month, year since 1900

    std::time_t time_temp = std::mktime(&time_in);

    //Note: Return value of localtime is not threadsafe, because it might be
    // (and will be) reused in subsequent calls to std::localtime!
    const std::tm* time_out = std::localtime(&time_temp);

    //Sunday == 0, Monday == 1, and so on ...
    std::cout << "Tag: " << time_out->tm_wday << "\n";

    time_t Zeitstempel;
    tm* nun;
    Zeitstempel = time(0);
    nun = localtime(&Zeitstempel);
    cout << nun->tm_hour << ':' << nun->tm_min << endl;

    return 0;
}

