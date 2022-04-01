#pragma once
#include <vector>
#include <algorithm>
#include "Employee.h"

using namespace std;

class DataManager
{
public:
	DataManager()
	{
		_employees.reserve(MAX_EMPLOYEE_COUNT);
		bIsSorted = false;
	}

	vector<Employee>& getData(void)
	{
		if (!bIsSorted)
		{
			sort(_employees.begin(), _employees.end(), DataManager::compare);
			bIsSorted = true;
		}
		return _employees;
	}

	int getSize(void)
	{
		return _employees.size();
	}

	void setData(const Employee& employee)
	{
		bIsSorted = false;
		_employees.push_back(employee);
	}

	static bool compare(Employee a, Employee b)
	{
		if (((a.GetEmployeeNum() <= Employee::MAX_EMPLOYEE_NUM) && (b.GetEmployeeNum() <= Employee::MAX_EMPLOYEE_NUM))
				|| ((a.GetEmployeeNum() >= Employee::MIN_EMPLOYEE_NUM) && (b.GetEmployeeNum() >= Employee::MIN_EMPLOYEE_NUM)))
			return a.GetEmployeeNum() < b.GetEmployeeNum();

		return a.GetEmployeeNum() > b.GetEmployeeNum();
	}

private:

public:
	static const int MAX_EMPLOYEE_COUNT = 1500000;

private:
	vector<Employee> _employees;
	bool bIsSorted;
};