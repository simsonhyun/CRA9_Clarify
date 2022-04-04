#include "pch.h"
#include "../ClarifyPJT/Del.h"

class DeleteOption1Test : public ::testing::Test {
protected:
	void SetUp() override {
		Employee employee1 = { 12345678, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {1234, 5678}, {1990, 01, 01}, Certi::Certi_ADV };
		Employee employee2 = { 12345678, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {1234, 5678}, {1990, 01, 01}, Certi::Certi_ADV };
		Employee employee3 = { 12345678, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {1234, 5678}, {1990, 01, 01}, Certi::Certi_ADV };
		Employee employee4 = { 12345678, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {1234, 5678}, {1990, 01, 01}, Certi::Certi_ADV };
		Employee employee5 = { 12345678, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {1234, 5678}, {1990, 01, 01}, Certi::Certi_ADV };
		Employee employee6 = { 12345678, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {1234, 5678}, {1990, 01, 01}, Certi::Certi_ADV };
		Employee employee7 = { 12345678, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {1234, 5678}, {1990, 01, 01}, Certi::Certi_ADV };
		Employee employee8 = { 12345678, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {1234, 5678}, {1990, 01, 01}, Certi::Certi_ADV };
		Employee employee9 = { 12345678, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {1234, 5678}, {1990, 01, 01}, Certi::Certi_ADV };
		Employee employee10 = { 12345678, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {1234, 5678}, {1990, 01, 01}, Certi::Certi_ADV };
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

TEST_F(DeleteOption1Test, DeleteAllByEmployeeNumTestWithOptionP) {
	Employee deleteEmployee = { 12345678, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {1234, 5678}, {1990, 01, 01}, Certi::Certi_ADV };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_p, Option2::Option2_None, Column::Column_employeeNum, Column::Column_None, deleteEmployee };

	vector<Employee> result = deleteTest->Command(input);
	int deleteCount = 0;
	for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetEmployeeNum(), deleteEmployee.GetEmployeeNum());
		deleteCount++;
	}
	EXPECT_EQ(5, deleteCount);
	EXPECT_EQ(0, dataManager->getSize());
};

TEST_F(DeleteOption1Test, DeleteAllByEmployeeNumTestWithoutOptionP) {
	Employee deleteEmployee = { 12345678, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {1234, 5678}, {1990, 01, 01}, Certi::Certi_ADV };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_None, Option2::Option2_None, Column::Column_employeeNum, Column::Column_None, deleteEmployee };

	vector<Employee> result = deleteTest->Command(input);
	int deleteCount = 0;
	for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetEmployeeNum(), deleteEmployee.GetEmployeeNum());
		deleteCount++;
	}
	EXPECT_EQ(10, deleteCount);
	EXPECT_EQ(0, dataManager->getSize());
};

TEST_F(DeleteOption1Test, DeleteNoneByEmployeeNumTest) {
	Employee deleteEmployee = { 87654321, {"±è", "Ã¶¼ö"}, CareerLevel::CareerLevel_2,  {1234, 8765}, {1990, 02, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_p, Option2::Option2_None, Column::Column_employeeNum, Column::Column_None, deleteEmployee };

	vector<Employee> result = deleteTest->Command(input);
	size_t deleteCount = result.size();
	EXPECT_EQ(0, deleteCount);
	EXPECT_EQ(10, dataManager->getSize());
};

TEST_F(DeleteOption1Test, DeleteAllByNameTestWithOptionP) {
	Employee deleteEmployee = { 12345678, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {1234, 5678}, {1990, 01, 01}, Certi::Certi_ADV };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_p, Option2::Option2_None, Column::Column_Name, Column::Column_None, deleteEmployee };

	vector<Employee> result = deleteTest->Command(input);
	int deleteCount = 0;
	for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetName(), deleteEmployee.GetName());
		deleteCount++;
	}
	EXPECT_EQ(5, deleteCount);
	EXPECT_EQ(0, dataManager->getSize());
};

