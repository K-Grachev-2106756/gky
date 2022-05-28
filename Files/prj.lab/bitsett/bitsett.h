// authoring
#include <iostream>
#include <fstream>
#include <vector>
#include <BitSetI/BitSetI.h>
#pragma once
#ifndef BITSETT_BITSETT_H_20220309
#define BITSETT_BITSETT_H_20220309

template <typename T>
class BitSet:public BitSetI
{
public:
	class BitHolder {
	public:
		friend class BitSet<T>;
		BitHolder(BitSet<T>* rhs, const T pos);
		BitHolder& operator=(const bool rhs);
		operator bool() const;
		~BitHolder() = default;
	private:
		T bitset_cell=0, bitset_bit=0;
		BitSet<T>* bitset = nullptr;
	};
	T datasize{0};
	std::vector<T> data{0};
	int Tsize = sizeof(T)*8;
	BitSet<T>(const T size = 0, const bool filler = false);
	BitSet<T>(const BitSet<T>& copy);
	BitSet<T>(const std::string str);
	
	BitSet<T>& operator=(const BitSet<T>& rhs);
	BitSet<T>& operator&=(const BitSet<T>& rhs);
	BitSet<T>& operator|=(const BitSet<T>& rhs);
	BitSet<T>& operator^=(const BitSet<T>& rhs);
	BitSet<T>& operator<<=(const T rhs);
	BitSet<T>& operator>>=(const T rhs);

	bool operator==(const BitSet<T>& rhs) const;
	bool operator!=(const BitSet<T>& rhs) const;

	BitSet<T> operator~() const;
	BitSet<T> operator&(const BitSet<T>& rhs) const;
	BitSet<T> operator|(const BitSet<T>& rhs) const;
	BitSet<T> operator^(const BitSet<T>& rhs) const;
	BitSet<T> operator<<(const T rhs) const;
	BitSet<T> operator>>(const T rhs) const;

	BitHolder operator[](const T position);
	bool operator[](const T position) const;
	T size() const;
	void resize(const T size, const bool filler = false);
	int bitsetlength(const int quantity);
	~BitSet<T>() = default;

	void WriteTo(std::ostream& s, const Format f) override
	{
	}
};
template <typename T>
std::ostream& operator<<(std::ostream& ostream,const BitSet<T>& data);
template <typename T>
std::istream& operator>>(std::istream& istream, BitSet<T>& data);

