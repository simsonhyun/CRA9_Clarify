#include "pch.h"
#include "../ClarifyPJT/Add.h"

TEST(TEST_ADD_MODULE, ADD_TEST) {
	DataManager dataManager = DataManager();
	Add add = Add(dataManager);

	PhoneNum phonenum;
	phonenum.middleNum = 1234;
	phonenum.lastNum = 5678;
	BirthDay birthday;
	birthday.year = 1990;
	birthday.month = 01;
	birthday.day = 23;
	Employee employee(12345678, "홍길동", CareerLevel_2, phonenum, birthday, Certi_PRO);
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

TEST(TEST_ADD_MODULE, ADD_MAX_SIZE_TEST) {
	DataManager dataManager = DataManager();
	Add add = Add(dataManager);

	PhoneNum phonenum;
	phonenum.middleNum = 1234;
	phonenum.lastNum = 5678;
	BirthDay birthday;
	birthday.year = 1990;
	birthday.month = 01;
	birthday.day = 23;

	int employeeNum = 90000000;
	for (int i = 0; i < 100000; i++, employeeNum++)
	{
		Employee inputemployee(employeeNum, "홍길동", CareerLevel_2, phonenum, birthday, Certi_PRO);
		InputParameter inputParameter = { Option1_null, Option2_null, Column_null, inputemployee };
		add.Command(inputParameter);
	}

	ASSERT_TRUE(dataManager.getSize() == 100000);
	
	employeeNum = 90000000;
	vector<Employee> employees = dataManager.getData(); //employeenum 순서대로 sorting되든, 입력대로 add되든 test가능
	for(auto employee: employees)
	{
		Employee inputEmployee(employeeNum++, "홍길동", CareerLevel_2, phonenum, birthday, Certi_PRO);
		Employee* result = &employee;
		EXPECT_EQ(result->GetEmployeeNum(), inputEmployee.GetEmployeeNum());
		EXPECT_EQ(result->GetName(), inputEmployee.GetName());
		EXPECT_EQ(result->GetCl(), inputEmployee.GetCl());
		EXPECT_EQ(result->GetPhoneNum().middleNum, inputEmployee.GetPhoneNum().middleNum);
		EXPECT_EQ(result->GetPhoneNum().lastNum, inputEmployee.GetPhoneNum().lastNum);
		EXPECT_EQ(result->GetBirthDay().year, inputEmployee.GetBirthDay().year);
		EXPECT_EQ(result->GetBirthDay().month, inputEmployee.GetBirthDay().month);
		EXPECT_EQ(result->GetBirthDay().day, inputEmployee.GetBirthDay().day);
		EXPECT_EQ(result->GetCerti(), inputEmployee.GetCerti());
	}
}
