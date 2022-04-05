#include "pch.h"
#include "../ClarifyPJT/Del.h"

class DeleteOption2Test : public ::testing::Test {
protected:
	void SetUp() override {
		Employee employee1 = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 5678}, {1995, 01, 01}, Certi::Certi_EX };
		Employee employee2 = { 11010678, {"LEE", "GILDONG"}, CareerLevel::CareerLevel_1,  {1234, 1234}, {1991, 02, 01}, Certi::Certi_PRO };
		Employee employee3 = { 10340608, {"HONG", "ILDONG"}, CareerLevel::CareerLevel_2,  {1234, 4321}, {1992, 03, 01}, Certi::Certi_EX };
		Employee employee4 = { 14475488, {"LEE", "SOONSIN"}, CareerLevel::CareerLevel_2,  {5678, 5678}, {1999, 01, 01}, Certi::Certi_EX };
		Employee employee5 = { 13481675, {"KIM", "YOUSIN"}, CareerLevel::CareerLevel_3,  {4321, 5678}, {1992, 01, 01}, Certi::Certi_ADV };
		Employee employee6 = { 12197457, {"YOON", "SEOKYUL"}, CareerLevel::CareerLevel_2,  {3456, 4321}, {1995, 02, 01}, Certi::Certi_PRO };
		Employee employee7 = { 17841097, {"LEE", "JAEMYUNG"}, CareerLevel::CareerLevel_4,  {7890, 2345}, {1993, 12, 01}, Certi::Certi_PRO };
		Employee employee8 = { 15686355, {"HONG", "JOONPYO"}, CareerLevel::CareerLevel_2,  {1234, 8765}, {1997, 01, 01}, Certi::Certi_PRO };
		Employee employee9 = { 11183073, {"LEE", "JOONSEOK"}, CareerLevel::CareerLevel_2,  {1243, 1234}, {1992, 05, 01}, Certi::Certi_PRO };
		Employee employee10 = { 10208468, {"SIM", "SANGJEONG"}, CareerLevel::CareerLevel_1,  {8765, 5678}, {1996, 03, 01}, Certi::Certi_PRO };
		dataManager->setData(employee1);
		dataManager->setData(employee2);
		dataManager->setData(employee3);
		dataManager->setData(employee4);
		dataManager->setData(employee5);
		dataManager->setData(employee6);
		dataManager->setData(employee7);
		dataManager->setData(employee8);
		dataManager->setData(employee9);
		dataManager->setData(employee10);
	}
	void TearDown() override {
		;
	}
public:
	DataManager* dataManager = new DataManager();
	Del* deleteTest = new Del(*dataManager);
};

TEST_F(DeleteOption2Test, DeleteNameWithOptionFTestWithOptionP) {
	Employee deleteEmployee = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 0000}, {1992, 01, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_p, Option2::Option2_Name_f, Column::Column_Name, Column::Column_None, deleteEmployee };

	OutputParameter result = deleteTest->Command(input);
	/*for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetName()._firstName, deleteEmployee.GetName()._firstName);
		deleteCount++;
	}*/
	EXPECT_EQ(3, result.resultCount);
	EXPECT_EQ(7, dataManager->getSize());
};

TEST_F(DeleteOption2Test, DeleteNameWithOptionLTestWithOptionP) {
	Employee deleteEmployee = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 0000}, {1992, 01, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_p, Option2::Option2_Name_l, Column::Column_Name, Column::Column_None, deleteEmployee };

	OutputParameter result = deleteTest->Command(input);
	/*for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetName()._lastName, deleteEmployee.GetName()._lastName);
		deleteCount++;
	}*/
	EXPECT_EQ(2, result.resultCount);
	EXPECT_EQ(8, dataManager->getSize());
};

TEST_F(DeleteOption2Test, DeleteNameWithOptionXTestWithOptionP) {
	Employee deleteEmployee = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 0000}, {1992, 01, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_p, Option2::Option2_None, Column::Column_Name, Column::Column_None, deleteEmployee };

	OutputParameter result = deleteTest->Command(input);
	/*for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetName(), deleteEmployee.GetName());
		deleteCount++;
	}*/
	EXPECT_EQ(1, result.resultCount);
	EXPECT_EQ(9, dataManager->getSize());
};

