#include "binary_sort_tree.h"
#include "Stack_and_Queue.h"

/*
 *初始化二叉排序树
 * @param BST 二叉排序树指针
 * @return succeed-成功, failed-失败
 */
Status BST_init(BinarySortTreePtr BST) 
{
    if (!BST) return failed;
    BST->root = NULL;
    return succeed;
}

/*
 *二叉排序树的插入
 * @param BST 二叉排序树指针
 * @param value 要插入节点的值
 * @return succeed-成功, failed-失败
 */
Status BST_insert(BinarySortTreePtr BST, ElemType value) 
{
    if (!BST) return failed;//判断树是否存在

    //创建新节点
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    if (!newNode) return failed;

    //判断该树根节点是否为空
    if (!BST->root) 
    {
        BST->root = newNode;
        return succeed;
    }

    //parent为current的父节点
    NodePtr current = BST->root;
    NodePtr parent = NULL;

    //开始遍历寻找合适位置
    while (current) 
    {
        parent = current;
        if (value < current->value) 
        {
            current = current->left;
        }
        else if (value > current->value) 
        {
            current = current->right;
        }
        else 
        {
            free(newNode);
            return failed; // 值已存在(默认情况下，二叉排序树的定义要求每个节点的键值唯一)
        }
    }

    //此时parent为要插入节点的父节点
    if (value < parent->value) 
    {
        parent->left = newNode;
    }
    else 
    {
        parent->right = newNode;
    }

    return succeed;
}

/*
 *二叉排序树的删除
 * @param BST 二叉排序树指针
 * @param value 要删除节点的值
 * @return succeed-成功, failed-失败
 */
Status BST_delete(BinarySortTreePtr BST, ElemType value) 
{
    if (!BST || !BST->root) return failed;

    //parent为current的父节点
    NodePtr current = BST->root;
    NodePtr parent = NULL;

    // 查找要删除的节点及其父节点
    while (current != NULL && current->value != value) 
    {
        parent = current;
        if (value < current->value)
        {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    // 未找到要删除的节点
    if (current == NULL) return failed;

    // 根据子节点情况处理删除
    
    // 情况1: 叶子节点
    if (current->left == NULL && current->right == NULL) 
    {
        if (current == BST->root) 
        {
            BST->root = NULL;
        }
        else if (parent->left == current) 
        {
            parent->left = NULL;
        }
        else 
        {
            parent->right = NULL;
        }
        free(current);
    }

    // 情况2: 只有一个右子节点
    else if (current->left == NULL) 
    {
        if (current == BST->root) 
        {
            BST->root = current->right;
        }
        else if (parent->left == current) 
        {
            parent->left = current->right;
        }
        else 
        {
            parent->right = current->right;
        }
        free(current);
    }
    // 情况3: 只有一个左子节点
    else if (current->right == NULL) 
    {
        if (current == BST->root) 
        {
            BST->root = current->left;
        }
        else if (parent->left == current) 
        {
            parent->left = current->left;
        }
        else {
            parent->right = current->left;
        }
        free(current);
    }

    // 情况4: 有两个子节点
    else 
    {
        // 找到右子树的最小节点及其父节点
        NodePtr S= current->right;
        NodePtr SParent = current;

        while (S->left != NULL) 
        {
            SParent = S;
            S = S->left;
        }

        // 保存后继节点的值
        ElemType SValue =S->value;

        // 递归删除后继节点（此时后继节点最多只有一个右子节点）
        BST_delete(BST, SValue);

        // 用后继节点的值替换当前节点值
        current->value = SValue;
    }

    return succeed;
}

/*
 *二叉排序树的查找
 * @param BST 二叉排序树指针
 * @param value 要查找节点的值
 * @return true-存在, false-不存在
 */
Status BST_search(BinarySortTreePtr BST, ElemType value) 
{
    // 检查树是否为空
    if (BST == NULL || BST->root == NULL) 
    {
        return false; // 空树直接返回不存在
    }

    //从根节点开始查找
    NodePtr current = BST->root;

    while (current != NULL) 
    {
        // 比较当前节点值
        if (value == current->value) 
        {
            return true; // 找到匹配值
        }
        // 根据BST性质决定查找方向
        else if (value < current->value)
        {
            current = current->left; // 向左子树查找
        }
        else 
        {
            current = current->right; // 向右子树查找
        }
    }
    // 遍历结束未找到
    return false;
}

/*
 *先序遍历(非递归)
 * @param BST 二叉排序树指针
 * @param visit 访问节点的回调函数
 * @return  succeed-成功, failed-失败
 * 
 * 前序遍历顺序：根节点 -> 左子树 -> 右子树
 */
Status BST_preorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)) 
{
    if (!BST || !BST->root || !visit) return failed;

    LinkedStack* stack = createStack();
    push(stack, BST->root);

    while (!isStackEmpty(stack)) 
    {
        NodePtr current = pop(stack);
        visit(current); // 先访问根节点

        // 注意入栈顺序：右子节点先入栈
        if (current->right) push(stack, current->right);
        if (current->left) push(stack, current->left);
    }

    freeStack(stack);
    return succeed;
}

/*
 *先序遍历(递归)的辅助函数
 * @param node 二叉排序树的节点指针
 * @param visit 访问节点的回调函数
 * @return None
 */
static void preorderHelper(NodePtr node, void (*visit)(NodePtr)) 
{
    if (!node) return;
    visit(node);
    preorderHelper(node->left, visit);
    preorderHelper(node->right, visit);
}

/*
 *先序遍历(递归)
 * @param BST 二叉排序树指针
 * @param visit 访问节点的回调函数
 * @return succeed-成功, failed-失败
 * 
 * 前序遍历顺序：根节点 -> 左子树 -> 右子树
 */
