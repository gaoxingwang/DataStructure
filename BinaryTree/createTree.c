#include <stdio.h>
#include <stdlib.h>

typedef struct BiTreeNode{
    char data;
    struct BiTreeNode *lchild;
    struct BiTreeNode *rchild;
}BiTreeNode,*BiTree;


/*创建二叉树 按前序输入二叉树中结点的值（一个字符）*/
/*用二叉链表表示二叉树*/
int CreateBiTree(BiTree *T)
{
    char ch;
    scanf("%c",&ch);
    //getchar();

    if(ch == '#')      /* '#' 表示空树*/
    {
        *T = NULL;
    }
    else
    {
        *T = (BiTree)malloc(sizeof(BiTreeNode));
        if(!*T)
        {
            exit(1);
        }
        (*T)->data = ch;               /*生成根节点*/
        CreateBiTree(&(*T)->lchild);   /*构造左子树*/
        CreateBiTree(&(*T)->rchild);   /*构造右子树*/
    }

    return 0;
}

/*前序遍历 根 左 右  */
int PreOrderTraverse(BiTree T)
{
    if(T == NULL)
    {
        return 0;
    }

    printf("%c",T->data);         /*显示结点数据*/
    PreOrderTraverse(T->lchild);  /*再先序遍历左子树*/
    PreOrderTraverse(T->rchild);  /*最后先序遍历右子树*/

    return 0;
}


/*中序遍历 左 根 右*/
int InOrderTraverse(BiTree T)
{
    if(T == NULL)
    {
        return 0;
    }

    PreOrderTraverse(T->lchild);
    printf("%c",T->data);
    PreOrderTraverse(T->rchild);

    return 0;
}


/*后序遍历 左 右 根*/
int PostOrderTraverse(BiTree T)
{
    if(T == NULL)
    {
        return 0;
    }

    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
    printf("%c",T->data);

    return 0;
}

/*销毁二叉树 释放内存*/
void destoryBiTree(BiTree *T)
{
    if(*T)
    {

        destoryBiTree(&(*T)->lchild);
        destoryBiTree(&(*T)->rchild);
        free(*T);
    }
}

/*树的深度*/
int TreeDepth(BiTree T)
{
    int depth = 0;
    int ldepth = 0;
    int rdepth = 0;

    if(T == NULL)
    {
        return 0;
    }

    ldepth = TreeDepth(T->lchild);
    rdepth = TreeDepth(T->rchild);

    depth = ((ldepth >= rdepth) ? ldepth+1 : rdepth+1);

    return depth;
}


/*二叉树的结点数目*/
int TreeNodeNum(BiTree T)
{
    int num = 0;

    if(T == NULL)
    {
        return 0;
    }
    else
    {
        num = TreeNodeNum(T->lchild) + TreeNodeNum(T->rchild) +1;    
    }

    return num;
}


/*叶结点数目*/
int leafNodeCount(BiTree T)
{
    int count = 0;

    if(T == NULL)
    {
        return 0;
    }

    if(T->lchild == NULL && T->rchild == NULL)
    {
        return 1;
    }
    
    count = leafNodeCount(T->lchild) + leafNodeCount(T->rchild);
    return count;
}


/*输出叶节点*/
void displayLeaf(BiTree T)
{
    if(T == NULL)
    {
        return;
    }
    if(T->lchild == NULL && T->rchild == NULL)
    {
        printf("%c\t",T->data);
    }
    else
    {
        displayLeaf(T->lchild);
        displayLeaf(T->rchild);
    }

}

void deleteLeftTree(BiTree *T)
{
    if(*T == NULL)
    {
        return;
    }
    destoryBiTree(&(*T)->lchild);
    (*T)->lchild = NULL;
}

void deleteRightTree(BiTree *T)
{
    if(*T == NULL)
    {
        return;
    }
    destoryBiTree(&(*T)->rchild);
    (*T)->rchild = NULL;
}

BiTree copyTree(BiTree T)
{
    BiTree lchild;
    BiTree rchild;
    BiTree p = NULL;;

    if(T == NULL)
    {
        return NULL;
    }

    lchild = copyTree(T->lchild);
    rchild = copyTree(T->rchild);
    
    p = (BiTree)malloc(sizeof(BiTreeNode));
    p->data = T->data;
    p->lchild = lchild;
    p->rchild = rchild;

    return p;
}


int main()
{
    int num = 0;
    int depth = 0;

    BiTree T = NULL;
    BiTree N = NULL;

    CreateBiTree(&T);

    printf("\n前序遍历\n");
    PreOrderTraverse(T);

    printf("\n中序遍历\n");
    InOrderTraverse(T);

    printf("\n后序遍历\n");
    PostOrderTraverse(T);

    depth = TreeDepth(T);
    printf("\nTree depth is %d\n",depth);

    num = TreeNodeNum(T);
    printf("\nTree Node Num is %d\n",num);

    num = 0;
    num = leafNodeCount(T);
    printf("\nleaf node count is %d\n",num);

    displayLeaf(T);

    N = copyTree(T);

    printf("\ndelete left tree result:\n");
    deleteLeftTree(&T);
    PreOrderTraverse(T);

    printf("\nTree N is :\n"); 
    PreOrderTraverse(N);

    destoryBiTree(&T);
    destoryBiTree(&N);
    return 0;
}
