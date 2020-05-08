#include <stdio.h>

//Function declarations.  
int * getNums();
int sort(int p);  
void outSort(int p);

int main()
{
	while (1) {

		char str[255];
		int *ptr;

		printf("Type in anything to continue\n");
		printf("Or type Q to quit.\n");

		scanf("%s", str);

		if (*str == 81) //This time this is a more precise way to check if input is capital Q.
		{						
			exit(0);
		}
		
		printf("Enter 10 numbers, please.\n");

		ptr = getNums(); //Function one.  The pointer ptr holds the array of getNums.

		sort(ptr);  //sort then takes that ptr and works it's magic.  (Courtesy of the videos.)
	}				//You'll notice only 2 functions called in main.  Funcion 3 (outSort) is called in function 2, thus no need to call it here. 

	return 0;
}

int * getNums()
{
	

	static int nums[10];

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &nums[i]);

	
	}
	//printf("You gave me:  %d", nums[0]);



	return nums;

}

int sort(int p)
{
	int *ptr = p;
	for (int i = 0; i < 10; i++)
		printf("\nThis num is: %d", *(ptr + i));

	int swapped;

	while (1) 
	{
		swapped = 0;

		for (int i = 0; i < 10; i++)
		{
			if (*(ptr + i) > *(ptr + (i + 1)))
			{
				int temp = *(ptr + i);
				*(ptr + i) = *(ptr + (i + 1));
				*(ptr + (i + 1)) = temp;
				swapped = 1;
			}
		}

		if (swapped == 0)
		{
			break;
		}

	}

	//return ptr;
	outSort(ptr);
	

}

void outSort(int p)
{

	int *ptr = p;

	FILE *fptr;

	fptr = fopen("ten.txt", "w");
	if (fptr == NULL)
	{
		printf("Error opening file.");
		return -1;
	}

	printf("\nSortedList: \n");
	for (int i = 1; i < 11; i++) {
		printf("%d\n", *(ptr + i));
		fprintf(fptr, "%d\n", *(ptr + i));
	}

	fclose(fptr);
}