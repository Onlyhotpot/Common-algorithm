#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"

#define MAXSIZE 100

void LevelOrderTraversal(Tree root);

int main()
{
    srand((unsigned)time(NULL));
    Tree T = initTree(5000);
    printf("How many node do you want of the tree: ");
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        insertNode(T, rand() % 10000);
    }
    preOrderTraversal(T);
    printf("\n");
    midOrderTraversal(T);
    printf("\n");
    LevelOrderTraversal(T);
    printf("\n");

    system("pause");
    return 0;
}

/**
* 利用队列进行树的层序遍历
*/
void LevelOrderTraversal(Tree root)
{
    Queue Q;
    TreeNode T;
    if (!root) return;
    Q = CreatQueue(MAXSIZE);
    add(Q, root);
    while (!isEmpty(Q))
    {
        T = poll(Q);
        printf("%d ", T->val);
        if (T->left)
            add(Q, root->left);
        if (T->right)
            add(Q, root->right);
    }
    freeQueue(Q);
}
