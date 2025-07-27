/*
	���ܣ� ɾ��˳����о��и���ֵ������Ԫ��
	���룺ԭ�����Ա�Ԫ�� 
	�����ɾ���ض�Ԫ�غ�����Ա�Ԫ�أ������ 

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
using namespace std;
template <class T>
void delete_number(T *&x,int last,int pos)  //������ɾ����������������ĳ�Ա���� 
{
	for(int i=pos+1;i<=last;i++)
	{
		x[i-1]=x[i];
	}
}
template <class T>
class SeqList{     //���Ա�׼ȷ��˵��˳����õ��Ƕ�̬�������� 
	protected:
		T *data;   //һ��ָ�룬���濪�ٿռ������ 
		int maxSize;   //��������������� 
		int last;      //������鿪�ٺ����һ��Ԫ�ص�λ�� 
		int pos;       //Ҫɾ����Ԫ���������е�λ�� 
	public:
		SeqList(int sz);  //���캯�� 
		void delete_num(int x);   //ɾ������ 
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
	pos=0;                 //pos����ʼֵ 
	data=new T[maxSize];   //����һ����СΪmaxSize������ 
}
template<class T>
void SeqList<T>::delete_num(int x)
{
	int judge=0;    
	for(int i=pos;i<=last;i++)   //�����ж��Ƿ��������ֵ��ȵ�����Ԫ��
	{
		if(data[i]==x)
		{
			judge=1;
			pos=i;
	        break;
		}
	}
	while(judge)                 //��������������û����ȫɾ��ʱ 
	{
		judge=0;
		delete_number(data,last,pos);  //���÷ǳ�Ա������ɾ������ 
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
		cout<<" ";          //ע�������ʽ��������֮���пո� 
		cout<<data[i];
	}
	cout<<" }";
}
int main()
{
	int n,k,x;
	cin>>n;
	SeqList<int> sq(n);     //����һ�����Ա� 
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		sq.setData(i,k);    //��ֵ 
	}
	cin>>x;
	sq.delete_num(x);           //ɾ������ֵx
	sq.output();            //��� 
	return 0;
}
