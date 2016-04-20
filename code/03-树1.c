#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode
{
	char Data;
	BinTree Left;
	BinTree Right;
};
int main()
{
	printf("helloworld\n");
	return 0;
}