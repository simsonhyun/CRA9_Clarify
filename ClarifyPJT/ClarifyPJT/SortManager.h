#pragma once

class SortManager
{
public:
	void Sorting(vector<Employee> targetVector)
	{
		sort(targetVector.begin(), targetVector.end(), SortManager::_compare);
	}

private:
	static bool _compare(const Employee& a, const Employee& b)
	{
		if (((a.GetEmployeeNum() <= Employee::MAX_EMPLOYEE_NUM) && (b.GetEmployeeNum() <= Employee::MAX_EMPLOYEE_NUM))
			|| ((a.GetEmployeeNum() >= Employee::MIN_EMPLOYEE_NUM) && (b.GetEmployeeNum() >= Employee::MIN_EMPLOYEE_NUM)))
			return a.GetEmployeeNum() < b.GetEmployeeNum();

		return a.GetEmployeeNum() > b.GetEmployeeNum();
	}

};