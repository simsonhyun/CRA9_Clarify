#include "Del.h"

bool
EmployeeNumDeletePolicy::deleteByPolicy(InputParameter input, Employee& aEmployee) const {
	if ((input.option2 == Option2::Option2_None) && (input.inputEmployee.GetEmployeeNum() == aEmployee.GetEmployeeNum())) return true;
	return false;
}

bool
NameDeletePolicy::deleteByPolicy(InputParameter input, Employee& aEmployee) const {
	if ((input.option2 == Option2::Option2_None) && (input.inputEmployee.GetName() == aEmployee.GetName())) return true;
	if ((input.option2 == Option2::Option2_Name_f) && (input.inputEmployee.GetName()._firstName == aEmployee.GetName()._firstName)) return true;
	if ((input.option2 == Option2::Option2_Name_l) && (input.inputEmployee.GetName()._lastName == aEmployee.GetName()._lastName)) return true;
	return false;
}

bool
CareerLevelDeletePolicy::deleteByPolicy(InputParameter input, Employee& aEmployee) const {
	if ((input.option2 == Option2::Option2_None) && (input.inputEmployee.GetCl() == aEmployee.GetCl())) return true;
	return false;
}

bool
PhoneNumDeletePolicy::deleteByPolicy(InputParameter input, Employee& aEmployee) const {
	if ((input.option2 == Option2::Option2_None) && (input.inputEmployee.GetPhoneNum() == aEmployee.GetPhoneNum())) return true;
	if ((input.option2 == Option2::Option2_PhoneNum_m) && (input.inputEmployee.GetPhoneNum()._middleNum == aEmployee.GetPhoneNum()._middleNum)) return true;
	if ((input.option2 == Option2::Option2_PhoneNum_l) && (input.inputEmployee.GetPhoneNum()._lastNum == aEmployee.GetPhoneNum()._lastNum)) return true;
	return false;
}

bool
BirthDayDeletePolicy::deleteByPolicy(InputParameter input, Employee& aEmployee) const {
	if ((input.option2 == Option2::Option2_None) && (input.inputEmployee.GetBirthDay() == aEmployee.GetBirthDay())) return true;
	if ((input.option2 == Option2::Option2_BirthDay_y) && (input.inputEmployee.GetBirthDay()._year == aEmployee.GetBirthDay()._year)) return true;
	if ((input.option2 == Option2::Option2_BirthDay_m) && (input.inputEmployee.GetBirthDay()._month == aEmployee.GetBirthDay()._month)) return true;
	if ((input.option2 == Option2::Option2_BirthDay_d) && (input.inputEmployee.GetBirthDay()._day == aEmployee.GetBirthDay()._day)) return true;
	return false;
}

bool
CertiDeletePolicy::deleteByPolicy(InputParameter input, Employee& aEmployee) const {
	if ((input.option2 == Option2::Option2_None) && (input.inputEmployee.GetCerti() == aEmployee.GetCerti())) return true;
	return false;
}

vector<Employee>
Del::deleteEmployeeInfo(InputParameter input) {
	vector<Employee> deleteList;
	deleteList.reserve(getDataManager()->MAX_EMPLOYEE_COUNT);
	vector<Employee>& employees = getDataManager()->getData();
	for (vector<Employee>::iterator aEmployee = employees.begin(); aEmployee != employees.end(); ) {
		if (deletePolicy[static_cast<int>(input.column)]->deleteByPolicy(input, *aEmployee)) {
			deleteList.push_back(*aEmployee);
			aEmployee = employees.erase(aEmployee);
			continue;
		}
		aEmployee++;
	}
	return deleteList;
}
