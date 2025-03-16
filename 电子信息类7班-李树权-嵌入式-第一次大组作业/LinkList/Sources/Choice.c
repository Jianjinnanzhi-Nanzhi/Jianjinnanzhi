#include"NodeList.h"
#include"Choice.h"

void ExchangeOE(LNode head)
{
    if (head->next == NULL || head->next->next == NULL)
    {
        printf("�������������ڵ�,�޷������żλ�û���\n");
        return;
    }
    LNode p, p1, p2;//p1��p2�ֱ���Ϊ������ż��λ�ýڵ�,pΪ�м����
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
}//������żλ�õĽڵ�

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
}//�ҵ������м�Ľڵ�

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
}//�ж������Ƿ��л�,�л��򷵻�1,�޻��򷵻�0

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
}//��ת����(�ǵݹ�)


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
}//��ת����δ��ͷ�ڵ�(�ݹ�)

LNode reverseListR(LNode head)
{
    LNode Falsehead = RL_Recursion(head);
    LNode newhead = InitList();//����µ�ͷ�ڵ�
    newhead->next = Falsehead;
    LNode p = newhead;
    while (p->next->next != NULL)
    {
        p = p->next;
    }//�ҵ���ݹ�����ͷ�ڵ�תΪβ�ڵ��β�ڵ��ǰ�ýڵ�
    LNode q = p->next;
    p->next = NULL;
    free(q);//��δ��תǰ��ͷ�ڵ���ͷ�
    return newhead;
}//��ת����(�ݹ�)
