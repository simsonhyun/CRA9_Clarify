#include "CommonType.h"
#include "CommandManager.h"

class AbstractSearchPolicy {
public:
	virtual bool searchByPolicy(Option2 option, const Employee& input, const Employee& data) const = 0;
};

class EmployeeNumSearchPolicy : public AbstractSearchPolicy {
public:
	virtual bool searchByPolicy(Option2 option, const Employee& input, const Employee& data) const override {
		if (option == Option2::Option2_None && input.GetEmployeeNum() != data.GetEmployeeNum()) return false;
		return true;
	}
};

class NameSearchPolicy : public AbstractSearchPolicy {
public:
	virtual bool searchByPolicy(Option2 option, const Employee& input, const Employee& data) const override {
		if (option == Option2::Option2_Name_f && input.GetName()._firstName != data.GetName()._firstName) return false;
		if (option == Option2::Option2_Name_l && input.GetName()._lastName != data.GetName()._lastName) return false;
		if (option == Option2::Option2_None && input.GetName() != data.GetName()) return false;
		return true;
	}
};

class CareerLevelSearchPolicy : public AbstractSearchPolicy {
public:
	virtual bool searchByPolicy(Option2 option, const Employee& input, const Employee& data) const override {
		if (option == Option2::Option2_None && input.GetCl() != data.GetCl()) return false;
		return true;
	}
};

class PhoneNumSearchPolicy : public AbstractSearchPolicy {
public:
	virtual bool searchByPolicy(Option2 option, const Employee& input, const Employee& data) const override {
		if (option == Option2::Option2_PhoneNum_l && input.GetPhoneNum()._lastNum != data.GetPhoneNum()._lastNum) return false;
		if (option == Option2::Option2_PhoneNum_m && input.GetPhoneNum()._middleNum != data.GetPhoneNum()._middleNum) return false;
		if (option == Option2::Option2_None && input.GetPhoneNum() != data.GetPhoneNum()) return false;
		return true;
	}
};

class BirthDaySearchPolicy : public AbstractSearchPolicy {
public:
	virtual bool searchByPolicy(Option2 option, const Employee& input, const Employee& data) const override {
		if (option == Option2::Option2_BirthDay_y && input.GetBirthDay()._year != data.GetBirthDay()._year) return false;
		if (option == Option2::Option2_BirthDay_m && input.GetBirthDay()._month != data.GetBirthDay()._month) return false;
		if (option == Option2::Option2_BirthDay_d && input.GetBirthDay()._day != data.GetBirthDay()._day) return false;
		if (option == Option2::Option2_None && input.GetBirthDay() != data.GetBirthDay()) return false;
		return true;
	}
};

class CertiSearchPolicy : public AbstractSearchPolicy {
public:
	virtual bool searchByPolicy(Option2 option, const Employee& input, const Employee& data) const override {
		if (option == Option2::Option2_None && input.GetCerti() != data.GetCerti()) return false;
		return true;
	}
};

class Search : public CommandManager {
public:
	Search(DataManager& dataManager) : CommandManager(dataManager) {
		searchPolicy[static_cast<int>(Column::Column_employeeNum)] = new EmployeeNumSearchPolicy();
		searchPolicy[static_cast<int>(Column::Column_Name)] = new NameSearchPolicy();
		searchPolicy[static_cast<int>(Column::Column_CareerLevel)] = new CareerLevelSearchPolicy();
		searchPolicy[static_cast<int>(Column::Column_PhoneNum)] = new PhoneNumSearchPolicy();
		searchPolicy[static_cast<int>(Column::Column_BirthDay)] = new BirthDaySearchPolicy();
		searchPolicy[static_cast<int>(Column::Column_Certi)] = new CertiSearchPolicy();
	}

	vector<Employee> Command(InputParameter input) override {
		vector<Employee> result;
		for (const Employee& datum : getDataManager()->getData()) {
			if (searchPolicy[static_cast<int>(input.column)]->searchByPolicy(input.option2, input.inputEmployee, datum))
				result.push_back(datum);
			if (input.option1 == Option1::Option1_p && result.size() >= 5) return result;
		}
		return result;
	}

public:
	static const int MAX_COLUMN = 6;
private:
	AbstractSearchPolicy* searchPolicy[MAX_COLUMN];
};