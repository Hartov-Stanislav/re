#pragma once
#include <stdbool.h>

typedef struct Stack;

struct Stack* addElement(struct Stack* head, int day, int month, int year);

bool isEmpty(struct Stack* head);

int deleteTop(struct Stack** head);

void deleteStack(struct Stack** head);

int searchData(struct Stack* head);

void inputData(const char* filename);
