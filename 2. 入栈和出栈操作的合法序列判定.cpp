/*
	���ܣ���ջ�ͳ�ջ�����ĺϷ������ж�
	���룺�ַ��� 
	������жϽ����yes/no�� 

	���뻷����Dev-C++ v5.11
	����ע�ͣ����Ĳ� 
	�޶����ڣ�2022��10��16��

	�ο����ף������������ݽṹ(��������󷽷���C++��������)(��3��)��,
	��Σ�2021��9�µ�3��
	ӡ�Σ�2022��6�µ�2��ӡˢ
	ҳ�룺PP85-87
*/
// ------------------------------ Testing Main ------------------------
#include <iostream>
#include <stdlib.h>
using namespace std;
template<class T>
struct LinkNode            //�ڵ���Ķ��� 
{
	T data;                //������ 
	LinkNode<T> *link;     //ָ���� 
	LinkNode(LinkNode<T> *ptr=NULL)    //����ʼ��ָ���Ա�Ĺ��캯�� 
	{
		link=ptr;
	}
	LinkNode(const T& item,LinkNode<T> *ptr=NULL)    //��ʼ�����ݳ�Ա��ָ���Ա�Ĺ��캯��
	{
		data=item;
		link=ptr;
	}
};
template<class T>
class LinkedStack{         //��ʽջ�ඨ�� 
	public:
		LinkedStack(): top(NULL){}   //���캯�����ÿ�ջ 
		~LinkedStack()
		{
			makeEmpty();
		};                           //�������� 
		void push(T x);              //��ջ 
		bool pop(T &x);              //��ջ 
		bool getTop(T &x);           //��ȡջ��Ԫ�� 
		bool IsEmpty()               
		{
			return top==NULL?true:false;
		}
		int getSize();               //��ջ��Ԫ�ظ���
		void makeEmpty();            //���ջ������  
	private:
		LinkNode<T> *top;            //ջ��ָ�룬����ͷָ�� 
};
template<class T>
void LinkedStack<T>::makeEmpty()
{
	//���ɾȥ��ʽջ�е�Ԫ��ֱ��ջ��ָ��Ϊ��
	LinkNode<T> *p;
	while(top!=NULL)
	{
		p=top;
		top=top->link;              //����ڵ��ͷ� 
		delete p;
	} 
};
template<class T>
void LinkedStack<T>::push(T x)
{
	//��Ԫ��ֵx������ʽջ��ջ��������ͷ
	LinkNode<T> *s=new LinkNode<T> (x);       //�����µĺ�x�Ľ�� 
	if(s==NULL)
	{
		cerr<<"�洢����ʧ�ܣ�"<<endl;
		exit(1);
	} 
	s->link=top;
	top=s;
};
template<class T>
bool LinkedStack<T>::pop(T &x)
{
	//ɾ��ջ����㣬���ر�ɾջ��Ԫ�ص�ֵ
	if(IsEmpty()==true)     //��ջ������ջ������ 
	return false;            
	LinkNode<T> *p=top;     //�����ݴ�ջ��Ԫ��
	top=top->link;         //ջ��ָ���˵��µ�ջ��λ��
	x=p->data;             //�ͷŽڵ㣬�����˳�Ԫ�ص�ֵ 
	delete p;
	return true; 
};
template<class T>
bool LinkedStack<T>::getTop(T &x)
{
	//����ջ��Ԫ�ص�ֵ
	if(IsEmpty()==true)    //��ջ���򷵻�false 
	return false;
	x=top->data;          //ջ�����򷵻�ջ��Ԫ�ص�ֵ 
	return true; 
}
template<class T>
int LinkedStack<T>::getSize()
{
	LinkNode<T> *p=top;
	int k=0;
	while(top!=NULL)
	{
		top=top->link;
		k++;
	}
	return k;
};
int main ()
{
	int t=1;
	LinkedStack<int> num;
	string u;
	cin>>u;
	for(int i=0;i<u.size();i++)
	{
		if(u[i]=='I')
		num.push(t);
		else if(u[i]=='O')
		{
			if(num.IsEmpty())
			{
				cout<<"no";
				return 0;
			}
			else
			num.pop(t);
		}
	}
	if(!num.IsEmpty())
	{
		cout<<"no";
		return 0;
	}
	cout<<"yes";
	return 0;
}