Status BST_preorderR(BinarySortTreePtr BST, void (*visit)(NodePtr)) 
{
    if (!BST || !BST->root || !visit) return failed;
    preorderHelper(BST->root, visit);
    return succeed;
}

/*
 *中序遍历(非递归)
 * @param BST 二叉排序树指针
 * @param visit 访问节点的回调函数
 * @return succeed-成功, failed-失败
 * 
 * 中序遍历顺序：左子树 -> 根节点 -> 右子树
 */
Status BST_inorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)) 
{
    if (!BST || !BST->root || !visit) return failed;

    LinkedStack* stack = createStack();
    NodePtr current = BST->root;

    while (current || !isStackEmpty(stack)) 
    {
        // 向左走到尽头，路径节点全部入栈
        while (current) 
        {
            push(stack, current);
            current = current->left;
        }

        // 弹出栈顶访问（此时左子树已处理）
        current = pop(stack);
        visit(current);

        // 处理右子树
        current = current->right;
    }

    freeStack(stack);
    return succeed;
}

/*
 *中序遍历(递归)的辅助函数
 * @param node 二叉排序树节点的指针
 * @param visit 访问节点的回调函数
 * @return succeed-成功, failed-失败
 */
static void inorderHelper(NodePtr node, void (*visit)(NodePtr)) 
{
    if (!node) return;
    inorderHelper(node->left, visit);
    visit(node);
    inorderHelper(node->right, visit);
}

/*
 *中序遍历(递归)
 * @param BST 二叉排序树指针
 * @param visit 访问节点的回调函数
 * @return succeed-成功, failed-失败
 * 
 * 中序遍历顺序：左子树 -> 根节点 -> 右子树
 */
Status BST_inorderR(BinarySortTreePtr BST, void (*visit)(NodePtr)) 
{
    if (!BST || !BST->root || !visit) return failed;
    inorderHelper(BST->root, visit);
    return succeed;
}

/*
 *后序遍历(非递归)
 * @param BST 二叉排序树指针
 * @param visit 访问节点的回调函数
 * @return succeed-成功, failed-失败
 * 
 * 后序遍历顺序：左子树 -> 右子树 -> 根节点
 */
Status BST_postorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)) 
{
    if (!BST || !BST->root || !visit) return failed;

    LinkedStack* mainStack = createStack(); //处理顺序：根→左→右
    LinkedStack* outputStack = createStack();//存储顺序：根→右→左  最终弹出顺序：左→右→根
    push(mainStack, BST->root);

    while (!isStackEmpty(mainStack))
    {
        NodePtr current = pop(mainStack);
        push(outputStack, current); // 压入输出栈

        // 注意入栈顺序：左子节点先入主栈
        if (current->left) push(mainStack, current->left);
        if (current->right) push(mainStack, current->right);
    }

    // 输出栈的弹出顺序即为后序序列
    while (!isStackEmpty(outputStack)) 
    {
        visit(pop(outputStack));
    }

    freeStack(mainStack);
    freeStack(outputStack);
    return succeed;
}

/*
 *后序遍历(递归)的辅助函数
 * @param node 二叉排序树节点的指针
 * @param visit 访问节点的回调函数
 * @return succeed-成功, failed-失败
 * 
 * 后序遍历顺序：左子树 -> 右子树 -> 根节点
 */
static void postorderHelper(NodePtr node, void (*visit)(NodePtr)) 
{
    if (!node) return;
    postorderHelper(node->left, visit);
    postorderHelper(node->right, visit);
    visit(node);
}

/*
 *后序遍历(递归)
 * @param BST 二叉排序树指针
 * @param visit 访问节点的回调函数
 * @return succeed-成功, failed-失败
 * 
 * 后序遍历顺序：左子树 -> 右子树 -> 根节点
 */
Status BST_postorderR(BinarySortTreePtr BST, void (*visit)(NodePtr))
{
    if (!BST || !BST->root || !visit) return failed;
    postorderHelper(BST->root, visit);
    return succeed;
}

/*
 * 层序遍历
 * @param BST 二叉排序树指针
 * @param visit 访问节点的回调函数
 * @return succeed-成功, failed-失败
 */
Status BST_levelOrder(BinarySortTreePtr BST, void (*visit)(NodePtr)) 
{
    if (!BST || !BST->root || !visit) return failed;

    LinkedQueue* queue = createQueue();
    enqueue(queue, BST->root);

    while (!isQueueEmpty(queue)) 
    {
        int levelSize = queue->size;  // 当前层的节点数

        for (int i = 0; i < levelSize; ++i) 
        {
            NodePtr node = dequeue(queue);
            visit(node);

            if (node->left) enqueue(queue, node->left);
            if (node->right) enqueue(queue, node->right);
        }
    }

    freeQueue(queue);
    return succeed;
}

/*
 *打印二叉树节点值的回调函数
 * @param node  要处理的二叉树节点指针
 */
void printNode(NodePtr node) 
{
    if (node) 
    {
        printf("%d ", node->value);
    }
}

/*
 *递归释放二叉树的销毁函数(辅助函数)
 * @param node  当前子树根节点指针
 */
void freeTreeHelper(NodePtr node) 
{
    if (!node) return;
    freeTreeHelper(node->left);
    freeTreeHelper(node->right);
    free(node);
}

/*
 * 清空二叉排序树
 * @param BST 二叉排序树指针
 */
void freeTree(BinarySortTreePtr BST)
{
    freeTreeHelper(BST->root);
    BST->root = NULL;
}

