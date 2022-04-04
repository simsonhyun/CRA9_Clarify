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

	RunProgram()
	{
		DataManager* dataManager = new DataManager();
		add = new Add(*dataManager);
		search = new Search(*dataManager);
		del = new Del(*dataManager);
		mod = new Mod(*dataManager);
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
		else throw invalid_argument("Invalid CMD Parsed");
	}

	const void _checkInvalidFileName(const string& fileName) const
	{
		// ��å 
		// 1. / ���� 3�� �̸�
		// 2. file �̸� 300 ����
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

	const void _checkInvalidCmd(const Command& command, const string& oneLineString) const
	{
		// , ����
		// ADD 9��
		// SCH 5��
		// DEL 5��
		// MOD 7��
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

		if ((command == Command::Command_Add) && (findCount == ADD_COMMA_COUNT)) {}
		else if ((command == Command::Command_Del) && (findCount == DEL_COMMA_COUNT)) {}
		else if ((command == Command::Command_Mod) && (findCount == MOD_COMMA_COUNT)) {}
		else if ((command == Command::Command_Sch) && (findCount == SCH_COMMA_COUNT)) {}
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

	Add* add;
	Search* search;
	Del* del;
	Mod* mod;
};