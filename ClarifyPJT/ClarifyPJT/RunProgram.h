#pragma once
#include "CommandParser.h"

class RunProgram
{
public:
	const void run(const string& cmdString)
	{
		InputParameter inputParameter = commandParser.ConvertParameter(cmdString);


	}
private:

public:
private:
	CommandParser commandParser;
};