TEST_F(DeleteOption2Test, DeleteEmployeeNumWithOptionFTestWithOptionP) {
	Employee deleteEmployee = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 0000}, {1992, 01, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_p, Option2::Option2_Name_f, Column::Column_employeeNum, Column::Column_None, deleteEmployee };

	OutputParameter result = deleteTest->Command(input);
	/*for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetName()._firstName, deleteEmployee.GetName()._firstName);
		deleteCount++;
	}*/
	EXPECT_EQ(0, result.resultCount);
	EXPECT_EQ(10, dataManager->getSize());
};

TEST_F(DeleteOption2Test, DeleteNameWithOptionFTestWithoutOptionP) {
	Employee deleteEmployee = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 0000}, {1992, 01, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_None, Option2::Option2_Name_f, Column::Column_Name, Column::Column_None, deleteEmployee };

	OutputParameter result = deleteTest->Command(input);
	/*for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetName()._firstName, deleteEmployee.GetName()._firstName);
		deleteCount++;
	}*/
	EXPECT_EQ(3, result.resultCount);
	EXPECT_EQ(7, dataManager->getSize());
};

TEST_F(DeleteOption2Test, DeleteNameWithOptionLTestWithoutOptionP) {
	Employee deleteEmployee = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 0000}, {1992, 01, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_None, Option2::Option2_Name_l, Column::Column_Name, Column::Column_None, deleteEmployee };

	OutputParameter result = deleteTest->Command(input);
	/*for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetName()._lastName, deleteEmployee.GetName()._lastName);
		deleteCount++;
	}*/
	EXPECT_EQ(2, result.resultCount);
	EXPECT_EQ(8, dataManager->getSize());
};

TEST_F(DeleteOption2Test, DeleteNameWithOptionXTestWithoutOptionP) {
	Employee deleteEmployee = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 0000}, {1992, 01, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_None, Option2::Option2_None, Column::Column_Name, Column::Column_None, deleteEmployee };

	OutputParameter result = deleteTest->Command(input);
	/*for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetName(), deleteEmployee.GetName());
		deleteCount++;
	}*/
	EXPECT_EQ(1, result.resultCount);
	EXPECT_EQ(9, dataManager->getSize());
};

TEST_F(DeleteOption2Test, DeleteEmployeeNumWithOptionFTestWithoutOptionP) {
	Employee deleteEmployee = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 0000}, {1992, 01, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_None, Option2::Option2_Name_f, Column::Column_employeeNum, Column::Column_None, deleteEmployee };

	OutputParameter result = deleteTest->Command(input);
	/*for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetName()._firstName, deleteEmployee.GetName()._firstName);
		deleteCount++;
	}*/
	EXPECT_EQ(0, result.resultCount);
	EXPECT_EQ(10, dataManager->getSize());
};

TEST_F(DeleteOption2Test, DeletePhoneNumWithOptionMTestWithOptionP) {
	Employee deleteEmployee = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 0000}, {1992, 01, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_p, Option2::Option2_PhoneNum_m, Column::Column_PhoneNum, Column::Column_None, deleteEmployee };

	OutputParameter result = deleteTest->Command(input);
	/*for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetPhoneNum()._middleNum, deleteEmployee.GetPhoneNum()._middleNum);
		deleteCount++;
	}*/
	EXPECT_EQ(4, result.resultCount);
	EXPECT_EQ(6, dataManager->getSize());
};

TEST_F(DeleteOption2Test, DeletePhoneNumWithOptionLTestWithOptionP) {
	Employee deleteEmployee = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 0000}, {1992, 01, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_p, Option2::Option2_PhoneNum_l, Column::Column_PhoneNum, Column::Column_None, deleteEmployee };

	OutputParameter result = deleteTest->Command(input);
	/*for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetPhoneNum()._lastNum, deleteEmployee.GetPhoneNum()._lastNum);
		deleteCount++;
	}*/
	EXPECT_EQ(0, result.resultCount);
	EXPECT_EQ(10, dataManager->getSize());
};

TEST_F(DeleteOption2Test, DeletePhoneNumWithOptionXTestWithOptionP) {
	Employee deleteEmployee = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 0000}, {1992, 01, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_p, Option2::Option2_None, Column::Column_PhoneNum, Column::Column_None, deleteEmployee };

	OutputParameter result = deleteTest->Command(input);
	/*for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetPhoneNum(), deleteEmployee.GetPhoneNum());
		deleteCount++;
	}*/
	EXPECT_EQ(0, result.resultCount);
	EXPECT_EQ(10, dataManager->getSize());
};

