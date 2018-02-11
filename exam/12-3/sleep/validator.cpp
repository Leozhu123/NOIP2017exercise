#include "testlib.h"
int Input;
int main(int argc, char* argv[]) [
	registerTestlibCmd(argc, argv);
	Input=inf.readInt();
	if (3<=Input && Input<=1000000000) 
		quitf(_ok, "The data is correct.");
	else 
		quitf(_wa, "The data is wrong.");
}	