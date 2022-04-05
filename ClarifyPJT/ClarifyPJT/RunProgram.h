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
	static const int ARGUMENT_COUNT = 3;
	static const int MAX_FILELENGTH = 300;

	// Command_None = 0,
	// Command_Add,
	// Command_Sch,
	// Command_Del,
	// Command_Mod,

	RunProgram()
	{
		DataManager* dataManager = new DataManager();
		commands.push_back(new Add(*dataManager));
		commands.push_back(new Search(*dataManager));
		commands.push_back(new Del(*dataManager));
		commands.push_back(new Mod(*dataManager));
	}

	const void run(const string& inputText, const string& outputText)
	{
		_checkInvalidFileName(inputText);
		_checkInvalidFileName(outputText);

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

	const bool compareFiles(const std::string& p1, const std::string& p2)
	{
		return fileManager.compareFiles(p1, p2);
	}

	const bool checkArgument(int argc) const
	{
		if (argc == ARGUMENT_COUNT)
		{
			return true;
		}

		return false;
	}

private:
	const string _run(const string& cmdString)
	{
		InputParameter inputParameter = commandParser.ConvertParameter(cmdString);
		_checkInvalidCmd(inputParameter.command, cmdString);

		try
		{
			if (inputParameter.command == CommandType::Command_None)
			{
				throw invalid_argument("Invalid Command!");
			}
		}
		catch (exception e)
		{
			cout << e.what() << endl;
		}

		for (const auto& command : commands)
		{
			if (command->getCommandType() == inputParameter.command)
			{
				OutputParameter ret = command->Command(inputParameter);
				if (inputParameter.command == CommandType::Command_Add)
				{
					return ADD_RETURN_SIG;
				}

				return printManager.Print(inputParameter.command, inputParameter.option1, ret);
			}
		}
	}

	const void _checkInvalidFileName(const string& fileName) const
	{
		// 정책 
		// 1. / 개수 3개 미만
		// 2. file 이름 300 이하
		static const char FIND_INVALID_CH = '/';

		bool ret = false;
		int findCount = 0;

		for (auto ch : fileName)
		{
			if (ch == FIND_INVALID_CH)
			{
				findCount++;
			}

			if (findCount > 3)
			{
				ret = true;
				break;
			}
		}

		if (fileName.length() >= MAX_FILELENGTH)
		{
			ret = true;
		}

		if (ret) throw invalid_argument("Input Invalid FileName");
	}

	const void _checkInvalidCmd(const CommandType& command, const string& oneLineString) const
	{
		// , 개수
		// ADD 9개
		// SCH 5개
		// DEL 5개
		// MOD 7개
		static const char FIND_COMMA_CH = ',';
		static const int ADD_COMMA_COUNT = 9;
		static const int SCH_COMMA_COUNT = 5;
		static const int DEL_COMMA_COUNT = 5;
		static const int MOD_COMMA_COUNT = 7;

		bool ret = false;
		int findCount = 0;

		for (auto ch : oneLineString)
		{
			if (ch == FIND_COMMA_CH)
			{
				findCount++;
			}
		}

		if ((command == CommandType::Command_Add) && (findCount == ADD_COMMA_COUNT)) {}
		else if ((command == CommandType::Command_Del) && (findCount == DEL_COMMA_COUNT)) {}
		else if ((command == CommandType::Command_Mod) && (findCount == MOD_COMMA_COUNT)) {}
		else if ((command == CommandType::Command_Sch) && (findCount == SCH_COMMA_COUNT)) {}
		else
		{
			throw invalid_argument("Invalid Command Input");
		}

	}

public:
private:
	CommandParser commandParser;
	PrintManager printManager;
	FileManager fileManager;

	vector<CommandManager*> commands;
};