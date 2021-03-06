#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class FileManager
{
public:
	const void InputOpen(const string& inputText)
	{
		try
		{
			ifstream inputTest(inputText);
			if (!inputTest.is_open())
			{
				throw exception("input file not exists");
			}
		}
		catch (exception e)
		{
			cout << e.what() << endl;
		}

		inputFile.open(inputText);
	}

	const void OutputOpen(const string& outputText)
	{
		try
		{
			ofstream outputTest(outputText, ios::trunc);
			if (!outputTest.is_open())
			{
				throw exception("output file fail");
			}
		}
		catch (exception e)
		{
			cout << e.what() << endl;
		}

		outputFile.open(outputText);
	}

	const void InputClose(void)
	{
		inputFile.close();
	}

	const void OutputClose(void)
	{
		outputFile.close();
	}

	const string ReadOneLine(void)
	{
		string outputString;

		if (inputFile.is_open())
		{
			if (inputFile.eof())
			{
				return outputString;
			}
			
			getline(inputFile, outputString);
		}

		return outputString;
	}

	const void WriteString(const string& inputString)
	{
		outputFile.write(inputString.c_str(), inputString.length());
	}

	bool compareFiles(const std::string& p1, const std::string& p2) 
	{
		std::ifstream f1(p1, std::ifstream::binary | std::ifstream::ate);
		std::ifstream f2(p2, std::ifstream::binary | std::ifstream::ate);

		if (f1.fail() || f2.fail()) {
			return false; //file problem
		}

		if (f1.tellg() != f2.tellg()) {
			return false; //size mismatch
		}

		//seek back to beginning and use std::equal to compare contents
		f1.seekg(0, std::ifstream::beg);
		f2.seekg(0, std::ifstream::beg);
		return std::equal(std::istreambuf_iterator<char>(f1.rdbuf()),
			std::istreambuf_iterator<char>(),
			std::istreambuf_iterator<char>(f2.rdbuf()));
	}

private:

public:
private:
	ifstream inputFile;
	ofstream outputFile;

};