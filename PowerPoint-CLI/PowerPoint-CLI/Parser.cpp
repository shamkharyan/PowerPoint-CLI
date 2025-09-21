#include "Parser.h"
#include "ArgVal.h"

Parser::Parser()
{
	initCommands();
}

void Parser::initCommands()
{
	Command addSlide;
	addSlide.addArg("-at", ArgVal::Type::NUMBER, true);
	addSlide.addArg("-bgcolor", ArgVal::Type::COLOR, false);
	m_commands["add-slide"] = addSlide;

	Command addShape;
	addShape.addArg("-type", ArgVal::Type::STRING, true);
	addShape.addArg("-start", ArgVal::Type::COORD, true);
	addShape.addArg("-end", ArgVal::Type::COORD, true);
	addShape.addArg("-w", ArgVal::Type::NUMBER, true);
	addShape.addArg("-h", ArgVal::Type::NUMBER, true);
	addShape.addArg("-r", ArgVal::Type::NUMBER, true);
	addShape.addArg("-bgcolor", ArgVal::Type::COLOR, false);
	addShape.addArg("-olcolor", ArgVal::Type::COLOR, false);
	m_commands["add-shape"] = addShape;

	Command addText;
	addText.addArg("-start", ArgVal::Type::COORD, true);
	addText.addArg("-size", ArgVal::Type::NUMBER, true);
	addText.addArg("-color", ArgVal::Type::COLOR, false);
	addText.addArg("-font", ArgVal::Type::STRING, false);
	addText.addArg("-style", ArgVal::Type::NUMBER, false);
	addText.addArg("-link", ArgVal::Type::NUMBER, false);
	m_commands["add-text"] = addText;

	Command create;
	create.addArg("-name", ArgVal::Type::STRING, false);
	m_commands["create"] = create;

	Command help;
	m_commands["help"] = help;

	Command close;
	m_commands["close"] = close;

	Command quit;
	m_commands["quit"] = quit;

	Command save;
	m_commands["save"] = save;

	Command move;
	move.addArg("-id", ArgVal::Type::NUMBER, true);
	move.addArg("-start", ArgVal::Type::NUMBER, true);
	move.addArg("-abs", ArgVal::Type::NONE, false);
	m_commands["move"] = move;

	Command del;
	move.addArg("-id", ArgVal::Type::NUMBER, true);
	m_commands["delete"] = del;

	Command gt;
	gt.addArg("-id", ArgVal::Type::NUMBER, true);
	m_commands["goto"] = gt;
}

bool Parser::evalToken(const std::string& token)
{
	if (m_state == State::EMPTY && m_commands.find(token) != m_commands.end())
	{
		m_currCommand = token;
		m_state = State::ARGUMENT;
	}
	if (m_state == State::ARGUMENT && m_commands[m_currCommand].findArg(token))
	{

	}
}