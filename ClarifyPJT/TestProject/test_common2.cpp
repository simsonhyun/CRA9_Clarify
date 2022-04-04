#include "pch.h"
#include "../ClarifyPJT/RunProgram.h"

TEST(RunTest2, CheckRun1)
{
	RunProgram runProgram;
	runProgram.run("TestCase/input_20_20.txt", "CommonTestFiles/output_20_20_Result.txt");

	EXPECT_TRUE(runProgram.compareFiles("TestCase/output_20_20.txt", "CommonTestFiles/output_20_20_test.txt"));
}

TEST(RunTest2, CheckRun2)
{
	RunProgram runProgram;
	runProgram.run("CommonTestFiles/inputDelTest.txt", "CommonTestFiles/outputDelTestResult.txt");

	EXPECT_TRUE(runProgram.compareFiles("CommonTestFiles/outputDelTestCorrect.txt", "CommonTestFiles/outputDelTestResult.txt"));
}