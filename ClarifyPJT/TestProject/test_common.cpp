#include "pch.h"
#include "../ClarifyPJT/CommandManager.h"
#include "../ClarifyPJT/Employee.h"
#include "../ClarifyPJT/CommandParser.cpp"
#include "../ClarifyPJT/PrintManager.h"
#include "../ClarifyPJT/FileManager.h"
#include "../ClarifyPJT/Add.h"


TEST(TestDataManager, CheckCommandManagerConstructor)
{
	DataManager dataManager = DataManager();
	CommandManager* commandManager = new Add(dataManager);
	//Add add = Add(dataManager);

	EXPECT_EQ(&dataManager, commandManager->getDataManager());
}

TEST(TestEmployee, CheckEmployeeData)
{
	PhoneNum phoneNum;
	phoneNum._middleNum = 100;
	phoneNum._lastNum = 200;

	BirthDay birthday;
	birthday._year = 2020;
	birthday._month = 12;
	birthday._day = 30;

	Employee testEmployee(100, Name("TestName", ""), CareerLevel::CareerLevel_1, phoneNum, birthday, Certi::Certi_ADV);

	EXPECT_EQ(testEmployee.GetEmployeeNum(), 100);
	EXPECT_EQ(testEmployee.GetName()._firstName, "TestName");
	EXPECT_EQ(testEmployee.GetCl(), CareerLevel::CareerLevel_1);
	EXPECT_EQ(testEmployee.GetPhoneNum()._middleNum, phoneNum._middleNum);
	EXPECT_EQ(testEmployee.GetBirthDay()._year, 2020);
	EXPECT_EQ(testEmployee.GetCerti(), Certi::Certi_ADV);

}

TEST(TestCommandParser, CheckParsing0)
{
	// ADD, , , ,17111236,VSID TVO,CL1,010-3669-1077,20120718,PRO
	CommandParser commandParser = CommandParser();
	PhoneNum phoneNum;
	phoneNum._middleNum = 3669;
	phoneNum._lastNum = 1077;

	BirthDay birthday;
	birthday._year = 2012;
	birthday._month = 07;
	birthday._day = 18;

	InputParameter inputParameter;
	inputParameter.option1 = Option1::Option1_None;
	inputParameter.option2 = Option2::Option2_None;
	inputParameter.column = Column::Column_None;
	inputParameter.inputEmployee.SetData(17111236, Name("VSID", "TVO"), CareerLevel::CareerLevel_1, phoneNum, birthday, Certi::Certi_PRO);
	
	InputParameter testParameter = commandParser.ConvertParameter("ADD, , , ,17111236,VSID TVO,CL1,010-3669-1077,20120718,PRO");

	EXPECT_EQ(testParameter.option1, inputParameter.option1);
	EXPECT_EQ(testParameter.option2, inputParameter.option2);
	EXPECT_EQ(testParameter.column, inputParameter.column);
	EXPECT_EQ(testParameter.inputEmployee.GetName()._firstName, inputParameter.inputEmployee.GetName()._firstName);
	EXPECT_EQ(testParameter.inputEmployee.GetName()._lastName, inputParameter.inputEmployee.GetName()._lastName);
}

TEST(TestCommandParser, CheckParsing1)
{
	// SCH, , , ,employeeNum,79110836
	CommandParser commandParser = CommandParser();

	InputParameter inputParameter;
	inputParameter.option1 = Option1::Option1_None;
	inputParameter.option2 = Option2::Option2_None;
	inputParameter.column = Column::Column_employeeNum;
	inputParameter.inputEmployee.SetData(79110836, Name("", ""), CareerLevel::CareerLevel_None, PhoneNum(0, 0), BirthDay(0, 0, 0), Certi::Certi_None);

	InputParameter testParameter = commandParser.ConvertParameter("SCH, , , ,employeeNum,79110836");

	EXPECT_EQ(testParameter.option1, inputParameter.option1);
	EXPECT_EQ(testParameter.option2, inputParameter.option2);
	EXPECT_EQ(testParameter.column, inputParameter.column);
	EXPECT_EQ(testParameter.inputEmployee.GetName()._firstName, inputParameter.inputEmployee.GetName()._firstName);
	EXPECT_EQ(testParameter.inputEmployee.GetName()._lastName, inputParameter.inputEmployee.GetName()._lastName);
}

