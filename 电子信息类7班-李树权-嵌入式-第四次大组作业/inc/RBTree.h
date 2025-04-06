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
    RED,    // 红色节点
    BLACK   // 黑色节点 
} Color;

typedef struct RBNode 
{
    int key;                //节点键值 
    Color color;            //节点颜色 
    struct RBNode* left;    //左子节点指针
    struct RBNode* right;   //右子节点指针 
    struct RBNode* parent;  //父节点指针 
} RBNode;

/**
 * @struct RedBlackTree
 * @brief 红黑树结构体
 */
typedef struct 
{
    RBNode* root;   // 根节点指针 
    RBNode* nil;    //哨兵节点指针(代表NIL) 
} RedBlackTree;

/**
 * @brief 初始化红黑树
 * @param tree 要初始化的红黑树指针
 */
void init_rbtree(RedBlackTree* tree);

/**
 * @brief 插入节点
 * @param tree 红黑树指针
 * @param key 要插入的键值
 * @note 先执行标准BST插入，然后调用insert_fixup修复
 */
void rb_insert(RedBlackTree* tree, int key);
                    
/**
 * @brief 删除节点
 * @param tree 红黑树指针
 * @param key 要删除的键值
 * @note 先查找节点，然后执行删除操作，最后修复红黑树性质
 */
void rb_delete(RedBlackTree* tree, int key);


#endif // ! RBTREE_H
