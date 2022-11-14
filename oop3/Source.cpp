#include "Money.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
	LongLong rub1(17, 5, 5, 1234);
	LongLong rub2(0, 0, 1, 1);
	cout << rub1 << endl;
	cout << rub2 << endl;
	unsigned char kop1 = 99;
	unsigned char kop2 = 19;
	Money bank(rub1, kop1);
	cout << bank << endl;
	Money client(rub2, kop2);
	cout << client << endl;
	bank = bank + client;
	cout << bank << endl;
	bank = bank - client;
	cout << bank << endl;
	cout << client << endl;
	cout << endl;
	bank = bank / client;
	cout << bank << endl;
}