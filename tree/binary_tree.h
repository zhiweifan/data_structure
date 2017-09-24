#ifndef Binary_Tree_H__
#define Binary_Tree_H__

typedef struct TreeNode *PtrToNode;
typedef struct PtrToNode Tree;

struct TreeNode
{
	ElementType Element;
	Tree left;
	Tree right;
}

#endif
