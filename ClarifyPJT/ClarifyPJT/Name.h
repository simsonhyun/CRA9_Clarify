#pragma once
#include <string>
using namespace std;

class Name
{
private:
public:
	Name() :
		_firstName(""),
		_lastName("")
	{ }

	Name(const string& firstName, const string& lastName) :
		_firstName(firstName),
		_lastName(lastName)
	{ }

	Name& operator=(const Name& r)
	{
		if (this == &r)
		{
			return *this;
		}

		_firstName = r._firstName;
		_lastName = r._lastName;
		return *this;
	}

	bool operator==(const Name& r)
	{
		return (_firstName == r._firstName) && (_lastName == r._lastName);
	}

private:
public:
	string _firstName;
	string _lastName;

};