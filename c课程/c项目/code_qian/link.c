/*
** Release Info:
** Author: LiQiang
** Date: 2011/8/1
** Version: V1.0
** History:
*/

/*include files*/
#include "link.h"

/*local function*/



/* function:
** para:
** return value:
*/
void print_link(LinkList Head)
{
	LinkList p;

	p = Head;

	printf("\n===========LinkList=============\n");
	while (p != NULL)
	{
		printf("%d ->", p->data);
		p = p->next;
	}

	printf("\n=============End===============\n");
}


/* function:
** para:
** return value:
*/
void print_dlink(DLinkList DHead)
{
	DLinkList p = NULL;
	DLinkList DTail = NULL;

	p = DHead;

	printf("\n===========Double LinkList=============\n");
	while (p != NULL)
	{
		printf("%d ->", p->data);
		DTail = p;
		p = p->next;
	}
	printf("\n");

	p = DTail;
	while (p != NULL)
	{
		printf("%d ->", p->data);
		p = p->prior;
	}

	printf("\n=============End===============\n");
}


/* function:
** para:
** return value:
*/
void print2_dlink(DLinkList DHead)
{
	DLinkList p = NULL;


	if (DHead == NULL)
	{
		return ;
	}

	p = DHead;

	printf("\n===========Double LinkList=============\n");
	while (p->next != NULL)
	{
		printf("%d ->", p->data);
		p = p->next;
	}
	printf("%d\n", p->data);

	while (p->prior!= NULL)
	{
		printf("%d ->", p->data);
		p = p->prior;
	}
	printf("%d", p->data);

	printf("\n=============End===============\n");
}


/* function:
** para:
** return value:
*/
void free_link(LinkList Head)
{
	LinkList p = Head;

	while (p != NULL)
	{
		Head = Head->next;
		free(p);
		p = Head;
	}
}


/* function:
** return value:
*/
LinkList creat_link()
{
	LNode *p;
	int temp;
	LNode *Head = NULL;

	while (1)
	{
		/*memory allocation*/
		p = (LNode *) malloc(sizeof(LNode));

		if (p == NULL)
		{
			printf("malloc fail!");
			return NULL;
		}

		/*init data*/
		printf("input number:\n");
		scanf("%d", &temp);

		if (temp == 888) /*finish*/
		{
			free(p); /*Free the memory*/
			break;
		}

		p->data = temp;
		p->next = Head;

		/*update Head pointer*/
		Head = p;
	}

	return Head;
}


/* function:gh`
** return value:
*/
DLinkList creat_dlink()
{
	DLNode *DHead = NULL;
	DLNode *p = NULL;
	int temp;

	while (1)
	{
		/*memory allocation*/
		p = (DLNode *)malloc(sizeof(DLNode));

		if (p == NULL)
		{
			printf("malloc fail!");
			return NULL;
		}

		/*init data*/
		printf("input number:\n");
		scanf("%d", &temp);

		if (temp == 888) /*finish*/
		{
			free(p); /*Free the memory*/
			break;
		}

#if 0
		p->data = temp;

		if (DHead == NULL) /*the first node*/
		{
			p->prior = NULL;
			p->next = NULL;
		}
		else /*other node*/
		{
			p->prior = NULL;
			p->next = DHead;
			DHead->prior = p;
		}
#else /**/

		p->data = temp;
		p->prior = NULL;
		p->next = DHead;

		if (DHead != NULL)
		{
			DHead->prior = p;
		}
#endif
		/*update head pointer*/
		DHead = p;
	}
	
	return DHead;
}


