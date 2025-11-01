#ifndef ___TREE_H__
#define __TREE_H__



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

extern Node *creatNode(int data);
extern Node *insert(Node *root, int data);
extern void preorderTraversal(Node *root);
extern void inorderTraversal(Node *root);
extern void postorderTraversal(Node *root);
extern Node *deleteNode(Node *root, int data);
extern Node *search(Node *root, int data);
extern void destoryTree(Node* root);
#endif