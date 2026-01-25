#include "list.h"

int main(int argc, char const *argv[])
{
    STU *head = create_Node(10, "小明");
    insert_tail(&head, 20, "小虎");
    insert_head(&head, 0, "小龙");
    insert_Num(&head, 2, 15, "小三");
    insert_Num(&head, 4, 30, "小舞");
    delete_Data(&head, "小三");
    printf_Node(head);
    deleteNode(&head);
    return 0;
}
