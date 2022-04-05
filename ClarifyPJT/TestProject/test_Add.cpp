#include "pch.h"
#include "../ClarifyPJT/Add.h"

TEST(TEST_ADD_MODULE, ADD_TEST) {
	DataManager dataManager = DataManager();
	Add add = Add(dataManager);

	PhoneNum phonenum;
	phonenum._middleNum = 1234;
	phonenum._lastNum = 5678;
	BirthDay birthday;
	birthday._year = 1990;
	birthday._month = 01;
	birthday._day = 23;
	Employee employee(12345678, Name("GILDONG", "HONG"), CareerLevel::CareerLevel_2, phonenum, birthday, Certi::Certi_PRO);
	InputParameter inputParameter = { CommandType::Command_None, Option1::Option1_None, Option2::Option2_None, Column::Column_None, Column::Column_None, employee };

	add.Command(inputParameter);

	ASSERT_TRUE(dataManager.getSize() != 0);
	vector<Employee> employees = dataManager.getData();
	Employee* result = employees.data();
	EXPECT_EQ(result->GetEmployeeNum(), employee.GetEmployeeNum());
	EXPECT_EQ(result->GetName()._firstName, employee.GetName()._firstName);
	EXPECT_EQ(result->GetName()._lastName, employee.GetName()._lastName);
	EXPECT_EQ(result->GetCl(), employee.GetCl());
	EXPECT_EQ(result->GetPhoneNum()._middleNum, employee.GetPhoneNum()._middleNum);
	EXPECT_EQ(result->GetPhoneNum()._lastNum, employee.GetPhoneNum()._lastNum);
	EXPECT_EQ(result->GetBirthDay()._year, employee.GetBirthDay()._year);
	EXPECT_EQ(result->GetBirthDay()._month, employee.GetBirthDay()._month);
	EXPECT_EQ(result->GetBirthDay()._day, employee.GetBirthDay()._day);
	EXPECT_EQ(result->GetCerti(), employee.GetCerti());

}

TEST(TEST_ADD_MODULE, ADD_MAX_SIZE_TEST) {
	DataManager dataManager = DataManager();
	Add add = Add(dataManager);

	PhoneNum phonenum;
	phonenum._middleNum = 1234;
	phonenum._lastNum = 5678;
	BirthDay birthday;
	birthday._year = 1990;
	birthday._month = 01;
	birthday._day = 23;

	int employeeNum = 90000000;
	for (int i = 0; i < 100000; i++, employeeNum++)
	{
		Employee inputemployee(employeeNum, Name("GILDONG", "HONG"), CareerLevel::CareerLevel_2, phonenum, birthday, Certi::Certi_PRO);
		InputParameter inputParameter = { CommandType::Command_None, Option1::Option1_None, Option2::Option2_None, Column::Column_None, Column::Column_None, inputemployee };
		add.Command(inputParameter);
	}

	ASSERT_TRUE(dataManager.getSize() == 100000);

	employeeNum = 90000000;
	vector<Employee> employees = dataManager.getData(); //employeenum ???? sorting??, ???? add?? test??
	for (auto employee : employees)
	{
		Employee inputEmployee(employeeNum++, Name("GILDONG", "HONG"), CareerLevel::CareerLevel_2, phonenum, birthday, Certi::Certi_PRO);
		Employee* result = &employee;
		EXPECT_EQ(result->GetEmployeeNum(), inputEmployee.GetEmployeeNum());
		EXPECT_EQ(result->GetName()._firstName, inputEmployee.GetName()._firstName);
		EXPECT_EQ(result->GetName()._lastName, inputEmployee.GetName()._lastName);
		EXPECT_EQ(result->GetCl(), inputEmployee.GetCl());
		EXPECT_EQ(result->GetPhoneNum()._middleNum, inputEmployee.GetPhoneNum()._middleNum);
		EXPECT_EQ(result->GetPhoneNum()._lastNum, inputEmployee.GetPhoneNum()._lastNum);
		EXPECT_EQ(result->GetBirthDay()._year, inputEmployee.GetBirthDay()._year);
		EXPECT_EQ(result->GetBirthDay()._month, inputEmployee.GetBirthDay()._month);
		EXPECT_EQ(result->GetBirthDay()._day, inputEmployee.GetBirthDay()._day);
		EXPECT_EQ(result->GetCerti(), inputEmployee.GetCerti());
	}
}

TEST(TEST_ADD_MODULE, ADD_INPUT_EXCEPTION_TEST) {
	DataManager dataManager = DataManager();
	Add add = Add(dataManager);

	PhoneNum phonenum;
	phonenum._middleNum = 1234;
	phonenum._lastNum = 5678;
	BirthDay birthday;
	birthday._year = 1990;
	birthday._month = 01;
	birthday._day = 23;
	Employee employee(12345678, Name("GILDONGDONGG", "HONG"), CareerLevel::CareerLevel_2, phonenum, birthday, Certi::Certi_PRO);
	InputParameter inputParameter = { CommandType::Command_None, Option1::Option1_None, Option2::Option2_None, Column::Column_None, Column::Column_None, employee };

	add.Command(inputParameter);

	ASSERT_TRUE(dataManager.getSize() != 1); // invalid? Input? ??? add?? ?? ?? ??
}
