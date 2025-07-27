/*
	���ܣ������Ա���Ԫ��ѭ������p��λ�� 
	���룺ԭ�����Ա�Ԫ�� 
	��������ƺ����Ա�Ԫ�أ�����0 

	���뻷����Dev-C++ v5.11
	����ע�ͣ����Ĳ� 
	�޶����ڣ�2022��9��16��

	�ο����ף������������ݽṹ(��������󷽷���C++��������)(��3��)��,
	��Σ�2021��9�µ�3��
	ӡ�Σ�2022��6�µ�2��ӡˢ
	ҳ�룺PP42-47
*/
// ------------------------------ Testing Main ------------------------
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
template <class T>
void Left_Shift(T *&x,int last)  //���������ƺ�������������ĳ�Ա����
{
	int q=x[0];                  //�ѿ�ͷԪ��ȡ�������������������ƣ�����ڰ�ȡ����ֵ�������һ���� ��������ʵ����ѭ������һλ 
	for(int i=1;i<=last;i++)
	{
		x[i-1]=x[i];
	}
	x[last]=q;
}
template <class T>
class SeqList{     //���Ա�׼ȷ��˵��˳����õ��Ƕ�̬�������� 
	protected:
		T *data;   //һ��ָ�룬���濪�ٿռ������ 
		int maxSize;   //��������������� 
		int last;      //������鿪�ٺ����һ��Ԫ�ص�λ�� 
	public:
		SeqList();  //���캯�� 
		void Left(int x);   //ѭ�����ƺ��� 
		void output();    //������� 
		void get_size(int sz)   //�������ֵ ��ʵ��ֵ 
		{
			maxSize=sz;            //maxSize��ֵ 
	        last=sz-1;             //last��ֵ 
		}
		void setData(int i,T& x)   //��ֵ����ֵ������ 
		{
			data[i-1]=x;
			
		}
};
template<class T>
SeqList<T>::SeqList()
{    
    int sz=100010;
	data=new T[sz];   //����һ����С�㹻������ ����Ϊ��Ŀû��˵�������Ԫ�� 
}
template<class T>
void SeqList<T>::Left(int x)  //���ƺ��� 
{
	while(x--)   //��ʵ���ǽ���p��ѭ������һλ��ǰ����Ĳ��� 
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
		cout<<" ";          //ע�������ʽ��������֮���пո���ʱ�Ͳ��ô�������ס�� 
		cout<<data[i];
	}
}
int main()
{
	int p,ans=0,num=0,judge=0;  //ans��¼�ж��ٸ�Ԫ�أ�num��¼ÿ������ʲô��judge�жϵ�ǰ��ʲô��Ϊ 
	string n;                   //��ΪҪ����һ�в�֪��������Ԫ�أ��������ַ�����������������һ�������� 
	cin>>p;
	getchar();
	getchar();                  //�����һ���س��� ����Ŀ���� 
	SeqList<int> sq;     //����һ�����Ա� 
	getline(cin,n);      //����һ���� 
	for(int i=0;i<n.size();i++)     //�������ֲ���ӵ�sq��data������ 
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
	sq.setData(++ans,num);  //���һ���ж��Ƿ������� 
	sq.get_size(ans);       //�������ֵ 
	sq.Left(p);           //ѭ������ 
	sq.output();            //��� 
	return 0;
}
