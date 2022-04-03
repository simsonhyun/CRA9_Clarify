#pragma once
#pragma once
#include "CommandManager.h"
#include"CommonType.h"
class Mod : public CommandManager {
public:
	Mod(DataManager& dataManager) :CommandManager(dataManager) {}

	vector<Employee> ModNotOption1(InputParameter targetEmployee) {
		DataManager* pdataManager = getDataManager();
		vector<Employee> TargetEmployees;
		vector<int> idxChangeEmployees;
		vector<Employee> aEmployees = pdataManager->getData();
		vector<Employee>* pEmployees = pdataManager->getPointerData();

		int sameCnt = 0;
		Column targetColumn = targetEmployee.column;
		for (int i = 0; i < aEmployees.size(); i++) {
			switch (targetColumn) {
			case Column::Column_employeeNum:
				if (aEmployees[i].GetEmployeeNum() == targetEmployee.inputEmployee.GetEmployeeNum()) {
					sameCnt++;
					TargetEmployees.push_back(aEmployees[i]);//값 변경되기전 백터를 return에 넣어줌
					idxChangeEmployees.push_back(i);
				}
				break;
			case Column::Column_Name:
				if (targetEmployee.option2 == Option2::Option2_Name_f) {
					if (aEmployees[i].GetName()._firstName == targetEmployee.inputEmployee.GetName()._firstName) {
						sameCnt++;
						TargetEmployees.push_back(aEmployees[i]);
						idxChangeEmployees.push_back(i);
					}
				}
				else if (targetEmployee.option2 == Option2::Option2_Name_l) {
					if (aEmployees[i].GetName()._lastName == targetEmployee.inputEmployee.GetName()._lastName) {
						sameCnt++;
						TargetEmployees.push_back(aEmployees[i]);
						idxChangeEmployees.push_back(i);
					}
				}
				else {
					if (aEmployees[i].GetName() == targetEmployee.inputEmployee.GetName()) {
						sameCnt++;
						TargetEmployees.push_back(aEmployees[i]);
						idxChangeEmployees.push_back(i);
					}
				}
				break;
			case Column::Column_CareerLevel:
				if (aEmployees[i].GetCl() == targetEmployee.inputEmployee.GetCl()) {
					sameCnt++;
					TargetEmployees.push_back(aEmployees[i]);
					idxChangeEmployees.push_back(i);
				}
				break;
			case Column::Column_PhoneNum:
				if (targetEmployee.option2 == Option2::Option2_PhoneNum_m) {
					if (aEmployees[i].GetPhoneNum()._middleNum == targetEmployee.inputEmployee.GetPhoneNum()._middleNum) {
						sameCnt++;
						TargetEmployees.push_back(aEmployees[i]);
						idxChangeEmployees.push_back(i);
					}
				}
				else if (targetEmployee.option2 == Option2::Option2_PhoneNum_l) {
					if (aEmployees[i].GetPhoneNum()._lastNum == targetEmployee.inputEmployee.GetPhoneNum()._lastNum) {
						sameCnt++;
						TargetEmployees.push_back(aEmployees[i]);
						idxChangeEmployees.push_back(i);
					}
				}
				else {
					if (aEmployees[i].GetPhoneNum() == targetEmployee.inputEmployee.GetPhoneNum()) {
						sameCnt++;
						TargetEmployees.push_back(aEmployees[i]);
						idxChangeEmployees.push_back(i);
					}
				}
				break;
			case Column::Column_BirthDay:
				if (targetEmployee.option2 == Option2::Option2_BirthDay_y) {
					if (aEmployees[i].GetBirthDay()._year == targetEmployee.inputEmployee.GetBirthDay()._year) {
						sameCnt++;
						TargetEmployees.push_back(aEmployees[i]);
						idxChangeEmployees.push_back(i);
					}
				}
				else if (targetEmployee.option2 == Option2::Option2_BirthDay_m) {
					if (aEmployees[i].GetBirthDay()._month == targetEmployee.inputEmployee.GetBirthDay()._month) {
						sameCnt++;
						TargetEmployees.push_back(aEmployees[i]);
						idxChangeEmployees.push_back(i);
					}
				}
				else if (targetEmployee.option2 == Option2::Option2_BirthDay_d) {
					if (aEmployees[i].GetBirthDay()._day == targetEmployee.inputEmployee.GetBirthDay()._day) {
						sameCnt++;
						TargetEmployees.push_back(aEmployees[i]);
						idxChangeEmployees.push_back(i);
					}
				}
				else {
					if (aEmployees[i].GetBirthDay() == targetEmployee.inputEmployee.GetBirthDay()) {
						sameCnt++;
						TargetEmployees.push_back(aEmployees[i]);
						idxChangeEmployees.push_back(i);
					}
				}
				break;
			case Column::Column_Certi:
				if (aEmployees[i].GetCerti() == targetEmployee.inputEmployee.GetCerti()) {
					sameCnt++;
					TargetEmployees.push_back(aEmployees[i]);
					idxChangeEmployees.push_back(i);
				}
				break;
			}
		}
		Column changeTargetColumn = targetEmployee.destColumn;
		for (int i = 0; i < idxChangeEmployees.size(); i++) {
			switch (changeTargetColumn) {
			case Column::Column_employeeNum:
				TargetEmployees[i].SetEmployeeNum(targetEmployee.inputDestEmployee.GetEmployeeNum());
				break;
			case Column::Column_Name:
				TargetEmployees[i].SetName(targetEmployee.inputDestEmployee.GetName());
				break;
			case Column::Column_CareerLevel:
				TargetEmployees[i].SetCl(targetEmployee.inputDestEmployee.GetCl());
				break;
			case Column::Column_PhoneNum:
				TargetEmployees[i].SetPhoneNum(targetEmployee.inputDestEmployee.GetPhoneNum());
				break;
			case Column::Column_BirthDay:
				TargetEmployees[i].SetBirthDay(targetEmployee.inputDestEmployee.GetBirthDay());
				break;
			case Column::Column_Certi:
				TargetEmployees[i].SetCerti(targetEmployee.inputDestEmployee.GetCerti());
				break;
			}
			pEmployees->erase(pEmployees->begin() + idxChangeEmployees[i]);
			pEmployees->insert(pEmployees->begin() + idxChangeEmployees[i], TargetEmployees[i]);

		}
		
		return TargetEmployees;
	}
	vector<Employee> ModOption1(InputParameter targetEmployee) {
		DataManager* pdataManager = getDataManager();
		vector<Employee> aEmployees = pdataManager->getData();
		vector<Employee>* pEmployees = pdataManager->getPointerData();
		vector<Employee> TargetEmployees;
		vector<Employee> PrintEmployees;
		vector<int> idxChangeEmployees;

		Column targetColumn = targetEmployee.column;
		for (int i = 0; i < aEmployees.size(); i++) {
			switch (targetColumn) {
			case Column::Column_employeeNum:
				if (aEmployees[i].GetEmployeeNum() == targetEmployee.inputEmployee.GetEmployeeNum()) {
					TargetEmployees.push_back(aEmployees[i]);
					idxChangeEmployees.push_back(i);
				}
				break;
			case Column::Column_Name:
				if (((targetEmployee.option2 == Option2::Option2_Name_f) &&
					(aEmployees[i].GetName()._firstName == targetEmployee.inputEmployee.GetName()._firstName)) ||
					((targetEmployee.option2 == Option2::Option2_Name_l) &&
					(aEmployees[i].GetName()._lastName == targetEmployee.inputEmployee.GetName()._lastName))) {
						TargetEmployees.push_back(aEmployees[i]);
						idxChangeEmployees.push_back(i);
				}
				else {
					if (aEmployees[i].GetName() == targetEmployee.inputEmployee.GetName()) {
						TargetEmployees.push_back(aEmployees[i]);
						idxChangeEmployees.push_back(i);
					}
				}
				break;
			case Column::Column_CareerLevel:
				if (aEmployees[i].GetCl() == targetEmployee.inputEmployee.GetCl()) {
					TargetEmployees.push_back(aEmployees[i]);
					idxChangeEmployees.push_back(i);
				}
				break;
			case Column::Column_PhoneNum:
				if (((targetEmployee.option2 == Option2::Option2_PhoneNum_m) &&
					(aEmployees[i].GetPhoneNum()._middleNum == targetEmployee.inputEmployee.GetPhoneNum()._middleNum)) ||
					((targetEmployee.option2 == Option2::Option2_PhoneNum_l) &&
					(aEmployees[i].GetPhoneNum()._lastNum == targetEmployee.inputEmployee.GetPhoneNum()._lastNum))){
					TargetEmployees.push_back(aEmployees[i]);
					idxChangeEmployees.push_back(i);
				}
				else {
					if (aEmployees[i].GetPhoneNum() == targetEmployee.inputEmployee.GetPhoneNum()) {
						TargetEmployees.push_back(aEmployees[i]);
						idxChangeEmployees.push_back(i);
					}
				}
				break;
			case Column::Column_BirthDay:
				if (((targetEmployee.option2 == Option2::Option2_BirthDay_y) &&
					(aEmployees[i].GetBirthDay()._year == targetEmployee.inputEmployee.GetBirthDay()._year)) ||
					((targetEmployee.option2 == Option2::Option2_BirthDay_m) &&
					(aEmployees[i].GetBirthDay()._month == targetEmployee.inputEmployee.GetBirthDay()._month)) ||
					((targetEmployee.option2 == Option2::Option2_BirthDay_d) &&
					(aEmployees[i].GetBirthDay()._day == targetEmployee.inputEmployee.GetBirthDay()._day))){
					
					TargetEmployees.push_back(aEmployees[i]);
					idxChangeEmployees.push_back(i);
				}
				else {
					if (aEmployees[i].GetBirthDay() == targetEmployee.inputEmployee.GetBirthDay()) {
						TargetEmployees.push_back(aEmployees[i]);
						idxChangeEmployees.push_back(i);
					}
				}
				break;
			case Column::Column_Certi:
				if (aEmployees[i].GetCerti() == targetEmployee.inputEmployee.GetCerti()) {
					TargetEmployees.push_back(aEmployees[i]);
					idxChangeEmployees.push_back(i);
				}
				break;
			}
		}

		for (int i = 0; i < TargetEmployees.size(); i++) {
			if (PrintEmployees.size() >= 5) break;
			PrintEmployees.push_back(TargetEmployees[i]);
		}
		Column changeTargetColumn = targetEmployee.destColumn;
		for (int i = 0; i < idxChangeEmployees.size(); i++) {
			switch (changeTargetColumn) {
			case Column::Column_employeeNum:
				TargetEmployees[i].SetEmployeeNum(targetEmployee.inputDestEmployee.GetEmployeeNum());
				break;
			case Column::Column_Name:
				TargetEmployees[i].SetName(targetEmployee.inputDestEmployee.GetName());
				break;
			case Column::Column_CareerLevel:
				TargetEmployees[i].SetCl(targetEmployee.inputDestEmployee.GetCl());
				break;
			case Column::Column_PhoneNum:
				TargetEmployees[i].SetPhoneNum(targetEmployee.inputDestEmployee.GetPhoneNum());
				break;
			case Column::Column_BirthDay:
				TargetEmployees[i].SetBirthDay(targetEmployee.inputDestEmployee.GetBirthDay());
				break;
			case Column::Column_Certi:
				TargetEmployees[i].SetCerti(targetEmployee.inputDestEmployee.GetCerti());
				break;
			}
			pEmployees->erase(pEmployees->begin() + idxChangeEmployees[i]);
			pEmployees->insert(pEmployees->begin() + idxChangeEmployees[i], TargetEmployees[i]);

		}

		return PrintEmployees;
	}
private:
};