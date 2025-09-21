#pragma once

#include "Command.h"

#include <string>
#include <unordered_set>

class Parser
{
public:
    Parser();
    bool evalToken(const std::string& token);
private:
    void initCommands();
private:
    enum class State
    {
        EMPTY,
        ARGUMENT,
        VALUE,
        ERROR,
        END
    };

    State m_state = State::EMPTY;
    std::unordered_map<std::string, Command> m_commands;
    std::string m_currCommand;
};
