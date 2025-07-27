/*
	���ܣ����Ա������ 
	���룺ԭ�����Ա�Ԫ�� 
	��������ú����Ա�Ԫ�أ����� 0 

	���뻷����Dev-C++ v5.11
	����ע�ͣ����Ĳ� 
	�޶����ڣ�2022��9��15��

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
void get_Inverts(T *&x,int last)  //���������ú�������������ĳ�Ա���� 
{
	for(int i=0;i<=last/2;i++)  //�������ã���һ�������һ���������ڶ����뵹���ڶ����������Դ����ƣ�ֱ���������м� 
	{
		int u=x[last-i];
		x[last-i]=x[i];
		x[i]=u;
	}
}
template <class T>
class SeqList{     //���Ա�׼ȷ��˵��˳����õ��Ƕ�̬�������� 
	protected:
		T *data;   //һ��ָ�룬���濪�ٿռ������ 
		int maxSize;   //��������������� 
		int last;      //������鿪�ٺ����һ��Ԫ�ص�λ�� 
	public:
		SeqList(int sz);  //���캯�� 
		void Inverts();   //���ú��� 
		void output();    //������� 
		void setData(int i,T& x)   //��ֵ����ֵ������ 
		{
			data[i-1]=x;
			
		}
};
template<class T>
SeqList<T>::SeqList(int sz)
{
	maxSize=sz;            //maxSize��ֵ 
	last=sz-1;             //last��ֵ 
	data=new T[maxSize];   //����һ����СΪmaxSize������ 
}
template<class T>
void SeqList<T>::Inverts()
{
	get_Inverts(data,last);  //���÷ǳ�Ա���������ú��� 
}
template<class T>
void SeqList<T>::output()
{
	cout<<"{ ";
	for(int i=0;i<maxSize;i++)
	{
		if(i!=0)
		cout<<" ";          //ע�������ʽ��������֮���пո� 
		cout<<data[i];
	}
	cout<<" }";
}
int main()
{
	int n,k;
	cin>>n;
	SeqList<int> sq(n);     //����һ�����Ա� 
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		sq.setData(i,k);    //��ֵ 
	}
	sq.Inverts();           //���� 
	sq.output();            //��� 
	return 0;
}
