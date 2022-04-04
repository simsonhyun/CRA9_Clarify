#include "RunProgram.h"

int main(int argc, char* argv[])
{
	RunProgram* runProgram = new RunProgram();

	runProgram->init();
	runProgram->_run("ADD, , , ,17111236,VSID TVO,CL1,010-3669-1077,20120718,PRO");

	return 0;
}