TEST_F(DeleteOption1Test, DeleteAllByNameTestWithoutOptionP) {
	Employee deleteEmployee = { 12345678, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {1234, 5678}, {1990, 01, 01}, Certi::Certi_ADV };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_None, Option2::Option2_None, Column::Column_Name, Column::Column_None, deleteEmployee };

	vector<Employee> result = deleteTest->Command(input);
	int deleteCount = 0;
	for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetName(), deleteEmployee.GetName());
		deleteCount++;
	}
	EXPECT_EQ(10, deleteCount);
	EXPECT_EQ(0, dataManager->getSize());
};

TEST_F(DeleteOption1Test, DeleteNoneByNameTest) {
	Employee deleteEmployee = { 87654321, {"±è", "Ã¶¼ö"}, CareerLevel::CareerLevel_2,  {1234, 8765}, {1990, 02, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_p, Option2::Option2_None, Column::Column_Name, Column::Column_None, deleteEmployee };

	vector<Employee> result = deleteTest->Command(input);
	size_t deleteCount = result.size();
	EXPECT_EQ(0, deleteCount);
	EXPECT_EQ(10, dataManager->getSize());
};

TEST_F(DeleteOption1Test, DeleteAllByCareerLevelWithOptionP) {
	Employee deleteEmployee = { 12345678, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {1234, 5678}, {1990, 01, 01}, Certi::Certi_ADV };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_p, Option2::Option2_None, Column::Column_CareerLevel, Column::Column_None, deleteEmployee };

	vector<Employee> result = deleteTest->Command(input);
	int deleteCount = 0;
	for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetCl(), deleteEmployee.GetCl());
		deleteCount++;
	}
	EXPECT_EQ(5, deleteCount);
	EXPECT_EQ(0, dataManager->getSize());
};

TEST_F(DeleteOption1Test, DeleteAllByCareerLevelWithoutOptionP) {
	Employee deleteEmployee = { 12345678, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {1234, 5678}, {1990, 01, 01}, Certi::Certi_ADV };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_None, Option2::Option2_None, Column::Column_CareerLevel, Column::Column_None, deleteEmployee };

	vector<Employee> result = deleteTest->Command(input);
	int deleteCount = 0;
	for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetCl(), deleteEmployee.GetCl());
		deleteCount++;
	}
	EXPECT_EQ(10, deleteCount);
	EXPECT_EQ(0, dataManager->getSize());
};

TEST_F(DeleteOption1Test, DeleteNoneByCareerLevelTest) {
	Employee deleteEmployee = { 87654321, {"±è", "Ã¶¼ö"}, CareerLevel::CareerLevel_2,  {1234, 8765}, {1990, 02, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_p, Option2::Option2_None, Column::Column_CareerLevel, Column::Column_None, deleteEmployee };

	vector<Employee> result = deleteTest->Command(input);
	size_t deleteCount = result.size();
	EXPECT_EQ(0, deleteCount);
	EXPECT_EQ(10, dataManager->getSize());
};

TEST_F(DeleteOption1Test, DeleteAllByPhoneNumTestWithOptionP) {
	Employee deleteEmployee = { 12345678, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {1234, 5678}, {1990, 01, 01}, Certi::Certi_ADV };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_p, Option2::Option2_None, Column::Column_PhoneNum, Column::Column_None, deleteEmployee };

	vector<Employee> result = deleteTest->Command(input);
	int deleteCount = 0;
	for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetPhoneNum(), deleteEmployee.GetPhoneNum());
		deleteCount++;
	}
	EXPECT_EQ(5, deleteCount);
	EXPECT_EQ(0, dataManager->getSize());
};

TEST_F(DeleteOption1Test, DeleteAllByPhoneNumTestWithoutOptionP) {
	Employee deleteEmployee = { 12345678, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {1234, 5678}, {1990, 01, 01}, Certi::Certi_ADV };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_None, Option2::Option2_None, Column::Column_PhoneNum, Column::Column_None, deleteEmployee };

	vector<Employee> result = deleteTest->Command(input);
	int deleteCount = 0;
	for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetPhoneNum(), deleteEmployee.GetPhoneNum());
		deleteCount++;
	}
	EXPECT_EQ(10, deleteCount);
	EXPECT_EQ(0, dataManager->getSize());
};

