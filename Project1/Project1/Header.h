#pragma once
#ifndef Header
#define Header

typedef struct student Student;

struct student{
	char* name;
	int ID;
	int Mark;
	Student* Next;
};

Student* Add(char** name, int* ID, int* Mark);
Student* AddInverse(char** name, int* ID, int* Mark);
void PrintList(Student* list);
Student* Find(Student* list, int ID);
void FindMark(Student* list, int mark);

#endif // !Header

