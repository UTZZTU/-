/*
	���ܣ�����ջʵ�ֱ��ʽ�ļ��� 
	���룺�ַ��� 
	����������� 

	���뻷����Dev-C++ v5.11
	����ע�ͣ����Ĳ� 
	�޶����ڣ�2022��10��24��

	�ο����ף������������ݽṹ(��������󷽷���C++��������)(��3��)��
	��Σ�2021��9�µ�3��
	ӡ�Σ�2022��6�µ�2��ӡˢ
	ҳ�룺PP95-100
*/
// ------------------------------ Testing Main ------------------------
#include <iostream>
#include <stdlib.h> 
#include <stdio.h>
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
string u;
LinkedStack<double> p;
double kh(int &i)    //�ݹ鴦�������ڱ��ʽ������д����Щ���� 
{
	double k=1,pos1=0,pos2=0,sum=0;
	for(i;;i++)
	{
		if(u[i]==')')
		{
			i++;
			return sum;
		}
	    if(u[i]>='0'&&u[i]<='9')
	    {
	    	while(u[i]>='0'&&u[i]<='9')
	    	{
	    		pos1=pos1*10+u[i]-'0';
	    		i++;
			}
			if(u[i]=='.')
			{
				i++;
				double num=0.1;
				while(u[i]>='0'&&u[i]<='9')
				{
					pos1+=(u[i]-'0')*num;
					i++;
					num/=10;
				}
			}
			if(u[i]==')'||u[i]=='+'||u[i]=='-')
			{
				i--;
				sum+=pos1*k;
				k=1;
				pos1=0;
			}
			else
			{
				pos1*=k;
				k=1;
				i--;
			}
		}
		else if(u[i]=='+')
		{
			k=1;
			pos1=0;
		}
		else if(u[i]=='-')
		{
			k=-1;
			pos1=0;
		}
		if(u[i]=='*')
		{
			i++;
			if(u[i]>='0'&&u[i]<='9')
	    {
	    	while(u[i]>='0'&&u[i]<='9')
	    	{
	    		pos2=pos2*10+u[i]-'0';
	    		i++;
			}
			if(u[i]=='.')
			{
				i++;
				double num=0.1;
				while(u[i]>='0'&&u[i]<='9')
				{
					pos2+=(u[i]-'0')*num;
					i++;
					num/=10;
				}
			}
			if(u[i]==')'||u[i]=='+'||u[i]=='-')
			{
				i--;
				sum+=(pos2*k*pos1);
				k=1;
				pos1=0;
				pos2=0;
			}
			else
			{
				pos1*=k*pos2;
				k=1;
				pos2=0;
				i--;
			}
		}
		    else if(u[i]=='-')
		    {
			   u[i]='*';
			   pos1*=-1;
			   k=1;
			   i--;
		    }
		    else if(u[i]=='(')
		    {
		    	i++;
		    	pos2=kh(i);
		    	if(u[i]==')'||u[i]=='+'||u[i]=='-')
			{
				i--;
				sum+=(pos2*k*pos1);
				k=1;
				pos1=0;
				pos2=0;
			}
			else
			{
				pos1*=k*pos2;
				k=1;
				pos2=0;
				i--;
			}
			}
		}
		else if(u[i]=='/')
		{
			i++;
			if(u[i]>='0'&&u[i]<='9')
	    {
	    	while(u[i]>='0'&&u[i]<='9')
	    	{
	    		pos2=pos2*10+u[i]-'0';
	    		i++;
			}
			if(u[i]=='.')
			{
				i++;
				double num=0.1;
				while(u[i]>='0'&&u[i]<='9')
				{
					pos2+=(u[i]-'0')*num;
					i++;
					num/=10;
				}
			}
			if(u[i]==')'||u[i]=='+'||u[i]=='-')
			{
				i--;
				sum+=(pos1*1.0/(pos2*k));
				k=1;
				pos1=0;
				pos2=0;
			}
			else
			{
				pos1=pos1*1.0/(pos2*k);
				k=1;
				pos2=0;
				i--;
			}
		}
		    else if(u[i]=='-')
		    {
			   u[i]='/';
			   pos1*=-1;
			   k=1;
			   i--;
		    }
		    else if(u[i]=='(')
		    {
		    	i++;
		    	pos2=kh(i);
		    	if(u[i]==')'||u[i]=='+'||u[i]=='-')
			{
				i--;
				sum+=(pos1*1.0/(pos2*k));
				k=1;
				pos1=0;
				pos2=0;
			}
			else
			{
				pos1=pos1*1.0/(pos2*k);
				k=1;
				pos2=0;
				i--;
			}
			}
		}
		else if(u[i]=='(')
		{
			i++;
			pos1=kh(i);
			if(u[i]==')'||u[i]=='+'||u[i]=='-')
			{
				i--;
				sum+=(k*pos1);
				k=1;
				pos1=0;
				pos2=0;
			}
			else
			{
				pos1*=k;
				k=1;
				pos2=0;
				i--;
			}
		}
	}
}
void solve()   //��ͷ��β�����ַ��������ӷ������ʱ��������ջ�ڣ��˳����������жϴ��� 
{
	double k=1,pos1=0,pos2=0;
	for(int i=0;i<u.size()-1;i++)
	{
	    if(u[i]>='0'&&u[i]<='9')
	    {
	    	while(u[i]>='0'&&u[i]<='9')
	    	{
	    		pos1=pos1*10+u[i]-'0';
	    		i++;
			}
			if(u[i]=='.')
			{
				i++;
				double num=0.1;
				while(u[i]>='0'&&u[i]<='9')
				{
					pos1+=(u[i]-'0')*num;
					i++;
					num/=10;
				}
			}
			if(u[i]=='#'||u[i]=='+'||u[i]=='-')
			{
				i--;
				p.push(pos1*k);
				k=1;
				pos1=0;
			}
			else
			{
				pos1*=k;
				k=1;
				i--;
			}
		}
		else if(u[i]=='+')
		{
			k=1;
			pos1=0;
		}
		else if(u[i]=='-')
		{
			k=-1;
			pos1=0;
		}
		if(u[i]=='*')
		{
			i++;
			if(u[i]>='0'&&u[i]<='9')
	    {
	    	while(u[i]>='0'&&u[i]<='9')
	    	{
	    		pos2=pos2*10+u[i]-'0';
	    		i++;
			}
			if(u[i]=='.')
			{
				i++;
				double num=0.1;
				while(u[i]>='0'&&u[i]<='9')
				{
					pos2+=(u[i]-'0')*num;
					i++;
					num/=10;
				}
			}
			if(u[i]=='#'||u[i]=='+'||u[i]=='-')
			{
				i--;
				p.push(pos2*k*pos1);
				k=1;
				pos1=0;
				pos2=0;
			}
			else
			{
				pos1*=k*pos2;
				k=1;
				pos2=0;
				i--;
			}
		}
		    else if(u[i]=='-')
		    {
			   u[i]='*';
			   pos1*=-1;
			   k=1;
			   i--;
		    }
		    else if(u[i]=='(')
		    {
		    	i++;
		    	pos2=kh(i);
		    	if(u[i]=='#'||u[i]=='+'||u[i]=='-')
			{
				i--;
				p.push(pos2*k*pos1);
				k=1;
				pos1=0;
				pos2=0;
			}
			else
			{
				pos1*=k*pos2;
				k=1;
				pos2=0;
				i--;
			}
			}
		}
		else if(u[i]=='/')
		{
			i++;
			if(u[i]>='0'&&u[i]<='9')
	    {
	    	while(u[i]>='0'&&u[i]<='9')
	    	{
	    		pos2=pos2*10+u[i]-'0';
	    		i++;
			}
			if(u[i]=='.')
			{
				i++;
				double num=0.1;
				while(u[i]>='0'&&u[i]<='9')
				{
					pos2+=(u[i]-'0')*num;
					i++;
					num/=10;
				}
			}
			if(u[i]=='#'||u[i]=='+'||u[i]=='-')
			{
				i--;
				p.push(pos1*1.0/(pos2*k));
				k=1;
				pos1=0;
				pos2=0;
			}
			else
			{
				pos1=pos1*1.0/(pos2*k);
				k=1;
				pos2=0;
				i--;
			}
		}
		    else if(u[i]=='-')
		    {
			   u[i]='/';
			   pos1*=-1;
			   k=1;
			   i--;
		    }
		    else if(u[i]=='(')
		    {
		    	i++;
		    	pos2=kh(i);
		    	if(u[i]=='#'||u[i]=='+'||u[i]=='-')
			{
				i--;
				p.push(pos1*1.0/(pos2*k));
				k=1;
				pos1=0;
				pos2=0;
			}
			else
			{
				pos1=pos1*1.0/(pos2*k);
				k=1;
				pos2=0;
				i--;
			}
			}
		}
		else if(u[i]=='(')
		{
			i++;
			pos1=kh(i);
			if(u[i]=='#'||u[i]=='+'||u[i]=='-')
			{
				i--;
				p.push(k*pos1);
				k=1;
				pos1=0;
				pos2=0;
			}
			else
			{
				pos1*=k;
				k=1;
				pos2=0;
				i--;
			}
		}
	}
	p.push(pos1*k);
}
int main ()
{
	cin>>u;
	solve();  //�����ַ���������ֽ⵽ջ�� 
	double sum=0,k;
	while(!p.IsEmpty())  //��ջ��Ԫ�ؽ������ 
	{
		p.pop(k);
		sum+=k;
	}
	printf("%.1f",sum);
	return 0;
}
