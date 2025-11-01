#include "tree.h"

int main(int argc, char const *argv[])
{

    // 创建二叉树和插入节点
    Node *root = NULL; // 创建根节点
    root = insert(root, 80);
    insert(root, 88);
    insert(root, 78);
    insert(root, 68);
    insert(root, 98);
    insert(root, 100);
    insert(root, 38);
    insert(root, 28);
    insert(root, 18);
    insert(root, 98);
    insert(root, 108);

    /*遍历二叉树*/
    preorderTraversal(root); // 先序遍历
    printf("\n");
    inorderTraversal(root); // 中序遍历
    printf("\n");
    postorderTraversal(root); // 后序遍历
    printf("\n");

    /*查找节点*/
    int key = 98;
    Node *find = search(root, key);
    if (find != NULL)
    {
        printf("已找到数据:%d \n", key);
    }
    else
    {
        printf("未找到数据\n");
    }

    /*删除节点*/
    int key2 = 38;
    root = deleteNode(root, key2);
    printf("删除节点 %d 后的中序遍历: ", key2);
    inorderTraversal(root);
    printf("\n");

    /*销毁二叉树*/
    destoryTree(root);
    root = NULL;

    return 0;
}
