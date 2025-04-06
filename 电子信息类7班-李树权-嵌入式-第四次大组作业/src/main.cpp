#define _CRT_SECURE_NO_WARNINGS
#include "binary_sort_tree.h"

int main()
{
    BinarySortTree BST;
    while (1)
    {
        printf("\n");
        printf("     *******************************            ****************************\n");
        printf("     *  1.排序二叉树的初始化       *            *        2.插入新节点      *\n");
        printf("     *  3.删除节点                 *            *        4.查找节点        *\n");
        printf("     *  5.先序遍历                 **************        6.中序遍历        *\n");
        printf("     *  7.后序遍历                 *            *        8.层序遍历        *\n");
        printf("     *  9.使用先中后层序这四种遍历 *            *        10.销毁排序二叉树 *\n");
        printf("     *******************************            ****************************\n");
        int a = 0;
        printf("请输入对应数字(1-10):");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            {
                int i;
                printf("创建几个节点:");
                scanf("%d", &i);
                int j = i + 1;
                while (i)
                {
                    printf("请输入第%d个节点的数据:", j - i);
                    int e = 0;
                    scanf("%d", &e);
                    if (!BST_insert(&BST, e))
                    {
                        printf("第%d个数据插入失败(已重复),请重新输入\n", j - i);
                        i++;
                    }
                    i--;
                }
                printf("排序二叉树初始化完成\n");
                printf("\n");
                break;
            }
        case 2:
            {
                int e = 0;
                printf("请输入要插入的数据:");
                scanf("%d", &e);
                while (1)
                {
                    if (!BST_insert(&BST, e))
                    {
                        printf("插入失败(已重复),请重新输入:");
                        scanf("%d", &e);
                    }
                    else
                    {
                        printf("插入成功\n");
                        break;
                    }
                }
                break;
            }
        case 3:
            {
                int t = 0;
                printf("请输入要删除节点的值:");
                scanf("%d", &t);
                if (!BST_delete(&BST, t))
                    printf("该二叉排序树无含该值的节点,删除失败\n");
                else
                    printf("删除成功\n");
                break;
            }
        case 4:
            {
                printf("请输入要查询的数据:");
                int y = 0;
                scanf("%d", &y);
                if (!BST_search(&BST, y))
                    printf("二叉排序树中不存在含该数据的节点\n");
                else
                    printf("二叉排序树中存在含该数据的节点\n");
                break;
            }
        case 5:
            {
                printf("请选择先序遍历的方式(1为递归版,2为非递归版):");
                while (1)
                {
                    int select1 = 0;
                    scanf("%d", &select1);
                    printf("二叉排序树--先序遍历: ");

                    if (select1 == 1)
                    {
                        if(!BST_preorderI(&BST, printNode)) printf("\n\n该二叉排序树不存在(未初始化)\n");
                        printf("\n");
                        break;
                    }
                    else if (select1 == 2)
                    {
                        if(!BST_preorderR(&BST, printNode)) printf("\n\n该二叉排序树不存在(未初始化)\n");
                        printf("\n");
                        break;
                    }
                    else
                        printf("请重新输入: ");
                }
                break;
            }
        case 6:
            {
                printf("请选择中序遍历的方式(1为递归版,2为非递归版):");
                while (1)
                {
                    int select2 = 0;
                    scanf("%d", &select2);
                    printf("二叉排序树--中序遍历: ");

                    if (select2 == 1)
                    {
                        if(!BST_inorderI(&BST, printNode)) printf("\n\n该二叉排序树不存在(未初始化)\n");
                        printf("\n");
                        break;
                    }
                    else if (select2 == 2)
                    {
                        if(!BST_inorderR(&BST, printNode)) printf("\n\n该二叉排序树不存在(未初始化)\n");
                        printf("\n");
                        break;
                    }
                    else
                        printf("请重新输入: ");
                }
                break;
            }
        case 7:
            {
                printf("请选择后序遍历的方式(1为递归版,2为非递归版):");
                while (1)
                {
                    int select3 = 0;
                    scanf("%d", &select3);
                    printf("二叉排序树--后序遍历: ");

                    if (select3 == 1)
                    {
                        if(!BST_postorderI(&BST, printNode)) printf("\n\n该二叉排序树不存在(未初始化)\n");
                        printf("\n");
                        break;
                    }
                    else if (select3 == 2)
                    {
                        if(!BST_postorderR(&BST, printNode))printf("\n\n该二叉排序树不存在(未初始化)\n");
                        printf("\n");
                        break;
                    }
                    else
                        printf("请重新输入: ");
                }
                break;
            }
        case 8:
            printf("二叉排序树--层序遍历: ");
            if(!BST_levelOrder(&BST, printNode)) printf("\n\n该二叉排序树不存在(未初始化)\n");
            printf("\n");
            break;
        case 9:
            if (! (&BST) || !(&BST)->root ) printf("\n该二叉排序树不存在(未初始化)\n\n");
            else 
            {
                printf("\n二叉排序树--先序遍历: ");
                BST_preorderR(&BST, printNode);
                printf("\n\n二叉排序树--中序遍历: ");
                BST_inorderR(&BST, printNode);
                printf("\n\n二叉排序树--后序遍历: ");
                BST_postorderR(&BST, printNode);
                printf("\n\n二叉排序树--层序遍历: ");
                BST_levelOrder(&BST, printNode);
                printf("\n\n");
            }
            break;
        case 10:
            freeTree(&BST);
            printf("销毁成功\n");
            break;
        
        default:
            printf("\n请重新输入\n");
            printf("\n");
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}