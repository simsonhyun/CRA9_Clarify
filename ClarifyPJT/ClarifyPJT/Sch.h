#include "CommonType.h"
#include "CommandManager.h"

class AbstractSearchPolicy {
public:
	virtual OutputParameter searchByPolicy(InputParameter input, const vector<Employee>& data) const = 0;

	static const int MAX_EMPLOYEE_COUNT = 1500000;
	static const int MAX_PRINT_SIZE = 5;
};

class EmployeeNumSearchPolicy : public AbstractSearchPolicy {
public:
	virtual OutputParameter searchByPolicy(InputParameter input, const vector<Employee>& data) const override {
		OutputParameter result;
		result.resultCount = 0;
		for (const Employee& datum : data) {
			if (input.option2 == Option2::Option2_None && input.inputEmployee.GetEmployeeNum() == datum.GetEmployeeNum()) {
				result.resultVector.push_back(datum);
				result.resultCount++;
				return result;
			}
		}
		return result;
	}
};

class NameSearchPolicy : public AbstractSearchPolicy {
public:
	virtual OutputParameter searchByPolicy(InputParameter input, const vector<Employee>& data) const override {
		OutputParameter result;
		if (input.option1 == Option1::Option1_p) result.resultVector.reserve(MAX_EMPLOYEE_COUNT);
		else result.resultCount = 0;

		for (const Employee& datum : data) {
			if (input.option2 == Option2::Option2_Name_f && input.inputEmployee.GetName()._firstName == datum.GetName()._firstName) {
				if (input.option1 == Option1::Option1_p) result.resultVector.push_back(datum);
				else result.resultCount++;
			}
			if (input.option2 == Option2::Option2_Name_l && input.inputEmployee.GetName()._lastName == datum.GetName()._lastName) {
				if (input.option1 == Option1::Option1_p) result.resultVector.push_back(datum);
				else result.resultCount++;
			}
			if (input.option2 == Option2::Option2_None && input.inputEmployee.GetName() == datum.GetName()) {
				if (input.option1 == Option1::Option1_p) result.resultVector.push_back(datum);
				else result.resultCount++;
			}
			if (input.option1 == Option1::Option1_p && result.resultVector.size() >= MAX_PRINT_SIZE) return result;
		}
		return result;
	}
};

class CareerLevelSearchPolicy : public AbstractSearchPolicy {
public:
	virtual OutputParameter searchByPolicy(InputParameter input, const vector<Employee>& data) const override {
		OutputParameter result;
		if (input.option1 == Option1::Option1_p) result.resultVector.reserve(MAX_EMPLOYEE_COUNT);
		else result.resultCount = 0;

		for (const Employee& datum : data) {
			if (input.option2 == Option2::Option2_None && input.inputEmployee.GetCl() == datum.GetCl()) {
				if (input.option1 == Option1::Option1_p) result.resultVector.push_back(datum);
				else result.resultCount++;
			}
			if (input.option1 == Option1::Option1_p && result.resultVector.size() >= MAX_PRINT_SIZE) return result;
		}
		return result;
	}
};

class PhoneNumSearchPolicy : public AbstractSearchPolicy {
public:
	virtual OutputParameter searchByPolicy(InputParameter input, const vector<Employee>& data) const override {
		OutputParameter result;
		if (input.option1 == Option1::Option1_p) result.resultVector.reserve(MAX_EMPLOYEE_COUNT);
		else result.resultCount = 0;

		for (const Employee& datum : data) {
			if (input.option2 == Option2::Option2_PhoneNum_l && input.inputEmployee.GetPhoneNum()._lastNum == datum.GetPhoneNum()._lastNum) {
				if (input.option1 == Option1::Option1_p) result.resultVector.push_back(datum);
				else result.resultCount++;
			}
			if (input.option2 == Option2::Option2_PhoneNum_m && input.inputEmployee.GetPhoneNum()._middleNum == datum.GetPhoneNum()._middleNum) {
				if (input.option1 == Option1::Option1_p) result.resultVector.push_back(datum);
				else result.resultCount++;
			}
			if (input.option2 == Option2::Option2_None && input.inputEmployee.GetPhoneNum() == datum.GetPhoneNum()) {
				if (input.option1 == Option1::Option1_p) result.resultVector.push_back(datum);
				else result.resultCount++;
			}
			if (input.option1 == Option1::Option1_p && result.resultVector.size() >= MAX_PRINT_SIZE) return result;
		}
		return result;
	}
};