TEST_F(DeleteOption2Test, DeleteEmployeeNumWithOptionMTestWithOptionP) {
	Employee deleteEmployee = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 0000}, {1992, 01, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_p, Option2::Option2_PhoneNum_m, Column::Column_employeeNum, Column::Column_None, deleteEmployee };

	OutputParameter result = deleteTest->Command(input);
	/*for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetEmployeeNum(), deleteEmployee.GetEmployeeNum());
		deleteCount++;
	}*/
	EXPECT_EQ(0, result.resultCount);
	EXPECT_EQ(10, dataManager->getSize());
};


TEST_F(DeleteOption2Test, DeletePhoneNumWithOptionMTestWithoutOptionP) {
	Employee deleteEmployee = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 0000}, {1992, 01, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_None, Option2::Option2_PhoneNum_m, Column::Column_PhoneNum, Column::Column_None, deleteEmployee };

	OutputParameter result = deleteTest->Command(input);
	/*for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetPhoneNum()._middleNum, deleteEmployee.GetPhoneNum()._middleNum);
		deleteCount++;
	}*/
	EXPECT_EQ(4, result.resultCount);
	EXPECT_EQ(6, dataManager->getSize());
};

TEST_F(DeleteOption2Test, DeletePhoneNumWithOptionLTestWithoutOptionP) {
	Employee deleteEmployee = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 0000}, {1992, 01, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_None, Option2::Option2_PhoneNum_l, Column::Column_PhoneNum, Column::Column_None, deleteEmployee };

	OutputParameter result = deleteTest->Command(input);
	/*for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetPhoneNum()._lastNum, deleteEmployee.GetPhoneNum()._lastNum);
		deleteCount++;
	}*/
	EXPECT_EQ(0, result.resultCount);
	EXPECT_EQ(10, dataManager->getSize());
};

TEST_F(DeleteOption2Test, DeletePhoneNumWithOptionXTestWithoutOptionP) {
	Employee deleteEmployee = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 0000}, {1992, 01, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_None, Option2::Option2_None, Column::Column_PhoneNum, Column::Column_None, deleteEmployee };

	OutputParameter result = deleteTest->Command(input);
	/*for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetPhoneNum(), deleteEmployee.GetPhoneNum());
		deleteCount++;
	}*/
	EXPECT_EQ(0, result.resultCount);
	EXPECT_EQ(10, dataManager->getSize());
};

TEST_F(DeleteOption2Test, DeleteEmployeeNumWithOptionMTestWithoutOptionP) {
	Employee deleteEmployee = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 0000}, {1992, 01, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_None, Option2::Option2_PhoneNum_m, Column::Column_employeeNum, Column::Column_None, deleteEmployee };

	OutputParameter result = deleteTest->Command(input);
	/*for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetEmployeeNum(), deleteEmployee.GetEmployeeNum());
		deleteCount++;
	}*/
	EXPECT_EQ(0, result.resultCount);
	EXPECT_EQ(10, dataManager->getSize());
};

TEST_F(DeleteOption2Test, DeleteBirtyDayWithOptionYTestWithOptionP) {
	Employee deleteEmployee = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 0000}, {1992, 01, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_p, Option2::Option2_BirthDay_y, Column::Column_BirthDay, Column::Column_None, deleteEmployee };

	OutputParameter result = deleteTest->Command(input);
	/*for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetBirthDay()._year, deleteEmployee.GetBirthDay()._year);
		deleteCount++;
	}*/
	EXPECT_EQ(3, result.resultCount);
	EXPECT_EQ(7, dataManager->getSize());
};

TEST_F(DeleteOption2Test, DeleteBirtyDayWithOptionMTestWithOptionP) {
	Employee deleteEmployee = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 0000}, {1992, 01, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_p, Option2::Option2_BirthDay_m, Column::Column_BirthDay, Column::Column_None, deleteEmployee };

	OutputParameter result = deleteTest->Command(input);
	/*for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetBirthDay()._month, deleteEmployee.GetBirthDay()._month);
		deleteCount++;
	}*/
	EXPECT_EQ(4, result.resultCount);
	EXPECT_EQ(6, dataManager->getSize());
};

TEST_F(DeleteOption2Test, DeleteBirtyDayWithOptionDTestWithOptionP) {
	Employee deleteEmployee = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 0000}, {1992, 01, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_p, Option2::Option2_BirthDay_d, Column::Column_BirthDay, Column::Column_None, deleteEmployee };

	OutputParameter result = deleteTest->Command(input);
	/*for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetBirthDay()._day, deleteEmployee.GetBirthDay()._day);
		deleteCount++;
	}*/
	EXPECT_EQ(10, result.resultCount);
	EXPECT_EQ(0, dataManager->getSize());
};

