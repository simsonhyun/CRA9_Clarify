#pragma once
#include "CommandParser.h"
#include "DataManager.h"
#include "PrintManager.h"
#include "FileManager.h"
#include "Add.h"
#include "Sch.h"
#include "Del.h"
#include "Mod.h"

class RunProgram
{
public:
	const string ADD_RETURN_SIG = "ADD_RETURN";

	const void init(void)
	{
		DataManager* dataManager = new DataManager();
		add = new Add(*dataManager);
		search = new Search(*dataManager);
		del = new Del(*dataManager);
		mod = new Mod(*dataManager);
	}

	const void run(const string& inputText, const string& outputText)
	{
		fileManager.InputOpen(inputText);
		fileManager.OutputOpen(outputText);

		string oneLineString;
		string returnString;

		try
		{
			while (1)
			{
				oneLineString = fileManager.ReadOneLine();
				if (oneLineString == "")
				{
					break;
				}

				returnString = _run(oneLineString);
				if (returnString != ADD_RETURN_SIG)
				{
					fileManager.WriteString(returnString);
				}
			}
		}
		catch(std::exception const& e) 
		{
			cout << "There was an error: " << e.what() << endl;
			fileManager.OutputClose();
			fileManager.InputClose();
		}

		fileManager.OutputClose();
		fileManager.InputClose();
	}

	const string _run(const string& cmdString)
	{
		InputParameter inputParameter = commandParser.ConvertParameter(cmdString);

		if (inputParameter.command == Command::Command_Add)
		{
			add->Command(inputParameter);
			return ADD_RETURN_SIG;
		}
		else if (inputParameter.command == Command::Command_Sch)
		{
			return printManager.Print(inputParameter.command, inputParameter.option1, search->search(inputParameter));
		}
		else if (inputParameter.command == Command::Command_Del)
		{
			return printManager.Print(inputParameter.command, inputParameter.option1, del->deleteEmployeeInfo(inputParameter));
		}
		else if (inputParameter.command == Command::Command_Mod)
		{
			if (inputParameter.option1 == Option1::Option1_None)
			{
				return printManager.Print(inputParameter.command, inputParameter.option1, mod->ModNotOption1(inputParameter));
			}
			else
			{
				return printManager.Print(inputParameter.command, inputParameter.option1, mod->ModOption1(inputParameter));
			}
		}
		else
		{
			_ASSERT(false);
			return "";
		}
	}

	bool compareFiles(const std::string& p1, const std::string& p2)
	{
		return fileManager.compareFiles(p1, p2);
	}

private:

public:
private:
	CommandParser commandParser;
	PrintManager printManager;
	FileManager fileManager;

	Add* add;
	Search* search;
	Del* del;
	Mod* mod;
};