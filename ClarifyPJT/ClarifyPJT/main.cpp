#include "RunProgram.h"

int main(int argc, char* argv[])
{
	RunProgram* runProgram = new RunProgram();

	if (runProgram->checkArgument(argc))
	{
		runProgram->run(argv[1], argv[2]);
	}
	else
	{
		cout << "Please Check Argument" << endl;
		cout << "Current Argc : " << argc << endl;
	}

	return 0;
}