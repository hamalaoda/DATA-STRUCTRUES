#include "tree.h"

// 创建新节点
Node *creatNode(int data)
{
    // 分配空间
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
    // 判断是否有头节点
    if (root == NULL) // 无头结点的情况
    {
        return creatNode(data);
    }

    // 有根节点
    if (data < root->data) // 插入数据小于头节点的数据
    {
        // 插入左子树
        root->left = insert(root->left, data); // 递归；每递归一次左子树就变成新的根节点然后继续判断
    }
    else if (data > root->data)
    {
        // 插入右子树
        root->right = insert(root->right, data);
    }
    // 不允许插入重复的值

    // 返回最开始的根节点：后续插入
    return root;
}

// 先序遍历(根 > 左 > 右)
void preorderTraversal(Node *root)
{
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// 中序遍历(左 > 根 > 右)
void inorderTraversal(Node *root)
{}