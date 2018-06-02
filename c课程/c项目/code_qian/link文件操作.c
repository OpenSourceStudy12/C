#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int data;
	struct node *next;
}Lnode,*pNode;

int link_print(pNode phead);

/*create the link
*function name: creat_link
*param: phead :the address of the first node pointer
*return value :0: create successful; -1:create  fail
*other instruction:
*/
int link_create(Lnode **pHead)
{
	Lnode *temp=NULL;
	int x;
	scanf("%d",&x);
	while(x!=0)
	{
		temp=(Lnode *)malloc(sizeof(Lnode));
		if(temp == NULL)
		{
			return -1;
		}
		temp->data=x;
		if(*pHead == NULL)/*the first node*/
		{
			temp->next = NULL;
			*pHead = temp; 
		}
		else /*other node*/
		{
			temp->next=*pHead;
			*pHead = temp;
		}
		scanf("%d",&x);
	}
	return 0;
}
int link_getLenth(pNode phead)
{
	pNode p = phead;
	int len = 0;
/*	if(phead == NULL)
	{
		return len;
	}*/
	while(p)
	{
		len++;
		p = p->next;
	}
	return len;
}
Lnode * link_find(pNode phead, int index)
{
	pNode p=phead;
	int i=0;
	int len=link_getLenth(phead);
	if((index < 1)||(index > len)) /*入参检查*/
	{
		printf("param error,%s:%d!\n",__FILE__,__LINE__);
		return NULL;
	}
	for(i=0;i<index-1; i++)
	{
		p=p->next;
		if(p == NULL)
		{
			break;
		}
	}
	return p;
}

Lnode * link_find2(pNode phead, int data)
{
}
/*insert a new node to the link
*function name: link_insert
*param: phead :the address of the first node pointer
*        index :the position of the inserting node
*          data : the value of the inserting node
*return value :0: insert successful; -1:insert  fail
*other instruction: the number of the first node is 1, 
*        在第一个结点之前插入结点，index 入参值为1，依次类推
*/
Lnode * link_insert(pNode phead, int index,int data)
{
	pNode s=NULL,p=NULL;
	//s=(pNode)malloc(sizeof(Lnode));
	//s->data=data;
	if(index < 1)
	{
		printf("param error,%s:%d!\n",__FILE__,__LINE__);
		return phead;
	}
	s=(pNode)malloc(sizeof(Lnode));
	s->data=data;
	if(index == 1)/*在第一个结点之前插入结点*/
	{
		s->next=phead;
		phead = s;
	}
	else
	{
		p = link_find(phead,index-1);
		if(p!=NULL)/*第i-1个结点存在*/
		{
			s->next= p->next;
			p->next=s;
		}
		else
		{
			printf("insert opertion error!\n");
		}
	}
	return phead;
}
/*insert a new node to the link
*function name: link_insert
*param: phead :the address of the first node pointer
*        index :the position of the inserting node
*          data : the value of the inserting node
*return value :0: insert successful; -1:insert  fail
*other instruction: the number of the first node is 1, 
*        在第一个结点之前插入结点，index 入参值为1，依次类推
*/
int link_insert2(pNode *phead, int index,int data)
{

}
/*
*function name: link_modify
*param: add :the address of the modified node pointer
*return value :0: modified successful; -1:modified  fail
*other instruction:
*/
int link_modify(Lnode *add, int newData)
{
	if(add == NULL)
	{
	printf("param error,%s:%d!\n",__FILE__,__LINE__);
		return -1;
	}
	add->data=newData;
	return 0;
}
Lnode * link_delete(pNode phead, int index)
{
}
int link_delete2(pNode *phead, int index)
{

}
pNode getMaxValue(pNode phead)
{
	pNode p=phead;
	pNode pMax = p;
	if(phead == NULL)
	{
		return NULL;
	}
	while(p)
	{
		if(p->data > pMax->data)
		{
			pMax = p;
		}
		p = p->next;
	}
	return pMax;
}
pNode deleFormOld(pNode pold, pNode pMax)
{
	pNode p=pold;
	if(pold == NULL)
	{
		printf("empty link\n");
		return pold;
	}
	if(p == pMax)
	{
		pold=pold->next;
		p->next;
		return pold;
	}
	while(p)
	{
		if(p->next == pMax)
		{
			p->next = pMax->next;
			//free(pmax); /*空间留给新链表用*/
			break;
		}
		p = p->next;
	}
	return pold;
}
pNode addToNew(pNode pnew, pNode pMax)
{
	if(pnew == NULL) /*empty link*/
	{
		pnew=pMax;
		pnew->next = NULL;
	}
	else
	{
		pMax->next = pnew;
		pnew = pMax;
	}
	return pnew;
}
pNode sort(pNode *pOld)
{
	int len,i;
	pNode pMax;
	pNode pNew=NULL;
	if(*pOld == NULL)
	{
		return *pOld;
	}
	len = link_getLenth(*pOld);
	
	for(i=0;i<len;i++)
	{
		pMax=getMaxValue(*pOld);
		printf("i = %d, the max Value = %d\n",i,pMax->data);
		(*pOld)=deleFormOld(*pOld,pMax);
		link_print(*pOld);
		pNew=addToNew(pNew,pMax);
		link_print(pNew);
	}
	/*
	while((*pOld)!=NULL)
	{
		pMax=getMaxValue(*pOld);
		deleFormOld(pOld,pMax);
		addToNew(&pNew,pMax);
	}
		addToNew(&pNew,pMax);
		link_print(pNew);
	*/
	return pNew;
}
int link_print(pNode phead)
{
	pNode p=phead;
	
	if(phead == NULL) /*empty link*/
	{
		printf("the link is empty!\n");
		return 0;
	}
	while(p != NULL)
	{
		printf("[%d]->",p->data);
		p=p->next;
	}
	printf("\n");
	return 0;
}
int save(pNode phead)
{
	pNode p=phead;
	FILE *fp=NULL;
	int write_value=0;
	if(p==NULL)
	{
		printf("empty link save()\n");
		return -1;
	}
	fp=fopen("stu","wb");
	if(fp == NULL)
	{
		printf("open the file error!\n");
		return -1;
	}
	while(p)
	{
		write_value=fwrite(p,sizeof(Lnode),1,fp);
		printf("write_value = %d\n",write_value);
		p=p->next;
	}
	fclose(fp);
	return 0;
}
pNode display()
{
	pNode phead=NULL;
	pNode s=NULL;
	FILE *fp=NULL;
	int read_value=0;

	fp=fopen("stu","rb");
	if(fp == NULL)
	{
		printf("open the file error!display()\n");
		return NULL;
	}
	s=(Lnode *)malloc(sizeof(Lnode));
	memset(s,0,sizeof(Lnode));
	while((read_value=fread(s,sizeof(Lnode),1,fp))==1)
	{

		s->next = phead;
		phead =s;
		s=(Lnode *)malloc(sizeof(Lnode));
		memset(s,0,sizeof(Lnode));
	}
	free(s);
	fclose(fp);
	return phead;
}
int main()
{
	int length;
	int modifyVaule=0;
	pNode phead = NULL;
	pNode new_phead = NULL;
	pNode searchP = NULL;
	link_create(&phead);
	link_print(phead);
	printf("\n");
	save(phead);
	new_phead=display();
	link_print(new_phead);
/*	length = link_getLenth(phead);
	printf("the length of link is %d\n",length);
	searchP = link_find(phead, 2);
	modifyVaule = link_modify(searchP,55);
	phead=link_insert(phead,10,66);
	link_print(phead);
	phead = sort(&phead);
	link_print(phead);
	*/
	return 0;
}
