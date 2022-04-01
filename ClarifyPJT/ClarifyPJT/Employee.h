#pragma once
#include <string>
using namespace std;

enum CareerLevel
{
	CareerLevel_None = 0,
	CareerLevel_1,
	CareerLevel_2,
	CareerLevel_3,
	CareerLevel_4,
};

enum Certi
{
	Certi_None = 0, 
	Certi_ADV,
	Certi_PRO,
	Certi_EX,
};

typedef struct PhoneNum
{
	int _middleNum;
	int _lastNum;

	PhoneNum()
	{

	}

	PhoneNum(const int middleNum, const int lastNum)
	{
		_middleNum = middleNum;
		_lastNum = lastNum;
	}

	PhoneNum& operator=(const PhoneNum& r)
	{
		if (this == &r)
		{
			return *this;
		}

		_middleNum = r._middleNum;
		_lastNum = r._lastNum;
		return *this;
	}
} PhoneNum;

typedef struct BirthDay
{
	int _year;
	int _month;
	int _day;

	BirthDay()
	{

	}

	BirthDay(const int year, const int month, const int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	BirthDay& operator=(const BirthDay& r)
	{
		if (this == &r)
		{
			return *this;
		}

		_year = r._year;
		_month = r._month;
		_day = r._day;
		return *this;
	}
} BirthDay;

class Employee
{
public:
	Employee()
	{

	}

	Employee(const int& employeeNum, const string& name, const CareerLevel& cl, const PhoneNum& phoneNum, const BirthDay& birthDay, const Certi& certi) :
		_employeeNum(employeeNum),
		_name(name),
		_cl(cl),
		_phoneNum(phoneNum),
		_birthDay(birthDay),
		_certi(certi)
	{}

	int GetEmployeeNum()
	{
		return _employeeNum;
	}
	string GetName()
	{
		return _name;
	}
	CareerLevel GetCl()
	{
		return _cl;
	}
	PhoneNum GetPhoneNum()
	{
		return _phoneNum;
	}
	BirthDay GetBirthDay()
	{
		return _birthDay;
	}
	Certi GetCerti()
	{
		return _certi;
	}

	void SetData(const int& employeeNum, const string& name, const CareerLevel& cl, const PhoneNum& phoneNum, const BirthDay& birthDay, const Certi& certi)
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
	static const int MIN_EMPLOYEE_NUM = 69000000;
	static const int MAX_EMPLOYEE_NUM = 21999999;
	static const int MIN_EMPLOYEE_BIRTH = 1969;
	static const int MAX_EMPLOYEE_BIRTH = 2021;
private:
	int _employeeNum;
	string _name;
	CareerLevel _cl;
	PhoneNum _phoneNum;
	BirthDay _birthDay;
	Certi _certi;

};