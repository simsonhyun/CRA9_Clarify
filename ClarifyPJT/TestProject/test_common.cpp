#include "pch.h"
#include "../ClarifyPJT/CommandManager.h"
#include "../ClarifyPJT/Employee.h"

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
	phoneNum.middleNum = 100;
	phoneNum.lastNum = 200;

	BirthDay birthday;
	birthday.year = 2020;
	birthday.month = 12;
	birthday.day = 30;

	Employee testEmployee(100, "TestName", CareerLevel_1, phoneNum, birthday, Certi_ADV);

	EXPECT_EQ(testEmployee.GetEmployeeNum(), 100);
	EXPECT_EQ(testEmployee.GetName(), "TestName");
	EXPECT_EQ(testEmployee.GetCl(), CareerLevel_1);
	EXPECT_EQ(testEmployee.GetPhoneNum().middleNum, phoneNum.middleNum);
	EXPECT_EQ(testEmployee.GetBirthDay().year, 2020);
	EXPECT_EQ(testEmployee.GetCerti(), Certi_ADV);

}