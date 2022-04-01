#pragma once
#include <string>
#include "BirthDay.h"
#include "Name.h"
#include "PhoneNum.h"
using namespace std;

enum class CareerLevel
{
	CareerLevel_None = 0,
	CareerLevel_1,
	CareerLevel_2,
	CareerLevel_3,
	CareerLevel_4,
};

enum class Certi
{
	Certi_None = 0, 
	Certi_ADV,
	Certi_PRO,
	Certi_EX,
};

class Employee
{
public:
	Employee() :
		_employeeNum(0),
		_name({"", ""}),
		_cl(CareerLevel::CareerLevel_None),
		_phoneNum({0, 0}),
		_birthDay({0, 0, 0}),
		_certi(Certi::Certi_None)
	{ }

	Employee(const int& employeeNum, const Name& name, const CareerLevel& cl, const PhoneNum& phoneNum, const BirthDay& birthDay, const Certi& certi) :
		_employeeNum(employeeNum),
		_name(name),
		_cl(cl),
		_phoneNum(phoneNum),
		_birthDay(birthDay),
		_certi(certi)
	{ }

	int GetEmployeeNum() const
	{
		return _employeeNum;
	}
	Name GetName() const
	{
		return _name;
	}

	CareerLevel GetCl() const
	{
		return _cl;
	}

	PhoneNum GetPhoneNum() const
	{
		return _phoneNum;
	}

	BirthDay GetBirthDay() const
	{
		return _birthDay;
	}

	Certi GetCerti() const
	{
		return _certi;
	}

	void SetData(const int& employeeNum, const Name& name, const CareerLevel& cl, const PhoneNum& phoneNum, const BirthDay& birthDay, const Certi& certi)
	{
		_employeeNum = employeeNum;
		_name = name;
		_cl = cl;
		_phoneNum = phoneNum;
		_birthDay = birthDay;
		_certi = certi;
	}

private:
	

public:
private:
	int _employeeNum;
	Name _name;
	CareerLevel _cl;
	PhoneNum _phoneNum;
	BirthDay _birthDay;
	Certi _certi;

};
