#pragma once
#include "CommandParser.h"
#include "DataManager.h"
#include "Add.h"

class RunProgram
{
public:
	const void init(void)
	{
		DataManager* dataManager = new DataManager();
		add = new Add(*dataManager);
	}

	const void run(const string& cmdString)
	{
		InputParameter inputParameter = commandParser.ConvertParameter(cmdString);

		if (inputParameter.command == Command::Command_Add)
		{
			add->Command(inputParameter);
		}
		else if (inputParameter.command == Command::Command_Sch)
		{

		}
		else if (inputParameter.command == Command::Command_Del)
		{

		}
		else if (inputParameter.command == Command::Command_Mod)
		{

		}
	}
private:

public:
private:
	CommandParser commandParser;
	Add* add;
	// Sch* sch;
	// Del* del;
	// Mod* mod;
};