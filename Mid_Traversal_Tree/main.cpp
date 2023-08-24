#include <stdio.h>
#include <stdlib.h>

struct tNode
{
    int data;
    struct tNode *left;
    struct tNode *right;
};

void MorrisTraversal(struct tNode *root)
{
    struct tNode *current, *pre;

    if (root == NULL)
        return;

    current = root;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            printf(" %d ", current->data);
            current = current->right;
        }
        else
        {
            /* 找到current的前驱节点 */
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;

            /* 将current节点作为其前驱节点的右孩子 */
            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }

            /* 恢复树的原有结构，更改right 指针 */
            else
            {
                pre->right = NULL;
                printf(" %d ", current->data);
                current = current->right;
            } /* End of if condition pre->right == NULL */
        }     /* End of if condition current->left == NULL*/
    }         /* End of while */
}

struct tNode *newtNode(int data)
{
    struct tNode *tNode = (struct tNode *)
        malloc(sizeof(struct tNode));
    tNode->data = data;
    tNode->left = NULL;
    tNode->right = NULL;

    return (tNode);
}

int Tree_height(struct tNode *root)
{
    struct tNode *L, *R, *pre, *flag = NULL, *near = NULL;
    int L_height = 1, R_height = 1, L_pre_height = 0, R_pre_height = 0;
    L = root->left;
    R = root->right;
    while (L != NULL)
    {
        if (L->left == NULL && L->right == NULL && flag != pre)
        {
            flag = pre;
            L = pre;
            L_height = L_pre_height;
        }
        if (L->left != NULL && L->right != NULL && L->left != near)
        {
            pre = L;
            L = L->left;
            near = L;
            L_height++;
            L_pre_height = L_height;
        }
        else if (L->right != NULL)
        {
            L = L->right;
            L_height++;
            near = pre;
        }
        if (L->left == NULL && L->right == NULL && pre == near)
        {
            L = L->left;
        }
    }

    flag = NULL;
    near = NULL;
    struct tNode *pre2;
    while (R != NULL)
    {
        if (R->left == NULL && R->right == NULL && flag != pre2)
        {
            flag = pre2;
            R = pre2;
            R_height = R_pre_height;
        }
        if (R->left != NULL && R->right != NULL && R->left != near)
        {
            pre2 = R;
            R = R->left;
            near = R;
            R_height++;
            R_pre_height = R_height;
        }
        else if (R->right != NULL)
        {
            R = R->right;
            R_height++;
            near = pre2;
        }
        if (R->left == NULL && R->right == NULL && pre2 == near)
        {
            R = R->left;
        }
    }

    return L_height > R_height ? L_height : R_height;
}

// 返回值类型为指针的函数
struct tNode *generateTree(int a[], int b[], int l1, int l2, int h1, int h2)
{
    struct tNode *root = newtNode(a[l1]);
    int pre = l2;
    while (b[pre] != root->data)
    {
        pre++;
    }
    int L_len = pre - l2;
    int R_len = h2 - pre;
    if (L_len)
    {
        root->left = generateTree(a, b, l1 + 1, l2, l1 + L_len, l2 + L_len - 1);
    }
    else
        root->left = NULL;
    if (R_len)
    {
        root->right = generateTree(a, b, h1 - R_len + 1, h2 - R_len + 1, h1, h2);
    }
    else
        root->right = NULL;

    return root;
}

/* 测试*/
int main()
{

    /* 构建树结构如下：
              1
            /   \
          2      3
        /  \
      4     5
    */
    struct tNode *root = newtNode(1);
    root->left = newtNode(2);
    root->right = newtNode(3);
    root->right->right = newtNode(6);
    root->right->right->right = newtNode(7);
    root->left->left = newtNode(4);
    root->left->right = newtNode(5);

    int NLR[] = {0, 1, 2, 4, 5, 3};
    int LNR[] = {0, 4, 2, 5, 1, 3};
    generateTree(NLR, LNR, 1, 1, 5, 5);
    // MorrisTraversal(root);
    // int h = Tree_height(root);
    // printf("这棵树高度为：%d ", h);
    return 0;
}