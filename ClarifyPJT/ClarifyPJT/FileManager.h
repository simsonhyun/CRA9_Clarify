#pragma once
#include <string>
#include <fstream>
using namespace std;

class FileManager
{
public:
	const void InputOpen(const string& inputText)
	{
		inputFile.open(inputText);
	}

	const void OutputOpen(const string& outputText)
	{
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
		outputFile << inputString;
	}

private:


public:
private:
	ifstream inputFile;
	ofstream outputFile;

};