/* function:
** para:
** return value:
*/
LinkList creat1_link()
{
	LinkList Head1 = NULL;
	LinkList Tail = NULL;
	LNode *p;
	int temp;


	while (1)
	{
		/*memory allocation*/
		p = (LNode *) malloc(sizeof(LNode));

		if (p == NULL)
		{
			printf("malloc fail!");
			return NULL;
		}

		/*init data*/
		printf("input number:\n");
		scanf("%d", &temp);

		if (temp == 888) /*finish*/
		{
			free(p); /*Free the memory*/
			break;
		}
		
		p->data = temp;
		p->next = NULL;

		if (Tail != NULL)
		{
			Tail->next = p;
		}

		/*update Head pointer*/
		if (Head1 == NULL)
		{
			Head1 = p;
		}

		/*update Tail pointer*/
		Tail = p;
	}

	return Head1;
}

#if 1
/* function:
** para:
** return value:
*/
LinkList search_link_by_index()
{

	return NULL;
}


/* function:
** para:
** return value:
*/
LinkList get_the_prev_node(LinkList Head, LinkList node)
{
	LinkList p = Head;

	/*If the node is the first node*/
	if (Head == node)
	{
		return node;
	}

	while (p != NULL)
	{
		if (p->next == node)
		{
			return p;
		}
	}

	return NULL;
}


/* function:
** para:
** return value:
*/
LinkList del_node_from_link(LinkList Head, LinkList node)
{
	LinkList prev = NULL;

	/*If the node is the first node*/
	if (Head == node)
	{
		Head = Head->next;
		return Head;
	}

	/*other node, find the prior node*/
	prev = get_the_prev_node(Head, node);
	if (prev == NULL)
	{
		return Head;
	}

	prev->next = node->next;

	return Head;
}


/* function:
** para:
** return value:
*/
LinkList search_link_by_value()
{
	return NULL;
}


/* function:
** para:
** return value:
*/
int insert_link(LNode **Head, int i, int x)
{
	LinkList p = NULL;
	LinkList s = NULL;

	/*add the first place*/
	if (i == 0)
	{
		p = malloc();

		if (p == NULL)
		{
			return -1;
		}

		p->data = x;
		p->next = *Head;
		*Head = p;

		return 1;
	}

	s = GetPlace(Head, i - 1);

	if (s == NULL)
	{
		return -1;
	}

	p = malloc();

	if (p == NULL)
	{
		return -1;
	}

	p->data = x;
	p->next = s->next;
	s->next = p;

	return NULL;
}


/* function:
** para:
** return value:
*/
LinkList delete_link()
{
	return NULL;
}


/* function:
** para:
** return value:
*/
LinkList find_max_link(LinkList Head)
{
	LinkList max = NULL;
	LinkList p = NULL;

	max = p = Head;

	while (p != NULL)
	{
		if (max->data < p->data)
		{
			max = p;
		}

		p = p->next;
	}

	return max;
}


/* function:
** para:
** return value:
*/
LinkList find_max_link_and_del(LinkList Head)
{
	LinkList max = NULL;
	LinkList p = NULL;
	LinkList q = NULL;
	LinkList prev = NULL;

	max = p = Head;

	while (p != NULL)
	{
		if (max->data < p->data)
		{
			prev = q;
			max = p;
		}

		q = p;
		p = p->next;
	}

	if (prev != NULL)
	{
		prev->next = max->next;
	}
	else
	{
		Head = Head->next;
	}

	return max;
}


/* function:
** para:
** return value:
*/
LinkList sort_link(LNode *Head)
{
	LNode *NewHead = NULL; /**/
	LinkList p = NULL;

	while (1)
	{
		/*Find the max node from old linklist*/
		p = find_max_link(Head);
		printf("Test1: the max node =%d\n", p->data);

		if (p == NULL)
		{
			break;
		}

		NewHead = add_node_to_link(NewHead, p);
		print_Link(NewHead);

		Head = del_node_from_link(Head, p);
		print_Link(Head);
	}

	return NewHead;
}
#endif

int main()
{
	DLNode *DHead = NULL;
	LNode *Head1 = NULL;

	DHead = creat_dlink();
	print2_dlink(DHead);
/*	insert_link(&Head, 10, 88);
	free_link(Head);
	Head1 = creat1_link();
	print_link(Head1);
	free_link(Head);
*/
	return 1;
}


