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
    if (root != NULL)
    {
        printf("%d ", root->data);      // 先打印根节点
        preorderTraversal(root->left);  // 递归遍历左子树
        preorderTraversal(root->right); // 递归遍历右子树
    }
    return; // 为空则退出当前递归层
}

// 中序遍历(左 > 根 > 右)
void inorderTraversal(Node *root)
{
    if (root != NULL)
    {
        // 先递归左子树；打印根内容；递归右子树
        inorderTraversal(root->left);
        printf("%d", root->data);
        inorderTraversal(root->right);
    }
    return;
}

// 后序遍历(左 > 右 > 根)
void postorderTraversal(Node *root)
{
    if (root != NULL)
    {
        // 先递归左子树；递归右子树；打印根内容
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d", root->data);
    }
    return;
}

// 查找节点
extern Node *search(Node *root, int data)
{
    // 1、判断节点是否为空 或 是否找到数据
    if (root == NULL || root->data == data)
    {
        return root; // 返回此时root的地址
    }

    // 2、判断数据大小
    if (data < root->data)
    {
        // 递归左子树，每递归一次，将左子树作为新的根节点传入函数
        root->left = search(root->left, data);
    }
    if (data > root->data)
    {
        // 递归右子树，每递归一次，将右子树作为新的根节点传入函数
        root->right = search(root->right, data);
    }
}

// 查找最大子节点
Node *findMax(Node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

// 删除节点
Node *deleteNode(Node *root, int data)
{
    // 1、判断是否存在该节点
    if (root == NULL)
    {
        return NULL; // 返回上一层的递归函数
    }

    // 2、判断根内容与data

    if (data < root->data) //  data小于根内容
    {

        root->left = deleteNode(root->left, data); // 递归左子树；每递归一次根的左子树成为新的根节点
    }

    if (data > root->data) // data大于根内容
    {

        root->right = deleteNode(root->right, data); // 递归右子树；每递归一次根的右子树成为新的根节点
    }

    else // （data == root.data）
    {
        // 3、判断父节点是否有子节点

        //  (1)没有根节点
        if (root->left == NULL && root->right == NULL)
        {
            free(root);  // 回收对root指针的控制权 释放内存
            root = NULL; // 避免野指针 并将父节点的对应指针（左/右）置为NULL
        }

        // （2）有一个子节点

        if (root->left != NULL && root->right == NULL) // 只有左节点
        {
            Node *temp = root;
            root = root->left;
            free(temp);
        }

        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root;
            root = root->right;
            free(temp);
        }

        // （3）有两个子节点 (右子树的最大值替换根节点)
        else
        {
            Node *temp = findMax(root);
            root->data = temp->data;                           // 仅替换根节点的值
            root->right = deleteNode(root->right, temp->data); // 删除最大值的节点
        }
    }
    return root; // 返回当前的根节点
}

void destoryTree(Node *root)
{
    if (root != NULL)
    {
        destoryTree(root->left);
        destoryTree(root->right);
        free(root);
    }
}