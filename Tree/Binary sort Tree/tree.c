#include "tree.h"

// 创建新节点
Node *creatNode(Node *root, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("分配空间失败\n");
        exit(1); // 直接中止整个程序
    }

    // 初始化节点
    // 数据域
    newNode->data = data;
    // 指针域
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// 插入节点
Node *insert(Node *root, int data)
{
    
}