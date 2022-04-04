#pragma once
#include "CommandParser.h"
#include "DataManager.h"
#include "PrintManager.h"
#include "Add.h"
#include "Sch.h"

#define TEST_PRINT	(1)

class RunProgram
{
public:
	const void init(void)
	{
		DataManager* dataManager = new DataManager();
		add = new Add(*dataManager);
		search = new Search(*dataManager);
	}

	const void run(const string& inputText)
	{

	}

	const string _run(const string& cmdString)
	{
		InputParameter inputParameter = commandParser.ConvertParameter(cmdString);

		if (inputParameter.command == Command::Command_Add)
		{
			add->Command(inputParameter);
		}
		else if (inputParameter.command == Command::Command_Sch)
		{
			return printManager.Print(inputParameter.command, inputParameter.option1, search->search(inputParameter));
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
	PrintManager printManager;

	Add* add;
	Search* search;
	// Del* del;
	// Mod* mod;
};