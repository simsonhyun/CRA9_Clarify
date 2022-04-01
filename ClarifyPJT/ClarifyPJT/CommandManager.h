#pragma once
#include "DataManager.h"

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

public:
private:
	DataManager* _dataManager;

};