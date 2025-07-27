/*
	功能：计算二叉树的宽度 
	输入：该二叉树的前序遍历 
	输出：该二叉树的宽度 

	编译环境：Dev-C++ v5.11
	开发注释：王文博 
	修订日期：2022年11月5日

	参考文献：殷人昆《数据结构(用面向对象方法与C++语言描述)(第3版)》,
	版次：2021年9月第3版
	印次：2022年6月第2次印刷
	页码：PP182-200
*/
// ------------------------------ Testing Main ------------------------
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
using namespace std;
template<class T>
struct BinTreeNode{           //二叉树结点类定义 
	T data;                   //数据域 
	BinTreeNode<T> *leftChild,*rightChild;     //左子女，右子女链域 
	BinTreeNode():leftChild(NULL),rightChild(NULL) {}
	BinTreeNode(T x, BinTreeNode<T> *l =NULL, BinTreeNode<T> *r=NULL):data(x),leftChild(l),rightChild(r) {}
};
template<class T>
class BinaryTree{             //二叉树类定义 
	public:
	int depth[1010]={0};          //二叉树的宽度数组
	int maxdepth=0;           //二叉树的最大宽度 
	BinTreeNode<T> *root;                                 //二叉树的根指针 	
	BinaryTree():root(NULL) {}       //构造函数
	BinaryTree(T value): RefValue(value),root(NULL){}     //构造函数 
	BinaryTree(BinaryTree<T> &s);    //复制构造函数
    ~BinaryTree(){destroy(root);}    //析构函数
	bool IsEmpty(){return root == NULL;}   //判断二叉树是否为空
	BinTreeNode<T> *Parent(BinTreeNode<T> *current)     //返回父节点 
	{
		if(root==NULL||root==current) return NULL;
		else
		return Parent(root,current);
	} 
	int Height(){return Height(root);}                  //返回树的高度 
	int Size(){return Size(root);}                      //返回树的结点数 
	BinTreeNode<T> *getRoot(){return root;}             //取根 
	void setRoot(BinTreeNode<T> *p){root = p;}          //修改根 
	BinTreeNode<T> *Search(T item)                      //搜索 
	{
		return Search(root,item);
	}
	int Insert(T item){return Insert(root,item);}       //插入新元素 
	void createBinTree(T in[]){createBinTree(in,root);} //从输入流读入建树 
	void printBinTree(){printBinTree(root);}   //用广义表输出二叉树 
	void Traverse(){Traverse(root,1);}    //用凹入表输出二叉树 
	void createBinTree_pre(T pre[])       //用扩展前序序列建树 
	{
		int n=0;
		createBinTree_pre(pre,root,n);
	}
	void PreOrder(){PreOrder(root);}      //前序遍历 
	void InOrder(){InOrder(root);}        //中序遍历 
	void PostOrder(){PostOrder(root);}    //后序遍历 
	void LevelOrder();              //层次序遍历 
	void PreOrder_iter();           //非递归前序遍历 
	void InOrder_iter();            //非递归中序遍历 
	void PostOrder_iter();          //非递归后序遍历 
    T RefValue;                                           //数据停止输入标志 
    void destroy(BinTreeNode<T> *&subTree);               //销毁子树 
    void createBinTree(T in[], BinTreeNode<T> *&subTree);                     //从广义表串构建二叉树 
    void createBinTree_pre(T pre[], BinTreeNode<T> *&subTree,int &n);         //从扩展前序序列构建二叉树 
    BinTreeNode<T> *Parent(BinTreeNode<T> *subTree, BinTreeNode<T> *p);       //找父节点 
    BinTreeNode<T> *Search(BinTreeNode<T> *p, T item);    //搜索 
    int Insert(BinTreeNode<T> *&subTree, T item);         //插入 
    BinTreeNode<T> *Copy(BinTreeNode<T> *orignode);       //复制 
    int Height(BinTreeNode<T> *subTree);                  //求子树的高度 
    int Size(BinTreeNode<T> *subTree);                    //求子树的节点数 
    void printBinTree(BinTreeNode<T> *subTree);           //用广义表输出二叉树 
    void Traverse(BinTreeNode<T> *subTree,int k);         //用凹入表输出二叉树 
    void PreOrder(BinTreeNode<T> *p);                     //前序遍历 
    void InOrder(BinTreeNode<T> *p);                      //中序遍历 
    void PostOrder(BinTreeNode<T> *p);                    //后序遍历 
    bool equal(BinTreeNode<T> *a,BinTreeNode<T> *b);      //判等 
};
template<class T>
void BinaryTree<T>::destroy(BinTreeNode<T> *&subTree)
{
	//保护函数：若指针subTree不为空，则删除根为subTree的子树 
	if(subTree!=NULL)
	{
		destroy(subTree->leftChild);    //递归删除subTree的左子树 
		destroy(subTree->rightChild);   //递归删除subTree的右子树 
		delete subTree;                 //删除subTree 
		subTree = NULL;
	}
};
template<class T>
BinTreeNode<T> *BinaryTree<T>::Parent(BinTreeNode<T> *subTree,BinTreeNode<T> *current)
{
	//在子树subTree中搜索结点current的父节点。若找到，则函数返回父节点地址，否则函数返回NULL。
	if(subTree==NULL) return NULL;
	if(subTree==current) return NULL; //根节点无父节点
	if(subTree->leftChild==current||subTree->rightChild==current)
	return subTree;                  //找到，返回父节点subTree 
	BinTreeNode<T> *p;
	if((p=Parent(subTree->leftChild,current))!=NULL) return p;   //递归在左子树中搜索 
	else return Parent(subTree->rightChild,current);             //递归在右子树中搜索 
};
template<class T>
void BinaryTree<T>::Traverse(BinTreeNode<T> *subTree,int k)
{
	//按凹入表格式输出根为subTree的二叉树，k是层次（根在k=1层）
	if(subTree!=NULL)
	{
		depth[k]++;
		maxdepth=max(maxdepth,depth[k]);
		Traverse(subTree->leftChild,k+1);   //递归搜索并输出subTree的左子树 
		Traverse(subTree->rightChild,k+1);  //递归搜索并输出subTree的右子树 
	}
};
template<class T>
void BinaryTree<T>::InOrder(BinTreeNode<T> *subTree)
{
	//递归函数：此算法按照中序遍历以subTree为根的子树
	if(subTree!=NULL)    //递归结束条件 
	{
		InOrder(subTree->leftChild);   //中序遍历根的左子树 
		cout<<subTree->data<<" ";           //访问根节点 
		InOrder(subTree->rightChild);  //中序遍历根的右子树 
	} 
};
template<class T>
void BinaryTree<T>::PreOrder(BinTreeNode<T> *subTree)
{
	//递归函数：此算法按照前序遍历以subTree为根的子树
	if(subTree!=NULL)    //递归结束条件 
	{
		cout<<subTree->data<<" ";           //访问根节点 
		PreOrder(subTree->leftChild);   //前序遍历根的左子树 
		PreOrder(subTree->rightChild);  //前序遍历根的右子树 
	} 
};
template<class T>
void BinaryTree<T>::PostOrder(BinTreeNode<T> *subTree)
{
	//递归函数：此算法按照后序遍历以subTree为根的子树
	if(subTree!=NULL)    //递归结束条件 
	{
		PostOrder(subTree->leftChild);   //后序遍历根的左子树 
		PostOrder(subTree->rightChild);  //后序遍历根的右子树 
		cout<<subTree->data<<" ";           //访问根节点 
	} 
};
template<class T>
int BinaryTree<T>::Size(BinTreeNode<T> *subTree)
{
	//保护函数：计算以*subTree为根的二叉树的结点个数
	if(subTree==NULL) return 0;   //递归结束：空树结点个数为0
	else return 1+Size(subTree->leftChild)+Size(subTree->rightChild);
};
template<class T>
int BinaryTree<T>::Height(BinTreeNode<T> *subTree)
{
	//保护函数：计算以*subTree为根的二叉树高度
	if(subTree==NULL) return 0;          //递归结束：空树高度为0 
	else
	{
		int i=Height(subTree->leftChild);
		int j=Height(subTree->rightChild);
		return (i<j)?j+1:i+1;
	} 
};
template<class T>
BinaryTree<T>::BinaryTree(BinaryTree<T> &s)
{
	//共有函数：复制构造函数 
	root=Copy(s.root);
};
template<class T>
BinTreeNode<T> *BinaryTree<T>::Copy(BinTreeNode<T> *orignode)
{
	//保护函数：这个函数返回一个指针，它给出一个以orignode为根的二叉树的副本
	if(orignode==NULL) return NULL;             //根为空，返回空指针 
	BinTreeNode<T> *temp=new BinTreeNode<T>;    //创建根节点 
	temp->data=orignode->data;                  //传送数据 
	temp->leftChild=Copy(orignode->leftChild);  //复制左子树 
	temp->rightChild=Copy(orignode->rightChild);  //复制右子树 
	return temp;          //返回根指针 
};
template<class T>
void BinaryTree<T>::createBinTree_pre(T pre[], BinTreeNode<T> *&subTree, int &n)
{
	//保护函数：以递归方式建立二叉树。pre是输入串，限定T为字符型，序列以‘；’结束
	T ch =pre[n++];
	if(ch=='\0') return;        //处理结束，返回 
	if(ch!='#')                //建立非空子树 
	{
		subTree=new BinTreeNode<T>(ch);   //建立根结点 
		createBinTree_pre(pre,subTree->leftChild,n);     //递归建立左子树 
		createBinTree_pre(pre,subTree->rightChild,n);   //递归建立右子树 
	}
	else subTree = NULL;         //否则建立空子树 
};
int main ()
{
	char u[100010];
	BinaryTree<char> tree;   //建树 
	scanf("%s",u);
	int n=0;
	tree.createBinTree_pre(u,tree.root,n);   //前序建树 
	tree.Traverse(tree.root,0);   //遍历记录宽度 
	cout<<tree.maxdepth;
	return 0;
}
