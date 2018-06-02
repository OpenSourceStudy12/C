#include <stdlib.h>
#include <stdio.h>



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


int main()
{
	int i;
	int a[]= {99,7,9,10,1,4,20};
	
	shellsort(a,7);
	
	for(i = 0;i<7;i++)
		printf("a[%d] = %d\n",i+1,a[i]);
	return 0;
}

