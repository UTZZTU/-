/*
	功能：入栈和出栈操作的合法序列判定
	输入：字符串 
	输出：判断结果（yes/no） 

	编译环境：Dev-C++ v5.11
	开发注释：王文博 
	修订日期：2022年10月16日

	参考文献：殷人昆《数据结构(用面向对象方法与C++语言描述)(第3版)》,
	版次：2021年9月第3版
	印次：2022年6月第2次印刷
	页码：PP85-87
*/
// ------------------------------ Testing Main ------------------------
#include <iostream>
#include <stdlib.h>
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
