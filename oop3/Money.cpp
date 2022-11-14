#include "Money.h"
#include <iostream>

using namespace std;

Money::Money(LongLong _rubles, unsigned int _kopeiki) {
	rubles = _rubles;
	kopeiki = _kopeiki;
}
void Money::kopToRub() {
	rubles = rubles + kopeiki/100;
	kopeiki %= 100;
}

void Money::setRubles(LongLong _rubles) {
	rubles = _rubles;
}
LongLong Money::getRubles() {
	return rubles;
}
void Money::setKopeiki(unsigned int _kopeiki) {
	kopeiki = _kopeiki;
}
unsigned int Money::getKopeiki() {
	return kopeiki;
}

Money Money::operator+(Money obj) {
	rubles = rubles + (obj.rubles);
	kopeiki += obj.kopeiki;
	kopToRub();
	return *this;
}

Money Money::operator-(Money obj) {
	rubles = rubles - obj.rubles;
	if (obj.kopeiki > kopeiki) {
		rubles = rubles - 1;
		kopeiki = 100 - (obj.kopeiki - kopeiki);
	}
	else
		kopeiki -= obj.kopeiki;
	return *this;
}

/*Money Money::operator*(Money obj)
{
	unsigned char tempKop1, tempKop2;

	rubles = (rubles * 100) + kopeiki;
	tempKop1 = kopeiki;
	obj.rubles = (obj.rubles * 100) + obj.kopeiki;
	tempKop2 = obj.kopeiki;
	
	rubles = rubles * obj.rubles;
	kopeiki = rubles % 100;
	rubles = rubles / 100;
	obj.rubles = obj.rubles - kopeiki;
	return *this;
}
*/

Money Money::operator/(Money obj) {
	cout << rubles << endl;
	cout << rubles * 100 << endl;
	rubles = (rubles * 100) + kopeiki;
	cout << rubles << endl;
	obj.rubles = (obj.rubles * 100) + obj.kopeiki;
	cout << obj.rubles << endl;

	LongLong ostatok = rubles % obj.rubles;
	rubles = rubles / obj.rubles;
	cout << rubles << endl;
	LongLong null(0, 0, 0, 0);
	int count = 1;
	while (ostatok != null && count > -1) {
		ostatok = ostatok * 10;
		if (ostatok/obj.rubles != null) {
			ostatok = ostatok % obj.rubles;
			kopeiki = kopeiki + (ostatok / obj.rubles).getLow() * 10 * count;
			count--;
		}
	}
	kopToRub();
	return *this;
}

Money Money::operator=(Money obj)
{
	rubles = obj.rubles;
	kopeiki = obj.kopeiki;
	return *this;
}

bool Money::operator>(Money obj) {
	if (rubles != obj.rubles)
		return rubles > obj.rubles;
	else
		return kopeiki > obj.kopeiki;
}
bool Money::operator<(Money obj) {
	if (rubles != obj.rubles)
		return rubles < obj.rubles;
	else
		return kopeiki < obj.kopeiki;
}
bool Money::operator==(Money obj) {
	return (rubles == obj.rubles && kopeiki == obj.kopeiki);
}


ostream& operator<<(ostream& out, const Money& money) {
	out << money.rubles << "," << money.kopeiki;
	return out;
}

istream& operator>>(istream& in, Money& money) {
	in >> money.rubles;
	in >> money.kopeiki;
	return in;
}