/*
	功能：顺序表中移动元素 
	输入：原序线性表元素 
	输出：移动后线性表元素，返回 0 

	编译环境：Dev-C++ v5.11
	开发注释：王文博 
	修订日期：2022年10月24日

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
class SeqList{     //线性表，准确来说是顺序表，用的是动态分配数组 
	protected:
		T *data;   //一个指针，后面开辟空间成数组 
		int maxSize;   //这个数组的最大数量 
		int last;      //这个数组开辟后最后一个元素的位置 
		int wz;
	public:
		SeqList(int sz);  //构造函数 
		void output();    //输出函数 
		void setData(int i,T& x)   //传值（设值）函数 
		{
			data[i-1]=x;
		}
		void move_zero(); //移动0元素
		bool check();     //判断是否0都在后面
		int find(T x);   //找到某个元素的位置
		void move_back(int x); //移动该元素到最后 
};
template<class T>
SeqList<T>::SeqList(int sz)
{
	wz=0;
	maxSize=sz;            //maxSize赋值 
	last=sz-1;             //last赋值 
	data=new T[maxSize];   //开辟一个大小为maxSize的数组 
}
template<class T>
void SeqList<T>::output()
{
	for(int i=0;i<maxSize;i++)
	{
		if(i!=0)
		cout<<",";          //注意输出格式，两个数之间有逗号 
		cout<<data[i];
	}
}
template<class T>
void SeqList<T>::move_zero()
{
	while(!check())
	{
		int i=find(0);
		move_back(i);
	}
}
template<class T>
bool SeqList<T>::check()
{
	int i=0;
	while(i<=last&&data[i]!=0)
	i++;
	for(i;i<=last;i++)
	{
		if(data[i]!=0)
		return false;
	}
	return true;
}
template<class T>
int SeqList<T>::find(T x)
{
	for(int i=0;i<=last;i++)
	{
		if(data[i]==x)
		return i;
	}
}
template<class T>
void SeqList<T>::move_back(int x)
{
	for(int i=x+1;i<=last;i++)
	{
		T j=data[i-1];
		data[i-1]=data[i];
		data[i]=j;
	}
}
int main()
{
	int n=1,k=0,s1[101000],s2[101000],k1=1,k2=1;
	string u;
	getline(cin,u);
	for(int i=0;i<u.size();i++)  //字符串预处理 
	{
		if(u[i]>='0'&&u[i]<='9')
		{
			k=k*10+u[i]-'0';
		}
		else if(u[i]==',')
		{
			if(k&1)
			s1[k1++]=k;
			else
			s2[k2++]=k;
			k=0;
			n++;
		}
	}
	        if(k&1)
			s1[k1++]=k;
			else
			s2[k2++]=k;
	SeqList<int> sq(n);     //构造一个线性表 
	int i=1;
	for(int j=1;j<k1;j++)
	{
		sq.setData(i,s1[j]);    //传值 
		i++;
	}
	for(int j=1;j<k2;j++)
	{
		sq.setData(i,s2[j]);    //传值 
		i++;
	}
	sq.output();
	cout<<endl;
	return 0;
}
