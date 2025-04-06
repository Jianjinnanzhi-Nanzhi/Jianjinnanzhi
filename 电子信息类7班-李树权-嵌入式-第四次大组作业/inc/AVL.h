/***************************************************************************************
 *	File Name				:	AVL.h
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

#ifndef  AVL_H_
#define  AVL_H

#include <stdio.h>
#include <stdlib.h>


typedef struct AVLNode 
{
    int key;                    // �ڵ�洢�ļ�ֵ
    struct AVLNode* left;       // ���ӽڵ�ָ��
    struct AVLNode* right;      // ���ӽڵ�ָ��
    int height;                 // �ڵ�߶ȣ��Ӹýڵ㵽��ԶҶ�ӽڵ�ı�����
} AVLNode;


/**
 * �����½ڵ�
 * @param key �ڵ��ֵ
 * @return �½ڵ�ָ�루��������ΪNULL���߶ȳ�ʼ��Ϊ1��
 */
AVLNode* newNode(int key);

/**
 * ��������������LL�Ͳ�ƽ�⣩
 * @param y ʧ��ڵ�ָ��
 * @return ��ת����¸��ڵ�ָ��
 */
AVLNode* rightRotate(AVLNode* y);

/**
 * ��������������RR�Ͳ�ƽ�⣩
 * @param x ʧ��ڵ�ָ��
 * @return ��ת����¸��ڵ�ָ��
 */
AVLNode* leftRotate(AVLNode* x);

/**
 * ��AVL�������½ڵ�
 * @param node ��ǰ�������ڵ�
 * @param key Ҫ����ļ�ֵ
 * @return ���벢ƽ�����¸��ڵ�
 */
AVLNode* insert(AVLNode* node, int key);

/**
 * ��AVL��ɾ���ڵ�
 * @param root ��ǰ�������ڵ�
 * @param key Ҫɾ���ļ�ֵ
 * @return ɾ����ƽ�����¸��ڵ�
 */
AVLNode* deleteNode(AVLNode* root, int key);

#endif
