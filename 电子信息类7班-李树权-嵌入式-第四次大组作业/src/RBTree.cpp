#include "RBTree.h"

/**
 * @brief �����ڱ��ڵ�(NIL�ڵ�)
 * @return RBNode* �������ڱ��ڵ�ָ��
 * @note �ڱ��ڵ���ɫΪ��ɫ������ָ���ʼ��ΪNULL
 */
RBNode* create_nil_node()
{
    RBNode* node = (RBNode*)malloc(sizeof(RBNode));
    node->color = BLACK;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->key = 0;  // �ڱ��ڵ�ļ�ֵ������
    return node;
}

/**
 * @brief ��ʼ�������
 * @param tree Ҫ��ʼ���ĺ����ָ��
 */
void init_rbtree(RedBlackTree* tree) 
{
    tree->nil = create_nil_node();
    tree->root = tree->nil;  // ��ʼʱ���ڵ�ָ��NIL
}

/**
 * @brief �����½ڵ�
 * @param key �ڵ��ֵ
 * @return RBNode* �������½ڵ�ָ��
 * @note �½ڵ�Ĭ����ɫΪ��ɫ�������ӽڵ����ڲ���ʱ����ΪNIL
 */
RBNode* create_rbnode(int key) 
{
    RBNode* node = (RBNode*)malloc(sizeof(RBNode));
    node->key = key;
    node->color = RED;  // �½ڵ��ʼΪ��ɫ
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}


/**
 * @brief ����ת����
 * @param tree �����ָ��
 * @param x ��ת��׼�ڵ�
 */
