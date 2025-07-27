/*
	���ܣ�˳������ƶ�Ԫ�� 
	���룺ԭ�����Ա�Ԫ�� 
	������ƶ������Ա�Ԫ�أ����� 0 

	���뻷����Dev-C++ v5.11
	����ע�ͣ����Ĳ� 
	�޶����ڣ�2022��10��24��

	�ο����ף������������ݽṹ(��������󷽷���C++��������)(��3��)��,
	��Σ�2021��9�µ�3��
	ӡ�Σ�2022��6�µ�2��ӡˢ
	ҳ�룺PP42-47
*/
// ------------------------------ Testing Main ------------------------
#include <iostream>
#include <stdlib.h>
using namespace std;
template <class T>
class SeqList{     //���Ա�׼ȷ��˵��˳����õ��Ƕ�̬�������� 
	protected:
		T *data;   //һ��ָ�룬���濪�ٿռ������ 
		int maxSize;   //��������������� 
		int last;      //������鿪�ٺ����һ��Ԫ�ص�λ�� 
		int wz;
	public:
		SeqList(int sz);  //���캯�� 
		void output();    //������� 
		void setData(int i,T& x)   //��ֵ����ֵ������ 
		{
			data[i-1]=x;
		}
		void move_zero(); //�ƶ�0Ԫ��
		bool check();     //�ж��Ƿ�0���ں���
		int find(T x);   //�ҵ�ĳ��Ԫ�ص�λ��
		void move_back(int x); //�ƶ���Ԫ�ص���� 
};
template<class T>
SeqList<T>::SeqList(int sz)
{
	wz=0;
	maxSize=sz;            //maxSize��ֵ 
	last=sz-1;             //last��ֵ 
	data=new T[maxSize];   //����һ����СΪmaxSize������ 
}
template<class T>
void SeqList<T>::output()
{
	for(int i=0;i<maxSize;i++)
	{
		if(i!=0)
		cout<<",";          //ע�������ʽ��������֮���ж��� 
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
	for(int i=0;i<u.size();i++)  //�ַ���Ԥ���� 
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
	SeqList<int> sq(n);     //����һ�����Ա� 
	int i=1;
	for(int j=1;j<k1;j++)
	{
		sq.setData(i,s1[j]);    //��ֵ 
		i++;
	}
	for(int j=1;j<k2;j++)
	{
		sq.setData(i,s2[j]);    //��ֵ 
		i++;
	}
	sq.output();
	cout<<endl;
	return 0;
}
