#include <bits\stdc++.h>
#define OVERFLOW -1
using namespace std;
typedef char TElemType;
typedef struct BiTNode
{ // 结点结构
  TElemType data;
  struct BiTNode *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;

int ans = 0;
void Leaf1(BiTree &T) // 后序遍历统计叶子节点数目
{

  if (T != NULL)
  {
    Leaf1(T->lchild);
    Leaf1(T->rchild);
    if (T->lchild == NULL && T->rchild == NULL)
      ans++;
  }
}

int (*Visit)(TElemType);

// 按先序序列建立二叉树
int CreateBiTree(BiTree &T)
{
  TElemType ch;
  scanf("%c", &ch);
  if (ch == '.')
  {
    T = NULL;
  }
  else
  {
    if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
    {
      exit(OVERFLOW);
    }
    T->data = ch;            // 生成根结点
    CreateBiTree(T->lchild); // 构造左子树
    CreateBiTree(T->rchild); // 构造右子树
  }
  return 1;
} // CreateBiTree

// 后序遍历二叉树(递归)
void PostOrderTraverse(BiTree &T, int (*Visit)(TElemType e))
{
  if (T)
  {
    PostOrderTraverse(T->lchild, Visit); // 后序遍历左子树
    PostOrderTraverse(T->rchild, Visit); // 后序遍历右子树
    Visit(T->data);                      // 访问根结点
  }
} // PostOrderTraverse

int main(int argc, char *argv[])
{
  system("color f0");
  BiTree T; // declaration

  printf("\nInput a tree : \n");
  // 用例:ABD..EH...CF.I..G..\n
  CreateBiTree(T); // 创建
  Leaf1(T);

  printf("叶子节点的数目是：%d\n", ans);
  system("pause");
  return 0;
}
