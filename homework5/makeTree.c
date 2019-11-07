#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"

void makePre(Tree root, int* pre);
void makeMid(Tree root, int* mid);
Tree makeTree(int* pre,int* mid, int size);

int preCnt = 0;
int midCnt = 0;

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
    int* pre = (int*)malloc(n * sizeof(int));
    int* mid = (int*)malloc(n * sizeof(int));

    makePre(T, pre);
    makeMid(T, mid);

    makeTree(pre, mid, n);
}

Tree makeTree(int* pre, int* mid, int size)
{
    if (size == 1)
        return initTree(pre[0]);
    if (size == 0)
        return NULL;

    int cnt = 1;
    for (int i = 0; i < size; ++i)
    {
        if (mid[i] == pre[0])
            break;
        ++cnt;
    }

    Tree root = initTree(pre[0]);

    root->left = makeTree(pre + 1, mid, size - cnt - 1);
    root->right = makeTree(pre + cnt + 1, mid + cnt, cnt);
}

// 将树的前序遍历输入数组pre
void makePre(Tree root, int* pre)
{
    if (!root) return;
    pre[0] = root->val;
    ++preCnt;
    makePre(root->left, pre + preCnt);
    makePre(root->right, pre + preCnt);
}

// 将树的中序遍历输入数组mid
void makeMid(Tree root, int* mid)
{
    if (!root) return;
    ++midCnt;
    makeMid(root->left, mid + midCnt - 1);
    *(mid + midCnt) = root->val;
    makeMid(root->right, mid + midCnt);
}
