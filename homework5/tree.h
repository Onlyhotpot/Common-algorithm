#include <stdio.h>
#include <stdlib.h>

#ifndef TREE_H
#define TREE_H

#define elementType int

struct node;
typedef struct node* Tree;
typedef Tree TreeNode;
typedef TreeNode Position;

struct node
{
    elementType val;
    TreeNode left;
    TreeNode right;
};

Tree initTree(elementType element);
Position findMax(Tree T);
Position findMin(Tree T);
void insertNode(Tree T, elementType element);
void deleteNode(Tree T, elementType element);
void preOrderTraversal(Tree T);
void midOrderTraversal(Tree T);

Tree initTree(elementType element)
{
    TreeNode T = (TreeNode)malloc(sizeof(struct node));
    T->val = element;
    T->left = NULL;
    T->right = NULL;
}

Position findMax(Tree T)
{
    if (T)
    {
        while (T->right)
            T = T->right;
        return T;
    }
    return NULL;
}

Position findMin(Tree T)
{
    if (T)
    {
        while (T->left)
            T = T->left;
        return T;
    }
    return NULL;
}

void insertNode(Tree T, elementType element)
{
    while (T->val != element)
    {
        if (T->val > element)
        {
            if (!T->left)
            {
                TreeNode t = (TreeNode)malloc(sizeof(struct node));
                t->val = element;
                t->left = NULL;
                t->right = NULL;
                T->left = t;
                break;
            }
            T = T->left;
        }
        if (T->val < element)
        {
            if (!T->right)
            {
                TreeNode t = (TreeNode)malloc(sizeof(struct node));
                t->val = element;
                t->left = NULL;
                t->right = NULL;
                T->right = t;
                break;
            }
            T = T->right;
        }
    }
}

void deleteNode(Tree T, elementType element)
{
    while (T && T->val != element)
    {
        if (T->val > element)
            T = T->left;
        else
            T = T->right;
    }
    if (T)
    {
        if (T->right)
        {
            TreeNode temp = T->right;
            if (!temp->left)
            {
                T->right = NULL;
                T->val = temp->val;
                free(temp);
            }
            else
            {
                while (temp->left->left)
                    temp = temp->left;
                T->val = temp->left->val;
                free(temp->left);
                temp->left = NULL;
            }
        }
        else if (T->left)
        {
            if (T->left)
            {
                TreeNode temp = T->left;
                if (!temp->right)
                {
                    T->left=NULL;
                    T->val = temp->val;
                    free(temp);
                }
                else
                {
                    while (temp->right->right)
                        temp = temp->right;
                    T->val = temp->right->val;
                    free(temp->right);
                    temp->right = NULL;
                }
            }
        }
    }
}

void preOrderTraversal(Tree T)
{
    if (!T) return;
    printf("%d ", T->val);
    preOrderTraversal(T->left);
    preOrderTraversal(T->right);
}

void midOrderTraversal(Tree T)
{
    if (!T) return;
    preOrderTraversal(T->left);
    printf("%d ", T->val);
    preOrderTraversal(T->right);
}

#endif
