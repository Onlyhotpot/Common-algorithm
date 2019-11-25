#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"

void getPre(Tree root, int* pre, int* preCnt);
void getMid(Tree root, int* mid, int* midCnt);
Tree makeTree(int* pre,int* mid, int size);

int main()
{
    srand((unsigned)time(NULL));

    while (1)
    {
        Tree T = initTree(50000);
        printf("How many node do you want of the tree: ");
        int n;
        scanf("%d", &n);
        for (int i = 1; i < n; ++i)
        {
            insertNode(T, rand() % 100000);
        }

        int* pre = (int*)malloc(n * sizeof(int));
        int* mid = (int*)malloc(n * sizeof(int));

        int preCnt = 0;
        getPre(T, pre, &preCnt);
        int midCnt = 0;
        getMid(T, mid, &midCnt);
        freeTree(T);

        n = preCnt;
        Tree newT = makeTree(pre, mid, n);
        freeTree(newT);
        printf("And number of n is %d\n", n);
    }

    system("pause");
    return 0;
}

/*
*使用前缀遍历后中缀遍历构造树
*/
Tree makeTree(int* pre, int* mid, int size)
{
    if (size == 1)
        return initTree(pre[0]);
    if (size == 0)
        return NULL;

    int cnt = 0;
    for (int i = 0; i < size; ++i)
    {
        if (mid[i] == pre[0])
            break;
        ++cnt;
    }

    Tree root = initTree(pre[0]);

    root->left = makeTree(pre + 1, mid, cnt);
    root->right = makeTree(pre + cnt + 1, mid + cnt + 1, size - cnt - 1);

    return root;
}

// 将树的前序遍历输入数组pre
void getPre(Tree root, int* pre, int* preCnt)
{
    if (!root) return;
    pre[*preCnt] = root->val;
    ++(*preCnt);
    getPre(root->left, pre, preCnt);
    getPre(root->right, pre, preCnt);
}

// 将树的中序遍历输入数组mid
void getMid(Tree root, int* mid, int* midCnt)
{
    if (!root) return;
    getMid(root->left, mid, midCnt);
    mid[*midCnt] = root->val;
    ++(*midCnt);
    getMid(root->right, mid, midCnt);
}
