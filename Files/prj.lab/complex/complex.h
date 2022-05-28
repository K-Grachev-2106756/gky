// authoring
#include <iostream>
#include <fstream>
#pragma once
#ifndef COMPLEX_COMPLEX_H_20220309
#define COMPLEX_COMPLEX_H_20220309

class Complex
{
public:
	double re;
	double im;

	//три конструктора
	Complex(double rez, double imz);
	Complex(double rez);
	Complex();

	//перегруженные операторы
	bool operator==(const Complex& other) const
	{
		return (abs(this->im-other.im)<2*std::numeric_limits<double>::epsilon()) && (abs(this->re - other.re) < 2 * std::numeric_limits<double>::epsilon());
	}
	bool operator!=(const Complex& other) const
	{
		return !(*this == other);
	}
	bool operator<(const Complex& other) const
	{
		return std::sqrt(this->im * this->im + this->re * this->re) < std::sqrt(other.im * other.im + other.re * other.re);
	}
	bool operator>=(const Complex& other) const
	{
		return !(*this < other);
	}
	bool operator>(const Complex& other) const
	{
		return std::sqrt(this->im * this->im + this->re * this->re) > std::sqrt(other.im * other.im + other.re * other.re);
	}
	bool operator<=(const Complex& other) const
	{
		return !(*this > other);
	}

	Complex& operator=(const Complex& other);
	Complex& operator=(const int& other);
	Complex& operator+=(const Complex& other);
	Complex& operator-=(const Complex& other);
	Complex& operator/=(const Complex& other);
	Complex& operator*=(const Complex& other); 
	Complex& operator+=(const int& other);
	Complex& operator-=(const int& other);
	Complex& operator/=(const int& other);
	Complex& operator*=(const int& other);
	
	Complex operator-() const;
	~Complex() = default;
	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };
	std::istream& readFrom(std::istream& is);

private:
protected:
};


//ввод вывод
inline std::ostream& operator<<(std::ostream& os, const Complex& a)
{
	os <<"{"<< a.re << "," << a.im<<"}";
	return os;
}

inline std::istream& operator>>(std::istream& is, Complex& a)
{
	return a.readFrom(is);
}


Complex const operator-(const Complex& Com, const Complex& other);
Complex const operator+(const Complex& Com, const Complex& other);
Complex const operator/(const Complex& Com, const Complex& other);
Complex const operator*(const Complex& Com, const Complex& other);

Complex const operator+(const Complex& Com, const int& other);
Complex const operator-(const Complex& Com, const int& other);
Complex const operator/(const Complex& Com, const int& other);
Complex const operator*(const Complex& Com, const int& other);



#endif