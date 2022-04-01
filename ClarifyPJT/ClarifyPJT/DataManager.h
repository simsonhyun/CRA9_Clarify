#pragma once
#include <vector>
#include "Employee.h"
using namespace std;

class DataManager
{
public:
	DataManager()
	{
		_employees.reserve(MAX_EMPLOYEE_COUNT);
	}

	const vector<Employee>& getData(void)
	{
		return _employees;
	}
	void setData(const Employee& employee)
	{
		_employees.push_back(employee);
	}
	int getSize(void)
	{
		return _employees.size();
	}

private:



public:
	static const int MAX_EMPLOYEE_COUNT = 1500000;

private:
	vector<Employee> _employees;


};