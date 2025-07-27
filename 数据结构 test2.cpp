/*
	功能： 删除顺序表中具有给定值的所有元素
	输入：原序线性表元素 
	输出：删除特定元素后的线性表元素，并输出 

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
using namespace std;
template <class T>
void delete_number(T *&x,int last,int pos)  //独立的删除函数，不属于类的成员函数 
{
	for(int i=pos+1;i<=last;i++)
	{
		x[i-1]=x[i];
	}
}
template <class T>
class SeqList{     //线性表，准确来说是顺序表，用的是动态分配数组 
	protected:
		T *data;   //一个指针，后面开辟空间成数组 
		int maxSize;   //这个数组的最大数量 
		int last;      //这个数组开辟后最后一个元素的位置 
		int pos;       //要删除的元素在数组中的位置 
	public:
		SeqList(int sz);  //构造函数 
		void delete_num(int x);   //删除函数 
		void output();    //输出函数 
		void setData(int i,T& x)   //传值（设值）函数 
		{
			data[i-1]=x;
			
		}
};
template<class T>
SeqList<T>::SeqList(int sz)
{
	maxSize=sz;            //maxSize赋值 
	last=sz-1;             //last赋值 
	pos=0;                 //pos赋初始值 
	data=new T[maxSize];   //开辟一个大小为maxSize的数组 
}
template<class T>
void SeqList<T>::delete_num(int x)
{
	int judge=0;    
	for(int i=pos;i<=last;i++)   //先行判断是否有与给定值相等的数组元素
	{
		if(data[i]==x)
		{
			judge=1;
			pos=i;
	        break;
		}
	}
	while(judge)                 //当数组中这类数没有完全删完时 
	{
		judge=0;
		delete_number(data,last,pos);  //调用非成员函数的删除函数 
		last--;
		for(int i=pos;i<=last;i++)
	    {
		    if(data[i]==x)
		    {
			    judge=1;
			    pos=i;
	            break;
		    }
	   }
	}
	
}
template<class T>
void SeqList<T>::output()
{
	cout<<"{";
	for(int i=0;i<=last;i++)
	{
		cout<<" ";          //注意输出格式，两个数之间有空格 
		cout<<data[i];
	}
	cout<<" }";
}
int main()
{
	int n,k,x;
	cin>>n;
	SeqList<int> sq(n);     //构造一个线性表 
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		sq.setData(i,k);    //传值 
	}
	cin>>x;
	sq.delete_num(x);           //删除给定值x
	sq.output();            //输出 
	return 0;
}
