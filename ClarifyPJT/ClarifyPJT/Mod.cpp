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

vector<Employee> Mod::ModNotOption1(InputParameter targetEmployee) {
	DataManager* pdataManager = getDataManager();
	vector<Employee> TargetEmployees;
	vector<int> idxChangeEmployees;
	vector<Employee> aEmployees = pdataManager->getData();
	vector<Employee>* pEmployees = pdataManager->getPointerData();

	int sameCnt = 0;
	Column targetColumn = targetEmployee.column;
	for (int EmployeeIndex = 0; EmployeeIndex < aEmployees.size(); EmployeeIndex++) {
		if (paFindModDatabyColumn[static_cast<int>(targetColumn)]->findmodDataByPolicy(targetEmployee, aEmployees[EmployeeIndex])) {
			sameCnt++;
			TargetEmployees.push_back(aEmployees[EmployeeIndex]);//값 변경되기전 백터를 return에 넣어줌
			idxChangeEmployees.push_back(EmployeeIndex);
		}
	}
	Column changeTargetColumn = targetEmployee.destColumn;
	for (int EmployeeIndex = 0; EmployeeIndex < idxChangeEmployees.size(); EmployeeIndex++) {
		paFindModDatabyColumn[static_cast<int>(changeTargetColumn)]->ChangeModDataByPolicy(targetEmployee, TargetEmployees[EmployeeIndex]);
		pEmployees->erase(pEmployees->begin() + idxChangeEmployees[EmployeeIndex]);
		pEmployees->insert(pEmployees->begin() + idxChangeEmployees[EmployeeIndex], TargetEmployees[EmployeeIndex]);

	}

	return TargetEmployees;
}
vector<Employee> Mod::ModOption1(InputParameter targetEmployee) {
	DataManager* pdataManager = getDataManager();
	vector<Employee> aEmployees = pdataManager->getData();
	vector<Employee>* pEmployees = pdataManager->getPointerData();
	vector<Employee> TargetEmployees;
	vector<Employee> PrintEmployees;
	vector<int> idxChangeEmployees;

	Column targetColumn = targetEmployee.column;
	for (int EmployeeIndex = 0; EmployeeIndex < aEmployees.size(); EmployeeIndex++) {
		if (paFindModDatabyColumn[static_cast<int>(targetColumn)]->findmodDataByPolicy(targetEmployee, aEmployees[EmployeeIndex])) {
			TargetEmployees.push_back(aEmployees[EmployeeIndex]);
			idxChangeEmployees.push_back(EmployeeIndex);
		}
	}

	for (int BeforeChangeDataIdx = 0; BeforeChangeDataIdx < TargetEmployees.size(); BeforeChangeDataIdx++) {
		if (PrintEmployees.size() >= 5) break;
		PrintEmployees.push_back(TargetEmployees[BeforeChangeDataIdx]);
	}
	Column changeTargetColumn = targetEmployee.destColumn;
	for (int EmployeeIndex = 0; EmployeeIndex < idxChangeEmployees.size(); EmployeeIndex++) {
		paFindModDatabyColumn[static_cast<int>(changeTargetColumn)]->ChangeModDataByPolicy(targetEmployee, TargetEmployees[EmployeeIndex]);
		pEmployees->erase(pEmployees->begin() + idxChangeEmployees[EmployeeIndex]);
		pEmployees->insert(pEmployees->begin() + idxChangeEmployees[EmployeeIndex], TargetEmployees[EmployeeIndex]);
	}

	return PrintEmployees;
}