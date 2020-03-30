#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Student* CreateList()
{
	Student* head = (Student*)malloc(sizeof(Student));
	/*head->ID = NULL;
	head->Mark = 0.0f;
	head->name = NULL;*/
	head->Next = NULL;
	return head;
}

Student* CreateStudent(char* studentName, int ID, int Mark)
{
	
	Student* newStudent = (Student*)malloc(sizeof(Student));
	newStudent->ID = ID;
	newStudent->Mark = Mark;
	newStudent->name = studentName;
	newStudent->Next = NULL;
	return newStudent;
}

void PrintList(Student* list)
{
	Student* first = list->Next;
	while (first)
	{
		printf("Name: %s\nID: %d\nMark: %d\n->",first->name, first->ID, first->Mark);
		first = first->Next;
	}

	printf("NULL");

}

void Insert(Student* head, char* name, int ID, int Mark)
{
	Student* newStudent = CreateStudent(name, ID, Mark);

	newStudent->Next = head->Next;
	head->Next = newStudent;
}

Student* Add(char** name, int* ID, int* Mark)
{	
	Student* list = CreateList();

	int order[10] = {0,1,2,3,4,5,6,7,8,9};
	int temp = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = i; j < 10; j++)
		{
			if (Mark[i] > Mark[j])
			{
				temp = order[j];
				order[j] = order[i];
				order[i] = temp;
			}
		}
	}
	

	for (int i = 0; i < 10; i++)
	{
		Insert(list,name[order[i]*20], ID[order[i]], Mark[order[i]]);
	}

	return list;

}

Student* AddInverse(char **name, int* ID, int* Mark)
{
	Student* list = CreateList();

	for (int i = 9; i >= 0; i--)
	{
		Insert(list, name[i], ID[i], Mark[i]);
	}

	return list;

}

Student* Find(Student* list,int ID)
{
	Student* current = list->Next;
	while (current)
	{
		if (current->ID != ID)
		{
			current = current->Next;
		}
		else
			return current;

	}
	return NULL;
}

void FindMark(Student* list, int mark)
{
	Student* current = list->Next;
	while (current)
	{
		if (current->Mark >= mark)
		{
			printf("%d\n%d\n->", current->ID, current->Mark);
		}
		
		current = current->Next;
	}

	printf("NULL");
}