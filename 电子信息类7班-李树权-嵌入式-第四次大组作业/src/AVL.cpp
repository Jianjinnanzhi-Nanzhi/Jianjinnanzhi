#include "AVL.h"

/**
 * �����½ڵ�
 * @param key �ڵ��ֵ
 * @return �½ڵ�ָ�루��������ΪNULL���߶ȳ�ʼ��Ϊ1��
 */
AVLNode* newNode(int key) 
{
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;  // �½ڵ��ʼ�߶�Ϊ1����Ϊ��ΪҶ�ӽڵ㣩
    return node;
}

/**
 * ��ȡ�ڵ�߶ȣ���ȫ����NULLָ�룩
 * @param node �ڵ�ָ��
 * @return �ڵ�߶ȣ�NULL�ڵ㷵��0��
 */
int height(AVLNode* node) 
{
    // NULL�ڵ�߶ȶ���Ϊ0�������߶�Ϊ0��
    return node == NULL ? 0 : node->height;
}

//���������������ֵ
int max(int a, int b) 
{
    return (a > b) ? a : b;
}

/**
 * ����ڵ��ƽ������
 * ƽ������ = �������߶� - �������߶�
 * ֵ��Χ��-1����������1�㣩��0��ƽ�⣩��1����������1�㣩
 * ����ֵ����1ʱ��Ҫ����
 */
int getBalance(AVLNode* node) 
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

/**
 * ��������������LL�Ͳ�ƽ�⣩
 * @param y ʧ��ڵ�ָ��
 * @return ��ת����¸��ڵ�ָ��
 */
AVLNode* rightRotate(AVLNode* y) 
{
    //�����ӽڵ�ָ��
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    //ִ����ת���޸�ָ���ϵ��
    x->right = y;
    y->left = T2;

    //���¸߶ȣ������ȸ���y����Ϊy������x���ӽڵ㣩
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x; // �����µĸ��ڵ�
}

/**
 * ��������������RR�Ͳ�ƽ�⣩
 * @param x ʧ��ڵ�ָ��
 * @return ��ת����¸��ڵ�ָ��
 */
AVLNode* leftRotate(AVLNode* x) 
{
    // �����ӽڵ�ָ��
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // ִ����ת
    y->left = x;
    x->right = T2;

    // ���¸߶�
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}


/**
 * ��AVL�������½ڵ�
 * @param node ��ǰ�������ڵ�
 * @param key Ҫ����ļ�ֵ
 * @return ���벢ƽ�����¸��ڵ�
 */
AVLNode* insert(AVLNode* node, int key) 
{
   // ִ�б�׼BST���루�ݹ飩
    if (node == NULL)
        return newNode(key); // �����λ�ã������½ڵ�

    // �ݹ����������
    if (key < node->key)
        node->left = insert(node->left, key);
    // �ݹ����������
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // �������ظ�����ʵ��Ӧ���пɸ��������޸ģ�
        return node;

    //���µ�ǰ�ڵ�߶�
    node->height = 1 + max(height(node->left), height(node->right));

    //���ƽ�Ⲣ�������ֲ�ƽ�����
    int balance = getBalance(node);

    //����LL��-> ����
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    //���ң�RR��-> ����
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    //���ң�LR��-> ����������������������ǰ�ڵ�
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // ����RL��-> ����������������������ǰ�ڵ�
    if (balance < -1 && key < node->right->key) 
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    //����δ�����Ľڵ�ָ�루�Ѿ�ƽ��������
    return node;
}

/**
 * ���������е���С�ڵ㣨����ɾ���ã�
 * @param node �������ڵ�
 * @return ��С��ֵ�ڵ�ָ��
 */
AVLNode* minValueNode(AVLNode* node) 
{
    AVLNode* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

/**
 * ��AVL��ɾ���ڵ�
 * @param root ��ǰ�������ڵ�
 * @param key Ҫɾ���ļ�ֵ
 * @return ɾ����ƽ�����¸��ڵ�

 */
AVLNode* deleteNode(AVLNode* root, int key) 
{
    //ִ�б�׼BSTɾ�� 
    if (root == NULL)
        return root;

    // �ݹ����Ҫɾ���Ľڵ�
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else 
    {
        // �ҵ�Ҫɾ���Ľڵ㣬�������������
        // /�ڵ���0��1���ӽڵ�
        if ((root->left == NULL) || (root->right == NULL)) 
        {
            AVLNode* temp = root->left ? root->left : root->right;

            // ���ӽڵ�
            if (temp == NULL) 
            {
                temp = root;
                root = NULL;
            }
            // ��һ���ӽڵ�
            else
                *root = *temp; // ���ӽڵ����ݸ��ǵ�ǰ�ڵ�

            free(temp);
        }
        // �ڵ��������ӽڵ�
        else 
        {
            // �ҵ�����������С�ڵ㣨�����̣�
            AVLNode* temp = minValueNode(root->right);

            // �ú�̽ڵ��ֵ�滻��ǰ�ڵ�ֵ
            root->key = temp->key;

            // ɾ����̽ڵ㣨��ʱҪɾ����ֵ�ں��λ�ã��Ҹýڵ������һ�����ӽڵ㣩
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // �����Ϊ�գ�ɾ����û�нڵ㣩
    if (root == NULL)
        return root;

    //���µ�ǰ�ڵ�߶�
    root->height = 1 + max(height(root->left), height(root->right));

    //���ƽ�Ⲣ�������ֲ�ƽ�����
    int balance = getBalance(root);

    // ���������LL��
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // ���������LR��
    if (balance > 1 && getBalance(root->left) < 0) 
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // ���������RR��
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // ���������RL��
    if (balance < -1 && getBalance(root->right) > 0) 
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
