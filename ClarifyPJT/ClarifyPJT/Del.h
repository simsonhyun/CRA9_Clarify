#pragma once

#include "CommandManager.h"
#include "CommonType.h"

class AbstractDeletePolicy {
public:
	virtual bool deleteByPolicy(InputParameter input, Employee& aEmployee) const = 0;
};

class EmployeeNumDeletePolicy : public AbstractDeletePolicy {
public:
	virtual bool deleteByPolicy(InputParameter input, Employee& aEmployee) const override;
};

class NameDeletePolicy : public AbstractDeletePolicy {
public:
	virtual bool deleteByPolicy(InputParameter input, Employee& aEmployee) const override;
};

class CareerLevelDeletePolicy : public AbstractDeletePolicy {
public:
	virtual bool deleteByPolicy(InputParameter input, Employee& aEmployee) const override;
};

class PhoneNumDeletePolicy : public AbstractDeletePolicy {
public:
	virtual bool deleteByPolicy(InputParameter input, Employee& aEmployee) const override;
};

class BirthDayDeletePolicy : public AbstractDeletePolicy {
public:
	virtual bool deleteByPolicy(InputParameter input, Employee& aEmployee) const override;
};

class CertiDeletePolicy : public AbstractDeletePolicy {
public:
	virtual bool deleteByPolicy(InputParameter input, Employee& aEmployee) const override;
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

	vector<Employee> Command(InputParameter input) override;

private:


public:
	static const int MAX_COLUMN = 6;

private:
	AbstractDeletePolicy* deletePolicy[MAX_COLUMN];
};