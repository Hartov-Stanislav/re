#include <stdbool.h>
#include <stdlib.h>
#include "Test.h"
#include "Stack.h"

bool case1()
{
	struct Stack* head = NULL;
	head = addElement(head, 1, 2 , 03);
	head = addElement(head, 5, 9 , 1956);
	head =addElement(head, 13, 12 , 2020);
	head = addElement(head, 24, 12 , 2020);
	if (searchData(head) == 24122020)
	{
		free(head);
		return true;
	}
	else
	{
		free(head);
		return false;
	}
}

bool case2()
{
	struct Stack* head = NULL;
	head = addElement(head, 24, 12, 2020);
	head = addElement(head, 24, 12, 2020);
	head = addElement(head, 24, 12, 2020);
	head = addElement(head, 24, 12, 2020);
	if (searchData(head) == 24122020)
	{
		free(head);
		return true;
	}
	else
	{
		free(head);
		return false;
	}
}

bool test()
{
	return (case1() && case2());
}
