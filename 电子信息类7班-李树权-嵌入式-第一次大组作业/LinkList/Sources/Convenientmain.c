#include"Convenientmain.h"
#define _CRT_SECURE_NO_WARNINGS

void One(LNode head)
{
    int i;
    printf("���������ڵ�(������20��):");
    scanf("%d", &i);
    int j = i + 1;
    while (i)
    {
        printf("�������%d���ڵ������(���Ȳ�����10��):", j - i);
        int e = 0;
        scanf("%d", &e);
        insertHead(head, e);
        i--;
    }
    printf("�����ʼ�����\n");
    printf("\n");
    printf("�밴�س�������....");
}//ѡ��1��ִ�����

void Tow(LNode head)
{
    printf("��������:");
    PrintNode(head);
    int pos, data;
    printf("������Ҫ�����λ��:");
    scanf("%d", &pos);
    printf("������Ҫ���������:");
    scanf("%d", &data);
    insertNode(head, pos, data);
    PrintNode(head);
    printf("����ɹ�\n");
    printf("\n");
    printf("�밴�س�������....");
}//ѡ��2��ִ�����

void Three(LNode head)
{
    reverseListNR(head);
    printf("��ת����ɹ�\n");
    printf("\n");
    printf("�밴�س�������....");
}

void Four(LNode head)
{
    PrintNode(head);
    printf("�밴�س�������....");
}

void Five(LNode head)
{
    LNode p;
    p = FindMiddleNode(head);
    printf("�м����������Ϊ:%d", p->data);
    printf("\n");
    printf("�밴�س�������....");
}

void Six(LNode head)
{
    if (isCycle(head) == 1)
    {
        printf("����ɻ�!\n");
    }
    else
    {
        printf("������δ�ɻ�!\n");
    }
    printf("\n");
    printf("�밴�س�������....");
}

void Seven(LNode head)
{
    PrintNode(head);
    int index = 0;
    printf("������Ҫɾ�����ݵ�λ��(�ڼ����ڵ�):");
    scanf("%d", &index);
    if (delectNode(head, index) == 0)
    {
        printf("û�д�����\n");
    }
    else
    {
        delectNode(head, index);
        PrintNode(head);
        printf("ɾ���ɹ�!\n");
    }
    printf("\n");
    printf("�밴�س�������....");
}

void Eight(LNode head)
{
    ExchangeOE(head);
    printf("��ż��ת���\n");
    printf("\n");
    printf("�밴�س�������....");
}

void Nine(LNode head)
{
    printf("������Ҫ��ѯ������:");
    int T = 0;
    scanf("%d", &T);
    if (FindList(head, T) == -1)
    {
        printf("���������ڴ�����\n");
    }
    else
    {
        printf("��������ڴ�����\n");
    }
    printf("\n");
    printf("�밴�س�������....");
}

void Ten(LNode head)
{
    create_CirList(head);
    printf("����ɻ����\n");
    printf("\n");
    printf("�밴�س�������....");
}
