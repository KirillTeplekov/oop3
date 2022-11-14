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
	Конструктор класса
	@param _rubles - рубли
	@param _kopeiki - копейки
	*/
	Money(LongLong _rubles, unsigned int _kopeiki);

	/*
	Установить значение рублей
	@param _rubles - рубли
	*/
	void setRubles(LongLong _rubles);
	
	/*
	Получить значение рублей
	@return - рубли в виде LongLong
	*/
	LongLong getRubles();

	/*
	Установить значение копеек
	@param _kopeiki - копеек
	*/
	void setKopeiki(unsigned int _kopeiki);

	/*
	Получить значение копеек
	@return - копей типа unsigned int
	*/
	unsigned int getKopeiki();

	/*
	Сложение двух Money
	@param _val - слагаемое в виде Money
	@return - возвращает сумму в виде Money
	*/
	Money operator+(Money obj);

	/*
	Разность двух Money
	@param obj - вычитаемое типа Money
	@return - возвращает разность в виде Money
	*/
	Money operator-(Money obj);

	/*
	Деление двух Money
	@param obj - делитель в виде Money
	@return - возвращает частное в виде Money
	*/
	Money operator/(Money obj);

	/*
	Присваивание
	@param obj - экземпляр класса Money
	@return - присваивает текущему экземпляру значения obj
	*/
	Money operator=(Money obj);

	/*
	Сравнение "первое больше второго?"
	@param compared - сравниваемое Money
	@return - возвращает результат сравнения > (true or false)
	*/
	bool operator>(Money obj);

	/*
	Сравнение "первое меньше второго?"
	@param compared - сравниваемое Money
	@return - возвращает результат сравнения < (true or false)
	*/
	bool operator<(Money obj);

	/*
	Сравнение "первое равно второму?"
	@param compared - сравниваемое Money
	@return - возвращает результат сравнения == (true or false)
	*/
	bool operator==(Money obj);

	/*
	Вывод Money
	@param out - поток вывода
	@param lLong - выводимый Money
	@return - возвращает поток вывода
	*/
	friend std::ostream& operator<<(std::ostream& out, const Money& Money);

	/*
	Вывод Money
	@param in - поток ввода
	@param lLong - Money для которого вводятся значени
	@return - возвращает поток ввода
	*/
	friend std::istream& operator>>(std::istream& in, Money& Money);
};