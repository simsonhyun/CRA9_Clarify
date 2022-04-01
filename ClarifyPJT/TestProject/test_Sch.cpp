#include "pch.h"
#include "../ClarifyPJT/Sch.h"

class SearchTest : public ::testing::Test {
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
	Search* searchTest = new Search(*dataManager);
};

TEST_F(SearchTest, SearchByEmployeeNumTest) {
	Employee searchEmployee = { 12345678, {"±è", "Ã¶¼ö"}, CareerLevel::CareerLevel_2,  {1234, 8765}, {1990, 02, 01}, Certi::Certi_PRO };
	InputParameter input = { Command::Command_Sch, Option1::Option1_None, Option2::Option2_None, Column::Column_employeeNum, Column::Column_None, searchEmployee };

	vector<Employee> result = searchTest->search(input);
	for (const Employee& ep : result) {
		EXPECT_EQ(ep.GetEmployeeNum(), searchEmployee.GetEmployeeNum());
	}
	EXPECT_EQ(2, result.size());
};

TEST_F(SearchTest, SearchByCareerLevelTest) {
	Employee searchEmployee = { 11111111, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {9513, 7412}, {1990, 04, 03}, Certi::Certi_PRO };
	InputParameter input = { Command::Command_Sch, Option1::Option1_None, Option2::Option2_None, Column::Column_CareerLevel, Column::Column_None, searchEmployee };

	vector<Employee> result = searchTest->search(input);
	for (const Employee& ep : result) {
		EXPECT_EQ(ep.GetCl(), searchEmployee.GetCl());
	}
	EXPECT_EQ(2, result.size());
};

TEST_F(SearchTest, SearchByCertiTest) {
	Employee searchEmployee = { 87654321, {"°í", "±æµ¿"}, CareerLevel::CareerLevel_4,  {1354, 9516}, {1990, 03, 02}, Certi::Certi_ADV };
	InputParameter input = { Command::Command_Sch, Option1::Option1_None, Option2::Option2_None, Column::Column_Certi, Column::Column_None, searchEmployee };

	vector<Employee> result = searchTest->search(input);
	for (const Employee& ep : result) {
		EXPECT_EQ(ep.GetCerti(), searchEmployee.GetCerti());
	}
	EXPECT_EQ(2, result.size());
};

TEST_F(SearchTest, SearchByNameTest) {
	Employee searchEmployee = { 87654321, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_4,  {1354, 9516}, {1990, 03, 02}, Certi::Certi_ADV };
	InputParameter input = { Command::Command_Sch, Option1::Option1_None, Option2::Option2_None, Column::Column_Name, Column::Column_None, searchEmployee };

	vector<Employee> result = searchTest->search(input);
	for (const Employee& ep : result) {
		EXPECT_EQ(ep.GetName()._firstName, searchEmployee.GetName()._firstName);
		EXPECT_EQ(ep.GetName()._lastName, searchEmployee.GetName()._lastName);
	}
	EXPECT_EQ(2, result.size());

	input = { Command::Command_Sch, Option1::Option1_None, Option2::Option2_Name_f, Column::Column_Name, Column::Column_None, searchEmployee };
	result.clear();
	result = searchTest->search(input);
	for (const Employee& ep : result) {
		EXPECT_EQ(ep.GetName()._firstName, searchEmployee.GetName()._firstName);
	}
	EXPECT_EQ(2, result.size());

	input = { Command::Command_Sch, Option1::Option1_None, Option2::Option2_Name_l, Column::Column_Name, Column::Column_None, searchEmployee };
	result.clear();
	result = searchTest->search(input);
	for (const Employee& ep : result) {
		EXPECT_EQ(ep.GetName()._lastName, searchEmployee.GetName()._lastName);
	}
	EXPECT_EQ(3, result.size());
};

TEST_F(SearchTest, SearchByPhoneNumTest) {
	Employee searchEmployee = { 12345678, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {1234, 5678}, {1990, 01, 01}, Certi::Certi_ADV };
	InputParameter input = { Command::Command_Sch, Option1::Option1_None, Option2::Option2_None, Column::Column_PhoneNum, Column::Column_None, searchEmployee };

	vector<Employee> result = searchTest->search(input);
	for (const Employee& ep : result) {
		EXPECT_EQ(ep.GetPhoneNum()._middleNum, searchEmployee.GetPhoneNum()._middleNum);
		EXPECT_EQ(ep.GetPhoneNum()._lastNum, searchEmployee.GetPhoneNum()._lastNum);
	}
	EXPECT_EQ(1, result.size());

	input = { Command::Command_Sch, Option1::Option1_None, Option2::Option2_PhoneNum_m, Column::Column_PhoneNum, Column::Column_None, searchEmployee };
	result.clear();
	result = searchTest->search(input);
	for (const Employee& ep : result) {
		EXPECT_EQ(ep.GetPhoneNum()._middleNum, searchEmployee.GetPhoneNum()._middleNum);
	}
	EXPECT_EQ(2, result.size());

	input = { Command::Command_Sch, Option1::Option1_None, Option2::Option2_PhoneNum_l, Column::Column_PhoneNum, Column::Column_None, searchEmployee };
	result.clear();
	result = searchTest->search(input);
	for (const Employee& ep : result) {
		EXPECT_EQ(ep.GetPhoneNum()._lastNum, searchEmployee.GetPhoneNum()._lastNum);
	}
	EXPECT_EQ(2, result.size());
};

TEST_F(SearchTest, SearchByBirthDayTest) {
	Employee searchEmployee = { 12345678, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {1234, 5678}, {1990, 01, 01}, Certi::Certi_ADV };
	InputParameter input = { Command::Command_Sch, Option1::Option1_None, Option2::Option2_None, Column::Column_BirthDay, Column::Column_None, searchEmployee };

	vector<Employee> result = searchTest->search(input);
	for (const Employee& ep : result) {
		EXPECT_EQ(ep.GetBirthDay()._year, searchEmployee.GetBirthDay()._year);
		EXPECT_EQ(ep.GetBirthDay()._month, searchEmployee.GetBirthDay()._month);
		EXPECT_EQ(ep.GetBirthDay()._day, searchEmployee.GetBirthDay()._day);
	}
	EXPECT_EQ(1, result.size());

	input = { Command::Command_Sch, Option1::Option1_None, Option2::Option2_BirthDay_y, Column::Column_BirthDay, Column::Column_None, searchEmployee };
	result.clear();
	result = searchTest->search(input);
	for (const Employee& ep : result) {
		EXPECT_EQ(ep.GetBirthDay()._year, searchEmployee.GetBirthDay()._year);
	}
	EXPECT_EQ(5, result.size());

	input = { Command::Command_Sch, Option1::Option1_None, Option2::Option2_BirthDay_m, Column::Column_BirthDay, Column::Column_None, searchEmployee };
	result.clear();
	result = searchTest->search(input);
	for (const Employee& ep : result) {
		EXPECT_EQ(ep.GetBirthDay()._month, searchEmployee.GetBirthDay()._month);
	}
	EXPECT_EQ(2, result.size());

	input = { Command::Command_Sch, Option1::Option1_None, Option2::Option2_BirthDay_d, Column::Column_BirthDay, Column::Column_None, searchEmployee };
	result.clear();
	result = searchTest->search(input);
	for (const Employee& ep : result) {
		EXPECT_EQ(ep.GetBirthDay()._day, searchEmployee.GetBirthDay()._day);
	}
	EXPECT_EQ(2, result.size());
};