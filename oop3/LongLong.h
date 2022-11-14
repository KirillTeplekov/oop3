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
	 онструктор по умолчанию, создаЄт класс LongLong с пол€ми (0, 0, 0, 0)
	*/
	LongLong();

	/*
	 онструктор класса
	@param _hHigh - первые 4 байта длинного числа
	@param _mHigh - втора€ часть длинного числа
	@param _mLow - треть€ часть длинного числа
	@param _lLow - четверта€ часть длинного числа
	*/
	LongLong(long _hHigh, unsigned long _mHigh, unsigned long _mLow, unsigned long _lLow);


	/*
	ѕолучить младшую часть (дл€ перевода в unsigned long)
	@return - возвращает unsigned long (значение lLow)
	*/
	unsigned long getLow();
	

	/*
	—ложение двух LongLong
	@param _val - слагаемое в виде LongLong
	@return - возвращает сумму в виде LongLong
	*/
	LongLong operator+(LongLong _val);
	
	/*
	сложение с int
	@param _val - слагаемое типа int
	@return - возвращает сумму в виде LongLong
	*/
	LongLong operator+(int obj);
	
	/*
	–азность двух LongLong
	@param obj - вычитаемое типа LongLong
	@return - возвращает разность в виде LongLong
	*/
	LongLong operator-(LongLong obj);
	
	/*
	–азность с int
	@param _val - вычитаемое типа int
	@return - возвращает разность в виде LongLong
	*/
	LongLong operator-(int _val);
	
	/*
	ѕроизведение двух LongLong
	@param obj - множитель в виде LongLong
	@return - возвращает произведение в виде LongLong
	*/
	LongLong operator*(LongLong obj);

	/*
	ѕроизведение с int
	@param _val - вычитаемое в виде LongLong
	@return - возвращает произведение в виде LongLong
	*/
	LongLong operator*(int _val);

	/*
	ƒеление двух LongLong
	@param obj - делитель в виде LongLong
	@return - возвращает частное в виде LongLong
	*/
	LongLong operator/(LongLong obj);
	
	/*
	ƒеление на int
	@param obj - делитель типа int
	@return - возвращает частное в виде LongLong
	*/
	LongLong operator/(int _val);
	
	/*
	ќстаток от делени€ двух LongLong
	@param obj - делитель в виде LongLong
	@return - возвращает остаток от делени€ на obj в виде LongLong
	*/
	LongLong operator%(LongLong obj);
	
	/*
	ќстаток от делени€ на int
	@param _val - делитель типа int
	@return - возвращает остаток от делени€ на _val в виде LongLong
	*/
	int operator%(int _val);
	
	/*
	ѕрисваивание
	@param obj - экземпл€р класса LongLong
	@return - присваивает текущему экземпл€ру значени€ obj
	*/
	LongLong operator=(LongLong obj);

	/*
	—равнение "первое больше второго?"
	@param compared - сравниваемое LongLOng
	@return - возвращает результат сравнени€ > (true or false)
	*/
	bool operator>(LongLong compared);
	
	/*
	—равнение "первое меньше второго?"
	@param compared - сравниваемое LongLOng
	@return - возвращает результат сравнени€ < (true or false)
	*/
	bool operator<(LongLong compared);
	
	/*
	—равнение "первое равно второму?"
	@param compared - сравниваемое LongLOng
	@return - возвращает результат сравнени€ == (true or false)
	*/
	bool operator==(LongLong compared);
	
	/*
	—равнение "первое не равно второму?"
	@param compared - сравниваемо LongLOng
	@return - возвращает результат сравнени€ != (true or false)
	*/
	bool operator!=(LongLong compared);
	
	/*
	¬ывод LongLong
	@param out - поток вывода
	@param lLong - выводимый LongLong
	@return - возвращает поток вывода
	*/
	friend std::ostream& operator<<(std::ostream& out, const LongLong& lLong);

	/*
	¬ывод LongLong
	@param in - поток ввода
	@param lLong - LongLong дл€ которого ввод€тс€ значени
	@return - возвращает поток ввода
	*/
	friend std::istream& operator>>(std::istream& in, LongLong& lLong);
};