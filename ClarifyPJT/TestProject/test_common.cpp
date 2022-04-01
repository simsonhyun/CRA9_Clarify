#include "pch.h"
#include "../ClarifyPJT/CommandManager.h"
#include "../ClarifyPJT/Employee.h"
#include "../ClarifyPJT/CommandParser.cpp"

TEST(TestDataManager, CheckCommandManagerConstructor)
{
	DataManager dataManager = DataManager();
	CommandManager commandManager = CommandManager(dataManager);
	//Add add = Add(dataManager);

	EXPECT_EQ(&dataManager, commandManager.getDataManager());
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
	inputParameter.inputEmployee.SetData(17111236, Name("TVO", "VSID"), CareerLevel::CareerLevel_1, phoneNum, birthday, Certi::Certi_PRO);
	
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
	inputParameter.destColumn = Column::Column_BirthDay;
	inputParameter.inputEmployee.SetData(0, Name("NTAWR", "FB"), CareerLevel::CareerLevel_None, PhoneNum(0, 0), BirthDay(0, 0, 0), Certi::Certi_None);
	inputParameter.inputDestEmployee.SetData(0, Name("", ""), CareerLevel::CareerLevel_None, PhoneNum(0, 0), BirthDay(2005, 05, 20), Certi::Certi_None);

	InputParameter testParameter = commandParser.ConvertParameter("MOD,-p, , ,name,FB NTAWR,birthday,20050520");

	EXPECT_EQ(testParameter.option1, inputParameter.option1);
	EXPECT_EQ(testParameter.option2, inputParameter.option2);
	EXPECT_EQ(testParameter.column, inputParameter.column);
	EXPECT_EQ(testParameter.destColumn, inputParameter.destColumn);
	EXPECT_EQ(testParameter.inputEmployee.GetBirthDay()._day, inputParameter.inputEmployee.GetBirthDay()._day);
	EXPECT_EQ(testParameter.inputDestEmployee.GetBirthDay()._day, inputParameter.inputDestEmployee.GetBirthDay()._day);
}