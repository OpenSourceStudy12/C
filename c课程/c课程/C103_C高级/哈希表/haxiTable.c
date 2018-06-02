#include <stdio.h>
#include <stdlib.h>


#define NIL -1 
#define M 11         //表长度
typedef int KeyType;
typedef struct node
{   //哈希表结点类型
	KeyType key;
   char name[20];
	char sex;
	float score;
}HashType;

//用除余法求K的哈希地址的函数h 
int h(KeyType K)
{ 
	return K%M; 
}

int Increment(int i)   //用线性探查法求第i个增量di 
{ 
	return i; 
} 

//求在哈希表T[0..M-1]中第i次探查的哈希地址hi，0≤i≤M-1
int Hash(KeyType k,int i)
{ 
    return (h(k)+Increment(i))%M; 
}

//在哈希表T[0..M-1]中查找K,成功时返回1。失败有两种情况：找到一个开放址时返回0;表满未找到时返回-1
int HashSearch(HashType T[],KeyType K,int *pos)
{ 
        int i=0;                //记录探查次数 
        do
        { 
	     printf("*********\n");
	     *pos=Hash(K,i);   //求探查地址hi
	     if(T[*pos].key==K) 
		    return 1;
	     if(T[*pos].key==NIL) 
	            return 0;  //查找到空结点返回
     }while(++i<M);            //最多做M次探查 
     return -1; 
}         

void Hashlnsert(HashType T[],HashType newnode)
{ 
  
        int pos,sign;
  sign=HashSearch(T,newnode.key,&pos);   
  if(!sign)         //找到一个开放的地址pos 
        T[pos]=newnode; //插入新结点newnode，插入成功
  else if(sign>0) //插人失败
        printf("重复的关键字!");
  else 
  {  
        printf("表满错误,终止程序执行!");
        return;
  }
}

//根据A[0..n-1]中结点建立哈希表T[0..M-1]
void CreateHashTable(HashType T[],HashType A[],int n)
{
	int i;  
	if(n>M)//用开放定址法处理冲突时，装填因子α须不大于1
	{    
                printf("装填因子α须不大于1");
                return;
 	}
	for(i=0;i<M;i++)
     	        T[i].key=NIL;   //将各关键字清空，使地址i为开放地址
	for(i=0;i<n;i++)  //依次将A[0..n-1]插入到哈希表T[0..m-1]中
                Hashlnsert(T,A[i]);
} 



int main()
{
	HashType stu[] = {{20,"aaa",'M',99},{30,"BBB"},{70,"CCC"},{15,"ddd"},{8,"eee"},{12,"ccc"},{18,"ttt"},{63,"ppp"},{19,"kkk"}};
	//申请哈系表空间
	HashType *hashTable = malloc(sizeof(HashType)*M);
	CreateHashTable(hashTable,stu,sizeof(stu)/sizeof(HashType));


	int i;
	for(i=0;i<M;i++)
	{
		printf("%d   :    %d     %s\n",i, hashTable[i].key, hashTable[i].name);
	}
	
	int index;
	int re = HashSearch(hashTable,20,&index);
	if(re == 1)
	{
		printf("找到了，位置:%d    %d:%s\n",index,hashTable[index].key,hashTable[index].name);
	}
	else
	{
		printf("不存在\n");
	}
	
	


}
