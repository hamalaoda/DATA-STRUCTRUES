#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct STU
{
    int age;
    char *name;
    struct STU *next;
} STU;

extern void printf_Node(STU *head);                               // 打印节点
extern STU *create_Node(int data, char *arg);                     // 创建节点
extern void insert_tail(STU **head, int age, char *name);         // 尾插法插入节点
extern void deleteNode(STU **head);                               // 删除节点
extern void insert_head(STU **head, int age, char *arg);          // 头插法插入节点
extern void findNode(STU *head, char *name);                      // 查找节点
extern void insert_Num(STU **head, int num, int age, char *name); // 指定位置插入节点
extern void delete_Data(STU **head, char *name);                  // 根据名字删除节点

#endif // !__LIST_H__