void left_rotate(RedBlackTree* tree, RBNode* x) 
{
    RBNode* y = x->right;  // ����yΪx�����ӽڵ�

    // ��y����������Ϊx��������
    x->right = y->left;
    if (y->left != tree->nil)
    {
        y->left->parent = x;
    }

    // ��y�ĸ��ڵ���Ϊx�ĸ��ڵ�
    y->parent = x->parent;
    if (x->parent == tree->nil) 
    {
        tree->root = y;  // xΪ���ڵ�ʱ��y��Ϊ�¸�
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else 
    {
        x->parent->right = y;
    }

    // ��x�ŵ�y��������λ��
    y->left = x;
    x->parent = y;
}

/**
 * @brief ����ת����
 * @param tree �����ָ��
 * @param y ��ת��׼�ڵ�
 */
void right_rotate(RedBlackTree* tree, RBNode* y) 
{
    RBNode* x = y->left;  // ����xΪy�����ӽڵ�

    // ��x����������Ϊy��������
    y->left = x->right;
    if (x->right != tree->nil) 
    {
        x->right->parent = y;
    }

    // ��x�ĸ��ڵ���Ϊy�ĸ��ڵ�
    x->parent = y->parent;
    if (y->parent == tree->nil) 
    {
        tree->root = x;  // yΪ���ڵ�ʱ��x��Ϊ�¸�
    }
    else if (y == y->parent->left)
    {
        y->parent->left = x;
    }
    else 
    {
        y->parent->right = x;
    }

    // ��y�ŵ�x��������λ��
    x->right = y;
    y->parent = x;
}

/**
 * @brief ����ڵ����޸�����
 * @param tree �����ָ��
 * @param z �²���Ľڵ�
 * @noteȷ����������ʲ����ƻ�
 */
void insert_fixup(RedBlackTree* tree, RBNode* z) 
{
    // ��z�ĸ��ڵ�Ϊ��ɫʱѭ��
    while (z->parent->color == RED)
    {
        // ���ڵ����游�ڵ�����ӽڵ�
        if (z->parent == z->parent->parent->left)
        {
            RBNode* y = z->parent->parent->right;  // y��z������ڵ�

            // ����ڵ��Ǻ�ɫ
            if (y->color == RED)
            {
                z->parent->color = BLACK;      // ���ڵ���
                y->color = BLACK;              // ����ڵ���
                z->parent->parent->color = RED; // �游�ڵ���
                z = z->parent->parent;         // zָ���游�ڵ�������
            }
            else 
            {             
                // �����Ǻ�ɫ��z�����ӽڵ�
                if (z == z->parent->right) 
                {
                    z = z->parent;            // zָ�򸸽ڵ�
                    left_rotate(tree, z);     // ����ת
                }
                // �����Ǻ�ɫ��z�����ӽڵ�
                z->parent->color = BLACK;     // ���ڵ���
                z->parent->parent->color = RED; // �游�ڵ���
                right_rotate(tree, z->parent->parent); // ����ת�游�ڵ�
            }
        }
        else
        {  // �Գ���������ڵ����游�ڵ�����ӽڵ�
            RBNode* y = z->parent->parent->left;  // y��z������ڵ�

            // ��������ڵ��Ǻ�ɫ
            if (y->color == RED) 
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else 
            {
                // ���������Ǻ�ɫ��z�����ӽڵ�
                if (z == z->parent->left)
                {
                    z = z->parent;
                    right_rotate(tree, z);
                }
                //���������Ǻ�ɫ��z�����ӽڵ�
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                left_rotate(tree, z->parent->parent);
            }
        }
    }
    tree->root->color = BLACK;  // ȷ�����ڵ�ʼ��Ϊ��ɫ
}

/**
 * @brief ����ڵ�
 * @param tree �����ָ��
 * @param key Ҫ����ļ�ֵ
 * @note ��ִ�б�׼BST���룬Ȼ�����insert_fixup�޸�
 */
void rb_insert(RedBlackTree* tree, int key) 
{
    RBNode* z = create_rbnode(key);  // �����½ڵ�
    RBNode* y = tree->nil;           // y���ڸ��ٸ��ڵ�
    RBNode* x = tree->root;          // x�Ӹ��ڵ㿪ʼ����

    // ��׼BST�������
    while (x != tree->nil) 
    {
        y = x;
        if (z->key < x->key) 
        {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }

    // �����½ڵ�ĸ��ڵ�
    z->parent = y;
    if (y == tree->nil)
    {
        tree->root = z;  // ��Ϊ��ʱ���½ڵ��Ϊ��
    }
    else if (z->key < y->key) 
    {
        y->left = z;
    }
    else 
    {
        y->right = z;
    }

    // ��ʼ���½ڵ���ӽڵ�ΪNIL
    z->left = tree->nil;
    z->right = tree->nil;
    z->color = RED;  // �½ڵ��ʼΪ��ɫ

    // �޸����������
    insert_fixup(tree, z);
}


/**
 * @brief ������v�滻����u
 * @param tree �����ָ��
 * @param u ���滻���������ڵ�
 * @param v �滻���������ڵ�
 * ��֤���ṹ��ȷ
 */
void rb_transplant(RedBlackTree* tree, RBNode* u, RBNode* v) 
{
    if (u->parent == tree->nil) 
    {
        tree->root = v;  // u�Ǹ��ڵ�ʱ��v��Ϊ�¸�
    }
    else if (u == u->parent->left) 
    {
        u->parent->left = v;
    }
    else 
    {
        u->parent->right = v;
    }
    v->parent = u->parent;  // ����v�ĸ��ڵ�ָ��
}

/**
 * @brief ���������е���С�ڵ�
 * @param tree �����ָ��
 * @param x �������ڵ�
 * @return RBNode* ��С�ڵ�ָ��
 */
RBNode* tree_minimum(RedBlackTree* tree, RBNode* x) 
{
    while (x->left != tree->nil) 
    {
        x = x->left;
    }
    return x;
}

/**
 * @brief ɾ���ڵ����޸�����
 * @param tree �����ָ��
 * @param x ��Ҫ�޸��Ľڵ�
 * @note ȷ����������ʲ����ƻ�
 */
void delete_fixup(RedBlackTree* tree, RBNode* x) 
{
    while (x != tree->root && x->color == BLACK) 
    {
        if (x == x->parent->left)
        {
            RBNode* w = x->parent->right;  // w��x���ֵܽڵ�

            // ���1���ֵܽڵ�w�Ǻ�ɫ
            if (w->color == RED)
            {
                w->color = BLACK;
                x->parent->color = RED;
                left_rotate(tree, x->parent);
                w = x->parent->right;  // �����ֵܽڵ�
            }

            // ���2��w�������ӽڵ㶼�Ǻ�ɫ
            if (w->left->color == BLACK && w->right->color == BLACK) 
            {
                w->color = RED;
                x = x->parent;  // ��x����
            }
            else 
            {
                // ���3��w�����ӽڵ��Ǻ�ɫ�����ӽڵ��Ǻ�ɫ
                if (w->right->color == BLACK)
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    right_rotate(tree, w);
                    w = x->parent->right;
                }
                // ���4��w�����ӽڵ��Ǻ�ɫ
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                left_rotate(tree, x->parent);
                x = tree->root;  // ��ֹѭ��
            }
        }
        else 
        {  // �Գ������x�����ӽڵ�
            RBNode* w = x->parent->left;

            // �����ֵܽڵ�w�Ǻ�ɫ
            if (w->color == RED) 
            {
                w->color = BLACK;
                x->parent->color = RED;
                right_rotate(tree, x->parent);
                w = x->parent->left;
            }

            // ����w�������ӽڵ㶼�Ǻ�ɫ
            if (w->right->color == BLACK && w->left->color == BLACK) 
            {
                w->color = RED;
                x = x->parent;
            }
            else 
            {
                // ����w�����ӽڵ��Ǻ�ɫ�����ӽڵ��Ǻ�ɫ
                if (w->left->color == BLACK)
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    left_rotate(tree, w);
                    w = x->parent->left;
                }
                // ����w�����ӽڵ��Ǻ�ɫ
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                right_rotate(tree, x->parent);
                x = tree->root;
            }
        }
    }
    x->color = BLACK;  // ȷ��x�ڵ��Ϊ��ɫ
}