TEST_F(DeleteOption1Test, DeleteNoneByPhoneNumTest) {
	Employee deleteEmployee = { 87654321, {"±è", "Ã¶¼ö"}, CareerLevel::CareerLevel_2,  {1234, 8765}, {1990, 02, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_p, Option2::Option2_None, Column::Column_PhoneNum, Column::Column_None, deleteEmployee };

	vector<Employee> result = deleteTest->Command(input);
	size_t deleteCount = result.size();
	EXPECT_EQ(0, deleteCount);
	EXPECT_EQ(10, dataManager->getSize());
};

TEST_F(DeleteOption1Test, DeleteAllByBirthDayTestWithOptionP) {
	Employee deleteEmployee = { 12345678, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {1234, 5678}, {1990, 01, 01}, Certi::Certi_ADV };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_p, Option2::Option2_None, Column::Column_BirthDay, Column::Column_None, deleteEmployee };

	vector<Employee> result = deleteTest->Command(input);
	int deleteCount = 0;
	for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetBirthDay(), deleteEmployee.GetBirthDay());
		deleteCount++;
	}
	EXPECT_EQ(5, deleteCount);
	EXPECT_EQ(0, dataManager->getSize());
};

TEST_F(DeleteOption1Test, DeleteAllByBirthDayTestWithoutOptionP) {
	Employee deleteEmployee = { 12345678, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {1234, 5678}, {1990, 01, 01}, Certi::Certi_ADV };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_None, Option2::Option2_None, Column::Column_BirthDay, Column::Column_None, deleteEmployee };

	vector<Employee> result = deleteTest->Command(input);
	int deleteCount = 0;
	for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetBirthDay(), deleteEmployee.GetBirthDay());
		deleteCount++;
	}
	EXPECT_EQ(10, deleteCount);
	EXPECT_EQ(0, dataManager->getSize());
};

TEST_F(DeleteOption1Test, DeleteNoneByBirthDayTest) {
	Employee deleteEmployee = { 87654321, {"±è", "Ã¶¼ö"}, CareerLevel::CareerLevel_2,  {1234, 8765}, {1990, 02, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_p, Option2::Option2_None, Column::Column_BirthDay, Column::Column_None, deleteEmployee };

	vector<Employee> result = deleteTest->Command(input);
	size_t deleteCount = result.size();
	EXPECT_EQ(0, deleteCount);
	EXPECT_EQ(10, dataManager->getSize());
};

TEST_F(DeleteOption1Test, DeleteAllByCertiTestWithOptionP) {
	Employee deleteEmployee = { 12345678, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {1234, 5678}, {1990, 01, 01}, Certi::Certi_ADV };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_p, Option2::Option2_None, Column::Column_Certi, Column::Column_None, deleteEmployee };

	vector<Employee> result = deleteTest->Command(input);
	int deleteCount = 0;
	for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetCerti(), deleteEmployee.GetCerti());
		deleteCount++;
	}
	EXPECT_EQ(5, deleteCount);
	EXPECT_EQ(0, dataManager->getSize());
};

TEST_F(DeleteOption1Test, DeleteAllByCertiTestWithoutOptionP) {
	Employee deleteEmployee = { 12345678, {"È«", "±æµ¿"}, CareerLevel::CareerLevel_1,  {1234, 5678}, {1990, 01, 01}, Certi::Certi_ADV };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_None, Option2::Option2_None, Column::Column_Certi, Column::Column_None, deleteEmployee };

	vector<Employee> result = deleteTest->Command(input);
	int deleteCount = 0;
	for (const Employee& aEmployee : result) {
		EXPECT_EQ(aEmployee.GetCerti(), deleteEmployee.GetCerti());
		deleteCount++;
	}
	EXPECT_EQ(10, deleteCount);
	EXPECT_EQ(0, dataManager->getSize());
};

TEST_F(DeleteOption1Test, DeleteNoneByCertiTest) {
	Employee deleteEmployee = { 87654321, {"±è", "Ã¶¼ö"}, CareerLevel::CareerLevel_2,  {1234, 8765}, {1990, 02, 01}, Certi::Certi_PRO };
	InputParameter input = { CommandType::Command_Del, Option1::Option1_p, Option2::Option2_None, Column::Column_Certi, Column::Column_None, deleteEmployee };

	vector<Employee> result = deleteTest->Command(input);
	size_t deleteCount = result.size();
	EXPECT_EQ(0, deleteCount);
	EXPECT_EQ(10, dataManager->getSize());
};