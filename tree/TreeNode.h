#ifndef TreeNode_H__
#define TreeNode_H__

typedef struct TreeNode *PtrToNode;
struct TreeNode
{
	ElementType Element;
	PtrToNode FisrtChild;
	PtrToNode NextSlbling;
}

#endif
