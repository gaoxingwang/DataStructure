#include <stdio.h>

#define MAX_TREE_SIZE 100

typedef int TElemType;


/* ˫�ױ�ʾ���ڵ�*/
typedef struct PTNode{   /*�������*/
    TElemType data;      /*�������*/
    int parent;          /*˫��λ��*/
}PTNode;

typedef struct {                  /*���ṹ*/
    PTNode nodes[MAX_TREE_SIZE];  /*�������*/
    int r,n;                      /*����λ�úͽ����*/
}PTree;




