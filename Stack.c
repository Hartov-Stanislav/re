#include "Stack.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Stack
{
	int day;
	int month;
	int year;
	struct Stack* next;
};

struct Stack* newStack()
{
	struct Stack* head = NULL;
	return head;
}

struct Stack* addElement(struct Stack* head, int day,int month, int year)
{
	struct Stack* newElement = malloc(sizeof(struct Stack));
	if (newElement == NULL)
	{
		return 0;
	}
	newElement->next = head;
	newElement->day = day;
	newElement->month = month;
	newElement->year = year;
	head = newElement;
	return head;
}

bool isEmpty(struct Stack* head)
{
	return head == NULL;
}

int deleteTop(struct Stack** head)
{
	if (*head == NULL)
	{
		return NULL;
	}
	int temp = (*head)->year+ (*head)->month*1000+ (*head)->year*100000;
	struct Stack* oldElement = *head;
	*head = oldElement->next;
	free(oldElement);
	return temp;
}

void deleteStack(struct Stack** head)
{
	while (*head != NULL)
	{
		deleteTop(head);
	}
}

int searchData(struct Stack* head)
{
	struct Stack* newHead = head;
	int day = 0;
	int month = 0;
	int year = 0;
	while (newHead->next != NULL)
	{
		if (newHead->year >= year && newHead->month >= month && newHead->day >= day)
		{
			year = newHead->year;
			month = newHead->month;
			day = newHead->day;
		}
		newHead = newHead->next;
	}
	return (year + 10000 * month + 1000000 * day);
}

void inputData(const char* filename)
{
	FILE* input = fopen(filename, "r");
	if (input == NULL)
	{
		printf("Cannot open file.\n");
		return NULL;
	}
	struct Stack* head = NULL;
	do
	{
		int day;
		int month;
		int year;
		char point;
		fscanf(input, "%d", &day);
		fscanf(input, "%c", &point);
		fscanf(input, "%d", &month);
		fscanf(input, "%c", &point);
		fscanf(input, "%d", &year);
		head = addElement(head, day, month, year);
	} while (!feof(input));
	fclose(input);
	int answer = searchData(head);
	deleteStack(&head);
	printf("%d%d.%d%d.%d", answer / 10000000, answer / 1000000 % 10, answer / 100000 % 10, answer / 10000 % 10, answer % 10000);
}