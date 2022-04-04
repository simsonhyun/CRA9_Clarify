#include "pch.h"
#include "../ClarifyPJT/RunProgram.h"

class RunTest : public ::testing::Test {
protected:
	void SetUp() override 
	{
		Employee employee1 = { 15123099, {"JHOP", "VXIHXOTH"}, CareerLevel::CareerLevel_3,  {3112, 2609}, {1977, 12, 11}, Certi::Certi_ADV };

		runProgram->init();
		runProgram->_run("ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV");
		runProgram->_run("ADD, , , ,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO");
		runProgram->_run("ADD, , , ,18115040,TTETHU HBO,CL3,010-4581-2050,20080718,ADV");
		runProgram->_run("ADD, , , ,88114052,NQ LVARW,CL4,010-4528-3059,19911021,PRO");
		runProgram->_run("ADD, , , ,19129568,SRERLALH HMEF,CL2,010-3091-9521,19640910,PRO");
		runProgram->_run("ADD, , , ,17111236,VSID TVO,CL1,010-3669-1077,20120718,PRO");
		runProgram->_run("ADD, , , ,18117906,TWU QSOLT,CL4,010-6672-7186,20030413,PRO");
		runProgram->_run("ADD, , , ,08123556,WN XV,CL1,010-7986-5047,20100614,PRO");
		runProgram->_run("ADD, , , ,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV");
		runProgram->_run("ADD, , , ,03113260,HH LTUPF,CL2,010-5798-5383,19791018,PRO");
		runProgram->_run("ADD, , , ,14130827,RPO JK,CL4,010-3231-1698,20090201,ADV");
		runProgram->_run("ADD, , , ,01122329,DN WD,CL4,010-7174-5680,20071117,PRO");
		runProgram->_run("ADD, , , ,08108827,RTAH VNUP,CL4,010-9031-2726,19780417,ADV");
		runProgram->_run("ADD, , , ,85125741,FBAH RTIJ,CL1,010-8900-1478,19780228,ADV");
		runProgram->_run("ADD, , , ,08117441,BMU MPOSXU,CL3,010-2703-3153,20010215,ADV");
		runProgram->_run("ADD, , , ,10127115,KBU MHU,CL3,010-3284-4054,19660814,ADV");
		runProgram->_run("ADD, , , ,12117017,LFIS JJIVL,CL1,010-7914-4067,20120812,PRO");
		runProgram->_run("ADD, , , ,11125777,TKOQKIS HC,CL1,010-6734-2289,19991001,PRO");
		runProgram->_run("ADD, , , ,11109136,QKAHCEX LTODDO,CL4,010-2627-8566,19640130,PRO");
		runProgram->_run("ADD, , , ,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO");
	}

	void TearDown() override 
	{
		;
	}

public:
	RunProgram* runProgram = new RunProgram();
};


//TEST_F(RunTest, CheckRun0)
//{
//	EXPECT_EQ(runProgram->_run("SCH,-p,-d, ,birthday,04"), "SCH,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV");
//	EXPECT_EQ(runProgram->_run("MOD,-p, , ,name,FB NTAWR,birthday,20050520"), "MOD,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO");
//	EXPECT_EQ(runProgram->_run("SCH, , , ,employeeNum,79110836"), "SCH,NONE");
//	EXPECT_EQ(runProgram->_run("DEL, , , ,employeeNum,18115040, ,birthday,04"), "DEL,1");
//	EXPECT_EQ(runProgram->_run("SCHDEL,-p,-l, ,name,MPOSXU"), "DEL,08117441,BMU MPOSXU,CL3,010-2703-3153,20010215,ADV");
//	EXPECT_EQ(runProgram->_run("SCH,-p, , ,certi,PRO"), "SCH,88114052,NQ LVARW,CL4,010-4528-3059,19911021,PRO\
//SCH, 01122329, DN WD, CL4, 010 - 7174 - 5680, 20071117, PRO\
//SCH, 03113260, HH LTUPF, CL2, 010 - 5798 - 5383, 19791018, PRO\
//SCH, 05101762, VCUHLE HMU, CL4, 010 - 3988 - 9289, 20030819, PRO\
//SCH, 08123556, WN XV, CL1, 010 - 7986 - 5047, 20100614, PRO");
//}

TEST(RunTest2, CheckRun1)
{
	RunProgram runProgram;

	runProgram.init();
	runProgram.run("TestCase/input_20_20.txt", "output_20_20_test.txt");

	EXPECT_TRUE(runProgram.compareFiles("output_20_20_test.txt", "TestCase/output_20_20.txt"));
}