#include <stdio.h>

typedef struct BiTreeNode{
    int data;
    struct BiTreeNode *lchild;
    struct BiTreeNode *rchild;
}BiTNode,*BiTree;


/*��������ǰ�����*/
void PreOrderTraverse(BiTree T)
{
    if(T==NULL)
    {
        return 0;
    }

    printf("%d",T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}



/*���������������*/
void InOrdertraverse(Bitree T)
{
    if(T==null)
    {
        return 0;
    }

    preOrderTraverse(T->lchild);
    printf("%d",T->data);
    PreOrderTraverse(T->rchild);
}


/*�������ĺ������*/
void ordertraverse(bitree T)
{
    if(T==null)
    {
        return 0;
    }

    preOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
    printf("%d",T->data);
}