TEST(TestCommandParser, CheckParsing2)
{
	// SCH,-p,-d, ,birthday,04
	CommandParser commandParser = CommandParser();

	InputParameter inputParameter;
	inputParameter.option1 = Option1::Option1_p;
	inputParameter.option2 = Option2::Option2_BirthDay_d;
	inputParameter.column = Column::Column_BirthDay;
	inputParameter.inputEmployee.SetData(0, Name("", ""), CareerLevel::CareerLevel_None, PhoneNum(0, 0), BirthDay(0, 0, 04), Certi::Certi_None);

	InputParameter testParameter = commandParser.ConvertParameter("SCH,-p,-d, ,birthday,04");

	EXPECT_EQ(testParameter.option1, inputParameter.option1);
	EXPECT_EQ(testParameter.option2, inputParameter.option2);
	EXPECT_EQ(testParameter.column, inputParameter.column);
	EXPECT_EQ(testParameter.inputEmployee.GetBirthDay()._day, inputParameter.inputEmployee.GetBirthDay()._day);
}

TEST(TestCommandParser, CheckParsing3)
{
	// MOD,-p, , ,name,FB NTAWR,birthday,20050520
	CommandParser commandParser = CommandParser();

	InputParameter inputParameter;
	inputParameter.option1 = Option1::Option1_p;
	inputParameter.option2 = Option2::Option2_None;
	inputParameter.column = Column::Column_Name;
	inputParameter.inputEmployee.SetData(0, Name("NTAWR", "FB"), CareerLevel::CareerLevel_None, PhoneNum(0, 0), BirthDay(0, 0, 0), Certi::Certi_None);
	inputParameter.inputDestEmployee.SetData(0, Name("", ""), CareerLevel::CareerLevel_None, PhoneNum(0, 0), BirthDay(2005, 05, 20), Certi::Certi_None);

	InputParameter testParameter = commandParser.ConvertParameter("MOD,-p, , ,name,FB NTAWR,birthday,20050520");

	EXPECT_EQ(testParameter.option1, inputParameter.option1);
	EXPECT_EQ(testParameter.option2, inputParameter.option2);
	EXPECT_EQ(testParameter.column, inputParameter.column);
	EXPECT_EQ(testParameter.inputEmployee.GetBirthDay()._day, inputParameter.inputEmployee.GetBirthDay()._day);
	EXPECT_EQ(testParameter.inputDestEmployee.GetBirthDay()._day, inputParameter.inputDestEmployee.GetBirthDay()._day);
}

TEST(TestPrintManager, CheckPrint0)
{
	// ADD, , , ,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV
	// ADD, , , ,02117175,TEST LDEXRI,CL4,010-2814-1699,19950704,ADV
	// input : SCH,-p,-d, ,birthday,04
	// output : SCH,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV

	string testString = "SCH,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV";
	testString += '\n';
	testString += "SCH,02117175,TEST LDEXRI,CL4,010-2814-1699,19950704,ADV";
	testString += '\n';

	PrintManager printManager = PrintManager();
	vector<Employee> inputEmployees;
	inputEmployees.push_back(Employee(2117175, Name("SBILHUT", "LDEXRI"), CareerLevel::CareerLevel_4, PhoneNum(2814, 1699), BirthDay(1995, 07, 04), Certi::Certi_ADV));
	inputEmployees.push_back(Employee(2117175, Name("TEST", "LDEXRI"), CareerLevel::CareerLevel_4, PhoneNum(2814, 1699), BirthDay(1995, 07, 04), Certi::Certi_ADV));

	OutputParameter outputParamter;
	outputParamter.resultCount = 0;
	outputParamter.resultVector = inputEmployees;

	EXPECT_EQ(printManager.Print(CommandType::Command_Sch, Option1::Option1_p, outputParamter), testString);
}

