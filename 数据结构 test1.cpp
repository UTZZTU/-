/*
	功能：线性表的逆置 
	输入：原序线性表元素 
	输出：逆置后线性表元素，返回 0 

	编译环境：Dev-C++ v5.11
	开发注释：王文博 
	修订日期：2022年9月15日

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
void get_Inverts(T *&x,int last)  //独立的逆置函数，不属于类的成员函数 
{
	for(int i=0;i<=last/2;i++)  //进行逆置，第一个与最后一个交换，第二个与倒数第二个交换，以此类推，直到遍历到中间 
	{
		int u=x[last-i];
		x[last-i]=x[i];
		x[i]=u;
	}
}
template <class T>
class SeqList{     //线性表，准确来说是顺序表，用的是动态分配数组 
	protected:
		T *data;   //一个指针，后面开辟空间成数组 
		int maxSize;   //这个数组的最大数量 
		int last;      //这个数组开辟后最后一个元素的位置 
	public:
		SeqList(int sz);  //构造函数 
		void Inverts();   //逆置函数 
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
	data=new T[maxSize];   //开辟一个大小为maxSize的数组 
}
template<class T>
void SeqList<T>::Inverts()
{
	get_Inverts(data,last);  //调用非成员函数的逆置函数 
}
template<class T>
void SeqList<T>::output()
{
	cout<<"{ ";
	for(int i=0;i<maxSize;i++)
	{
		if(i!=0)
		cout<<" ";          //注意输出格式，两个数之间有空格 
		cout<<data[i];
	}
	cout<<" }";
}
int main()
{
	int n,k;
	cin>>n;
	SeqList<int> sq(n);     //构造一个线性表 
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		sq.setData(i,k);    //传值 
	}
	sq.Inverts();           //逆置 
	sq.output();            //输出 
	return 0;
}
