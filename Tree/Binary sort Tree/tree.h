#ifndef ___TREE__
#define __TREE__

#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 定义二叉树的节点结构
typedef struct Node
{
    int data;
    struct Node *left;  // 左子树
    struct Node *right; // 右子树
} Node;

extern Node *creatNode(Node *root, int data);
extern Node *insert(Node *root, int data);