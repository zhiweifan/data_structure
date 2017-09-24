#include "TreeNode.h"

static void ListDir(DirectoryOrFile D, int Depth)
{
	if (D is a legitimate entry)
	{
		PrintName(D, Name);
		if (D is a directory)
		{
			for each child, c, of D
				ListDir(C, Depth + 1)
		}
	}
} /* 算法的核心例程 */

void ListDirectory(DirectoryOrFile D)
{
	ListDir(D, 0)
}/* 驱动程序 */

