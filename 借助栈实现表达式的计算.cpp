/*
	功能：借助栈实现表达式的计算 
	输入：字符串 
	输出：计算结果 

	编译环境：Dev-C++ v5.11
	开发注释：王文博 
	修订日期：2022年10月24日

	参考文献：殷人昆《数据结构(用面向对象方法与C++语言描述)(第3版)》
	版次：2021年9月第3版
	印次：2022年6月第2次印刷
	页码：PP95-100
*/
// ------------------------------ Testing Main ------------------------
#include <iostream>
#include <stdlib.h> 
#include <stdio.h>
using namespace std;
template<class T>
struct LinkNode            //节点类的定义 
{
	T data;                //数据域 
	LinkNode<T> *link;     //指针域 
	LinkNode(LinkNode<T> *ptr=NULL)    //仅初始化指针成员的构造函数 
	{
		link=ptr;
	}
	LinkNode(const T& item,LinkNode<T> *ptr=NULL)    //初始化数据成员和指针成员的构造函数
	{
		data=item;
		link=ptr;
	}
};
template<class T>
class LinkedStack{         //链式栈类定义 
	public:
		LinkedStack(): top(NULL){}   //构造函数，置空栈 
		~LinkedStack()
		{
			makeEmpty();
		};                           //析构函数 
		void push(T x);              //进栈 
		bool pop(T &x);              //退栈 
		bool getTop(T &x);           //读取栈顶元素 
		bool IsEmpty()               
		{
			return top==NULL?true:false;
		}
		int getSize();               //求栈的元素个数
		void makeEmpty();            //清空栈的内容  
	private:
		LinkNode<T> *top;            //栈顶指针，即链头指针 
};
template<class T>
void LinkedStack<T>::makeEmpty()
{
	//逐次删去链式栈中的元素直至栈顶指针为空
	LinkNode<T> *p;
	while(top!=NULL)
	{
		p=top;
		top=top->link;              //逐个节点释放 
		delete p;
	} 
};
template<class T>
void LinkedStack<T>::push(T x)
{
	//将元素值x插入链式栈的栈顶，即链头
	LinkNode<T> *s=new LinkNode<T> (x);       //创建新的含x的结点 
	if(s==NULL)
	{
		cerr<<"存储分配失败！"<<endl;
		exit(1);
	} 
	s->link=top;
	top=s;
};
template<class T>
bool LinkedStack<T>::pop(T &x)
{
	//删除栈顶结点，返回被删栈顶元素的值
	if(IsEmpty()==true)     //若栈空则不退栈，返回 
	return false;            
	LinkNode<T> *p=top;     //否则暂存栈顶元素
	top=top->link;         //栈顶指针退到新的栈顶位置
	x=p->data;             //释放节点，返回退出元素的值 
	delete p;
	return true; 
};
template<class T>
bool LinkedStack<T>::getTop(T &x)
{
	//返回栈顶元素的值
	if(IsEmpty()==true)    //若栈空则返回false 
	return false;
	x=top->data;          //栈不空则返回栈顶元素的值 
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
double kh(int &i)    //递归处理括号内表达式，纯手写，有些繁琐 
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
void solve()   //从头到尾处理字符串，到加法或减法时把数塞进栈内，乘除括号特殊判断处理 
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
	solve();  //处理字符串，把其分解到栈里 
	double sum=0,k;
	while(!p.IsEmpty())  //对栈内元素进行相加 
	{
		p.pop(k);
		sum+=k;
	}
	printf("%.1f",sum);
	return 0;
}
