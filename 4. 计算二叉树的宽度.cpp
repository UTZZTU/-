/*
	���ܣ�����������Ŀ�� 
	���룺�ö�������ǰ����� 
	������ö������Ŀ�� 

	���뻷����Dev-C++ v5.11
	����ע�ͣ����Ĳ� 
	�޶����ڣ�2022��11��5��

	�ο����ף������������ݽṹ(��������󷽷���C++��������)(��3��)��,
	��Σ�2021��9�µ�3��
	ӡ�Σ�2022��6�µ�2��ӡˢ
	ҳ�룺PP182-200
*/
// ------------------------------ Testing Main ------------------------
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
using namespace std;
template<class T>
struct BinTreeNode{           //����������ඨ�� 
	T data;                   //������ 
	BinTreeNode<T> *leftChild,*rightChild;     //����Ů������Ů���� 
	BinTreeNode():leftChild(NULL),rightChild(NULL) {}
	BinTreeNode(T x, BinTreeNode<T> *l =NULL, BinTreeNode<T> *r=NULL):data(x),leftChild(l),rightChild(r) {}
};
template<class T>
class BinaryTree{             //�������ඨ�� 
	public:
	int depth[1010]={0};          //�������Ŀ������
	int maxdepth=0;           //������������� 
	BinTreeNode<T> *root;                                 //�������ĸ�ָ�� 	
	BinaryTree():root(NULL) {}       //���캯��
	BinaryTree(T value): RefValue(value),root(NULL){}     //���캯�� 
	BinaryTree(BinaryTree<T> &s);    //���ƹ��캯��
    ~BinaryTree(){destroy(root);}    //��������
	bool IsEmpty(){return root == NULL;}   //�ж϶������Ƿ�Ϊ��
	BinTreeNode<T> *Parent(BinTreeNode<T> *current)     //���ظ��ڵ� 
	{
		if(root==NULL||root==current) return NULL;
		else
		return Parent(root,current);
	} 
	int Height(){return Height(root);}                  //�������ĸ߶� 
	int Size(){return Size(root);}                      //�������Ľ���� 
	BinTreeNode<T> *getRoot(){return root;}             //ȡ�� 
	void setRoot(BinTreeNode<T> *p){root = p;}          //�޸ĸ� 
	BinTreeNode<T> *Search(T item)                      //���� 
	{
		return Search(root,item);
	}
	int Insert(T item){return Insert(root,item);}       //������Ԫ�� 
	void createBinTree(T in[]){createBinTree(in,root);} //�����������뽨�� 
	void printBinTree(){printBinTree(root);}   //�ù������������� 
	void Traverse(){Traverse(root,1);}    //�ð������������� 
	void createBinTree_pre(T pre[])       //����չǰ�����н��� 
	{
		int n=0;
		createBinTree_pre(pre,root,n);
	}
	void PreOrder(){PreOrder(root);}      //ǰ����� 
	void InOrder(){InOrder(root);}        //������� 
	void PostOrder(){PostOrder(root);}    //������� 
	void LevelOrder();              //�������� 
	void PreOrder_iter();           //�ǵݹ�ǰ����� 
	void InOrder_iter();            //�ǵݹ�������� 
	void PostOrder_iter();          //�ǵݹ������� 
    T RefValue;                                           //����ֹͣ�����־ 
    void destroy(BinTreeNode<T> *&subTree);               //�������� 
    void createBinTree(T in[], BinTreeNode<T> *&subTree);                     //�ӹ�������������� 
    void createBinTree_pre(T pre[], BinTreeNode<T> *&subTree,int &n);         //����չǰ�����й��������� 
    BinTreeNode<T> *Parent(BinTreeNode<T> *subTree, BinTreeNode<T> *p);       //�Ҹ��ڵ� 
    BinTreeNode<T> *Search(BinTreeNode<T> *p, T item);    //���� 
    int Insert(BinTreeNode<T> *&subTree, T item);         //���� 
    BinTreeNode<T> *Copy(BinTreeNode<T> *orignode);       //���� 
    int Height(BinTreeNode<T> *subTree);                  //�������ĸ߶� 
    int Size(BinTreeNode<T> *subTree);                    //�������Ľڵ��� 
    void printBinTree(BinTreeNode<T> *subTree);           //�ù������������� 
    void Traverse(BinTreeNode<T> *subTree,int k);         //�ð������������� 
    void PreOrder(BinTreeNode<T> *p);                     //ǰ����� 
    void InOrder(BinTreeNode<T> *p);                      //������� 
    void PostOrder(BinTreeNode<T> *p);                    //������� 
    bool equal(BinTreeNode<T> *a,BinTreeNode<T> *b);      //�е� 
};
template<class T>
void BinaryTree<T>::destroy(BinTreeNode<T> *&subTree)
{
	//������������ָ��subTree��Ϊ�գ���ɾ����ΪsubTree������ 
	if(subTree!=NULL)
	{
		destroy(subTree->leftChild);    //�ݹ�ɾ��subTree�������� 
		destroy(subTree->rightChild);   //�ݹ�ɾ��subTree�������� 
		delete subTree;                 //ɾ��subTree 
		subTree = NULL;
	}
};
template<class T>
BinTreeNode<T> *BinaryTree<T>::Parent(BinTreeNode<T> *subTree,BinTreeNode<T> *current)
{
	//������subTree���������current�ĸ��ڵ㡣���ҵ����������ظ��ڵ��ַ������������NULL��
	if(subTree==NULL) return NULL;
	if(subTree==current) return NULL; //���ڵ��޸��ڵ�
	if(subTree->leftChild==current||subTree->rightChild==current)
	return subTree;                  //�ҵ������ظ��ڵ�subTree 
	BinTreeNode<T> *p;
	if((p=Parent(subTree->leftChild,current))!=NULL) return p;   //�ݹ��������������� 
	else return Parent(subTree->rightChild,current);             //�ݹ��������������� 
};
template<class T>
void BinaryTree<T>::Traverse(BinTreeNode<T> *subTree,int k)
{
	//��������ʽ�����ΪsubTree�Ķ�������k�ǲ�Σ�����k=1�㣩
	if(subTree!=NULL)
	{
		depth[k]++;
		maxdepth=max(maxdepth,depth[k]);
		Traverse(subTree->leftChild,k+1);   //�ݹ����������subTree�������� 
		Traverse(subTree->rightChild,k+1);  //�ݹ����������subTree�������� 
	}
};
template<class T>
void BinaryTree<T>::InOrder(BinTreeNode<T> *subTree)
{
	//�ݹ麯�������㷨�������������subTreeΪ��������
	if(subTree!=NULL)    //�ݹ�������� 
	{
		InOrder(subTree->leftChild);   //����������������� 
		cout<<subTree->data<<" ";           //���ʸ��ڵ� 
		InOrder(subTree->rightChild);  //����������������� 
	} 
};
template<class T>
void BinaryTree<T>::PreOrder(BinTreeNode<T> *subTree)
{
	//�ݹ麯�������㷨����ǰ�������subTreeΪ��������
	if(subTree!=NULL)    //�ݹ�������� 
	{
		cout<<subTree->data<<" ";           //���ʸ��ڵ� 
		PreOrder(subTree->leftChild);   //ǰ��������������� 
		PreOrder(subTree->rightChild);  //ǰ��������������� 
	} 
};
template<class T>
void BinaryTree<T>::PostOrder(BinTreeNode<T> *subTree)
{
	//�ݹ麯�������㷨���պ��������subTreeΪ��������
	if(subTree!=NULL)    //�ݹ�������� 
	{
		PostOrder(subTree->leftChild);   //����������������� 
		PostOrder(subTree->rightChild);  //����������������� 
		cout<<subTree->data<<" ";           //���ʸ��ڵ� 
	} 
};
template<class T>
int BinaryTree<T>::Size(BinTreeNode<T> *subTree)
{
	//����������������*subTreeΪ���Ķ������Ľ�����
	if(subTree==NULL) return 0;   //�ݹ����������������Ϊ0
	else return 1+Size(subTree->leftChild)+Size(subTree->rightChild);
};
template<class T>
int BinaryTree<T>::Height(BinTreeNode<T> *subTree)
{
	//����������������*subTreeΪ���Ķ������߶�
	if(subTree==NULL) return 0;          //�ݹ�����������߶�Ϊ0 
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
	//���к��������ƹ��캯�� 
	root=Copy(s.root);
};
template<class T>
BinTreeNode<T> *BinaryTree<T>::Copy(BinTreeNode<T> *orignode)
{
	//���������������������һ��ָ�룬������һ����orignodeΪ���Ķ������ĸ���
	if(orignode==NULL) return NULL;             //��Ϊ�գ����ؿ�ָ�� 
	BinTreeNode<T> *temp=new BinTreeNode<T>;    //�������ڵ� 
	temp->data=orignode->data;                  //�������� 
	temp->leftChild=Copy(orignode->leftChild);  //���������� 
	temp->rightChild=Copy(orignode->rightChild);  //���������� 
	return temp;          //���ظ�ָ�� 
};
template<class T>
void BinaryTree<T>::createBinTree_pre(T pre[], BinTreeNode<T> *&subTree, int &n)
{
	//�����������Եݹ鷽ʽ������������pre�����봮���޶�TΪ�ַ��ͣ������ԡ���������
	T ch =pre[n++];
	if(ch=='\0') return;        //������������� 
	if(ch!='#')                //�����ǿ����� 
	{
		subTree=new BinTreeNode<T>(ch);   //��������� 
		createBinTree_pre(pre,subTree->leftChild,n);     //�ݹ齨�������� 
		createBinTree_pre(pre,subTree->rightChild,n);   //�ݹ齨�������� 
	}
	else subTree = NULL;         //������������ 
};
int main ()
{
	char u[100010];
	BinaryTree<char> tree;   //���� 
	scanf("%s",u);
	int n=0;
	tree.createBinTree_pre(u,tree.root,n);   //ǰ���� 
	tree.Traverse(tree.root,0);   //������¼��� 
	cout<<tree.maxdepth;
	return 0;
}
