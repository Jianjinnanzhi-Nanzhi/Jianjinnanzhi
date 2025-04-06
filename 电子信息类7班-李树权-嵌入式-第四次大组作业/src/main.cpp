#define _CRT_SECURE_NO_WARNINGS
#include "binary_sort_tree.h"

int main()
{
    BinarySortTree BST;
    while (1)
    {
        printf("\n");
        printf("     *******************************            ****************************\n");
        printf("     *  1.����������ĳ�ʼ��       *            *        2.�����½ڵ�      *\n");
        printf("     *  3.ɾ���ڵ�                 *            *        4.���ҽڵ�        *\n");
        printf("     *  5.�������                 **************        6.�������        *\n");
        printf("     *  7.�������                 *            *        8.�������        *\n");
        printf("     *  9.ʹ�����к���������ֱ��� *            *        10.������������� *\n");
        printf("     *******************************            ****************************\n");
        int a = 0;
        printf("�������Ӧ����(1-10):");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            {
                int i;
                printf("���������ڵ�:");
                scanf("%d", &i);
                int j = i + 1;
                while (i)
                {
                    printf("�������%d���ڵ������:", j - i);
                    int e = 0;
                    scanf("%d", &e);
                    if (!BST_insert(&BST, e))
                    {
                        printf("��%d�����ݲ���ʧ��(���ظ�),����������\n", j - i);
                        i++;
                    }
                    i--;
                }
                printf("�����������ʼ�����\n");
                printf("\n");
                break;
            }
        case 2:
            {
                int e = 0;
                printf("������Ҫ���������:");
                scanf("%d", &e);
                while (1)
                {
                    if (!BST_insert(&BST, e))
                    {
                        printf("����ʧ��(���ظ�),����������:");
                        scanf("%d", &e);
                    }
                    else
                    {
                        printf("����ɹ�\n");
                        break;
                    }
                }
                break;
            }
        case 3:
            {
                int t = 0;
                printf("������Ҫɾ���ڵ��ֵ:");
                scanf("%d", &t);
                if (!BST_delete(&BST, t))
                    printf("�ö����������޺���ֵ�Ľڵ�,ɾ��ʧ��\n");
                else
                    printf("ɾ���ɹ�\n");
                break;
            }
        case 4:
            {
                printf("������Ҫ��ѯ������:");
                int y = 0;
                scanf("%d", &y);
                if (!BST_search(&BST, y))
                    printf("�����������в����ں������ݵĽڵ�\n");
                else
                    printf("�����������д��ں������ݵĽڵ�\n");
                break;
            }
        case 5:
            {
                printf("��ѡ����������ķ�ʽ(1Ϊ�ݹ��,2Ϊ�ǵݹ��):");
                while (1)
                {
                    int select1 = 0;
                    scanf("%d", &select1);
                    printf("����������--�������: ");

                    if (select1 == 1)
                    {
                        if(!BST_preorderI(&BST, printNode)) printf("\n\n�ö���������������(δ��ʼ��)\n");
                        printf("\n");
                        break;
                    }
                    else if (select1 == 2)
                    {
                        if(!BST_preorderR(&BST, printNode)) printf("\n\n�ö���������������(δ��ʼ��)\n");
                        printf("\n");
                        break;
                    }
                    else
                        printf("����������: ");
                }
                break;
            }
        case 6:
            {
                printf("��ѡ����������ķ�ʽ(1Ϊ�ݹ��,2Ϊ�ǵݹ��):");
                while (1)
                {
                    int select2 = 0;
                    scanf("%d", &select2);
                    printf("����������--�������: ");

                    if (select2 == 1)
                    {
                        if(!BST_inorderI(&BST, printNode)) printf("\n\n�ö���������������(δ��ʼ��)\n");
                        printf("\n");
                        break;
                    }
                    else if (select2 == 2)
                    {
                        if(!BST_inorderR(&BST, printNode)) printf("\n\n�ö���������������(δ��ʼ��)\n");
                        printf("\n");
                        break;
                    }
                    else
                        printf("����������: ");
                }
                break;
            }
        case 7:
            {
                printf("��ѡ���������ķ�ʽ(1Ϊ�ݹ��,2Ϊ�ǵݹ��):");
                while (1)
                {
                    int select3 = 0;
                    scanf("%d", &select3);
                    printf("����������--�������: ");

                    if (select3 == 1)
                    {
                        if(!BST_postorderI(&BST, printNode)) printf("\n\n�ö���������������(δ��ʼ��)\n");
                        printf("\n");
                        break;
                    }
                    else if (select3 == 2)
                    {
                        if(!BST_postorderR(&BST, printNode))printf("\n\n�ö���������������(δ��ʼ��)\n");
                        printf("\n");
                        break;
                    }
                    else
                        printf("����������: ");
                }
                break;
            }
        case 8:
            printf("����������--�������: ");
            if(!BST_levelOrder(&BST, printNode)) printf("\n\n�ö���������������(δ��ʼ��)\n");
            printf("\n");
            break;
        case 9:
            if (! (&BST) || !(&BST)->root ) printf("\n�ö���������������(δ��ʼ��)\n\n");
            else 
            {
                printf("\n����������--�������: ");
                BST_preorderR(&BST, printNode);
                printf("\n\n����������--�������: ");
                BST_inorderR(&BST, printNode);
                printf("\n\n����������--�������: ");
                BST_postorderR(&BST, printNode);
                printf("\n\n����������--�������: ");
                BST_levelOrder(&BST, printNode);
                printf("\n\n");
            }
            break;
        case 10:
            freeTree(&BST);
            printf("���ٳɹ�\n");
            break;
        
        default:
            printf("\n����������\n");
            printf("\n");
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}