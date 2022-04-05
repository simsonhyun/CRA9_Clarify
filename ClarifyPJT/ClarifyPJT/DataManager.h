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
	}

	vector<Employee>& getData(void)
	{
		return _employees;
	}

	int getSize(void)
	{
		return (int)_employees.size();
	}

	void setData(const Employee& employee)
	{
		_employees.push_back(employee);
	}

private:

public:
	static const int MAX_EMPLOYEE_COUNT = 1500000;

private:
	vector<Employee> _employees;
};