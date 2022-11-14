#pragma once
#include "Windows.h"
#include <string>

class LongLong {
	long hHigh;
	unsigned long mHigh;
	unsigned long mLow;
	unsigned long lLow;

	DWORD High;
	DWORD Low;
	DWORD longlong;

	void unit();
	void separate();
	std::string toString();

public:
	/*
	����������� �� ���������, ������ ����� LongLong � ������ (0, 0, 0, 0)
	*/
	LongLong();

	/*
	����������� ������
	@param _hHigh - ������ 4 ����� �������� �����
	@param _mHigh - ������ ����� �������� �����
	@param _mLow - ������ ����� �������� �����
	@param _lLow - ��������� ����� �������� �����
	*/
	LongLong(long _hHigh, unsigned long _mHigh, unsigned long _mLow, unsigned long _lLow);


	/*
	�������� ������� ����� (��� �������� � unsigned long)
	@return - ���������� unsigned long (�������� lLow)
	*/
	unsigned long getLow();
	

	/*
	�������� ���� LongLong
	@param _val - ��������� � ���� LongLong
	@return - ���������� ����� � ���� LongLong
	*/
	LongLong operator+(LongLong _val);
	
	/*
	�������� � int
	@param _val - ��������� ���� int
	@return - ���������� ����� � ���� LongLong
	*/
	LongLong operator+(int obj);
	
	/*
	�������� ���� LongLong
	@param obj - ���������� ���� LongLong
	@return - ���������� �������� � ���� LongLong
	*/
	LongLong operator-(LongLong obj);
	
	/*
	�������� � int
	@param _val - ���������� ���� int
	@return - ���������� �������� � ���� LongLong
	*/
	LongLong operator-(int _val);
	
	/*
	������������ ���� LongLong
	@param obj - ��������� � ���� LongLong
	@return - ���������� ������������ � ���� LongLong
	*/
	LongLong operator*(LongLong obj);

	/*
	������������ � int
	@param _val - ���������� � ���� LongLong
	@return - ���������� ������������ � ���� LongLong
	*/
	LongLong operator*(int _val);

	/*
	������� ���� LongLong
	@param obj - �������� � ���� LongLong
	@return - ���������� ������� � ���� LongLong
	*/
	LongLong operator/(LongLong obj);
	
	/*
	������� �� int
	@param obj - �������� ���� int
	@return - ���������� ������� � ���� LongLong
	*/
	LongLong operator/(int _val);
	
	/*
	������� �� ������� ���� LongLong
	@param obj - �������� � ���� LongLong
	@return - ���������� ������� �� ������� �� obj � ���� LongLong
	*/
	LongLong operator%(LongLong obj);
	
	/*
	������� �� ������� �� int
	@param _val - �������� ���� int
	@return - ���������� ������� �� ������� �� _val � ���� LongLong
	*/
	int operator%(int _val);
	
	/*
	������������
	@param obj - ��������� ������ LongLong
	@return - ����������� �������� ���������� �������� obj
	*/
	LongLong operator=(LongLong obj);

	/*
	��������� "������ ������ �������?"
	@param compared - ������������ LongLOng
	@return - ���������� ��������� ��������� > (true or false)
	*/
	bool operator>(LongLong compared);
	
	/*
	��������� "������ ������ �������?"
	@param compared - ������������ LongLOng
	@return - ���������� ��������� ��������� < (true or false)
	*/
	bool operator<(LongLong compared);
	
	/*
	��������� "������ ����� �������?"
	@param compared - ������������ LongLOng
	@return - ���������� ��������� ��������� == (true or false)
	*/
	bool operator==(LongLong compared);
	
	/*
	��������� "������ �� ����� �������?"
	@param compared - ����������� LongLOng
	@return - ���������� ��������� ��������� != (true or false)
	*/
	bool operator!=(LongLong compared);
	
	/*
	����� LongLong
	@param out - ����� ������
	@param lLong - ��������� LongLong
	@return - ���������� ����� ������
	*/
	friend std::ostream& operator<<(std::ostream& out, const LongLong& lLong);

	/*
	����� LongLong
	@param in - ����� �����
	@param lLong - LongLong ��� �������� �������� �������
	@return - ���������� ����� �����
	*/
	friend std::istream& operator>>(std::istream& in, LongLong& lLong);
};