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
    int key;                    // 节点存储的键值
    struct AVLNode* left;       // 左子节点指针
    struct AVLNode* right;      // 右子节点指针
    int height;                 // 节点高度（从该节点到最远叶子节点的边数）
} AVLNode;


/**
 * 创建新节点
 * @param key 节点键值
 * @return 新节点指针（左右子树为NULL，高度初始化为1）
 */
AVLNode* newNode(int key);

/**
 * 右旋操作（处理LL型不平衡）
 * @param y 失衡节点指针
 * @return 旋转后的新根节点指针
 */
AVLNode* rightRotate(AVLNode* y);

/**
 * 左旋操作（处理RR型不平衡）
 * @param x 失衡节点指针
 * @return 旋转后的新根节点指针
 */
AVLNode* leftRotate(AVLNode* x);

/**
 * 向AVL树插入新节点
 * @param node 当前子树根节点
 * @param key 要插入的键值
 * @return 插入并平衡后的新根节点
 */
AVLNode* insert(AVLNode* node, int key);

/**
 * 从AVL树删除节点
 * @param root 当前子树根节点
 * @param key 要删除的键值
 * @return 删除并平衡后的新根节点
 */
AVLNode* deleteNode(AVLNode* root, int key);

#endif
