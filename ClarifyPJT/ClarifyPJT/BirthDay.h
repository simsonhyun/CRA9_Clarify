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

	bool operator==(const BirthDay& r)
	{
		return (_year == r._year) && (_month == r._month) && (_day == r._day);
	}

	bool operator!=(const BirthDay& r)
	{
		return (_year != r._year) || (_month != r._month) || (_day != r._day);
	}

	friend bool operator==(const BirthDay& B1, const BirthDay& B2)
	{
		return (B1._year == B2._year) && (B1._month == B2._month) && (B1._day == B2._day);
	}

private:
public:
	int _year;
	int _month;
	int _day;
		
};