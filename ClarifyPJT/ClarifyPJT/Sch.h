#include "CommonType.h"
#include "CommandManager.h"

class AbstractSearchPolicy {
public:
	virtual vector<Employee> searchByPolicyWithPrint(InputParameter input, DataManager& data) const = 0;
	virtual int searchByPolicyWithoutPrint(InputParameter input, DataManager& data) const = 0;
};

class EmployeeNumSearchPolicy : public AbstractSearchPolicy {
public:
	virtual vector<Employee> searchByPolicyWithPrint(InputParameter input, DataManager& data) const override {
		vector<Employee> searchList;
		for (const Employee& datum : data.getData()) {
			if (input.inputEmployee.GetEmployeeNum() == datum.GetEmployeeNum())
				searchList.push_back(datum);
		}
		return searchList;
	}
	virtual int searchByPolicyWithoutPrint(InputParameter input, DataManager& data) const override {
		int searchList = 0;
		for (const Employee& datum : data.getData()) {
			if (input.inputEmployee.GetEmployeeNum() == datum.GetEmployeeNum())
				searchList++;
		}
		return searchList;
	}
};

class NameSearchPolicy : public AbstractSearchPolicy {
public:
	virtual vector<Employee> searchByPolicyWithPrint(InputParameter input, DataManager& data) const override {
		vector<Employee> searchList;
		return searchList;
	}
	virtual int searchByPolicyWithoutPrint(InputParameter input, DataManager& data) const override {
		return 0;
	}
};

class CareerLevelSearchPolicy : public AbstractSearchPolicy {
public:
	virtual vector<Employee> searchByPolicyWithPrint(InputParameter input, DataManager& data) const override {
		vector<Employee> searchList;
		for (const Employee& datum : data.getData()) {
			if (input.inputEmployee.GetCl() == datum.GetCl())
				searchList.push_back(datum);
		}
		return searchList;
	}
	virtual int searchByPolicyWithoutPrint(InputParameter input, DataManager& data) const override {
		int searchList = 0;
		for (const Employee& datum : data.getData()) {
			if (input.inputEmployee.GetCl() == datum.GetCl())
				searchList++;
		}
		return searchList;
	}
};

class PhoneNumSearchPolicy : public AbstractSearchPolicy {
public:
	virtual vector<Employee> searchByPolicyWithPrint(InputParameter input, DataManager& data) const override {
		vector<Employee> searchList;
		return searchList;
	}
	virtual int searchByPolicyWithoutPrint(InputParameter input, DataManager& data) const override {
		return 0;
	}
};

class BirthDaySearchPolicy : public AbstractSearchPolicy {
public:
	virtual vector<Employee> searchByPolicyWithPrint(InputParameter input, DataManager& data) const override {
		vector<Employee> searchList;
		return searchList;
	}
	virtual int searchByPolicyWithoutPrint(InputParameter input, DataManager& data) const override {
		return 0;
	}
};

class CertiSearchPolicy : public AbstractSearchPolicy {
public:
	virtual vector<Employee> searchByPolicyWithPrint(InputParameter input, DataManager& data) const override {
		vector<Employee> searchList;
		for (const Employee& datum : data.getData()) {
			if (input.inputEmployee.GetCerti() == datum.GetCerti())
				searchList.push_back(datum);
		}
		return searchList;
	}
	virtual int searchByPolicyWithoutPrint(InputParameter input, DataManager& data) const override {
		int searchList = 0;
		for (const Employee& datum : data.getData()) {
			if (input.inputEmployee.GetCerti() == datum.GetCerti())
				searchList++;
		}
		return searchList;
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

	vector<Employee> searchWithPrint(InputParameter input) {
		return searchPolicy[static_cast<int>(input.column)]->searchByPolicyWithPrint(input, *getDataManager());
	}
	int searchWithoutPrint(InputParameter input) {
		return searchPolicy[static_cast<int>(input.column)]->searchByPolicyWithoutPrint(input, *getDataManager());
	}

public:
	static const int MAX_COLUMN = 6;
private:
	AbstractSearchPolicy* searchPolicy[MAX_COLUMN];
};