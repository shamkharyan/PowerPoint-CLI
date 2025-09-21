#include "Tokenizer.h"
#include <string>
#include <iostream>

Tokenizer::Tokenizer(std::istream& is, std::size_t maxLen) : m_is(is), m_maxLen(maxLen) {}

bool Tokenizer::getNextToken(std::string& token)
{
	char c;

	token.clear();
	while (m_is.get(c))
	{
		if (c == '\n')
			return false;
		if (!std::isspace(c))
			break;
	}

	token.push_back(c);
	if (c == ',')
		return true;

	while (m_is.get(c))
	{
		if (std::isspace(c) || c == ',')
		{
			if (c == ',' || c == '\n')
				m_is.unget();
			break;
		}
		if (token.length() >= m_maxLen)
			break;
		token.push_back(c);
	}
	return true;
}