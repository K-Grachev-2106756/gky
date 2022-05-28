#include <rational/rational.h>
#include <sstream>
#include <cctype> 

Rational::Rational()
{
	this->numenator = 0;
	this->denominator = 1;
}
Rational::Rational(int a)
{
	this->numenator = a;
	this->denominator = 1;
}
Rational::Rational(int a, int b)
{
			if (b == 0) 
			{
				throw std::invalid_argument("ошибка деления на ноль");
			}
			this->numenator = a;
			this->denominator = b;
			drob(*this);
}


Rational const operator+(const Rational& Rat, const Rational& other)
{
	Rational a = Rat;
	a += other;
	return a;
}
Rational const operator+(const Rational& Rat, const int& other)
{
	Rational a = Rat;
	a += other;
	return a;	
}

Rational const operator-(const Rational& Rat, const Rational& other)
{
	Rational a = Rat;
	a += other * (-1);
	return a;
}
Rational const operator-(const Rational& Rat, const int& other)
{
	Rational a = Rat;
	a += other * (-1);
	return a;
}
Rational Rational:: operator-() const
{
	Rational a = (*this);
	a *= -1;
	return a;
}
Rational const operator*(const Rational& Rat, const Rational& other)
{
	Rational a = Rat;
	a *= other;
	return a;
}
Rational const operator*(const Rational& Rat, const int& other)
{
	Rational a = Rat;
	a *= other;
	return a;
}

Rational const operator/(const Rational& Rat, const Rational& other)
{
	Rational a = Rat;
	a /= other;
	return a;
}
Rational const operator/(const Rational& Rat, const int& other)
{
	Rational a = Rat;
	a /= other;
	return a;
}

Rational& Rational::operator=(const Rational& other)
{
	this->numenator = other.numenator;
	this->denominator = other.denominator;
	return *this;
}
Rational& Rational::operator+=(const Rational& other)
{
	if (this->denominator == other.denominator)
	{
		this->numenator += other.numenator;
		drob(*this);
		return *this;
	}
	else
	{
		this->numenator = this->numenator * other.denominator + this->denominator * other.numenator;
		this->denominator = this->denominator * other.denominator;
		drob(*this);
		return *this;
	}
}
Rational& Rational::operator+=(const int& other)
{
	this->numenator = this->numenator + other * this->denominator;
	drob(*this);
	return *this;
}

Rational& Rational::operator-=(const Rational& other)
{
	*this += other * (-1);
	return *this;
}
Rational& Rational::operator-=(const int& other)
{
	*this += other * (-1);
	return *this;
}
Rational& Rational::operator*=(const Rational& other)
{
	this->numenator = this->numenator * other.numenator;
	this->denominator = this->denominator * other.denominator;
	drob(*this);
	return *this;
}
Rational& Rational::operator*=(const int& other)
{
	this->numenator = other * this->numenator;
	drob(*this);
	return *this;
}
Rational& Rational::operator/=(const Rational& other)
{
		if (other.numenator==0)
		{
			throw std::invalid_argument("ошибка деленения на ноль");
		}
		this->numenator = this->numenator * other.denominator;
		this->denominator = this->denominator * other.numenator;
		drob(*this);
		return *this;	
}
Rational& Rational::operator/=(const int& other)
{
		if (other==0)
		{
			throw std::invalid_argument("ошибка деленения на ноль");
		}
		this->numenator = this->numenator/ other;
		drob(*this);
		return *this;
}

Rational Rational::operator++(int)
{
	this->numenator += this->denominator;
	drob(*this);
	return *this;
}
Rational Rational::operator--(int)
{
	this->numenator -= this->denominator;
	drob(*this);
	return *this;
}

std::istream& Rational::ReadFrom(std::istream& is)
{
	int a(0);
	char slash(0);
	int b(0);

	is >> a;
	is.get(slash);
	if (!isdigit(is.peek())) {
		is >> b;
		is.setstate(std::ios_base::failbit);
	}
	else 
	{
		is >> b;
	}
	if (!is.bad()) 
	{
		if (slash == Rational::line) 
		{
			Rational z(a, b);
			numenator = z.numenator;
			denominator = z.denominator;
		}
		else 
		{
			is.setstate(std::ios_base::failbit);
		}
	}
	return is;

	/*using namespace std;
	int a(0), b(0);
	char slash(0);

	char trash(0);
	int c(0);
	string str;
	str = "";
	while ((isdigit(is.peek()) || is.peek() == '.' || is.peek() == '-' || is.peek()==' ') && is.peek() != '/')
	{
		is >> trash;
		if (trash != ' ')
		{
			str += trash;
		}
		if (trash == '.')
		{
			c = 1;
		}
	}
	if (c == 1)
	{
		is.setstate(std::ios_base::failbit);
	}
	else
	{
		is >> slash;
		if (is.good() && slash == Rational::line)
		{
			a = std::atoi(str.c_str());
			str = "";
			while ((isdigit(is.peek()) || is.peek() == '.' || is.peek() == '-'|| is.peek()==' ') && is.peek() != EOF)
			{
				trash = ' ';
				is >> trash;
				if (trash != ' ')
				{
					str += trash;
				}
				if (trash == '.')
				{
					c = 1;
				}
			}
			if (c == 1)
			{
				is.setstate(std::ios_base::failbit);
			}
			else
			{
				b = std::atoi(str.c_str());
				if (b > 0)
				{
					Rational z(a, b);
					numenator = z.numenator;
					denominator = z.denominator;
				}
				else
				{
					is.setstate(std::ios_base::failbit);
				}
			}
		}
		else
		{
			is.setstate(std::ios_base::failbit);
		}
	}
	return is;*/
	
}




void Rational::drob(Rational &a)
{
	int r=0,r1,r2,numminus=1, denminus=1;
	r1 = abs(a.numenator);
	r2 = abs(a.denominator);
	if (r1==0)
	{
		a.denominator = 1;
	}
	else
	{
		if (r1 == r2)
		{
			a.numenator /= r1;
			a.denominator /= r1;
		}
		else
		{

			while (r1 != r2)
			{
				if (r1 > r2)
				{
					r1 -= r2;
				}
				else
				{
					r2 -= r1;
				}
			}
			a.numenator /= r1;
			a.denominator /= r1;
		}
		if (a.denominator < 0)
		{
			a.numenator *= -1;
			a.denominator *= -1;
		}
	}
	
}

