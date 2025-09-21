#pragma once

#include "ArgVal.h"

#include <string>
#include <unordered_map>
#include <functional>

class Command
{
public:
	struct Argument
	{
		bool required;
		ArgVal::Type type;
		ArgVal value;
	};
public:
	Command() = default;

	void addArg(const std::string& argName, ArgVal::Type t, bool required);
	void removeArg(const std::string& argName);
	void setArgValue(const std::string& argName, ArgVal argVal);
	bool findArg(const std::string& argName) const;

	void setFunction(std::function<void()> func);
	void execute();
private:
	std::unordered_map<std::string, Argument> m_args;
	std::function<void()> m_func;
};
