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

class AbstractFastDelete {
public:
	virtual vector<Employee> deleteFast(InputParameter input, DataManager* dataManager) const = 0;
};

class FastDelete : public AbstractFastDelete {
public:
	FastDelete(AbstractDeletePolicy* deletePolicy) {
		_deletePolicy = deletePolicy;
	}

	virtual vector<Employee> deleteFast(InputParameter input, DataManager* dataManager) const override;

private:
	AbstractDeletePolicy* _deletePolicy;
};

class NotFastDelete : public AbstractFastDelete {
public:
	NotFastDelete(AbstractDeletePolicy* deletePolicy) {
		_deletePolicy = deletePolicy;
	}

	virtual vector<Employee> deleteFast(InputParameter input, DataManager* dataManager) const override;

private:
	AbstractDeletePolicy* _deletePolicy;
};

class Del : public CommandManager {
public:
	Del(DataManager& dataManager) : CommandManager(CommandType::Command_Del, dataManager) {
		_deleteFast[static_cast<int>(Column::Column_employeeNum)] = new FastDelete(new EmployeeNumDeletePolicy());
		_deleteFast[static_cast<int>(Column::Column_Name)] = new NotFastDelete(new NameDeletePolicy());
		_deleteFast[static_cast<int>(Column::Column_CareerLevel)] = new NotFastDelete(new CareerLevelDeletePolicy());
		_deleteFast[static_cast<int>(Column::Column_PhoneNum)] = new NotFastDelete(new PhoneNumDeletePolicy());
		_deleteFast[static_cast<int>(Column::Column_BirthDay)] = new NotFastDelete(new BirthDayDeletePolicy());
		_deleteFast[static_cast<int>(Column::Column_Certi)] = new NotFastDelete(new CertiDeletePolicy());
	}

	vector<Employee> Command(InputParameter input) override;

private:


public:
	static const int MAX_COLUMN = 6;

private:
	AbstractFastDelete* _deleteFast[MAX_COLUMN];
};