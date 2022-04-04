#pragma once
#pragma once
#include "CommandManager.h"
#include"CommonType.h"
class AbstractModifyPolicy {
public:
	virtual bool findmodDataByPolicy(InputParameter targetEmployee, Employee& aEmployee) const = 0;
	virtual void ChangeModDataByPolicy(InputParameter targetEmployee, Employee& aEmployee) const = 0;
};

class EmployeeNumModPolicy :public AbstractModifyPolicy {
public:
	virtual bool findmodDataByPolicy(InputParameter targetEmployee, Employee& aEmployee) const override;
	virtual void ChangeModDataByPolicy(InputParameter targetEmployee, Employee& aEmployee) const override;
};
class NameModPolicy :public AbstractModifyPolicy {
public:
	virtual bool findmodDataByPolicy(InputParameter targetEmployee, Employee& aEmployee) const override;
	virtual void ChangeModDataByPolicy(InputParameter targetEmployee, Employee& aEmployee) const override;
};
class CareerLevelModPolicy :public AbstractModifyPolicy {
public:
	virtual bool findmodDataByPolicy(InputParameter targetEmployee, Employee& aEmployee) const override;
	virtual void ChangeModDataByPolicy(InputParameter targetEmployee, Employee& aEmployee) const override;
};
class PhoneNumModPolicy :public AbstractModifyPolicy {
public:
	virtual bool findmodDataByPolicy(InputParameter targetEmployee, Employee& aEmployee) const override;
	virtual void ChangeModDataByPolicy(InputParameter targetEmployee, Employee& aEmployee) const override;
};
class BirthDayModPolicy :public AbstractModifyPolicy {
public:
	virtual bool findmodDataByPolicy(InputParameter targetEmployee, Employee& aEmployee) const override;
	virtual void ChangeModDataByPolicy(InputParameter targetEmployee, Employee& aEmployee) const override;
};
class CertiModPolicy :public AbstractModifyPolicy {
public:
	virtual bool findmodDataByPolicy(InputParameter targetEmployee, Employee& aEmployee) const override;
	virtual void ChangeModDataByPolicy(InputParameter targetEmployee, Employee& aEmployee) const override;
};

class Mod : public CommandManager {
public:
	Mod(DataManager& dataManager) :CommandManager(dataManager) {
		paFindModDatabyColumn[static_cast<int>(Column::Column_employeeNum)] = new EmployeeNumModPolicy();
		paFindModDatabyColumn[static_cast<int>(Column::Column_Name)] = new NameModPolicy();
		paFindModDatabyColumn[static_cast<int>(Column::Column_CareerLevel)] = new CareerLevelModPolicy();
		paFindModDatabyColumn[static_cast<int>(Column::Column_PhoneNum)] = new PhoneNumModPolicy();
		paFindModDatabyColumn[static_cast<int>(Column::Column_BirthDay)] = new BirthDayModPolicy();
		paFindModDatabyColumn[static_cast<int>(Column::Column_Certi)] = new CertiModPolicy();

	}

	vector<Employee> ModNotOption1(InputParameter targetEmployee);
	vector<Employee> ModOption1(InputParameter targetEmployee);
private:

public:
	static const int MAX_COLUMN = 6;
private:
	AbstractModifyPolicy* paFindModDatabyColumn[MAX_COLUMN];
};