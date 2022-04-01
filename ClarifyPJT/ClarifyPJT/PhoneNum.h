#pragma once

class PhoneNum
{
private:
public:
	PhoneNum() :
		_middleNum(0),
		_lastNum(0)
	{ }

	PhoneNum(const int middleNum, const int lastNum) :
		_middleNum(middleNum),
		_lastNum(lastNum)
	{ }

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

	bool operator==(const PhoneNum& r)
	{
		return (_middleNum == r._middleNum) && (_lastNum == r._lastNum);
	}

	bool operator!=(const PhoneNum& r)
	{
		return (_middleNum != r._middleNum) || (_lastNum != r._lastNum);
	}

private:
public:
	int _middleNum;
	int _lastNum;
	
};