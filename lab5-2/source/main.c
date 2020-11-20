#include<stdio.h>.
#include<stdlib.h>

#define issues 5
#define rateing 10

void recordresponse(int issuu, int rating);
void highrating();
void lowrating();
float averrating();
void displayresult();

int response[issues][rateing];
const char *topics[issues] = { "Global waring","The Economy","War","Health Care","Education" };

int main()
{
	int response, i;
	do
	{
		printf("Please rate the following topics on a scale from 1~10""\n1 = least important,10 = most important\n");

		for (i = 0; i < issues; i++)
		{
			do
			{
				printf("%s?", topics[i]);
				scanf_s("%d", &response);
			} while (response < 1 || response>10);
			recordresponse(i, response);
		}

		printf("Enter 1 to stop.Enter 0 to rate the issues again.");
		scanf_s("%d", &response);
	} while (response != 1);

	displayresult();
	system("pause");
	return 0;
}
void recordresponse(int issue, int rating)
{
	response[issue][rating - 1]++;
}
void highrating()
{
	int highrating = 0, hightopic = 0;
	int i, j;
	for (i = 0; i < issues; i++)
	{
		int toprating = 0;
		for (j = 0; j < rateing; j++)
		{
			toprating += response[i][j] * (j + 1);
		}
		if (highrating < toprating)
		{
			highrating += toprating;
			hightopic = i;
		}
	}
	printf("The highest rated topic was %s",topics[hightopic]);
	printf("with a total rating of %d\n", highrating);
}
void lowrating()
{
	int lowrating = 0, lowtopic = 0;
	int i, j;
	for (i = 0; i < issues; i++)
	{
		int toprating = 0;
		for (j = 0; j < rateing; j++)
		{
			toprating += response[i][j] * (j + 1);
		}
		if (i == 0)
		{
			lowrating = toprating;
		}
		if (lowrating > toprating)
		{
			lowrating = toprating;
			lowrating = i;
		}
	}
	printf("The lowest rated topic was %s", topics[lowtopic]);
	printf("with a total rating of %d\n", lowrating);
}
float averrating(int issue)
{
	float total = 0;
	int counter = 0;
	int i;
	for (i = 0; i < rateing; i++)
	{
		if (response[issue][i] != 0)
		{
			total += response[issue][i] * (i + 1);
			counter += response[issue][i];
		}
	}
	return total / counter;
}
void displayresult()
{
	int i, j;
	printf("%20s", "Topic");

	for (i = 1; i <= rateing; i++)
	{
		printf("%4d", i);
	}
	printf("%20s", "Averange Ratting");

	for (i = 0; i < issues; i++)
	{
		printf("%20s", topics[i]);

		for (j = 0; j < rateing; j++)
		{
			printf("%4d", response[i][j]);
		}
		printf("%20.2f", averrating(i));
	}
	highrating();
	lowrating();
}

