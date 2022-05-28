// authoring
#include <iostream>
#include <fstream>
#include <string>

#pragma once
#ifndef RATIONAL_RATIONAL_H_20220309
#define RATIONAL_RATIONAL_H_20220309

class Rational
{
public:
	//���� ������ 
	int numenator;
	int denominator;
	//������������ ������
	Rational();
	Rational(int a);
	Rational(int a, int b);

	//���������� ������������� ���������
	bool operator==(const Rational& other) const { return this->numenator * other.denominator == other.numenator* this->denominator; } ;
	bool operator!=(const Rational& other) const { return !(*this == other); };
	bool operator<(const Rational& other) const { return this->numenator * other.denominator < this->denominator* other.numenator; };
	bool operator>(const Rational& other) const { return this->numenator * other.denominator > this->denominator* other.numenator; };
	bool operator<=(const Rational& other) const{ return !(*this > other); };
	bool operator>=(const Rational& other) const { return !(*this < other); };



	//������� ���������
	Rational& operator=(const Rational& other);

	Rational& operator+=(const Rational& other);
	Rational& operator+=(const int& other);

	Rational& operator-=(const Rational& other);
	Rational& operator-=(const int& other);

	Rational& operator*=(const Rational& other);
	Rational& operator*=(const int& other);

	Rational& operator/=(const Rational& other);
	Rational& operator/=(const int& other);

	Rational operator++(int);
	Rational operator--(int);
	Rational operator-() const;

	static const char line = '/';
	std::istream& ReadFrom(std::istream& is);
~Rational() = default;
private:
	//����� ��� ���������� �����
	void drob(Rational &a);
protected:
};

//���� �����
inline std::ostream& operator<<(std::ostream& os, const Rational& a) 
{
	os << a.numenator << a.line << a.denominator;
	return os;
}

inline std::istream& operator>>(std::istream& is, Rational& a)
{
	return a.ReadFrom(is);
}
//�������� ���������
Rational const operator+(const Rational& Rat, const Rational& other);
Rational const operator+(const Rational& Rat, const int& other);

Rational const operator-(const Rational& Rat, const Rational& other);
Rational const operator-(const Rational& Rat, const int& other);

Rational const operator*(const Rational& Rat, const Rational& other);
Rational const operator*(const Rational& Rat, const int& other);

Rational const operator/(const Rational& Rat, const Rational& other);
Rational const operator/(const Rational& Rat, const int& other);

	
#endif