/**
 * @brief ɾ���ڵ�
 * @param tree �����ָ��
 * @param key Ҫɾ���ļ�ֵ
 * @note �Ȳ��ҽڵ㣬Ȼ��ִ��ɾ������������޸����������
 */
void rb_delete(RedBlackTree* tree, int key) 
{
    RBNode* z = tree->root;
    // ����Ҫɾ���Ľڵ�
    while (z != tree->nil && z->key != key) 
    {
        if (key < z->key)
        {
            z = z->left;
        }
        else {
            z = z->right;
        }
    }

    if (z == tree->nil) 
    {
        printf("Key %d not found in the tree.\n", key);
        return;
    }

    RBNode* y = z;              // y��¼ʵ�ʱ�ɾ���Ľڵ�
    RBNode* x;                  // x��¼y���ӽڵ�
    Color y_original_color = y->color;  // ����ԭʼ��ɫ

    //z�����һ����NIL�ӽڵ�
    if (z->left == tree->nil) 
    {
        x = z->right;
        rb_transplant(tree, z, z->right);
    }
    // zֻ�����ӽڵ�
    else if (z->right == tree->nil) 
    {

        x = z->left;
        rb_transplant(tree, z, z->left);
    }
    //z��������NIL�ӽڵ�
    else 
    {
        y = tree_minimum(tree, z->right);  // �ҵ�z�ĺ�̽ڵ�
        y_original_color = y->color;
        x = y->right;

        if (y->parent == z) 
        {
            x->parent = y;
        }
        else 
        {
            rb_transplant(tree, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        rb_transplant(tree, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    // ���ɾ���Ľڵ��Ǻ�ɫ����Ҫ�޸�
    if (y_original_color == BLACK)
    {
        delete_fixup(tree, x);
    }

    free(z);  // �ͷű�ɾ���ڵ���ڴ�
}

