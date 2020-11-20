#include<stdio.h>
#include<stdlib.h>

#define Students 3
#define Exams 4

void miniumu(int grades[][Exams], int puplis, int tests);
void maxiumu(int grades[][Exams], int puplis, int tests);
void aver(int grades[][Exams], int puplis, int tests);
void printArray(int grades[][Exams], int puplis, int tests);
void printmenu();

int main()
{
	int studentgrades[Students][Exams] = { {77,68,86,73},{96,87,89,78},{70,90,86,81} };
	void(*processgrages[4])(int[Students][Exams], int, int) = { printArray,miniumu,maxiumu,aver };


	int choice = 0;

	while (choice != 4)
	{
		do
		{
			printmenu();
			scanf_s("%d", &choice);
		} while (choice < 0 || choice > 4);

		if (choice != 4)
		{
			(*processgrages[choice])(studentgrades, Students, Exams);
		}
		else
		{
			printf("\tProgram Ended. \n");
		}
	}
	system("pause");
	return 0;
}
void miniumu(int grades[][Exams], int puplis, int tests)
{
	int i, j;
	int lowgrade = 100;
	for (i = 0; i < puplis; i++)
	{
		for (j = 0; j < tests; j++)
		{
			if (grades[i][j] < lowgrade)
				lowgrade = grades[i][j];
		}
	}
	printf("\n\tThe lowest grade is %d", lowgrade);
	printf("\n");
}
void maxiumu(int grades[][Exams], int puplis, int tests)
{
	int i, j;
	int highgrade = 0;
	for (i = 0; i < puplis; i++)
	{
		for (j = 0; j < tests; j++)
		{
			if (grades[i][j] > highgrade)
				highgrade = grades[i][j];
		}
	}
	printf("\n\tThe highest grade is %d", highgrade);
	printf("\n");
}

void aver(int grades[][Exams], int puplis, int tests)
{
	int i, j, total;
	for (i = 0; i < puplis; i++)
	{
		total = 0;
		for (j = 0; j < tests; j++)
		{
			total += grades[i][j];
		}
		printf("\n\t The average grade for student %d is %.1f", i + 1, (double)total / tests);
	}
	printf("\n");
}
void printArray(int grades[][Exams], int puplis, int tests)
{
	int i, j;
	printf("\n\t\t\t[0][1][2][3]");
	for (i = 0; i < puplis; i++)
	{
		printf("\n\tstudentgrades[%d]", i);
		for (j = 0; j < tests; j++)
		{
			printf("%-7d", grades[i][j]);
		}
	}
	printf("\n");
}

void printmenu()
{
	printf("\n");
	printf("\tEnter a choice:\n");
	printf("\t0 Print the array of grade\n");
	printf("\t1 Find the minimum grade\n") ;
	printf("\t2 Find the maximum grade\n");
	printf("\t3 Print the average on all tests for each student\n") ;
	printf("\t4 End program\n") ;
	printf("\tChoice");
}

