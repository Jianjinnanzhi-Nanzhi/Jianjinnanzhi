#include "binary_sort_tree.h"
#include "Stack_and_Queue.h"

/*
 *��ʼ������������
 * @param BST ����������ָ��
 * @return succeed-�ɹ�, failed-ʧ��
 */
Status BST_init(BinarySortTreePtr BST) 
{
    if (!BST) return failed;
    BST->root = NULL;
    return succeed;
}

/*
 *�����������Ĳ���
 * @param BST ����������ָ��
 * @param value Ҫ����ڵ��ֵ
 * @return succeed-�ɹ�, failed-ʧ��
 */
Status BST_insert(BinarySortTreePtr BST, ElemType value) 
{
    if (!BST) return failed;//�ж����Ƿ����

    //�����½ڵ�
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    if (!newNode) return failed;

    //�жϸ������ڵ��Ƿ�Ϊ��
    if (!BST->root) 
    {
        BST->root = newNode;
        return succeed;
    }

    //parentΪcurrent�ĸ��ڵ�
    NodePtr current = BST->root;
    NodePtr parent = NULL;

    //��ʼ����Ѱ�Һ���λ��
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
            return failed; // ֵ�Ѵ���(Ĭ������£������������Ķ���Ҫ��ÿ���ڵ�ļ�ֵΨһ)
        }
    }

    //��ʱparentΪҪ����ڵ�ĸ��ڵ�
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
 *������������ɾ��
 * @param BST ����������ָ��
 * @param value Ҫɾ���ڵ��ֵ
 * @return succeed-�ɹ�, failed-ʧ��
 */
Status BST_delete(BinarySortTreePtr BST, ElemType value) 
{
    if (!BST || !BST->root) return failed;

    //parentΪcurrent�ĸ��ڵ�
    NodePtr current = BST->root;
    NodePtr parent = NULL;

    // ����Ҫɾ���Ľڵ㼰�丸�ڵ�
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

    // δ�ҵ�Ҫɾ���Ľڵ�
    if (current == NULL) return failed;

    // �����ӽڵ��������ɾ��
    
    // ���1: Ҷ�ӽڵ�
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

    // ���2: ֻ��һ�����ӽڵ�
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
    // ���3: ֻ��һ�����ӽڵ�
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

    // ���4: �������ӽڵ�
    else 
    {
        // �ҵ�����������С�ڵ㼰�丸�ڵ�
        NodePtr S= current->right;
        NodePtr SParent = current;

        while (S->left != NULL) 
        {
            SParent = S;
            S = S->left;
        }

        // �����̽ڵ��ֵ
        ElemType SValue =S->value;

        // �ݹ�ɾ����̽ڵ㣨��ʱ��̽ڵ����ֻ��һ�����ӽڵ㣩
        BST_delete(BST, SValue);

        // �ú�̽ڵ��ֵ�滻��ǰ�ڵ�ֵ
        current->value = SValue;
    }

    return succeed;
}

/*
 *�����������Ĳ���
 * @param BST ����������ָ��
 * @param value Ҫ���ҽڵ��ֵ
 * @return true-����, false-������
 */
Status BST_search(BinarySortTreePtr BST, ElemType value) 
{
    // ������Ƿ�Ϊ��
    if (BST == NULL || BST->root == NULL) 
    {
        return false; // ����ֱ�ӷ��ز�����
    }

    //�Ӹ��ڵ㿪ʼ����
    NodePtr current = BST->root;

    while (current != NULL) 
    {
        // �Ƚϵ�ǰ�ڵ�ֵ
        if (value == current->value) 
        {
            return true; // �ҵ�ƥ��ֵ
        }
        // ����BST���ʾ������ҷ���
        else if (value < current->value)
        {
            current = current->left; // ������������
        }
        else 
        {
            current = current->right; // ������������
        }
    }
    // ��������δ�ҵ�
    return false;
}

/*
 *�������(�ǵݹ�)
 * @param BST ����������ָ��
 * @param visit ���ʽڵ�Ļص�����
 * @return  succeed-�ɹ�, failed-ʧ��
 * 
 * ǰ�����˳�򣺸��ڵ� -> ������ -> ������
 */
Status BST_preorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)) 
{
    if (!BST || !BST->root || !visit) return failed;

    LinkedStack* stack = createStack();
    push(stack, BST->root);

    while (!isStackEmpty(stack)) 
    {
        NodePtr current = pop(stack);
        visit(current); // �ȷ��ʸ��ڵ�

        // ע����ջ˳�����ӽڵ�����ջ
        if (current->right) push(stack, current->right);
        if (current->left) push(stack, current->left);
    }

    freeStack(stack);
    return succeed;
}

/*
 *�������(�ݹ�)�ĸ�������
 * @param node �����������Ľڵ�ָ��
 * @param visit ���ʽڵ�Ļص�����
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
 *�������(�ݹ�)
 * @param BST ����������ָ��
 * @param visit ���ʽڵ�Ļص�����
 * @return succeed-�ɹ�, failed-ʧ��
 * 
 * ǰ�����˳�򣺸��ڵ� -> ������ -> ������
 */
Status BST_preorderR(BinarySortTreePtr BST, void (*visit)(NodePtr)) 
{
    if (!BST || !BST->root || !visit) return failed;
    preorderHelper(BST->root, visit);
    return succeed;
}

