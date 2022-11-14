#pragma once
#include "LongLong.h"
#include <iostream>

using namespace std;

class Money {
	LongLong rubles;
	unsigned int kopeiki;
	void kopToRub();
public:
	/*
	����������� ������
	@param _rubles - �����
	@param _kopeiki - �������
	*/
	Money(LongLong _rubles, unsigned int _kopeiki);

	/*
	���������� �������� ������
	@param _rubles - �����
	*/
	void setRubles(LongLong _rubles);
	
	/*
	�������� �������� ������
	@return - ����� � ���� LongLong
	*/
	LongLong getRubles();

	/*
	���������� �������� ������
	@param _kopeiki - ������
	*/
	void setKopeiki(unsigned int _kopeiki);

	/*
	�������� �������� ������
	@return - ����� ���� unsigned int
	*/
	unsigned int getKopeiki();

	/*
	�������� ���� Money
	@param _val - ��������� � ���� Money
	@return - ���������� ����� � ���� Money
	*/
	Money operator+(Money obj);

	/*
	�������� ���� Money
	@param obj - ���������� ���� Money
	@return - ���������� �������� � ���� Money
	*/
	Money operator-(Money obj);

	/*
	������� ���� Money
	@param obj - �������� � ���� Money
	@return - ���������� ������� � ���� Money
	*/
	Money operator/(Money obj);

	/*
	������������
	@param obj - ��������� ������ Money
	@return - ����������� �������� ���������� �������� obj
	*/
	Money operator=(Money obj);

	/*
	��������� "������ ������ �������?"
	@param compared - ������������ Money
	@return - ���������� ��������� ��������� > (true or false)
	*/
	bool operator>(Money obj);

	/*
	��������� "������ ������ �������?"
	@param compared - ������������ Money
	@return - ���������� ��������� ��������� < (true or false)
	*/
	bool operator<(Money obj);

	/*
	��������� "������ ����� �������?"
	@param compared - ������������ Money
	@return - ���������� ��������� ��������� == (true or false)
	*/
	bool operator==(Money obj);

	/*
	����� Money
	@param out - ����� ������
	@param lLong - ��������� Money
	@return - ���������� ����� ������
	*/
	friend std::ostream& operator<<(std::ostream& out, const Money& Money);

	/*
	����� Money
	@param in - ����� �����
	@param lLong - Money ��� �������� �������� �������
	@return - ���������� ����� �����
	*/
	friend std::istream& operator>>(std::istream& in, Money& Money);
};