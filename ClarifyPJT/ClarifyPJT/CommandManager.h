#pragma once
#include "DataManager.h"
#include "CommonType.h"

class CommandManager
{
public:
	CommandManager(DataManager& dataManager) :
		_dataManager(&dataManager)
	{

	}

	DataManager* getDataManager(void) const
	{
		return _dataManager;
	}

	virtual vector<Employee> Command(InputParameter input) { return vector<Employee>(); };

public:
private:
	DataManager* _dataManager;

};