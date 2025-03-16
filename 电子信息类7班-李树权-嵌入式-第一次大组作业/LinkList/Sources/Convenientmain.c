#include"Convenientmain.h"
#define _CRT_SECURE_NO_WARNINGS

void One(LNode head)
{
    int i;
    printf("创建几个节点(不超过20个):");
    scanf("%d", &i);
    int j = i + 1;
    while (i)
    {
        printf("请输入第%d个节点的数据(长度不超过10个):", j - i);
        int e = 0;
        scanf("%d", &e);
        insertHead(head, e);
        i--;
    }
    printf("链表初始化完成\n");
    printf("\n");
    printf("请按回车键继续....");
}//选项1的执行语句

void Tow(LNode head)
{
    printf("链表数据:");
    PrintNode(head);
    int pos, data;
    printf("请输入要插入的位置:");
    scanf("%d", &pos);
    printf("请输入要插入的数据:");
    scanf("%d", &data);
    insertNode(head, pos, data);
    PrintNode(head);
    printf("插入成功\n");
    printf("\n");
    printf("请按回车键继续....");
}//选项2的执行语句

void Three(LNode head)
{
    reverseListNR(head);
    printf("反转链表成功\n");
    printf("\n");
    printf("请按回车键继续....");
}

void Four(LNode head)
{
    PrintNode(head);
    printf("请按回车键继续....");
}

void Five(LNode head)
{
    LNode p;
    p = FindMiddleNode(head);
    printf("中间链表的数据为:%d", p->data);
    printf("\n");
    printf("请按回车键继续....");
}

void Six(LNode head)
{
    if (isCycle(head) == 1)
    {
        printf("链表成环!\n");
    }
    else
    {
        printf("该链表未成环!\n");
    }
    printf("\n");
    printf("请按回车键继续....");
}

void Seven(LNode head)
{
    PrintNode(head);
    int index = 0;
    printf("请输入要删除数据的位置(第几个节点):");
    scanf("%d", &index);
    if (delectNode(head, index) == 0)
    {
        printf("没有此数据\n");
    }
    else
    {
        delectNode(head, index);
        PrintNode(head);
        printf("删除成功!\n");
    }
    printf("\n");
    printf("请按回车键继续....");
}

void Eight(LNode head)
{
    ExchangeOE(head);
    printf("奇偶反转完成\n");
    printf("\n");
    printf("请按回车键继续....");
}

void Nine(LNode head)
{
    printf("请输入要查询的数据:");
    int T = 0;
    scanf("%d", &T);
    if (FindList(head, T) == -1)
    {
        printf("该链表不存在此数据\n");
    }
    else
    {
        printf("该链表存在此数据\n");
    }
    printf("\n");
    printf("请按回车键继续....");
}

void Ten(LNode head)
{
    create_CirList(head);
    printf("链表成环完成\n");
    printf("\n");
    printf("请按回车键继续....");
}
