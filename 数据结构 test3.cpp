/*
	功能：将线性表中元素循环左移p个位置 
	输入：原序线性表元素 
	输出：左移后线性表元素，返回0 

	编译环境：Dev-C++ v5.11
	开发注释：王文博 
	修订日期：2022年9月16日

	参考文献：殷人昆《数据结构(用面向对象方法与C++语言描述)(第3版)》,
	版次：2021年9月第3版
	印次：2022年6月第2次印刷
	页码：PP42-47
*/
// ------------------------------ Testing Main ------------------------
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
template <class T>
void Left_Shift(T *&x,int last)  //独立的左移函数，不属于类的成员函数
{
	int q=x[0];                  //把开头元素取出来，其他的依次左移，最后在把取出的值赋给最后一个数 ，这样就实现了循环左移一位 
	for(int i=1;i<=last;i++)
	{
		x[i-1]=x[i];
	}
	x[last]=q;
}
template <class T>
class SeqList{     //线性表，准确来说是顺序表，用的是动态分配数组 
	protected:
		T *data;   //一个指针，后面开辟空间成数组 
		int maxSize;   //这个数组的最大数量 
		int last;      //这个数组开辟后最后一个元素的位置 
	public:
		SeqList();  //构造函数 
		void Left(int x);   //循环左移函数 
		void output();    //输出函数 
		void get_size(int sz)   //更新最大值 和实际值 
		{
			maxSize=sz;            //maxSize赋值 
	        last=sz-1;             //last赋值 
		}
		void setData(int i,T& x)   //传值（设值）函数 
		{
			data[i-1]=x;
			
		}
};
template<class T>
SeqList<T>::SeqList()
{    
    int sz=100010;
	data=new T[sz];   //开辟一个大小足够的数组 ，因为题目没有说输入多少元素 
}
template<class T>
void SeqList<T>::Left(int x)  //左移函数 
{
	while(x--)   //其实就是进行p次循环左移一位当前数组的操作 
	{
		Left_Shift(data,last);
	}
}
template<class T>
void SeqList<T>::output()
{
	for(int i=0;i<maxSize;i++)
	{
		if(i!=0)
		cout<<" ";          //注意输出格式，两个数之间有空格，这时就不用大括号括住了 
		cout<<data[i];
	}
}
int main()
{
	int p,ans=0,num=0,judge=0;  //ans记录有多少个元素，num记录每个数是什么，judge判断当前是什么行为 
	string n;                   //因为要输入一行不知道数量的元素，所以用字符串读，并把数从中一个个剥离 
	cin>>p;
	getchar();
	getchar();                  //多读入一个回车符 ，题目特性 
	SeqList<int> sq;     //构造一个线性表 
	getline(cin,n);      //读入一行数 
	for(int i=0;i<n.size();i++)     //剥离数字并添加到sq的data数组中 
	{
		if(n[i]==' ')
		{
			if(judge)
			{
				judge=0;
				sq.setData(++ans,num);
				num=0;
			}
			else
			continue;
		}
		else if(n[i]>='0'&&n[i]<='9')
		{
			judge=1;
			num=num*10+n[i]-'0';
		}
	}
	if(num)
	sq.setData(++ans,num);  //最后一次判断是否有数字 
	sq.get_size(ans);       //更新最大值 
	sq.Left(p);           //循环左移 
	sq.output();            //输出 
	return 0;
}
