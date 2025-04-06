#include "RBTree.h"

/**
 * @brief 创建哨兵节点(NIL节点)
 * @return RBNode* 创建的哨兵节点指针
 * @note 哨兵节点颜色为黑色，所有指针初始化为NULL
 */
RBNode* create_nil_node()
{
    RBNode* node = (RBNode*)malloc(sizeof(RBNode));
    node->color = BLACK;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->key = 0;  // 哨兵节点的键值无意义
    return node;
}

/**
 * @brief 初始化红黑树
 * @param tree 要初始化的红黑树指针
 */
void init_rbtree(RedBlackTree* tree) 
{
    tree->nil = create_nil_node();
    tree->root = tree->nil;  // 初始时根节点指向NIL
}

/**
 * @brief 创建新节点
 * @param key 节点键值
 * @return RBNode* 创建的新节点指针
 * @note 新节点默认颜色为红色，左右子节点需在插入时设置为NIL
 */
RBNode* create_rbnode(int key) 
{
    RBNode* node = (RBNode*)malloc(sizeof(RBNode));
    node->key = key;
    node->color = RED;  // 新节点初始为红色
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}


/**
 * @brief 左旋转操作
 * @param tree 红黑树指针
 * @param x 旋转基准节点
 */
void left_rotate(RedBlackTree* tree, RBNode* x) 
{
    RBNode* y = x->right;  // 设置y为x的右子节点

    // 将y的左子树变为x的右子树
    x->right = y->left;
    if (y->left != tree->nil)
    {
        y->left->parent = x;
    }

    // 将y的父节点设为x的父节点
    y->parent = x->parent;
    if (x->parent == tree->nil) 
    {
        tree->root = y;  // x为根节点时，y成为新根
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else 
    {
        x->parent->right = y;
    }

    // 将x放到y的左子树位置
    y->left = x;
    x->parent = y;
}

/**
 * @brief 右旋转操作
 * @param tree 红黑树指针
 * @param y 旋转基准节点
 */
void right_rotate(RedBlackTree* tree, RBNode* y) 
{
    RBNode* x = y->left;  // 设置x为y的左子节点

    // 将x的右子树变为y的左子树
    y->left = x->right;
    if (x->right != tree->nil) 
    {
        x->right->parent = y;
    }

    // 将x的父节点设为y的父节点
    x->parent = y->parent;
    if (y->parent == tree->nil) 
    {
        tree->root = x;  // y为根节点时，x成为新根
    }
    else if (y == y->parent->left)
    {
        y->parent->left = x;
    }
    else 
    {
        y->parent->right = x;
    }

    // 将y放到x的右子树位置
    x->right = y;
    y->parent = x;
}

/**
 * @brief 插入节点后的修复操作
 * @param tree 红黑树指针
 * @param z 新插入的节点
 * @note确保红黑树性质不被破坏
 */
void insert_fixup(RedBlackTree* tree, RBNode* z) 
{
    // 当z的父节点为红色时循环
    while (z->parent->color == RED)
    {
        // 父节点是祖父节点的左子节点
        if (z->parent == z->parent->parent->left)
        {
            RBNode* y = z->parent->parent->right;  // y是z的叔叔节点

            // 叔叔节点是红色
            if (y->color == RED)
            {
                z->parent->color = BLACK;      // 父节点变黑
                y->color = BLACK;              // 叔叔节点变黑
                z->parent->parent->color = RED; // 祖父节点变红
                z = z->parent->parent;         // z指向祖父节点继续检查
            }
            else 
            {             
                // 叔叔是黑色且z是右子节点
                if (z == z->parent->right) 
                {
                    z = z->parent;            // z指向父节点
                    left_rotate(tree, z);     // 左旋转
                }
                // 叔叔是黑色且z是左子节点
                z->parent->color = BLACK;     // 父节点变黑
                z->parent->parent->color = RED; // 祖父节点变红
                right_rotate(tree, z->parent->parent); // 右旋转祖父节点
            }
        }
        else
        {  // 对称情况：父节点是祖父节点的右子节点
            RBNode* y = z->parent->parent->left;  // y是z的叔叔节点

            // 镜像：叔叔节点是红色
            if (y->color == RED) 
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else 
            {
                // 镜像：叔叔是黑色且z是左子节点
                if (z == z->parent->left)
                {
                    z = z->parent;
                    right_rotate(tree, z);
                }
                //镜像：叔叔是黑色且z是右子节点
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                left_rotate(tree, z->parent->parent);
            }
        }
    }
    tree->root->color = BLACK;  // 确保根节点始终为黑色
}

/**
 * @brief 插入节点
 * @param tree 红黑树指针
 * @param key 要插入的键值
 * @note 先执行标准BST插入，然后调用insert_fixup修复
 */
void rb_insert(RedBlackTree* tree, int key) 
{
    RBNode* z = create_rbnode(key);  // 创建新节点
    RBNode* y = tree->nil;           // y用于跟踪父节点
    RBNode* x = tree->root;          // x从根节点开始查找

    // 标准BST插入过程
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

    // 设置新节点的父节点
    z->parent = y;
    if (y == tree->nil)
    {
        tree->root = z;  // 树为空时，新节点成为根
    }
    else if (z->key < y->key) 
    {
        y->left = z;
    }
    else 
    {
        y->right = z;
    }

    // 初始化新节点的子节点为NIL
    z->left = tree->nil;
    z->right = tree->nil;
    z->color = RED;  // 新节点初始为红色

    // 修复红黑树性质
    insert_fixup(tree, z);
}


/**
 * @brief 用子树v替换子树u
 * @param tree 红黑树指针
 * @param u 被替换的子树根节点
 * @param v 替换的子树根节点
 * 保证树结构正确
 */
void rb_transplant(RedBlackTree* tree, RBNode* u, RBNode* v) 
{
    if (u->parent == tree->nil) 
    {
        tree->root = v;  // u是根节点时，v成为新根
    }
    else if (u == u->parent->left) 
    {
        u->parent->left = v;
    }
    else 
    {
        u->parent->right = v;
    }
    v->parent = u->parent;  // 更新v的父节点指针
}

/**
 * @brief 查找子树中的最小节点
 * @param tree 红黑树指针
 * @param x 子树根节点
 * @return RBNode* 最小节点指针
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
 * @brief 删除节点后的修复操作
 * @param tree 红黑树指针
 * @param x 需要修复的节点
 * @note 确保红黑树性质不被破坏
 */
void delete_fixup(RedBlackTree* tree, RBNode* x) 
{
    while (x != tree->root && x->color == BLACK) 
    {
        if (x == x->parent->left)
        {
            RBNode* w = x->parent->right;  // w是x的兄弟节点

            // 情况1：兄弟节点w是红色
            if (w->color == RED)
            {
                w->color = BLACK;
                x->parent->color = RED;
                left_rotate(tree, x->parent);
                w = x->parent->right;  // 更新兄弟节点
            }

            // 情况2：w的两个子节点都是黑色
            if (w->left->color == BLACK && w->right->color == BLACK) 
            {
                w->color = RED;
                x = x->parent;  // 将x上移
            }
            else 
            {
                // 情况3：w的右子节点是黑色，左子节点是红色
                if (w->right->color == BLACK)
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    right_rotate(tree, w);
                    w = x->parent->right;
                }
                // 情况4：w的右子节点是红色
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                left_rotate(tree, x->parent);
                x = tree->root;  // 终止循环
            }
        }
        else 
        {  // 对称情况：x是右子节点
            RBNode* w = x->parent->left;

            // 镜像：兄弟节点w是红色
            if (w->color == RED) 
            {
                w->color = BLACK;
                x->parent->color = RED;
                right_rotate(tree, x->parent);
                w = x->parent->left;
            }

            // 镜像：w的两个子节点都是黑色
            if (w->right->color == BLACK && w->left->color == BLACK) 
            {
                w->color = RED;
                x = x->parent;
            }
            else 
            {
                // 镜像：w的左子节点是黑色，右子节点是红色
                if (w->left->color == BLACK)
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    left_rotate(tree, w);
                    w = x->parent->left;
                }
                // 镜像：w的左子节点是红色
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                right_rotate(tree, x->parent);
                x = tree->root;
            }
        }
    }
    x->color = BLACK;  // 确保x节点变为黑色
}

/**
 * @brief 删除节点
 * @param tree 红黑树指针
 * @param key 要删除的键值
 * @note 先查找节点，然后执行删除操作，最后修复红黑树性质
 */
void rb_delete(RedBlackTree* tree, int key) 
{
    RBNode* z = tree->root;
    // 查找要删除的节点
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

    RBNode* y = z;              // y记录实际被删除的节点
    RBNode* x;                  // x记录y的子节点
    Color y_original_color = y->color;  // 保存原始颜色

    //z最多有一个非NIL子节点
    if (z->left == tree->nil) 
    {
        x = z->right;
        rb_transplant(tree, z, z->right);
    }
    // z只有左子节点
    else if (z->right == tree->nil) 
    {

        x = z->left;
        rb_transplant(tree, z, z->left);
    }
    //z有两个非NIL子节点
    else 
    {
        y = tree_minimum(tree, z->right);  // 找到z的后继节点
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

    // 如果删除的节点是黑色，需要修复
    if (y_original_color == BLACK)
    {
        delete_fixup(tree, x);
    }

    free(z);  // 释放被删除节点的内存
}

