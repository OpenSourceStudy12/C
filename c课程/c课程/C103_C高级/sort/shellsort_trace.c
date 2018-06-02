#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH 9

void shellsort(int v[], int n);
void arrayPrintf(int v[], int n);
void traceShellsort(int v[], int n);
int traceOut(int n, int gap, int i, int j, int isnewline);
int traceCount;

int main(void) 
{
	int arr[ARRAY_LENGTH] = { 12, 2, 20, 19, 28, 30, 12, 42, 35 };
	
	printf("Original array:\t\t");
	arrayPrintf(arr, ARRAY_LENGTH);
	/*sort the array by shell arithmetic*/
	//shellsort(arr, ARRAY_LENGTH);
	traceShellsort(arr, ARRAY_LENGTH);
	putchar('\n');
	printf("MinToMax array:\t\t");
	arrayPrintf(arr, ARRAY_LENGTH);
	return EXIT_SUCCESS;
}

/*shellsort函数：按递增顺序对v[0]…v[n-1]进行排序*/
void shellsort(int v[], int n) 
{
	int gap, i, j, temp;
	
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < n; i++)
		{
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) 
			{
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
		}
	}
	return;
}
/*shell排序算法的跟踪版，相同的算法，它将输出带有跟踪过程的数据*/
void traceShellsort(int v[], int n) 
{
	int gap, i, j, temp;
	extern int traceCount;
	traceCount = 1;
	for (gap = n / 2; gap > 0; gap /= 2) 
	{
		for (i = gap; i < n; i++) 
		{
			for (j = i - gap; traceOut(n, gap, i, j, !(j >= 0 && v[j] > v[j	+ gap])) && j >= 0 && v[j] > v[j + gap]; j -= gap) 
			{
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
				arrayPrintf(v, n);
			}
		}
	}
}
/*用于跟踪交换过程*/
int traceOut(int n, int gap, int i, int j, int isnewline) 
{
	printf("%2d. n=%d gap=%d i=%d j=%2d %c", traceCount++, n, gap, i, j,isnewline ? '\n' : ' ');
	return 1;
}
/*用于输出一组数组*/
void arrayPrintf(int v[], int n) 
{
	int i;
	
	for (i = 0; i < n; i++)
		printf("%d ", v[i]);
	putchar('\n');
	return;
}
