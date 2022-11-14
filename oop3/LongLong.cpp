#pragma once
#include "LongLong.h"
#include <iostream>
#include <sstream>

using namespace std;

LongLong::LongLong()
{
	hHigh = 0;
	mHigh = 0;
	mLow = 0;
	lLow = 0;
	unit();
}

LongLong::LongLong(long _hHigh, unsigned long _mHigh, unsigned long _mLow, unsigned long _lLow) {
	hHigh = _hHigh;
	mHigh = _mHigh;
	mLow = _mLow;
	lLow = _lLow;
	unit();
}

void LongLong::unit() {
	High = MAKELONG(hHigh, mHigh);
	Low = MAKELONG(mLow, lLow);
	longlong = MAKELONG(High, Low);
}

void LongLong::separate()
{
	High = HIWORD(longlong);
	Low = LOWORD(longlong);

	hHigh = HIWORD(High);
	mHigh = LOWORD(High);
	mLow = HIWORD(Low);
	lLow = LOWORD(Low);
}

string LongLong::toString() {
	stringstream out;
	out << longlong;
	return out.str();
}

unsigned long LongLong::getLow()
{
	return lLow;
}

LongLong LongLong::operator+(LongLong obj)
{
	longlong += obj.longlong;
	separate();
	return *this;
}

LongLong LongLong::operator+(int _val)
{
	LongLong obj(0, 0, 0, 0);
	obj.longlong = _val;
	obj.separate();
	longlong += obj.longlong;
	separate();
	return *this;
}

LongLong LongLong::operator-(LongLong obj)
{
	longlong -= obj.longlong;
	separate();
	return *this;
}

LongLong LongLong::operator-(int _val)
{
	LongLong obj(0, 0, 0, 0);
	obj.longlong = _val;
	obj.separate();
	longlong -= obj.longlong;
	separate();
	return *this;
}

LongLong LongLong::operator*(LongLong obj)
{
	longlong *= obj.longlong;
	separate();
	return *this;
}

LongLong LongLong::operator*(int _val)
{
	LongLong obj(0, 0, 0, 0);
	obj.longlong = _val;
	obj.separate();
	longlong *= obj.longlong;
	separate();
	return *this;
}

LongLong LongLong::operator/(LongLong obj)
{
	if (obj.longlong != 0) {
		std::cout << "ll = " << longlong << endl;
		std::cout << "obj.ll = " << obj.longlong << endl;
		longlong = longlong/obj.longlong;
		std::cout << "ll = " << longlong << endl;
		separate();
	}
	return *this;
}

LongLong LongLong::operator/(int _val)
{
	LongLong obj(0, 0, 0, 0);
	obj.longlong = _val;
	obj.separate();
	if (obj.longlong != 0) {
		longlong /= obj.longlong;
		separate();
	}
	return *this;
}

LongLong LongLong::operator%(LongLong obj)
{
	LongLong ostatok(0, 0, 0, 0);
	if (obj.longlong != 0) {
		ostatok.longlong = longlong % obj.longlong;
		ostatok.separate();
	}
	return ostatok;
}

int LongLong::operator%(int _val)
{
	LongLong ostatok(0, 0, 0, 0);
	LongLong obj(0, 0, 0, 0);
	obj.longlong = _val;
	obj.separate();
	if (obj.longlong != 0) {
		ostatok.longlong = longlong % obj.longlong;
		ostatok.separate();
	}
	return ostatok.lLow;
}

LongLong LongLong::operator=(LongLong obj)
{
	longlong = obj.longlong;
	separate();
	return *this;
}

bool LongLong::operator>(LongLong compared)
{
	if (High != compared.High)
		return High > compared.High;
	else
		return Low > compared.Low;
}

bool LongLong::operator<(LongLong compared)
{
	if (High != compared.High)
		return High < compared.High;
	else
		return Low < compared.Low;
}

bool LongLong::operator==(LongLong compared)
{
	return (High == compared.High && Low == compared.Low);
}

bool LongLong::operator!=(LongLong compared)
{
	return !(High == compared.High && Low == compared.Low);
}

std::ostream& operator<<(std::ostream& out, const LongLong& lLong)
{
	out << lLong.longlong;
	return out;
}

std::istream& operator>>(std::istream& in, LongLong& lLong)
{
	in >> lLong.longlong;
	lLong.separate();
	return in;
}