class BirthDaySearchPolicy : public AbstractSearchPolicy {
public:
	virtual OutputParameter searchByPolicy(InputParameter input, const vector<Employee>& data) const override {
		OutputParameter result;
		if (input.option1 == Option1::Option1_p) result.resultVector.reserve(MAX_EMPLOYEE_COUNT);
		else result.resultCount = 0;

		for (const Employee& datum : data) {
			if (input.option2 == Option2::Option2_BirthDay_y && input.inputEmployee.GetBirthDay()._year == datum.GetBirthDay()._year) {
				if (input.option1 == Option1::Option1_p) result.resultVector.push_back(datum);
				else result.resultCount++;
			}
			if (input.option2 == Option2::Option2_BirthDay_m && input.inputEmployee.GetBirthDay()._month == datum.GetBirthDay()._month) {
				if (input.option1 == Option1::Option1_p) result.resultVector.push_back(datum);
				else result.resultCount++;
			}
			if (input.option2 == Option2::Option2_BirthDay_d && input.inputEmployee.GetBirthDay()._day == datum.GetBirthDay()._day) {
				if (input.option1 == Option1::Option1_p) result.resultVector.push_back(datum);
				else result.resultCount++;
			}
			if (input.option2 == Option2::Option2_None && input.inputEmployee.GetBirthDay() == datum.GetBirthDay()) {
				if (input.option1 == Option1::Option1_p) result.resultVector.push_back(datum);
				else result.resultCount++;
			}
			if (input.option1 == Option1::Option1_p && result.resultVector.size() >= MAX_PRINT_SIZE) return result;
		}
		return result;
	}
};

class CertiSearchPolicy : public AbstractSearchPolicy {
public:
	virtual OutputParameter searchByPolicy(InputParameter input, const vector<Employee>& data) const override {
		OutputParameter result;
		if (input.option1 == Option1::Option1_p) result.resultVector.reserve(MAX_EMPLOYEE_COUNT);
		else result.resultCount = 0;

		for (const Employee& datum : data) {
			if (input.option2 == Option2::Option2_None && input.inputEmployee.GetCerti() == datum.GetCerti()) {
				if (input.option1 == Option1::Option1_p) result.resultVector.push_back(datum);
				else result.resultCount++;
			}
			if (input.option1 == Option1::Option1_p && result.resultVector.size() >= MAX_PRINT_SIZE) return result;
		}
		return result;
	}
};

class Search : public CommandManager {
public:
	Search(DataManager& dataManager) : CommandManager(CommandType::Command_Sch, dataManager), _dataManager(dataManager) {
		searchPolicy[static_cast<int>(Column::Column_employeeNum)] = new EmployeeNumSearchPolicy();
		searchPolicy[static_cast<int>(Column::Column_Name)] = new NameSearchPolicy();
		searchPolicy[static_cast<int>(Column::Column_CareerLevel)] = new CareerLevelSearchPolicy();
		searchPolicy[static_cast<int>(Column::Column_PhoneNum)] = new PhoneNumSearchPolicy();
		searchPolicy[static_cast<int>(Column::Column_BirthDay)] = new BirthDaySearchPolicy();
		searchPolicy[static_cast<int>(Column::Column_Certi)] = new CertiSearchPolicy();
	}

	OutputParameter Command(InputParameter input) override {
		return searchPolicy[static_cast<int>(input.column)]->searchByPolicy(input, _dataManager.getData());
	}

public:
	static const int MAX_COLUMN = 6;
private:
	AbstractSearchPolicy* searchPolicy[MAX_COLUMN];
	DataManager& _dataManager;
};