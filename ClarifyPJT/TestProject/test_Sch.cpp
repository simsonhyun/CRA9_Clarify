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
	InputParameter input = { Command::Command_Sch, Option1::Option1_null, Option2::Option2_null, Column::Column_employeeNum , searchEmployee };

	vector<Employee> result = searchTest->searchWithPrint(input);
	int employeeCnt = 0;
	for (const Employee& ep : result) {
		EXPECT_EQ(ep.GetEmployeeNum(), searchEmployee.GetEmployeeNum());
		employeeCnt++;
	}
	EXPECT_EQ(2, employeeCnt);
};

TEST_F(SearchTest, SearchByCareerLevelTest) {
	Employee searchEmployee = { 11111111, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {9513, 7412}, {1990, 04, 03}, Certi::Certi_PRO };
	InputParameter input = { Command::Command_Sch, Option1::Option1_null, Option2::Option2_null, Column::Column_CareerLevel , searchEmployee };

	vector<Employee> result = searchTest->searchWithPrint(input);
	int employeeCnt = 0;
	for (const Employee& ep : result) {
		EXPECT_EQ(ep.GetCl(), searchEmployee.GetCl());
		employeeCnt++;
	}
	EXPECT_EQ(2, employeeCnt);
};

TEST_F(SearchTest, SearchByCertiTest) {
	Employee searchEmployee = { 87654321, {"°í", "±æµ¿"}, CareerLevel::CareerLevel_4,  {1354, 9516}, {1990, 03, 02}, Certi::Certi_ADV };
	InputParameter input = { Command::Command_Sch, Option1::Option1_null, Option2::Option2_null, Column::Column_Certi , searchEmployee };

	vector<Employee> result = searchTest->searchWithPrint(input);
	int employeeCnt = 0;
	for (const Employee& ep : result) {
		EXPECT_EQ(ep.GetCerti(), searchEmployee.GetCerti());
		employeeCnt++;
	}
	EXPECT_EQ(2, employeeCnt);
};