#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
	char ai = 35;
	int i = 35;
	cout << setfill(' ');
	cout  << left << "|" << setw(9) << left << "Dec"  << "|" << setw(9) << right << "Hex" << "|" << setw(9) << right << "Oct" << "|" << setw(9) << right << "ASCII" << "|" << endl;
	
	for (int i = 35; i < 39; i++) {
		cout << left << "|" << setw(9) << left << dec << i << "|" << setw(9) << right << hex << i << "|" << setw(9) << right << oct << i << "|" << setw(9) << dec << right << ai << "|" << endl;
		ai++;
	}

	return 0;
}

