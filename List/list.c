#include "list.h"

//  打印节点
void printf_Node(STU *head)
{
    if (head == NULL)
    {
        printf("链表为空\n");
        return;
    }

    STU *current = head;
    while (current != NULL)
    {
        printf("年龄：%d, 姓名：%s\n", current->age, current->name);
        current = current->next;
    }
    return;
}

// 创建节点
STU *create_Node(int data, char *arg)
{
    // 判断内存分配情况
    STU *newNode = (STU *)malloc(sizeof(STU));
    if (NULL == newNode)
    {
        perror("malloc");
        return NULL;
    }
    // 初始化节点
    newNode->age = data;
    // 先给字符串分配空间
    newNode->name = (char *)malloc(strlen(arg) + 1);
    if (NULL == newNode->name)
    {
        perror("malloc name");
        free(newNode); // 如果名字分配失败，要把之前的人销毁，防止内存泄露
        return NULL;
    }
    strcpy(newNode->name, arg);
    newNode->next = NULL;
    return newNode;
}

// 尾插法插入节点
void insert_tail(STU **head, int age, char *name)
{
    // 1.判断头结点是否为空
    if (head == NULL)
    {
        printf("传入的头指针为空！\n");
        return;
    }

    // 2.如果头节点不为空，先生成新节点
    STU *newNode = create_Node(age, name);
    if (newNode == NULL)
    {
        return;
    }

    // 3.判断链表是否为空
    // 3.1链表为空时，新节点作为头节点
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    // 3.2 链表为非空，寻找尾节点
    STU *currentNode = *head;
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }

    // 4. 插入尾节点
    currentNode->next = newNode;
}

// 删除节点操作
void deleteNode(STU **head)
{
    if (head == NULL || *head == NULL)
    {
        return;
    }

    STU *temp = NULL;
    while (*head != NULL) // 删除节点，对一级指针进行操作
    {
        temp = *head;          // 保存当前节点
        *head = (*head)->next; // 移动到下一个节点
        free(temp);            // 释放当前节点
        temp = NULL;           // 避免野指针
    }
}

// 头插法添加节点
void insert_head(STU **head, int age, char *arg)
{
    // 1.判断传入的二级指针是否为空
    if (head == NULL)
    {
        printf("传入的二级指针为空\n");
        return;
    }
    // 2.生成新节点
    STU *newNode = create_Node(age, arg);
    if (newNode == NULL)
    {
        return;
    }

    // 3.插入头节点
    newNode->next = *head;
    *head = newNode;
}

// 查找结点
void findNode(STU *head, char *name)
{
    if (head == NULL)
    {
        printf("头节点为空\n");
        return;
    }
    // 查找节点
    while (head->next != NULL)
    {
        if (strcmp(name, head->name) == 0)
        {
            printf("已找到姓名为%s的节点\n", head->name);
            return;
        }
        head = head->next;
    }
    // 未找到节点
    printf("没有%s该节点\n", name);
}

// 根据位置插入节点
void insert_Num(STU **head, int num, int age, char *name)
{
    // 1. 检查：二级指针为空、位置为负、名字为空
    if (head == NULL || num < 0 || name == NULL)
    {
        printf("不允许插入");
        return;
    }

    // 2.创建新节点
    STU *newNode = create_Node(age, name);
    if (newNode == NULL)
    {
        printf("创建节点失败");
        return;
    }

    // 3.空链表处理
    if (*head == NULL)
    {
        if (num == 0)
        {
            *head = newNode; // 空链表，新节点就是头节点
            return;
        }
        printf("链表为空，位置不合法");
        free(newNode); // 释放新节点，避免内存泄漏
        return;
    }

    // 4.头插处理
    if (num == 0)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // 5. 中间/尾插
    STU *prev = *head; // 前驱节点
    int curIndex = 0;  // 标记当前的位置
    while (prev->next != NULL && (num - 1) > curIndex)
    {
        prev = prev->next;
        curIndex++;
    }
    if (num != curIndex + 1)
    {
        printf("插入位置不合法，超过链表长度");
        free(newNode);
        return;
    }
    // 5.1 位置合法
    newNode->next = prev->next;
    prev->next = newNode;
    return;
}

// 根据名字删除节点
void delete_Data(STU **head, char *name)
{
    if (*head == NULL)
    {
        printf("链表为空\n");
        return;
    }
    STU *prev = NULL;    // 前驱节点
    STU *target = *head; // 目标节点

    // 3.遍历查找目标节点
    while (target != NULL && strcmp(target->name, name) != 0)
    {
        prev = target; // 前驱节点始终保持在目标节点前一位
        target = target->next;
    }

    // 4. 未找到节点
    if (target == NULL)
    {
        printf("未找到目标节点\n");
        return;
    }

    // 5. 删除（分头节点）
    if (prev == NULL)
    {
        *head = target->next;
    }
    else
    {
        prev->next = target->next;
    }

    // 6. 清空节点
    target->next = NULL;
    free(target);
    target = NULL;
}