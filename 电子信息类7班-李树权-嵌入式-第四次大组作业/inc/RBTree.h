/***************************************************************************************
 *	File Name				:	RBTree.h
 *	CopyRight				:	2025 QG Studio
 *	SYSTEM					:   win11
 *	Create Data				:	2025.4.6
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/
#ifndef  RBTREE_H
#define  RBTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef enum 
{
    RED,    // ��ɫ�ڵ�
    BLACK   // ��ɫ�ڵ� 
} Color;

typedef struct RBNode 
{
    int key;                //�ڵ��ֵ 
    Color color;            //�ڵ���ɫ 
    struct RBNode* left;    //���ӽڵ�ָ��
    struct RBNode* right;   //���ӽڵ�ָ�� 
    struct RBNode* parent;  //���ڵ�ָ�� 
} RBNode;

/**
 * @struct RedBlackTree
 * @brief ������ṹ��
 */
typedef struct 
{
    RBNode* root;   // ���ڵ�ָ�� 
    RBNode* nil;    //�ڱ��ڵ�ָ��(����NIL) 
} RedBlackTree;

/**
 * @brief ��ʼ�������
 * @param tree Ҫ��ʼ���ĺ����ָ��
 */
void init_rbtree(RedBlackTree* tree);

/**
 * @brief ����ڵ�
 * @param tree �����ָ��
 * @param key Ҫ����ļ�ֵ
 * @note ��ִ�б�׼BST���룬Ȼ�����insert_fixup�޸�
 */
void rb_insert(RedBlackTree* tree, int key);
                    
/**
 * @brief ɾ���ڵ�
 * @param tree �����ָ��
 * @param key Ҫɾ���ļ�ֵ
 * @note �Ȳ��ҽڵ㣬Ȼ��ִ��ɾ������������޸����������
 */
void rb_delete(RedBlackTree* tree, int key);


#endif // ! RBTREE_H
