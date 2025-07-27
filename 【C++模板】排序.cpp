#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
template<typename T>
void fun(T a[],int n)
{
	sort(a,a+n);
	return ;
}
int main ()
{
	int n1,n2,a[20];
	string b[20];
	cin>>n1;
	for(int i=0;i<n1;i++)
	{
		cin>>a[i];
	}
	fun(a,n1);
	cin>>n2;
	for(int i=0;i<n2;i++)
	{
		cin>>b[i];
	}
	fun(b,n2);
	for(int i=0;i<n1;i++)
	{
		if(i!=0)
		cout<<" ";
		cout<<a[i];
	}
	cout<<endl;
	for(int i=0;i<n2;i++)
	{
		if(i!=0)
		cout<<" ";
		cout<<b[i];
	}
	return 0;
}