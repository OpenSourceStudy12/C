#ifndef _PARENTTREE_H
#define _PARENTTREE_H
#define MAX_NODE 100
typedef struct 
{
	char data;
	int parent;
}TreeNode,*PTreeNode;

typedef struct 
{
	TreeNode treeNode[MAX_NODE];
	int n;//实际的结点个数
}Tree,*PTree;
PTree treeCreat();
void treePrint(PTree tree);



#endif
