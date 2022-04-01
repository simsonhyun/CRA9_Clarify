#include "Del.h"

vector<Employee>
EmployeeNumDeletePolicy::deleteByPolicyWithPrint(InputParameter input, DataManager& data) const {
	vector<Employee> deleteList;
	vector<Employee>& employees = data.getData();
	for (vector<Employee>::iterator aEmployee = employees.begin(); aEmployee != employees.end(); ) {
		if (input.inputEmployee.GetEmployeeNum() == aEmployee->GetEmployeeNum()) {
			deleteList.push_back(*aEmployee);
			aEmployee = employees.erase(aEmployee);
			continue;
		}
		aEmployee++;
	}
	return deleteList;
}

int
EmployeeNumDeletePolicy::deleteByPolicyWithoutPrint(InputParameter input, DataManager& data) const {
	int deleteList = 0;
	vector<Employee>& employees = data.getData();
	for (vector<Employee>::iterator aEmployee = employees.begin(); aEmployee != employees.end(); ) {
		if (input.inputEmployee.GetEmployeeNum() == aEmployee->GetEmployeeNum()) {
			deleteList++;
			aEmployee = employees.erase(aEmployee);
			continue;
		}
		aEmployee++;
	}
	return deleteList;
}



vector<Employee>
NameDeletePolicy::deleteByPolicyWithPrint(InputParameter input, DataManager& data) const {
	vector<Employee> deleteList;
	vector<Employee>& employees = data.getData();
	for (vector<Employee>::iterator aEmployee = employees.begin(); aEmployee != employees.end(); ) {
		if (input.inputEmployee.GetName() == aEmployee->GetName()) {
			deleteList.push_back(*aEmployee);
			aEmployee = employees.erase(aEmployee);
			continue;
		}
		aEmployee++;
	}
	return deleteList;
}

int
NameDeletePolicy::deleteByPolicyWithoutPrint(InputParameter input, DataManager& data) const {
	int deleteList = 0;
	vector<Employee>& employees = data.getData();
	for (vector<Employee>::iterator aEmployee = employees.begin(); aEmployee != employees.end(); ) {
		if (input.inputEmployee.GetName() == aEmployee->GetName()) {
			deleteList++;
			aEmployee = employees.erase(aEmployee);
			continue;
		}
		aEmployee++;
	}
	return deleteList;
}



vector<Employee>
CareerLevelDeletePolicy::deleteByPolicyWithPrint(InputParameter input, DataManager& data) const {
	vector<Employee> deleteList;
	vector<Employee>& employees = data.getData();
	for (vector<Employee>::iterator aEmployee = employees.begin(); aEmployee != employees.end(); ) {
		if (input.inputEmployee.GetCl() == aEmployee->GetCl()) {
			deleteList.push_back(*aEmployee);
			aEmployee = employees.erase(aEmployee);
			continue;
		}
		aEmployee++;
	}
	return deleteList;
}

int
CareerLevelDeletePolicy::deleteByPolicyWithoutPrint(InputParameter input, DataManager& data) const {
	int deleteList = 0;
	vector<Employee>& employees = data.getData();
	for (vector<Employee>::iterator aEmployee = employees.begin(); aEmployee != employees.end(); ) {
		if (input.inputEmployee.GetCl() == aEmployee->GetCl()) {
			deleteList++;
			aEmployee = employees.erase(aEmployee);
			continue;
		}
		aEmployee++;
	}
	return deleteList;
}



vector<Employee>
PhoneNumDeletePolicy::deleteByPolicyWithPrint(InputParameter input, DataManager& data) const {
	vector<Employee> deleteList;
	vector<Employee>& employees = data.getData();
	for (vector<Employee>::iterator aEmployee = employees.begin(); aEmployee != employees.end(); ) {
		if (input.inputEmployee.GetPhoneNum() == aEmployee->GetPhoneNum()) {
			deleteList.push_back(*aEmployee);
			aEmployee = employees.erase(aEmployee);
			continue;
		}
		aEmployee++;
	}
	return deleteList;
}

int
PhoneNumDeletePolicy::deleteByPolicyWithoutPrint(InputParameter input, DataManager& data) const {
	int deleteList = 0;
	vector<Employee>& employees = data.getData();
	for (vector<Employee>::iterator aEmployee = employees.begin(); aEmployee != employees.end(); ) {
		if (input.inputEmployee.GetPhoneNum() == aEmployee->GetPhoneNum()) {
			deleteList++;
			aEmployee = employees.erase(aEmployee);
			continue;
		}
		aEmployee++;
	}
	return deleteList;
}



vector<Employee>
BirthDayDeletePolicy::deleteByPolicyWithPrint(InputParameter input, DataManager& data) const {
	vector<Employee> deleteList;
	vector<Employee>& employees = data.getData();
	for (vector<Employee>::iterator aEmployee = employees.begin(); aEmployee != employees.end(); ) {
		if (input.inputEmployee.GetBirthDay() == aEmployee->GetBirthDay()) {
			deleteList.push_back(*aEmployee);
			aEmployee = employees.erase(aEmployee);
			continue;
		}
		aEmployee++;
	}
	return deleteList;
}

int
BirthDayDeletePolicy::deleteByPolicyWithoutPrint(InputParameter input, DataManager& data) const {
	int deleteList = 0;
	vector<Employee>& employees = data.getData();
	for (vector<Employee>::iterator aEmployee = employees.begin(); aEmployee != employees.end(); ) {
		if (input.inputEmployee.GetBirthDay() == aEmployee->GetBirthDay()) {
			deleteList++;
			aEmployee = employees.erase(aEmployee);
			continue;
		}
		aEmployee++;
	}
	return deleteList;
}



vector<Employee>
CertiDeletePolicy::deleteByPolicyWithPrint(InputParameter input, DataManager& data) const {
	vector<Employee> deleteList;
	vector<Employee>& employees = data.getData();
	for (vector<Employee>::iterator aEmployee = employees.begin(); aEmployee != employees.end(); ) {
		if (input.inputEmployee.GetCerti() == aEmployee->GetCerti()) {
			deleteList.push_back(*aEmployee);
			aEmployee = employees.erase(aEmployee);
			continue;
		}
		aEmployee++;
	}
	return deleteList;
}

int
CertiDeletePolicy::deleteByPolicyWithoutPrint(InputParameter input, DataManager& data) const {
	int deleteList = 0;
	vector<Employee>& employees = data.getData();
	for (vector<Employee>::iterator aEmployee = employees.begin(); aEmployee != employees.end(); ) {
		if (input.inputEmployee.GetCerti() == aEmployee->GetCerti()) {
			deleteList++;
			aEmployee = employees.erase(aEmployee);
			continue;
		}
		aEmployee++;
	}
	return deleteList;
}



vector<Employee>
Del::deleteWithPrint(InputParameter input) {
	return deletePolicy[static_cast<int>(input.column)]->deleteByPolicyWithPrint(input, *getDataManager());
}

int
Del::searchWithoutPrint(InputParameter input) {
	return deletePolicy[static_cast<int>(input.column)]->deleteByPolicyWithoutPrint(input, *getDataManager());
}