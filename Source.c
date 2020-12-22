#include <stdio.h>
#include "Stack.h"
#include "Test.h"

int main()
{
	if (test() == false)
	{
		printf("tests failed");
		return 1;
	}
	inputData("input.txt");
	return 0;
}