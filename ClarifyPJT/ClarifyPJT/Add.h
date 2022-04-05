#pragma once
#include "CommandManager.h"
#include <stdexcept>
#include <iostream>

class Add : public CommandManager
{
public:
	Add(DataManager& dataManager) :
		 CommandManager(CommandType::Command_Add, dataManager)
	{ }

	OutputParameter Command(InputParameter inputParameter) override
	{
		try {
			_CheckInputdataValid(&inputParameter);
		} catch (invalid_argument& e){
			std::cout << " ERROR:Input ���� �߻�!!! " << e.what() << std::endl;
			return OutputParameter();
		}

		getDataManager()->setData(inputParameter.inputEmployee);
		return OutputParameter();
	}

private:
	void _CheckInputdataValid(InputParameter* inputParameter)
	{
		if (inputParameter->option1 != Option1::Option1_None) throw invalid_argument("ADD: option1 must be None");
		if (inputParameter->option2 != Option2::Option2_None) throw invalid_argument("ADD: option2 must be None");
		if (inputParameter->column != Column::Column_None) throw invalid_argument("ADD: column must be None");
		if (inputParameter->destColumn != Column::Column_None) throw invalid_argument("ADD: destcolumn must be None");

		Employee* employee = &inputParameter->inputEmployee;
		if (employee->GetEmployeeNum() > 99999999 || employee->GetEmployeeNum() < 0)
			throw invalid_argument("Add: EmployeeNum�� 8�ڸ� �������� �մϴ�.");
		if ((employee->GetName()._firstName.size() + employee->GetName()._lastName.size()) > 15)
			throw invalid_argument("Add: Name�� ������� 15�����Դϴ�.");
		for (auto name : employee->GetName()._firstName){
			if (name < 'A' || name > 'Z') throw invalid_argument("Add: FirstName�� ������ ���� �빮���Դϴ�.");
		}
		for (auto name : employee->GetName()._lastName) {
			if (name < 'A' || name > 'Z') throw invalid_argument("Add: Last Name�� ������ ���� �빮���Դϴ�.");
		}
		if (employee->GetPhoneNum()._middleNum > 9999 || employee->GetPhoneNum()._middleNum < 0)
			throw invalid_argument("Add: Middle PhoneNum�� 4�ڸ� �������� �մϴ�.");
		if (employee->GetPhoneNum()._lastNum > 9999 || employee->GetPhoneNum()._lastNum < 0)
			throw invalid_argument("Add: Last PhoneNum�� 4�ڸ� �������� �մϴ�.");
		if (employee->GetBirthDay()._year > 9999 || employee->GetBirthDay()._year < 0) throw invalid_argument("Add: Birthday�� Year�� 4�ڸ� �������� �մϴ�.");
		if (employee->GetBirthDay()._month > 12 || employee->GetBirthDay()._month < 1) throw invalid_argument("Add: Birthday�� Month�� 1~12 ������ ���ڿ��� �մϴ�.");
		if (employee->GetBirthDay()._day > 31 || employee->GetBirthDay()._day < 1) throw invalid_argument("Add: Birthday�� Day�� 1~31 ������ ���ڿ��� �մϴ�.");
	}
};