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
		_CheckInputdataValid(&inputParameter);

		getDataManager()->setData(inputParameter.inputEmployee);
	}

private:
	void _CheckInputdataValid(InputParameter* inputParameter)
	{
		_ASSERT(inputParameter->option1 == Option1::Option1_None);
		_ASSERT(inputParameter->option2 == Option2::Option2_None);
		_ASSERT(inputParameter->column == Column::Column_None);

		Employee* employee = &inputParameter->inputEmployee;
		_ASSERT((employee->GetEmployeeNum() >= Employee::MIN_EMPLOYEE_NUM && employee->GetEmployeeNum() <= 99999999) ||
			(employee->GetEmployeeNum() <= Employee::MAX_EMPLOYEE_NUM && employee->GetEmployeeNum() >= 0));
		_ASSERT((employee->GetName()._firstName.size() + employee->GetName()._lastName.size()) <= 15);
		for (auto name : employee->GetName()._firstName){

			if (name < 'A' || name > 'Z') _ASSERT(false);
		}
		for (auto name : employee->GetName()._lastName) {

			if (name < 'A' || name > 'Z') _ASSERT(false);
		}
		_ASSERT(employee->GetPhoneNum()._middleNum <= 9999 && employee->GetPhoneNum()._middleNum >= 0);
		_ASSERT(employee->GetPhoneNum()._lastNum <= 9999 && employee->GetPhoneNum()._lastNum >= 0);
		_ASSERT(employee->GetBirthDay()._year >= Employee::MIN_EMPLOYEE_BIRTH && employee->GetBirthDay()._year <= Employee::MAX_EMPLOYEE_BIRTH);
		_ASSERT(employee->GetBirthDay()._month <= 12);
		_ASSERT(employee->GetBirthDay()._month >= 1);
		_ASSERT(employee->GetBirthDay()._day >= 1);
		_ASSERT(employee->GetBirthDay()._day <= 31);
	}
};