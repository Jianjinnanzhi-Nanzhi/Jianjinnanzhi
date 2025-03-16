#include"NodeList.h"
#include"Choice.h"

void ExchangeOE(LNode head)
{
    if (head->next == NULL || head->next->next == NULL)
    {
        printf("该链表不足两个节点,无法完成奇偶位置互换\n");
        return;
    }
    LNode p, p1, p2;//p1和p2分别作为奇数和偶数位置节点,p为中间变量
    p1 = head;
    p2 = p1->next;
    p = p1;

    while (p1->next != NULL && p2->next != NULL)
    {

        p1 = p->next;
        p2 = p1->next;

        p->next = p2;
        p1->next = p2->next;
        p2->next = p1;

        p = p1;
    }
}//交换奇偶位置的节点

LNode FindMiddleNode(LNode head)
{
    LNode fast = head->next;
    LNode slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    LNode q = slow->next;
    return q;
}//找到链表中间的节点

int isCycle(LNode head)
{
    LNode fast = head;
    LNode slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return 1;
        }
    }
    return 0;
}//判断链表是否有环,有环则返回1,无环则返回0

LNode reverseListNR(LNode head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    LNode first = NULL;
    LNode second = head->next;
    LNode third = NULL;

    while (second != NULL)
    {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    LNode hd = InitList();
    hd->next = first;

    return hd;
}//反转链表(非递归)


LNode RL_Recursion(LNode head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    LNode newHead = RL_Recursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}//反转链表未加头节点(递归)

LNode reverseListR(LNode head)
{
    LNode Falsehead = RL_Recursion(head);
    LNode newhead = InitList();//添加新的头节点
    newhead->next = Falsehead;
    LNode p = newhead;
    while (p->next->next != NULL)
    {
        p = p->next;
    }//找到因递归的造成头节点转为尾节点的尾节点的前置节点
    LNode q = p->next;
    p->next = NULL;
    free(q);//将未反转前的头节点给释放
    return newhead;
}//反转链表(递归)
