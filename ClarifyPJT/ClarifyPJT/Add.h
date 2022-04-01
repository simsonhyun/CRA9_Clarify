#pragma once
#include "CommonType.h"
#include "CommandManager.h"

class Add : public CommandManager
{
public:
	Add(DataManager& dataManager)
		:CommandManager(dataManager) { }

	void Command(InputParameter inputParameter)
	{

	}

private:

};