#include "pch.h"
#include"../ClarifyPJT/Mod.h"
#include"../ClarifyPJT/Mod.cpp"

TEST(BasicModTest, NotOptionNotDupliModifyData) {
	DataManager dataManager = DataManager();
	Mod mod = Mod(dataManager);

	Employee employee(12345678, { "±æµ¿","È«" }, CareerLevel::CareerLevel_2, { 1234, 5678 }, { 1996,8,25 }, Certi::Certi_PRO);
	Employee employee2(12345680, { "±æµ¿","È«" }, CareerLevel::CareerLevel_2, {1357,2468 }, { 1990,1,13 }, Certi::Certi_ADV);
	Employee employee3(12345681, { "¼ø½Å","ÀÌ" }, CareerLevel::CareerLevel_2,{9876, 2453}, { 1993,5,20 }, Certi::Certi_EX);
	dataManager.setData(employee);
	dataManager.setData(employee2);
	dataManager.setData(employee3);
	InputParameter inputParameter = { CommandType::Command_Mod, Option1::Option1_None, Option2::Option2_None, 
										Column::Column_employeeNum, Column::Column_Certi,employee, employee2 };

	ASSERT_TRUE(mod.ModifyFunc(inputParameter).size()==1);
	vector<Employee> testvector = mod.getDataManager()->getData();
	
	ASSERT_TRUE(Certi::Certi_ADV == testvector[0].GetCerti());
	ASSERT_TRUE(Certi::Certi_ADV==testvector[1].GetCerti());
}
TEST(BasicModTest, NotOptionDupliModifyData) {
	DataManager dataManager = DataManager();
	Mod mod = Mod(dataManager);

	Employee employee(12345678, { "±æµ¿","È«" }, CareerLevel::CareerLevel_2, { 1234, 5678 }, { 1996,8,25 }, Certi::Certi_PRO);
	Employee employee2(12345680, { "±æµ¿","È«" }, CareerLevel::CareerLevel_2, { 1357,2468 }, { 1990,1,13 }, Certi::Certi_ADV);
	Employee employee3(12345681, { "¼ø½Å","ÀÌ" }, CareerLevel::CareerLevel_2, { 9876, 2453 }, { 1993,5,20 }, Certi::Certi_EX);
	dataManager.setData(employee);
	dataManager.setData(employee2);
	dataManager.setData(employee3);
	InputParameter inputParameter = { CommandType::Command_Mod, Option1::Option1_None, Option2::Option2_None,
										Column::Column_Name, Column::Column_Certi,employee, employee3 };

	ASSERT_TRUE(mod.ModifyFunc(inputParameter).size() == 2);
	
	vector<Employee> testvector = mod.getDataManager()->getData();
	ASSERT_TRUE(Certi::Certi_EX == testvector[0].GetCerti());
	ASSERT_TRUE(Certi::Certi_EX == testvector[1].GetCerti());
}
TEST(BasicModTest, Option2NameModifyData) {
	DataManager dataManager = DataManager();
	Mod mod = Mod(dataManager);

	Employee employee(12345678, { "±æµ¿","È«" }, CareerLevel::CareerLevel_2, { 1234, 5678 }, { 1996,8,25 }, Certi::Certi_PRO);
	Employee employee2(12345680, { "±æµ¿","±è" }, CareerLevel::CareerLevel_2, { 1357,2468 }, { 1990,1,13 }, Certi::Certi_ADV);
	Employee employee3(12345681, { "¼ø½Å","ÀÌ" }, CareerLevel::CareerLevel_3, { 9876, 2453 }, { 1993,5,20 }, Certi::Certi_EX);
	dataManager.setData(employee);
	dataManager.setData(employee2);
	dataManager.setData(employee3);
	InputParameter inputParameter = { CommandType::Command_Mod, Option1::Option1_None, Option2::Option2_Name_f,
										Column::Column_Name, Column::Column_CareerLevel,employee, employee3 };

	ASSERT_TRUE(mod.ModifyFunc(inputParameter).size() == 2);
	vector<Employee> testvector = mod.getDataManager()->getData();

	ASSERT_TRUE(CareerLevel::CareerLevel_3 == testvector[0].GetCl());
	ASSERT_TRUE(CareerLevel::CareerLevel_3 == testvector[1].GetCl());
}
TEST(BasicModTest, Option2phoneModifyData) {
	DataManager dataManager = DataManager();
	Mod mod = Mod(dataManager);

	Employee employee(12345678, { "±æµ¿","È«" }, CareerLevel::CareerLevel_1, { 1234, 5678 }, { 1996,8,25 }, Certi::Certi_PRO);
	Employee employee2(12345680, { "±æµ¿","±è" }, CareerLevel::CareerLevel_2, { 1357,5678 }, { 1990,1,13 }, Certi::Certi_ADV);
	Employee employee3(12345681, { "¼ø½Å","ÀÌ" }, CareerLevel::CareerLevel_3, { 9876, 2453 }, { 1993,5,20 }, Certi::Certi_EX);
	dataManager.setData(employee);
	dataManager.setData(employee2);
	dataManager.setData(employee3);
	InputParameter inputParameter = { CommandType::Command_Mod, Option1::Option1_None, Option2::Option2_PhoneNum_l,
										Column::Column_PhoneNum, Column::Column_BirthDay,employee, employee3 };

	ASSERT_TRUE(mod.ModifyFunc(inputParameter).size() == 2);
	vector<Employee> testvector = mod.getDataManager()->getData();

	ASSERT_TRUE(employee3.GetBirthDay()== testvector[0].GetBirthDay());
	ASSERT_TRUE(employee3.GetBirthDay() == testvector[1].GetBirthDay());
}
TEST(BasicModTest, Option1DupliModifyData) {
	DataManager dataManager = DataManager();
	Mod mod = Mod(dataManager);

	Employee employee(12345678, { "±æµ¿","È«" }, CareerLevel::CareerLevel_2, { 1234, 5678 }, { 1996,8,25 }, Certi::Certi_PRO);
	Employee employee2(12345680, { "±æµ¿","È«" }, CareerLevel::CareerLevel_2, { 1357,2468 }, { 1990,1,13 }, Certi::Certi_ADV);
	Employee employee3(12345681, { "¼ø½Å","ÀÌ" }, CareerLevel::CareerLevel_2, { 9876,2453 }, { 1993,5,20 }, Certi::Certi_EX);
	Employee employee4(12345682, { "±æµ¿","È«" }, CareerLevel::CareerLevel_3, { 4357,2468 }, { 1990,1,13 }, Certi::Certi_EX);
	Employee employee5(12345683, { "±æµ¿","È«" }, CareerLevel::CareerLevel_4, { 2557,2464 }, { 1991,1,13 }, Certi::Certi_ADV);
	Employee employee6(12345683, { "±æµ¿","È«" }, CareerLevel::CareerLevel_3, { 2556,7254 }, { 1992,1,13 }, Certi::Certi_ADV);
	Employee employee7(12345684, { "±æµ¿","È«" }, CareerLevel::CareerLevel_3, { 2556,7252 }, { 1992,2,13 }, Certi::Certi_ADV);
	dataManager.setData(employee);
	dataManager.setData(employee2);
	dataManager.setData(employee3);
	dataManager.setData(employee4);
	dataManager.setData(employee5);
	dataManager.setData(employee6);
	dataManager.setData(employee7);
	InputParameter inputParameter = { CommandType::Command_Mod, Option1::Option1_p, Option2::Option2_None,
										Column::Column_Name, Column::Column_Certi,employee, employee3 };
	vector<Employee> resultOption1 = mod.ModifyFunc(inputParameter);
	ASSERT_TRUE(resultOption1.size() != 6);
	ASSERT_TRUE(resultOption1.size() == 5);

	vector<Employee> testvector = mod.getDataManager()->getData();
	for (int i = 0; i < testvector.size(); i++) {
		ASSERT_TRUE(testvector[i].GetCerti() == Certi::Certi_EX);
	}
}

