
LNode *GetMaxFromLink(LNode *pHead)
{
	LinkList p = pHead;
	LinkList max = pHead;

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

LNode *FindPreNodeFromLink(LinkList pHead, LinkList max)
{
	LinkList p = pHead;

	while (p != NULL)
	{
		if (p->next == max)
		{
			return p;
		}
		p = p->next;
	}

	return NULL;
}


LNode *DelNodeFromLink(LinkList pHead, LinkList max)
{
	if (pHead == max)
	{
		pHead = pHead->next;
		return pHead;
	}

	prev = FindPreNodeFromLink(pHead, max);

	if (prev != NULL)
	{
		prev->next = max->next;
	}

	return pHead;
}

LNode *SortLink(LNode *pHead)
{
	LinkLink pNewHead = NULL;
	LinkList max = NULL;

	while (pHead != NULL)
	{
		/*get the max node from old link list*/
		max = GetMaxFromLink(pHead);

		printf("test: max = %d\n", max->data);

		/*delete the max node from old link list*/
		pHead = DelNodeFromLink(pHead, max);

		PrintLink(pHead);
		
		/*add the node to new link list*/
		pNewHead = AddNodeToLink(pNewHead, max);
		PrintLink(pNewHead);
	}

	return pNewHead;
}


void FreeLink(LinkList pHead)
{
	LinkList p = pHead;
	LinkList q;

	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
}
