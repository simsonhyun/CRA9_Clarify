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
			std::cout << " ERROR:Input 예외 발생!!! " << e.what() << std::endl;
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
			throw invalid_argument("Add: EmployeeNum는 8자리 정수여야 합니다.");
		if ((employee->GetName()._firstName.size() + employee->GetName()._lastName.size()) > 15)
			throw invalid_argument("Add: Name의 사이즈는 15까지입니다.");
		for (auto name : employee->GetName()._firstName){
			if (name < 'A' || name > 'Z') throw invalid_argument("Add: FirstName의 형식은 영어 대문자입니다.");
		}
		for (auto name : employee->GetName()._lastName) {
			if (name < 'A' || name > 'Z') throw invalid_argument("Add: Last Name의 형식은 영어 대문자입니다.");
		}
		if (employee->GetPhoneNum()._middleNum > 9999 || employee->GetPhoneNum()._middleNum < 0)
			throw invalid_argument("Add: Middle PhoneNum은 4자리 정수여야 합니다.");
		if (employee->GetPhoneNum()._lastNum > 9999 || employee->GetPhoneNum()._lastNum < 0)
			throw invalid_argument("Add: Last PhoneNum은 4자리 정수여야 합니다.");
		if (employee->GetBirthDay()._year > 9999 || employee->GetBirthDay()._year < 0) throw invalid_argument("Add: Birthday의 Year는 4자리 정수여야 합니다.");
		if (employee->GetBirthDay()._month > 12 || employee->GetBirthDay()._month < 1) throw invalid_argument("Add: Birthday의 Month는 1~12 범위의 숫자여야 합니다.");
		if (employee->GetBirthDay()._day > 31 || employee->GetBirthDay()._day < 1) throw invalid_argument("Add: Birthday의 Day는 1~31 범위의 숫자여야 합니다.");
	}
};