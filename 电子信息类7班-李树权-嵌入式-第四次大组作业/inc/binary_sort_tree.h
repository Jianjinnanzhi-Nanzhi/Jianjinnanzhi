/***************************************************************************************
 *	File Name				:	binary_sort_tree.h
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

#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define succeed 1
#define failed 0
#define Status int

typedef int ElemType;

typedef struct Node
{
    ElemType value;
    struct Node *left, *right;
}Node, *NodePtr;

typedef struct BinarySortTree
{
    NodePtr root = NULL;
} BinarySortTree, *BinarySortTreePtr;

/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr BST);

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr BST, ElemType value);

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(BinarySortTreePtr BST, ElemType value);

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(BinarySortTreePtr BST, ElemType value);

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(BinarySortTreePtr BST, void (*visit)(NodePtr));

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(BinarySortTreePtr BST, void (*visit)(NodePtr));

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(BinarySortTreePtr BST, void (*visit)(NodePtr));

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(BinarySortTreePtr BST, void (*visit)(NodePtr));

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(BinarySortTreePtr BST, void (*visit)(NodePtr));

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(BinarySortTreePtr BST, void (*visit)(NodePtr));

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(BinarySortTreePtr BST, void (*visit)(NodePtr));

/*
 *��ӡ�������ڵ�ֵ�Ļص�����
 * @param node  Ҫ����Ķ������ڵ�ָ��
 */
void printNode(NodePtr node);

/*
 *�ݹ��ͷŶ����������ٺ���(��������)
 * @param node  ��ǰ�������ڵ�ָ��
 */
void freeTree(BinarySortTreePtr BST);

#endif //BINARYSORTTREE_BINARY_SORT_TREE_H
