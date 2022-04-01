#pragma once

class BirthDay
{
private:
public:
	BirthDay() :
		_year(0),
		_month(0),
		_day(0)
	{ }

	BirthDay(const int year, const int month, const int day) :
		_year(year),
		_month(month),
		_day(day)
	{ }

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

private:
public:
	int _year;
	int _month;
	int _day;
		
};