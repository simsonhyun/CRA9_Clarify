#include "pch.h"
#include "../ClarifyPJT/RunProgram.h"

TEST(RunTest2, CheckRun1)
{
	RunProgram runProgram;
	runProgram.run("TestCase/input_20_20.txt", "CommonTestFiles/output_20_20_test.txt");

	EXPECT_TRUE(runProgram.compareFiles("TestCase/output_20_20.txt", "CommonTestFiles/output_20_20_test.txt"));
}