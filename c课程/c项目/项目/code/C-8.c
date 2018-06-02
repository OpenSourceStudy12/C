/*
** Release Info:
** Author: LiQiang
** Date: 2011/8/1
** Version: V1.0
** History:
*/

/*include files*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*local function*/



/* function:
** para:
** return value:
*/


struct node
{
	char *name;
	int num;
};



int main()
{
	struct node *pStu;
	char *p = NULL;

	p = (char *)malloc(sizeof(char) * 10);

	if (p == NULL)
	{
		...
	}

	strcpy(p, "LiQiang");

	....
	...

	free(p);

	p = NULL;

	....
	...


	if (p != NULL)
	{
		strcpy(p, "LiQiang");
	}


	

	pStu = (struct node *)malloc(sizeof(struct node));

	if (pStu == NULL)
	{
		...
	}

	strcpy(pStu->name, "liqiang");

}

