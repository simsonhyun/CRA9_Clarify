#include "Mod.h"


bool EmployeeNumModPolicy::findmodDataByPolicy(InputParameter targetEmployee, Employee& aEmployee) const {
	if (aEmployee.GetEmployeeNum() == targetEmployee.inputEmployee.GetEmployeeNum()) return true;
	return false;
}
void EmployeeNumModPolicy::ChangeModDataByPolicy(InputParameter targetEmployee, Employee& aEmployee) const {
	aEmployee.SetEmployeeNum(targetEmployee.inputDestEmployee.GetEmployeeNum());
}
bool NameModPolicy::findmodDataByPolicy(InputParameter targetEmployee, Employee& aEmployee) const {
	if ((targetEmployee.option2 == Option2::Option2_Name_f) && (aEmployee.GetName()._firstName == targetEmployee.inputEmployee.GetName()._firstName)) return true;
	if ((targetEmployee.option2 == Option2::Option2_Name_l) && (aEmployee.GetName()._lastName == targetEmployee.inputEmployee.GetName()._lastName)) return true;
	if ((targetEmployee.option2 == Option2::Option2_None) && (aEmployee.GetName() == targetEmployee.inputEmployee.GetName())) return true;
	return false;
}
void NameModPolicy::ChangeModDataByPolicy(InputParameter targetEmployee, Employee& aEmployee) const {
	aEmployee.SetName(targetEmployee.inputDestEmployee.GetName());
}
bool CareerLevelModPolicy::findmodDataByPolicy(InputParameter targetEmployee, Employee& aEmployee) const {
	if (aEmployee.GetCl() == targetEmployee.inputEmployee.GetCl()) return true;
	return false;
}
void CareerLevelModPolicy::ChangeModDataByPolicy(InputParameter targetEmployee, Employee& aEmployee) const {
	aEmployee.SetCl(targetEmployee.inputDestEmployee.GetCl());
}
bool PhoneNumModPolicy::findmodDataByPolicy(InputParameter targetEmployee, Employee& aEmployee) const {
	if ((targetEmployee.option2 == Option2::Option2_PhoneNum_m) && (aEmployee.GetPhoneNum()._middleNum == targetEmployee.inputEmployee.GetPhoneNum()._middleNum)) return true;
	if ((targetEmployee.option2 == Option2::Option2_PhoneNum_l) && (aEmployee.GetPhoneNum()._lastNum == targetEmployee.inputEmployee.GetPhoneNum()._lastNum)) return true;
	if ((targetEmployee.option2 == Option2::Option2_None) && (aEmployee.GetPhoneNum() == targetEmployee.inputEmployee.GetPhoneNum())) return true;
	return false;
}
void PhoneNumModPolicy::ChangeModDataByPolicy(InputParameter targetEmployee, Employee& aEmployee) const {
	aEmployee.SetPhoneNum(targetEmployee.inputDestEmployee.GetPhoneNum());
}
bool BirthDayModPolicy::findmodDataByPolicy(InputParameter targetEmployee, Employee& aEmployee) const {
	if ((targetEmployee.option2 == Option2::Option2_BirthDay_y) && (aEmployee.GetBirthDay()._year == targetEmployee.inputEmployee.GetBirthDay()._year)) return true;
	if ((targetEmployee.option2 == Option2::Option2_BirthDay_m) && (aEmployee.GetBirthDay()._month == targetEmployee.inputEmployee.GetBirthDay()._month)) return true;
	if ((targetEmployee.option2 == Option2::Option2_BirthDay_d) && (aEmployee.GetBirthDay()._day == targetEmployee.inputEmployee.GetBirthDay()._day)) return true;
	if ((targetEmployee.option2 == Option2::Option2_None) && (aEmployee.GetBirthDay() == targetEmployee.inputEmployee.GetBirthDay())) return true;
	return false;
}
void BirthDayModPolicy::ChangeModDataByPolicy(InputParameter targetEmployee, Employee& aEmployee) const {
	aEmployee.SetBirthDay(targetEmployee.inputDestEmployee.GetBirthDay());
}
bool CertiModPolicy::findmodDataByPolicy(InputParameter targetEmployee, Employee& aEmployee) const {
	if (aEmployee.GetCerti() == targetEmployee.inputEmployee.GetCerti()) return true;
	return false;
}
void CertiModPolicy::ChangeModDataByPolicy(InputParameter targetEmployee, Employee& aEmployee) const {
	aEmployee.SetCerti(targetEmployee.inputDestEmployee.GetCerti());
}

OutputParameter Mod::Command(InputParameter targetEmployee) {
	DataManager* pdataManager = getDataManager();
	vector<Employee> &aEmployeesData = pdataManager->getData();
	vector<Employee> PrintEmployees;
	vector<Employee> TargetEmployees;

	Column targetColumn = targetEmployee.column;
	Column changeTargetColumn = targetEmployee.destColumn;
	for (int EmployeeIndex = 0; EmployeeIndex < aEmployeesData.size(); EmployeeIndex++) {
		if (paFindModDatabyColumn[static_cast<int>(targetColumn)]->findmodDataByPolicy(targetEmployee, aEmployeesData[EmployeeIndex])) {
			if ((targetEmployee.option1 == Option1::Option1_p) && (PrintEmployees.size() < 5)) PrintEmployees.push_back(aEmployeesData[EmployeeIndex]);
			paFindModDatabyColumn[static_cast<int>(changeTargetColumn)]->ChangeModDataByPolicy(targetEmployee, aEmployeesData[EmployeeIndex]);
			TargetEmployees.push_back(aEmployeesData[EmployeeIndex]);
		}
	}
	// if (targetEmployee.option1 == Option1::Option1_p) return PrintEmployees;
	// return TargetEmployees;
	return OutputParameter();
}