TEST(BasicModTest, Option1and2ModifyData) {
	DataManager dataManager = DataManager();
	Mod mod = Mod(dataManager);

	Employee employee(12345678, { "±æµ¿","È«" }, CareerLevel::CareerLevel_2, { 1234, 5678 }, { 1996,8,25 }, Certi::Certi_PRO);
	Employee employee2(12345680, { "½Åµ¿","È«" }, CareerLevel::CareerLevel_2, { 1357,2468 }, { 1990,1,13 }, Certi::Certi_ADV);
	Employee employee3(12345681, { "¼ø½Å","ÀÌ" }, CareerLevel::CareerLevel_2, { 9876,2453 }, { 1993,5,20 }, Certi::Certi_EX);
	Employee employee4(12345682, { "°íµ¿","È«" }, CareerLevel::CareerLevel_3, { 4357,2468 }, { 1990,1,13 }, Certi::Certi_EX);
	Employee employee5(12345683, { "¼Òµ¿","È«" }, CareerLevel::CareerLevel_4, { 2557,2464 }, { 1991,1,13 }, Certi::Certi_ADV);
	Employee employee6(12345683, { "¸¶µ¿","È«" }, CareerLevel::CareerLevel_3, { 2556,7254 }, { 1992,1,13 }, Certi::Certi_ADV);
	Employee employee7(12345684, { "±¸µ¿","È«" }, CareerLevel::CareerLevel_3, { 2556,7252 }, { 1992,2,13 }, Certi::Certi_ADV);
	dataManager.setData(employee);
	dataManager.setData(employee2);
	dataManager.setData(employee3);
	dataManager.setData(employee4);
	dataManager.setData(employee5);
	dataManager.setData(employee6);
	dataManager.setData(employee7);
	InputParameter inputParameter = { CommandType::Command_Mod, Option1::Option1_p, Option2::Option2_Name_l,
										Column::Column_Name, Column::Column_Certi,employee, employee3 };

	ASSERT_TRUE(mod.ModifyFunc(inputParameter).size() == 5);

	vector<Employee> testvector = mod.getDataManager()->getData();
	for (int i = 0; i < testvector.size(); i++) {
		ASSERT_TRUE(testvector[i].GetCerti() == Certi::Certi_EX);
	}
}