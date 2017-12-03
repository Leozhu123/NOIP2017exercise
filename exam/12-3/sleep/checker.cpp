#include "testlib.h"
int Input,Answer,usrAns;
int main(int argc, char* argv[]) 
{
	registerTestlibCmd(argc, argv);
	Input=inf.readInt();
	usrAns=ouf.readInt();
	Answer=Input/2;
	if(Input%2==1) ;
	else if(Answer%2==0) Answer=Answer-1;
		else Answer=Answer-2;
	if (Answer==usrAns)
		quitf(_ok, "The answer is correct.");
	else
		quitf(_wa, "The answer is wrong: expected = %d, found = %d", Answer, usrAns);
}
