#pragma once

#include <istream>
#include <string>

class Tokenizer
{
public:
	Tokenizer(std::istream& is, std::size_t maxLen = 20);

	bool getNextToken(std::string&);
private:
	std::istream& m_is;
	std::size_t m_maxLen;
};
