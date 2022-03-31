#include "pch.h"
#include "../ClarifyPJT/Add.h"

TEST(TEST_ADD_MODULE, TEST) {
	DataManager dataManager = DataManager();
	Add add = Add(dataManager);

	PhoneNum phonenum;
	phonenum.middleNum = 1234;
	phonenum.lastNum = 5678;
	BirthDay birthday;
	birthday.year = 1990;
	birthday.month = 01;
	birthday.day = 23;
	Employee employee(12345678, "ȫ�浿", CareerLevel_2, phonenum, birthday, Certi_PRO);
	InputParameter inputParameter = { Option1_null, Option2_null, Column_null, employee };
	
	add.Command(inputParameter);

	ASSERT_TRUE(dataManager.getSize() != 0);
	vector<Employee> employees = dataManager.getData();
	Employee* result = employees.data();
	EXPECT_EQ(result->GetEmployeeNum(), employee.GetEmployeeNum());
	EXPECT_EQ(result->GetName(), employee.GetName());
	EXPECT_EQ(result->GetCl(), employee.GetCl());
	EXPECT_EQ(result->GetPhoneNum().middleNum, employee.GetPhoneNum().middleNum);
	EXPECT_EQ(result->GetPhoneNum().lastNum, employee.GetPhoneNum().lastNum);
	EXPECT_EQ(result->GetBirthDay().year, employee.GetBirthDay().year);
	EXPECT_EQ(result->GetBirthDay().month, employee.GetBirthDay().month);
	EXPECT_EQ(result->GetBirthDay().day, employee.GetBirthDay().day);
	EXPECT_EQ(result->GetCerti(), employee.GetCerti());

}
