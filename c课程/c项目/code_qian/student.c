/*
*/
/*include files*/
#include "student.h"


/*MACRO*/


/*local function */



//struct student stu1;
STUDENT stu1;
//, stu2;

int main()
{

	stu1 = {1, "LiQiang"};


	stu1.num = 001;

	stu1.pname = (char *)malloc(32);
	strcpy(stu1.pname, "LiQiang");

}