TEST(TestPrintManager, CheckPrint1)
{
	// input : SCH,-p,-d, ,birthday,04

	string testString = "SCH,NONE";
	testString += '\n';

	PrintManager printManager = PrintManager();
	vector<Employee> inputEmployees;
	// inputEmployees.push_back(Employee(2117175, Name("LDEXRI", "SBILHUT"), CareerLevel::CareerLevel_4, PhoneNum(2814, 1699), BirthDay(1995, 07, 04), Certi::Certi_ADV));
	// inputEmployees.push_back(Employee(2117175, Name("LDEXRI", "TEST"), CareerLevel::CareerLevel_4, PhoneNum(2814, 1699), BirthDay(1995, 07, 04), Certi::Certi_ADV));

	OutputParameter outputParamter;
	outputParamter.resultCount = 0;
	outputParamter.resultVector = inputEmployees;

	EXPECT_EQ(printManager.Print(CommandType::Command_Sch, Option1::Option1_p, outputParamter), testString);
}

TEST(TestPrintManager, CheckPrint2)
{
	// input : SCH, , , ,birthday,04

	string testString = "SCH,2";
	testString += '\n';

	PrintManager printManager = PrintManager();
	vector<Employee> inputEmployees;
	inputEmployees.push_back(Employee(2117175, Name("LDEXRI", "SBILHUT"), CareerLevel::CareerLevel_4, PhoneNum(2814, 1699), BirthDay(1995, 07, 04), Certi::Certi_ADV));
	inputEmployees.push_back(Employee(2117175, Name("LDEXRI", "TEST"), CareerLevel::CareerLevel_4, PhoneNum(2814, 1699), BirthDay(1995, 07, 04), Certi::Certi_ADV));

	OutputParameter outputParamter;
	outputParamter.resultCount = 0;
	outputParamter.resultVector = inputEmployees;

	EXPECT_EQ(printManager.Print(CommandType::Command_Sch, Option1::Option1_None, outputParamter), testString);
}

TEST(TestFileManager, FileInputTest)
{
	FileManager fileManager;

	fileManager.InputOpen("CommonTestFiles/InputTest.txt");

	EXPECT_EQ(fileManager.ReadOneLine(), "ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV");
	EXPECT_EQ(fileManager.ReadOneLine(), "ADD, , , ,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO");
	EXPECT_EQ(fileManager.ReadOneLine(), "ADD, , , ,18115040,TTETHU HBO,CL3,010-4581-2050,20080718,ADV");

	fileManager.InputClose();
}

TEST(TestFileManager, FileOutputTest)
{
	FileManager fileManager;

	fileManager.OutputOpen("CommonTestFiles/OutputTest.txt");

	string writeString = "ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV";
	writeString += 0xA;
	fileManager.WriteString(writeString);

	writeString = "ADD, , , ,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO";
	writeString += 0xA;
	fileManager.WriteString(writeString);

	writeString = "ADD, , , ,18115040,TTETHU HBO,CL3,010-4581-2050,20080718,ADV";
	writeString += 0xA;
	fileManager.WriteString(writeString);

	fileManager.OutputClose();




	fileManager.InputOpen("CommonTestFiles/OutputTest.txt");

	EXPECT_EQ(fileManager.ReadOneLine(), "ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV");
	EXPECT_EQ(fileManager.ReadOneLine(), "ADD, , , ,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO");
	EXPECT_EQ(fileManager.ReadOneLine(), "ADD, , , ,18115040,TTETHU HBO,CL3,010-4581-2050,20080718,ADV");

	fileManager.InputClose();
}