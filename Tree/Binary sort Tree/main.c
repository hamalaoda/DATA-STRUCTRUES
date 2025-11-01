#include "tree.h"

int main(int argc, char const *argv[])
{

    // 创建二叉树和插入节点
    Node *root = calloc(1, sizeof(Node)); // 创建根节点
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

    return 0;
}