template <typename T>
BitSet<T>::BitSet<T>(const T size, const bool filler)
{
	int length = bitsetlength(size);
	this->datasize = size;
	if (filler) {
		for (int i = length - 1; i >= 0; i--) data[i] = (1 << Tsize) - 1;
		if (size % Tsize != 0) data[0] = (1 << size % Tsize) - 1;
	}
}
template <typename T>
BitSet<T>::BitSet<T>(const std::string str)
{
	int length = bitsetlength(str.length());
	this->data = std::vector<T>(length, 0);
	this->datasize = str.length();
	for (int i = 0, j = datasize - 1; i < datasize; i++, j--)
		if (str[i] == '1') (*this)[j] = 1;
}
template <typename T>
BitSet<T>::BitSet<T>(const BitSet<T>& copy)
{
	*this = copy;
}
template <typename T>
BitSet<T>& BitSet<T>::operator=(const BitSet<T>& rhs)
{
	this->data = rhs.data;
	this->datasize = rhs.datasize;
	return *this;
}
template <typename T>
BitSet<T>& BitSet<T>::operator&=(const BitSet<T>& rhs)
{
	if (this->datasize != rhs.datasize) throw std::logic_error("BitSet<T> error: sizes of operands do not match");
	for (int i = 0; i < this->data.size(); i++)
	{
		this->data[i] &= rhs.data[i];
	}
	return *this;
}
template <typename T>
BitSet<T>& BitSet<T>::operator|=(const BitSet<T>& rhs)
{
	if (this->datasize != rhs.datasize) throw std::logic_error("BitSet<T> error: sizes of operands do not match");
	for (int i = 0; i < this->data.size(); i++)
	{
		this->data[i] |= rhs.data[i];
	}
	return *this;
}
template <typename T>
BitSet<T>& BitSet<T>::operator^=(const BitSet<T>& rhs)
{
	if (this->datasize != rhs.datasize) throw std::logic_error("BitSet<T> error: sizes of operands do not match");
	for (int i = 0; i < this->data.size(); i++)
	{
		this->data[i] ^= rhs.data[i];
	}
	return *this;
}
template <typename T>
BitSet<T>& BitSet<T>::operator<<=(const T rhs)
{
	if (rhs < 0)
	{
		throw std::invalid_argument("BitSet<T> error: bitwise shift by negative count is undefined");
	}
	for (int i = 0; i < this->datasize - rhs; i++)
	{
		(*this)[i] = (*this)[(i + rhs)];
	}
	for (int i = this->datasize - rhs; i < this->datasize; i++)
	{
		(*this)[i] = 0;
	}
}
template <typename T>
BitSet<T>& BitSet<T>::operator>>=(const T rhs)
{
	if (rhs < 0)
	{
		throw std::invalid_argument("BitSet<T> error: bitwise shift by negative count is undefined");
	}
	for (int i = this->datasize - 1; i > rhs; i--)
	{
		(*this)[i] = (*this)[i - rhs];
	}
	for (int i = 0; i < rhs; i++)
	{
		(*this)[i] = 0;
	}

}
template <typename T>
bool BitSet<T>::operator==(const BitSet<T>& rhs) const
{
	return (this->datasize == rhs.datasize);
}
template <typename T>
bool BitSet<T>::operator!=(const BitSet<T>& rhs) const
{
	return !(*this == rhs);
}
template <typename T>
BitSet<T> BitSet<T>::operator~() const
{
	BitSet<T> a(*this);
	for (int i = 0; i < a.datasize; i++)
	{
		a[i] = !a[i];
	}
	return a;
}
template <typename T>
BitSet<T> BitSet<T>::operator&(const BitSet<T>& rhs) const
{
	BitSet<T> a(*this);
	return a &= rhs;
}
template <typename T>
BitSet<T> BitSet<T>::operator|(const BitSet<T>& rhs) const
{
	BitSet<T> a(*this);
	return a |= rhs;
}
template <typename T>
BitSet<T> BitSet<T>::operator^(const BitSet<T>& rhs) const
{
	BitSet<T> a(*this);
	return a ^= rhs;
}
template <typename T>
BitSet<T> BitSet<T>::operator<<(const T rhs) const
{
	BitSet<T> a(*this);
	return a <<= rhs;
}
template <typename T>
BitSet<T> BitSet<T>::operator>>(const T rhs) const
{
	BitSet<T> a(*this);
	return a >>= rhs;
}
template <typename T>
T BitSet<T>::size() const
{
	return this->datasize;
}
template <typename T>
void BitSet<T>::resize(const T size, const bool filler)
{
	if (size < 0)
	{
		throw std::invalid_argument("BitSet<T> error: BitSet<T> size can not be negative");
	}
	int b = this->datasize;
	this->datasize = size;
	if (size > b) {
		for (int i = 0; i < bitsetlength(size) - bitsetlength(datasize); i++) data.push_back(0);
		for (int i = b; i < datasize; i++) (*this)[i] = filler;
	}
	else for (int i = datasize; i < b; i++) (*this)[i] = 0;
}
template <typename T>
int BitSet<T>::bitsetlength(const int quantity)
{
	return (quantity + (Tsize-1)) / Tsize;
}
template <typename T>
std::ostream& operator<<(std::ostream& ostream, const BitSet<T>& data)
{
	for (int i = data.datasize - 1; i >= 0; i--) ostream << data[i];
	return ostream;
}
template <typename T>
std::istream& operator>>(std::istream& istream, BitSet<T>& data)
{
	std::string input, base;
	istream >> std::noskipws >> input >> std::skipws;
	for (auto i : input)
		if (i == '1' || i == '0') base += i;
		else break;
	data = BitSet<T>(base);
	return istream;
}
template <typename T>
BitSet<T>::BitHolder::BitHolder(BitSet<T>* rhs, const T pos)
{
	this->bitset = rhs;
	this->bitset_cell = pos / Tsize;
	this->bitset_bit = pos % Tsize;
}
template <typename T>
BitSet<T>::BitHolder BitSet<T>::operator[](const T position)
{
	if (position < 0) throw std::invalid_argument("BitSet<T> error: index out of range");
	if (position > this->datasize) throw std::out_of_range("BitSet<T> error: index out of range");
	return BitHolder(this, position);
}
template <typename T>
BitSet<T>::BitHolder& BitSet<T>::BitHolder::operator=(const bool rhs)
{
	T p = 1 << bitset_bit;
	if (rhs) bitset->data[bitset_cell] = bitset->data[bitset_cell] | p;
	else bitset->data[bitset_cell] = bitset->data[bitset_cell] & ((1 << Tsize) - p - 1);
	return *this;
}
template <typename T>
BitSet<T>::BitHolder::operator bool() const {
	if (bitset_bit < 0) throw std::invalid_argument("BitSet<T> error: index out of range");
	if (bitset_cell > bitset->datasize) throw std::out_of_range("BitSet<T> error: index out of range");
	T b = bitset->data[bitset_cell] & (1 << bitset_bit);
	if (b == 0) return false;
	return true;
}
template <typename T>
bool BitSet<T>::operator[](const T position) const
{
	if (position < 0) throw std::invalid_argument("BitSet<T> error: index out of range");
	if (position > this->datasize) throw std::out_of_range("BitSet<T> error: index out of range");
	T b = this->data[position / Tsize] & (1 << position);
	if (b == 0) return false;
	return true;
}
#endif