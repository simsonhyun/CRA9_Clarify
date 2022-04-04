#pragma once
#include <iostream>
#include "CommonType.h"
#include "DataManager.h"

class CommandManager
{
private:
	CommandType _myCommandType;
	DataManager* _dataManager;

public:
	CommandManager(CommandType command, DataManager& dataManager) :
		_myCommandType(command),
		_dataManager(&dataManager)
	{ }

	DataManager* getDataManager(void) const
	{
		return _dataManager;
	}

	CommandType getCommandType(void) const
	{
		return _myCommandType;
	}

	virtual vector<Employee> Command(InputParameter input) = 0;
	//{ 
	//	try
	//	{
	//		throw exception("Invalid function");
	//	}
	//	catch (exception e)
	//	{
	//		std::cout << e.what() << endl;
	//	}

	//	return vector<Employee>(); 
	//};

};