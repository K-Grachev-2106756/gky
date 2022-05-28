#include <Complex/Complex.h>
Complex::Complex(double rez, double imz)
{
	re = rez;
	im = imz;
}
Complex::Complex(double rez)
{
	re = rez;
	im = 0.0;
}
Complex::Complex()
{
	re = 0.0;
	im = 0.0;
}
Complex& Complex::operator=(const Complex& other)
{
	this->im = other.im;
	this->re = other.re;
	return *this;
}
Complex& Complex::operator=(const int& other)
{
	this->im = 0;
	this->re = other;
	return *this;
}
Complex& Complex::operator+=(const Complex& other)
{
	this->re += other.re;
	this->im += other.im;
	return *this;
}
Complex& Complex::operator-=(const Complex& other)
{
	this->re -= other.re;
	this->im -= other.im;
	return *this;
}
Complex& Complex::operator/=(const Complex& other)
{
		if (other.re * other.re + other.im * other.im == 0)
		{
			throw "Can't do this";
		}
		double re = (this->re * other.re + this->im * other.im) / (other.re * other.re + other.im * other.im);
		double im = (other.re * this->im - this->re * other.im) / (other.re * other.re + other.im * other.im);
		this->re = re;
		this->im = im;
		return *this;
}
Complex& Complex::operator*=(const Complex& other)
{
	double re = this->re * other.re - this->im * other.im;
	double im = this->im * other.re + this->re * other.im;
	this->im = im;
	this->re = re;
	return *this;
}
Complex& Complex::operator+=(const int& other)
{
	Complex a(other);
	return *this += a;
}
Complex& Complex::operator-=(const int& other)
{
	Complex a(other);
	return *this -= a;
}
Complex& Complex::operator/=(const int& other)
{
	Complex a(other);
	return *this /= a;
}
Complex& Complex::operator*=(const int& other)
{
	Complex a(other);
	return *this *= a;
}
Complex Complex::operator-() const
{
	Complex a = *this;
	a *= -1;
	return a;
}



Complex const operator+(const Complex& Com, const Complex& other)
{
	Complex a = Com;
	a += other;
	return a;
}
Complex const operator-(const Complex& Com, const Complex& other)
{
	Complex a = Com;
	a += other * (-1);
	return a;
}
Complex const operator/(const Complex& Com, const Complex& other)
{
	Complex a = Com;
	a /= other;
	return a;
}
Complex const operator*(const Complex& Com, const Complex& other)
{
	Complex a = Com;
	a *= other;
	return a;
}


Complex const operator+(const Complex& Com, const int& other)
{
	Complex a = Com, b(other);
	a += b;
	return a;
}
Complex const operator-(const Complex& Com, const int& other)
{
	Complex a = Com, b(other);
	a -=b;
	return a;
}
Complex const operator/(const Complex& Com, const int& other)
{
	Complex a = Com, b(other);
	a /= b;
	return a;
}
Complex const operator*(const Complex& Com, const int& other)
{
	Complex a = Com, b(other);
	a *= b;
	return a;
}
std::istream& Complex::readFrom(std::istream& is)
{
	double real(0.0), imaganary(0.0);
	char lb(0), rb(0), sep(0);
	is >> lb >> real >> sep >> imaganary >> rb;
	if (is.good())
	{
		if (lb == Complex::leftBrace && sep == Complex::separator && rb == Complex::rightBrace)
		{
			re = real;
			im = imaganary;
		}
		else
		{
			is.setstate(std::ios_base::failbit);
		}
	}
	return is;
}
//bool test(const std::string& str)
//{
//	using namespace std;
//	istringstream ifstream(str);
//}

