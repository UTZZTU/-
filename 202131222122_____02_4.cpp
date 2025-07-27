/*
	���ܣ��ڵ�������ͳ��ֵΪx�Ľ�����
	���룺�������� 
	��������Ա���Խ�� 

	���뻷����Dev-C++ v5.11
	����ע�ͣ����Ĳ� 
	�޶����ڣ�2022��10��4�� 

    �ο����ף������������ݽṹ(��������󷽷���C++��������)(��3��)��,
	��Σ�2021��9�µ�3��
	ӡ�Σ�2022��6�µ�2��ӡˢ
	ҳ�룺PP49-75
*/
// ------------------------------ Testing Main ------------------------
#include <iostream>
#include <stdlib.h>
using namespace std;
template <class T>
struct LinkNode
{
	T data;													// ������
	LinkNode<T> *link;										// ��ָ����
	LinkNode(LinkNode<T> *ptr=NULL) {link = ptr;};			// ���캯��������ʼ��ָ���Ա
	LinkNode(const T &item, LinkNode<T> *ptr = NULL)
		{ data = item;  link = ptr; }						// ���캯������ʼ�����ݺ�ָ��
};

template <class T>
class List
{
	public:
		List() { Sentinel = new LinkNode<T>; }					// ���캯��
	    List(const T x) { Sentinel = new LinkNode<T>(x); }		// ���캯��
	    List(List<T> &L);										// ���ƹ��캯��
	    int Length() const;										// ���
	    LinkNode<T> *getSentinel() const {return Sentinel;}		// ���ظ���ͷ����ַ
	    LinkNode<T> *Search(T x);								// ��������Ϊx��Ԫ��
	    LinkNode<T> *Locate(int i);								// ��λ��i��Ԫ��
	    bool getData(int i, T &x);								// ��ȡԪ�ص����ݣ��Ŀα����룬ֻ������
	    void setData(int i, T &x);								// ����Ԫ�ص����ݣ��޸�Ԫ�ص�����Ϊx
	    bool Insert (int i, T &x);								// �ڵ�iԪ�غ����x
	    bool Remove (int i, T &x);								// ɾ����iԪ�أ�����ɾ��Ԫ�ص�ֵx
	    List<T>& operator=(List<T> &L);						    // ���غ�������ֵ
	    void output();                                          //������� 
	    void inputRear(T x);                                    //�������� 
	public:
	    LinkNode<T> *Sentinel;
};

template <class T>
List<T>::List(List<T> &L)
{
	T value; 
	LinkNode<T> *srcptr = L.getSentinel();					// �����Ʊ�ı�ͷ
	LinkNode<T> *destptr = Sentinel = new LinkNode<T>;		// ���Ʊ�ı�ͷ
	while(srcptr->link!=NULL)								// �����㸴�� 
	{ 	
		value=srcptr->link->data;
		destptr->link = new LinkNode<T>(value);
		destptr = destptr->link;
		srcptr = srcptr->link;
	};
	destptr->link=NULL;										// �������Ʊ�
};

template <class T>
int List<T> :: Length() const 
{
	LinkNode<T> *p = Sentinel->link;						// ���ָ�� p ָʾ��һ�Ž��
	int count = 0; 
	while ( p != NULL )										// ��������
	{
		p = p->link;  count++;
	}			
	return count;
}

template <class T>
LinkNode<T> *List<T>::Search(T x)
{
	LinkNode<T> * current = Sentinel->link;
	while (current!= NULL)
		if (current->data==x) break;
		else current = current->link;
	return current;
}

template <class T>
LinkNode<T> *List<T>::Locate(int i)
{
	// ���ر��е� i ��Ԫ�صĵ�ַ���� i<0 �� i>���н�������򷵻�NULL
	if (i < 0) return NULL;									// i������
	LinkNode<T> *current = Sentinel;  int k = 0;
	while ( current != NULL && k < i )
		{ current = current->link; k++; }
	return current;											// ���ص� i �Ž���ַ��NULL
};

template <class T>
bool List<T>::getData(int i, T &x)
{
	if (i<=0) return false;
    LinkNode<T> *current = Locate(i);
	if (current == NULL) return false;
	else
	{
		x = current->data;
		return true;
	}
};

template <class T>
void List<T>::setData(int i, T &x)
{
	if (i<=0) 
		cerr << "Ԫ�ظ�ֵʱ��λ�ô���!" << endl;
    LinkNode<T> *current = Locate(i);
	if (current == NULL)
		cerr << "Ԫ�ظ�ֵʱ��λ�ó���!" << endl;
	else
		current->data = x;
};

template <class T>
bool List<T> :: Insert(int i, T& x)
{	// ����Ԫ�� x �����������е� i �����֮��
	LinkNode<T> *current = Locate(i);
	if (current == NULL) return false;						// �޲���λ��
	LinkNode<T> *newNode = new  LinkNode<T>(x);				// �����½��
	newNode->link = current->link;							// ����
	current->link = newNode;			
	return true;											// ����ɹ�
};

template <class T>
bool List<T> :: Remove(int i, T& x)
{
	LinkNode<T> *del,*current=Locate(i);
	if(i<=1)
	{
		del=Sentinel;
		Sentinel=Sentinel->link;
	}
	else
	{
		if(current==NULL||current->link==NULL)
		return false;
		del=current->link;
		current->link=del->link;
	}
	x=del->data;
	delete del;
	return true;											// ɾ���ɹ�
};

template <class T>
List<T>& List<T>:: operator=(List<T>& L)
{
	T value; 
	LinkNode<T> *srcptr = L.getSentinel();					// �����Ʊ�ı�ͷ
	LinkNode<T> *destptr = Sentinel = new LinkNode<T>;		// ���Ʊ�ı�ͷ
	while(srcptr->link!=NULL)								// �����㸴�� 
	{ 	
		value=srcptr->link->data;
		destptr->link = new LinkNode<T>(value);
		destptr = destptr->link;
		srcptr = srcptr->link;
	};
	destptr->link=NULL;										// �������Ʊ�
	return * this;											// ��ֵ����ֵ����������
};

template <class T>  
void List<T> :: output()     // �Լ�����ʽ�������
{
       LinkNode<T> *p=Sentinel->link;
       int k=0;
        while(p!=NULL)
        {     
               if(!k)
               {
               	    cout<<p->data;
               	    k++;
			   }
		       else
		       cout<<"-->"<<p->data;
               p=p->link;   
         }
         cout<<endl;
}

template <class T>  
void List<T> :: inputRear(T x)   //���뺯�� 
{
       int k=0;
       T n;
       while(cin>>n)
       {
       	if(n==x)
       	    break;
       	else
       	{
       		Insert(k,n);
       		k++;
		}
	   }
}

template <class T>
void findall(List<T> LA,T &x,int &sum)
{
	LinkNode<T> *current=LA.Sentinel->link;
	while(current!=NULL)
	{
		if(current->data==x)
		sum++;
		current=current->link;
	}
}
int main ()
{
       List<int> A;
       int sum=0,n;
       A.inputRear(-1);
       cin>>n;
       findall(A,n,sum);
       A.output();
       cout<<sum;
       return 0;  
}

