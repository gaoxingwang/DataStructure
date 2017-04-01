#include <stdio.h>

typedef struct BiTreeNode{
    int data;
    struct BiTreeNode *lchild;
    struct BiTreeNode *rchild;
}BiTNode,*BiTree;


/*二叉树的前序遍历*/
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



/*二叉树的中序遍历*/
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


/*二叉树的后序遍历*/
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