TEST_F(DeleteOption2Test, DeleteBirtyDayWithOptionXTestWithOptionP) {
	Employee deleteEmployee = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 0000}, {1992, 01, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_p, Option2::Option2_None, Column::Column_BirthDay, Column::Column_None, deleteEmployee };

	OutputParameter result = deleteTest->Command(input);
	/*for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetBirthDay(), deleteEmployee.GetBirthDay());
		deleteCount++;
	}*/
	EXPECT_EQ(1, result.resultCount);
	EXPECT_EQ(9, dataManager->getSize());
};

TEST_F(DeleteOption2Test, DeleteEmployeeNumWithOptionYTestWithOptionP) {
	Employee deleteEmployee = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 0000}, {1992, 01, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_p, Option2::Option2_BirthDay_y, Column::Column_employeeNum, Column::Column_None, deleteEmployee };

	OutputParameter result = deleteTest->Command(input);
	/*for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetEmployeeNum(), deleteEmployee.GetEmployeeNum());
		deleteCount++;
	}*/
	EXPECT_EQ(0, result.resultCount);
	EXPECT_EQ(10, dataManager->getSize());
};

TEST_F(DeleteOption2Test, DeleteBirtyDayWithOptionYTestWithoutOptionP) {
	Employee deleteEmployee = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 0000}, {1992, 01, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_None, Option2::Option2_BirthDay_y, Column::Column_BirthDay, Column::Column_None, deleteEmployee };

	OutputParameter result = deleteTest->Command(input);
	/*for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetBirthDay()._year, deleteEmployee.GetBirthDay()._year);
		deleteCount++;
	}*/
	EXPECT_EQ(3, result.resultCount);
	EXPECT_EQ(7, dataManager->getSize());
};

TEST_F(DeleteOption2Test, DeleteBirtyDayWithOptionMTestWithoutOptionP) {
	Employee deleteEmployee = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 0000}, {1992, 01, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_None, Option2::Option2_BirthDay_m, Column::Column_BirthDay, Column::Column_None, deleteEmployee };

	OutputParameter result = deleteTest->Command(input);
	/*for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetBirthDay()._month, deleteEmployee.GetBirthDay()._month);
		deleteCount++;
	}*/
	EXPECT_EQ(4, result.resultCount);
	EXPECT_EQ(6, dataManager->getSize());
};

TEST_F(DeleteOption2Test, DeleteBirtyDayWithOptionDTestWithoutOptionP) {
	Employee deleteEmployee = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 0000}, {1992, 01, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_None, Option2::Option2_BirthDay_d, Column::Column_BirthDay, Column::Column_None, deleteEmployee };

	OutputParameter result = deleteTest->Command(input);
	/*for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetBirthDay()._day, deleteEmployee.GetBirthDay()._day);
		deleteCount++;
	}*/
	EXPECT_EQ(10, result.resultCount);
	EXPECT_EQ(0, dataManager->getSize());
};

TEST_F(DeleteOption2Test, DeleteBirtyDayWithOptionXTestWithoutOptionP) {
	Employee deleteEmployee = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 0000}, {1992, 01, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_None, Option2::Option2_None, Column::Column_BirthDay, Column::Column_None, deleteEmployee };

	OutputParameter result = deleteTest->Command(input);
	/*for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetBirthDay(), deleteEmployee.GetBirthDay());
		deleteCount++;
	}*/
	EXPECT_EQ(1, result.resultCount);
	EXPECT_EQ(9, dataManager->getSize());
};

TEST_F(DeleteOption2Test, DeleteEmployeeNumWithOptionYTestWithoutOptionP) {
	Employee deleteEmployee = { 12345678, {"HONG", "GILDONG"}, CareerLevel::CareerLevel_2,  {1234, 0000}, {1992, 01, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_None, Option2::Option2_BirthDay_y, Column::Column_employeeNum, Column::Column_None, deleteEmployee };

	OutputParameter result = deleteTest->Command(input);
	/*for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetEmployeeNum(), deleteEmployee.GetEmployeeNum());
		deleteCount++;
	}*/
	EXPECT_EQ(0, result.resultCount);
	EXPECT_EQ(10, dataManager->getSize());
};