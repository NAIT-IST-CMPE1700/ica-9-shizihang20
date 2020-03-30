#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "Header.h"

int main()
{

	char *NameList[10] = { "qwe","asd","zxc","wer","sdf","xcv","ert","dfg","cvb","rty" };
	int ID[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int Mark[10] = { 10,20,30,40,50,60,70,100,90,80 };
	int tempID,tempMark;

	Student* Normal = NULL;
	Student* Inverse = NULL;

	Inverse = Add(*NameList, ID, Mark);
	Normal = AddInverse(NameList, ID, Mark);

	int choice;
	int now = 1;

	while (now)
	{
		system("cls");
		printf("1.Display list in order of Id¡¯s\n2.Display list in descending order of Marks\n3.Display the names, marks and rank of a person given the ID(1---10)\n4.Display the names and marks of all person above a threshold marks value(0-100).\n5.Exit");
		printf("\nEnter you choice:");
		scanf_s("%d", &choice);



		switch (choice)
		{
		case 1:
			PrintList(Normal);
			printf("\n");
			system("pause");
			break;
		case 2:
			PrintList(Inverse);
			printf("\n");
			system("pause");
			break;
		case 3:
			printf("Enter the ID:");
			scanf_s("%d", &tempID);
			Student* temp = Find(Normal, tempID);
			if (temp == NULL)
			{
				printf("Error, null person");
				break;
			}
			printf("%d\n%d", temp->ID, temp->Mark);
			printf("\n");
			system("pause");
			break;
		case 4:
			printf("Enter the Mark:");
			scanf_s("%d", &tempMark);
			FindMark(Normal, tempMark);
			printf("\n");
			system("pause");
			break;
		case 5:
			now = 0;
			break;
		}
		
	}
	
	return 0;
}