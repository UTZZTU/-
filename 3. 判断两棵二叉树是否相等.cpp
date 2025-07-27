/*
	���ܣ��ж����ö������Ƿ���� 
	���룺������������ǰ����� 
	������Ƿ���� 

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
    BinTreeNode<T> *root;                                 //�������ĸ�ָ�� 
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
	for(int i=0;i<5*(k-1);i++) cout<<" ";
	if(subTree!=NULL)
	{
		cout<<subTree->data<<endl;   //���subTree������ֵ 
		Traverse(subTree->leftChild,k+1);   //�ݹ����������subTree�������� 
		Traverse(subTree->rightChild,k+1);  //�ݹ����������subTree�������� 
	} 
	else cout<<"#"<<endl;
};
template<class T>
void BinaryTree<T>::InOrder(BinTreeNode<T> *subTree)
{
	//�ݹ麯�������㷨�������������subTreeΪ��������
	if(subTree!=NULL)    //�ݹ�������� 
	{
		InOrder(subTree->leftChild);   //����������������� 
		cout<<subTree->data;           //���ʸ��ڵ� 
		InOrder(subTree->rightChild);  //����������������� 
	} 
};
template<class T>
void BinaryTree<T>::PreOrder(BinTreeNode<T> *subTree)
{
	//�ݹ麯�������㷨����ǰ�������subTreeΪ��������
	if(subTree!=NULL)    //�ݹ�������� 
	{
		cout<<subTree->data;           //���ʸ��ڵ� 
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
		cout<<subTree->data;           //���ʸ��ڵ� 
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
template<class T>
bool BinaryTree<T>::equal(BinTreeNode<T> *a,BinTreeNode<T> *b)   //�ж������������Ƿ�һ�� 
{
	if(a==NULL&&b==NULL)
	return true;
	else if(a==NULL&&b!=NULL||a!=NULL&&b==NULL)
	return false;
	else if(a->data!=b->data)
	return false;
	if(equal(a->leftChild,b->leftChild)&&equal(a->rightChild,b->rightChild))
	return true;
	else
	return false;
}
int main ()
{
	char u1[100010],u2[100010];
	BinaryTree<char> tree1,tree2;
	scanf("%s%s",u1,u2);
	int n1=0,n2=0;
	tree1.createBinTree_pre(u1,tree1.root,n1);  //���� 
	tree2.createBinTree_pre(u2,tree2.root,n2);
	if(tree1.equal(tree1.root,tree2.root))
	cout<<"equal";
	else
	cout<<"not equal";
	return 0;
}
