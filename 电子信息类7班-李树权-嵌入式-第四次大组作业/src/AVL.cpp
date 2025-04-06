#include "AVL.h"

/**
 * 创建新节点
 * @param key 节点键值
 * @return 新节点指针（左右子树为NULL，高度初始化为1）
 */
AVLNode* newNode(int key) 
{
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;  // 新节点初始高度为1（因为视为叶子节点）
    return node;
}

/**
 * 获取节点高度（安全处理NULL指针）
 * @param node 节点指针
 * @return 节点高度（NULL节点返回0）
 */
int height(AVLNode* node) 
{
    // NULL节点高度定义为0（空树高度为0）
    return node == NULL ? 0 : node->height;
}

//计算两个数的最大值
int max(int a, int b) 
{
    return (a > b) ? a : b;
}

/**
 * 计算节点的平衡因子
 * 平衡因子 = 左子树高度 - 右子树高度
 * 值范围：-1（右子树高1层）、0（平衡）、1（左子树高1层）
 * 绝对值超过1时需要调整
 */
int getBalance(AVLNode* node) 
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

/**
 * 右旋操作（处理LL型不平衡）
 * @param y 失衡节点指针
 * @return 旋转后的新根节点指针
 */
AVLNode* rightRotate(AVLNode* y) 
{
    //保存子节点指针
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    //执行旋转（修改指针关系）
    x->right = y;
    y->left = T2;

    //更新高度（必须先更新y，因为y现在是x的子节点）
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x; // 返回新的根节点
}

/**
 * 左旋操作（处理RR型不平衡）
 * @param x 失衡节点指针
 * @return 旋转后的新根节点指针
 */
AVLNode* leftRotate(AVLNode* x) 
{
    // 保存子节点指针
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // 执行旋转
    y->left = x;
    x->right = T2;

    // 更新高度
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}


/**
 * 向AVL树插入新节点
 * @param node 当前子树根节点
 * @param key 要插入的键值
 * @return 插入并平衡后的新根节点
 */
AVLNode* insert(AVLNode* node, int key) 
{
   // 执行标准BST插入（递归）
    if (node == NULL)
        return newNode(key); // 到达空位置，创建新节点

    // 递归插入左子树
    if (key < node->key)
        node->left = insert(node->left, key);
    // 递归插入右子树
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // 不允许重复键（实际应用中可根据需求修改）
        return node;

    //更新当前节点高度
    node->height = 1 + max(height(node->left), height(node->right));

    //检查平衡并处理四种不平衡情况
    int balance = getBalance(node);

    //左左（LL）-> 右旋
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    //右右（RR）-> 左旋
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    //左右（LR）-> 先左旋左子树，再右旋当前节点
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // 右左（RL）-> 先右旋右子树，再左旋当前节点
    if (balance < -1 && key < node->right->key) 
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    //返回未调整的节点指针（已经平衡的情况）
    return node;
}

/**
 * 查找子树中的最小节点（辅助删除用）
 * @param node 子树根节点
 * @return 最小键值节点指针
 */
AVLNode* minValueNode(AVLNode* node) 
{
    AVLNode* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

/**
 * 从AVL树删除节点
 * @param root 当前子树根节点
 * @param key 要删除的键值
 * @return 删除并平衡后的新根节点

 */
AVLNode* deleteNode(AVLNode* root, int key) 
{
    //执行标准BST删除 
    if (root == NULL)
        return root;

    // 递归查找要删除的节点
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else 
    {
        // 找到要删除的节点，分三种情况处理：
        // /节点有0或1个子节点
        if ((root->left == NULL) || (root->right == NULL)) 
        {
            AVLNode* temp = root->left ? root->left : root->right;

            // 无子节点
            if (temp == NULL) 
            {
                temp = root;
                root = NULL;
            }
            // 有一个子节点
            else
                *root = *temp; // 用子节点内容覆盖当前节点

            free(temp);
        }
        // 节点有两个子节点
        else 
        {
            // 找到右子树的最小节点（中序后继）
            AVLNode* temp = minValueNode(root->right);

            // 用后继节点的值替换当前节点值
            root->key = temp->key;

            // 删除后继节点（此时要删除的值在后继位置，且该节点最多有一个右子节点）
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // 如果树为空（删除后没有节点）
    if (root == NULL)
        return root;

    //更新当前节点高度
    root->height = 1 + max(height(root->left), height(root->right));

    //检查平衡并处理四种不平衡情况
    int balance = getBalance(root);

    // 左左情况（LL）
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // 左右情况（LR）
    if (balance > 1 && getBalance(root->left) < 0) 
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // 右右情况（RR）
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // 右左情况（RL）
    if (balance < -1 && getBalance(root->right) > 0) 
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
