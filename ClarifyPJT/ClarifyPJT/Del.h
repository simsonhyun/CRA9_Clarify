#pragma once

#include "CommandManager.h"
#include "CommonType.h"

class AbstractDeletePolicy {
public:
	virtual vector<Employee> deleteByPolicyWithPrint(InputParameter input, DataManager& data) const = 0;
	virtual int deleteByPolicyWithoutPrint(InputParameter input, DataManager& data) const = 0;
};

class EmployeeNumDeletePolicy : public AbstractDeletePolicy {
public:
	virtual vector<Employee> deleteByPolicyWithPrint(InputParameter input, DataManager& data) const override;
	virtual int deleteByPolicyWithoutPrint(InputParameter input, DataManager& data) const override;
};

class NameDeletePolicy : public AbstractDeletePolicy {
public:
	virtual vector<Employee> deleteByPolicyWithPrint(InputParameter input, DataManager& data) const;
	virtual int deleteByPolicyWithoutPrint(InputParameter input, DataManager& data) const;
};

class CareerLevelDeletePolicy : public AbstractDeletePolicy {
public:
	virtual vector<Employee> deleteByPolicyWithPrint(InputParameter input, DataManager& data) const override;
	virtual int deleteByPolicyWithoutPrint(InputParameter input, DataManager& data) const override;
};

class PhoneNumDeletePolicy : public AbstractDeletePolicy {
public:
	virtual vector<Employee> deleteByPolicyWithPrint(InputParameter input, DataManager& data) const override;
	virtual int deleteByPolicyWithoutPrint(InputParameter input, DataManager& data) const override;
};

class BirthDayDeletePolicy : public AbstractDeletePolicy {
public:
	virtual vector<Employee> deleteByPolicyWithPrint(InputParameter input, DataManager& data) const override;
	virtual int deleteByPolicyWithoutPrint(InputParameter input, DataManager& data) const override;
};

class CertiDeletePolicy : public AbstractDeletePolicy {
public:
	virtual vector<Employee> deleteByPolicyWithPrint(InputParameter input, DataManager& data) const override;
	virtual int deleteByPolicyWithoutPrint(InputParameter input, DataManager& data) const override;
};

class Del : public CommandManager {
public:
	Del(DataManager& dataManager) : CommandManager(dataManager) {
		deletePolicy[static_cast<int>(Column::Column_employeeNum)] = new EmployeeNumDeletePolicy();
		deletePolicy[static_cast<int>(Column::Column_Name)] = new NameDeletePolicy();
		deletePolicy[static_cast<int>(Column::Column_CareerLevel)] = new CareerLevelDeletePolicy();
		deletePolicy[static_cast<int>(Column::Column_PhoneNum)] = new PhoneNumDeletePolicy();
		deletePolicy[static_cast<int>(Column::Column_BirthDay)] = new BirthDayDeletePolicy();
		deletePolicy[static_cast<int>(Column::Column_Certi)] = new CertiDeletePolicy();
	}

	vector<Employee> deleteWithPrint(InputParameter input);
	int searchWithoutPrint(InputParameter input);

private:


public:
	static const int MAX_COLUMN = 6;

private:
	AbstractDeletePolicy* deletePolicy[MAX_COLUMN];
};