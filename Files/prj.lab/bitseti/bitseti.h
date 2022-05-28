#include <iostream>
#include <fstream>
#include <vector>
#pragma once
#ifndef BITSETI_BITSETI_H_20220309
#define BITSETI_BITSETI_H_20220309


class BitSetI
{
public:
	enum class Format
	{
		Bin, Txt
	};
	virtual void WriteTo(std::ostream& s, const Format f)
	{
	}
};
#endif