/*
 *�������(�ǵݹ�)
 * @param BST ����������ָ��
 * @param visit ���ʽڵ�Ļص�����
 * @return succeed-�ɹ�, failed-ʧ��
 * 
 * �������˳�������� -> ���ڵ� -> ������
 */
Status BST_inorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)) 
{
    if (!BST || !BST->root || !visit) return failed;

    LinkedStack* stack = createStack();
    NodePtr current = BST->root;

    while (current || !isStackEmpty(stack)) 
    {
        // �����ߵ���ͷ��·���ڵ�ȫ����ջ
        while (current) 
        {
            push(stack, current);
            current = current->left;
        }

        // ����ջ�����ʣ���ʱ�������Ѵ���
        current = pop(stack);
        visit(current);

        // ����������
        current = current->right;
    }

    freeStack(stack);
    return succeed;
}

/*
 *�������(�ݹ�)�ĸ�������
 * @param node �����������ڵ��ָ��
 * @param visit ���ʽڵ�Ļص�����
 * @return succeed-�ɹ�, failed-ʧ��
 */
static void inorderHelper(NodePtr node, void (*visit)(NodePtr)) 
{
    if (!node) return;
    inorderHelper(node->left, visit);
    visit(node);
    inorderHelper(node->right, visit);
}

/*
 *�������(�ݹ�)
 * @param BST ����������ָ��
 * @param visit ���ʽڵ�Ļص�����
 * @return succeed-�ɹ�, failed-ʧ��
 * 
 * �������˳�������� -> ���ڵ� -> ������
 */
Status BST_inorderR(BinarySortTreePtr BST, void (*visit)(NodePtr)) 
{
    if (!BST || !BST->root || !visit) return failed;
    inorderHelper(BST->root, visit);
    return succeed;
}

/*
 *�������(�ǵݹ�)
 * @param BST ����������ָ��
 * @param visit ���ʽڵ�Ļص�����
 * @return succeed-�ɹ�, failed-ʧ��
 * 
 * �������˳�������� -> ������ -> ���ڵ�
 */
Status BST_postorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)) 
{
    if (!BST || !BST->root || !visit) return failed;

    LinkedStack* mainStack = createStack(); //����˳�򣺸��������
    LinkedStack* outputStack = createStack();//�洢˳�򣺸����ҡ���  ���յ���˳������ҡ���
    push(mainStack, BST->root);

    while (!isStackEmpty(mainStack))
    {
        NodePtr current = pop(mainStack);
        push(outputStack, current); // ѹ�����ջ

        // ע����ջ˳�����ӽڵ�������ջ
        if (current->left) push(mainStack, current->left);
        if (current->right) push(mainStack, current->right);
    }

    // ���ջ�ĵ���˳��Ϊ��������
    while (!isStackEmpty(outputStack)) 
    {
        visit(pop(outputStack));
    }

    freeStack(mainStack);
    freeStack(outputStack);
    return succeed;
}

/*
 *�������(�ݹ�)�ĸ�������
 * @param node �����������ڵ��ָ��
 * @param visit ���ʽڵ�Ļص�����
 * @return succeed-�ɹ�, failed-ʧ��
 * 
 * �������˳�������� -> ������ -> ���ڵ�
 */
static void postorderHelper(NodePtr node, void (*visit)(NodePtr)) 
{
    if (!node) return;
    postorderHelper(node->left, visit);
    postorderHelper(node->right, visit);
    visit(node);
}

/*
 *�������(�ݹ�)
 * @param BST ����������ָ��
 * @param visit ���ʽڵ�Ļص�����
 * @return succeed-�ɹ�, failed-ʧ��
 * 
 * �������˳�������� -> ������ -> ���ڵ�
 */
Status BST_postorderR(BinarySortTreePtr BST, void (*visit)(NodePtr))
{
    if (!BST || !BST->root || !visit) return failed;
    postorderHelper(BST->root, visit);
    return succeed;
}

/*
 * �������
 * @param BST ����������ָ��
 * @param visit ���ʽڵ�Ļص�����
 * @return succeed-�ɹ�, failed-ʧ��
 */
Status BST_levelOrder(BinarySortTreePtr BST, void (*visit)(NodePtr)) 
{
    if (!BST || !BST->root || !visit) return failed;

    LinkedQueue* queue = createQueue();
    enqueue(queue, BST->root);

    while (!isQueueEmpty(queue)) 
    {
        int levelSize = queue->size;  // ��ǰ��Ľڵ���

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
 *��ӡ�������ڵ�ֵ�Ļص�����
 * @param node  Ҫ����Ķ������ڵ�ָ��
 */
void printNode(NodePtr node) 
{
    if (node) 
    {
        printf("%d ", node->value);
    }
}

/*
 *�ݹ��ͷŶ����������ٺ���(��������)
 * @param node  ��ǰ�������ڵ�ָ��
 */
void freeTreeHelper(NodePtr node) 
{
    if (!node) return;
    freeTreeHelper(node->left);
    freeTreeHelper(node->right);
    free(node);
}

/*
 * ��ն���������
 * @param BST ����������ָ��
 */
void freeTree(BinarySortTreePtr BST)
{
    freeTreeHelper(BST->root);
    BST->root = NULL;
}

