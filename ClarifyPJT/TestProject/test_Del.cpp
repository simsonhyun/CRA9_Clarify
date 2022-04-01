#include "pch.h"
#include "../ClarifyPJT/Del.cpp"

class DeleteTest : public ::testing::Test {
protected:
	void SetUp() override {
		Employee employee1 = { 12345678, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {1234, 5678}, {1990, 01, 01}, Certi::Certi_ADV };
		Employee employee2 = { 87654321, {"±è", "Ã¶¼ö"}, CareerLevel::CareerLevel_2,  {1234, 8765}, {1990, 02, 01}, Certi::Certi_PRO };
		Employee employee3 = { 12345678, {"ÀÌ", "¿µÈñ"}, CareerLevel::CareerLevel_3,  {9876, 5678}, {1990, 01, 02}, Certi::Certi_EX };
		Employee employee4 = { 87654321, {"°í", "±æµ¿"}, CareerLevel::CareerLevel_4,  {1354, 9516}, {1990, 03, 02}, Certi::Certi_ADV };
		Employee employee5 = { 11111111, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {9513, 7412}, {1990, 04, 03}, Certi::Certi_PRO };
		dataManager->setData(employee1);
		dataManager->setData(employee2);
		dataManager->setData(employee3);
		dataManager->setData(employee4);
		dataManager->setData(employee5);
	}
	void TearDown() override {
		;
	}
public:
	DataManager* dataManager = new DataManager();
	Del* deleteTest = new Del(*dataManager);
};

TEST_F(DeleteTest, DeleteByEmployeeNumTest) {
	Employee deleteEmployee = { 12345678, {"±è", "Ã¶¼ö"}, CareerLevel::CareerLevel_2,  {1234, 8765}, {1990, 02, 01}, Certi::Certi_PRO };
	InputParameter input = { Command::Command_Sch, Option1::Option1_None, Option2::Option2_None, Column::Column_employeeNum, Column::Column_None, deleteEmployee };

	vector<Employee> result = deleteTest->deleteWithPrint(input);
	int employeeCnt = 0;
	for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetEmployeeNum(), deleteEmployee.GetEmployeeNum());
		employeeCnt++;
	}
	EXPECT_EQ(2, employeeCnt);
	EXPECT_EQ(3, dataManager->getSize());
};

TEST_F(DeleteTest, DeleteByNameTest) {
	Employee deleteEmployee = { 12345678, {"±è", "Ã¶¼ö"}, CareerLevel::CareerLevel_2,  {1234, 8765}, {1990, 02, 01}, Certi::Certi_PRO };
	InputParameter input = { Command::Command_Sch, Option1::Option1_None, Option2::Option2_None, Column::Column_Name, Column::Column_None, deleteEmployee };

	vector<Employee> result = deleteTest->deleteWithPrint(input);
	int employeeCnt = 0;
	for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetName(), deleteEmployee.GetName());
		employeeCnt++;
	}
	EXPECT_EQ(1, employeeCnt);
	EXPECT_EQ(4, dataManager->getSize());
};

TEST_F(DeleteTest, DeleteByCareerLevelTest) {
	Employee deleteEmployee = { 11111111, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {9513, 7412}, {1990, 04, 03}, Certi::Certi_PRO };
	InputParameter input = { Command::Command_Sch, Option1::Option1_None, Option2::Option2_None, Column::Column_CareerLevel, Column::Column_None, deleteEmployee };

	vector<Employee> result = deleteTest->deleteWithPrint(input);
	int employeeCnt = 0;
	for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetCl(), deleteEmployee.GetCl());
		employeeCnt++;
	}
	EXPECT_EQ(2, employeeCnt);
	EXPECT_EQ(3, dataManager->getSize());
};

TEST_F(DeleteTest, DeleteByPhoneNumTest) {
	Employee deleteEmployee = { 11111111, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {9513, 7412}, {1990, 04, 03}, Certi::Certi_PRO };
	InputParameter input = { Command::Command_Sch, Option1::Option1_None, Option2::Option2_None, Column::Column_PhoneNum, Column::Column_None, deleteEmployee };

	vector<Employee> result = deleteTest->deleteWithPrint(input);
	int employeeCnt = 0;
	for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetPhoneNum(), deleteEmployee.GetPhoneNum());
		employeeCnt++;
	}
	EXPECT_EQ(1, employeeCnt);
	EXPECT_EQ(4, dataManager->getSize());
};

TEST_F(DeleteTest, DeleteByBirthDayTest) {
	Employee deleteEmployee = { 87654321, {"°í", "±æµ¿"}, CareerLevel::CareerLevel_4,  {1354, 9516}, {1990, 03, 02}, Certi::Certi_ADV };
	InputParameter input = { Command::Command_Sch, Option1::Option1_None, Option2::Option2_None, Column::Column_BirthDay, Column::Column_None, deleteEmployee };

	vector<Employee> result = deleteTest->deleteWithPrint(input);
	int employeeCnt = 0;
	for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetBirthDay(), deleteEmployee.GetBirthDay());
		employeeCnt++;
	}
	EXPECT_EQ(1, employeeCnt);
	EXPECT_EQ(4, dataManager->getSize());
};

TEST_F(DeleteTest, DeleteByCertiTest) {
	Employee deleteEmployee = { 87654321, {"°í", "±æµ¿"}, CareerLevel::CareerLevel_4,  {1354, 9516}, {1990, 03, 02}, Certi::Certi_ADV };
	InputParameter input = { Command::Command_Sch, Option1::Option1_None, Option2::Option2_None, Column::Column_Certi, Column::Column_None, deleteEmployee };

	vector<Employee> result = deleteTest->deleteWithPrint(input);
	int employeeCnt = 0;
	for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetCerti(), deleteEmployee.GetCerti());
		employeeCnt++;
	}
	EXPECT_EQ(2, employeeCnt);
	EXPECT_EQ(3, dataManager->getSize());
};