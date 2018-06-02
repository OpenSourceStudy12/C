#ifndef _TRAINNU_H
#define _TRAINNU_H
/*
	trainnu : train number
	作用：
	定义车次链表的结构
	创建，修改，删除车次链表，
*/
#define TRAIN_DB "train.db" 
#define MAX_NAME 10
#define MAX_ARR_TRAINNU 10

typedef struct _station
{
	int train_nu;          // 车次
	char station_name[10];  // 车站名
	struct _station *next; //下一个车站

}NStation, *PNStation;

/*
	函数作用：从文件中读取车次链表
	参数    ：
	          size ：保存了全部车次链表的条数	
	返回值  ：指向车次链表首地址的指针数组
	
	
*/
PNStation* readTrainnu(int *size);




/*
	函数作用：创建车次链表
	返回值  ：指向车次链表首地址的指针
*/
PNStation createTrainnu();



/*
	函数作用：查看一班车次链表
	参数    ：车次链表头指针	
*/
void traverseTrainnu(PNStation start);



/*
	函数作用： 把添加了的车次写入文件
	参数    ： 车次链表都指针
*/
void writeTrainnu(PNStation start);


/*
	函数作用 ：遍历所有车次
	参数     ：车次数组的首地址
*/

void traverseAllTrainnu(PNStation *arr_start, int arr_size);


/*
	函数作用  ：通过列车车号查找列车	
*/
PNStation searchTrainByNu(int num, PNStation *arr_start, int arr_size);

/*
	函数作用 ： 在车次数组中通过车次号码找到车次，并删除
*/

void delOneTrain(PNStation *arr_start, int arr_size, int nu);

/*
	函数作用 ： 删除一条车次
*/
void dropTrain(PNStation *phead);

/*
	函数作用 ：将所有车次写入文件
*/
void writeAllTrainnu(PNStation* arr_start, int arr_size);





#endif
