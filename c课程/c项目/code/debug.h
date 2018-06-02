#ifndef _DEBUG_H_
#define _DEBUG_H_

#include<stdio.h>

#define _DEBUG_
#undef _DEBUG_
#ifdef  _DEBUG_
#define Debug(fmt,args...)   printf(fmt,##args)
#define trace()  printf("\nThe file  :\t%s\nThe function:\t%s\nThe line  :\t%d\nThe time  :\t%s\nThe data  :\t%s\n",_FILE_,\
		_func_,_LINE_,_TIME_,_DATA_)
#else
#define Debug(fmt,args...)
#define trace()

#endif
#endif

