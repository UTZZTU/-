#include <iostream>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	int *p=new int[100];
	for(int i=0;i<n;i++)
	{
		cin>>*(p+i);
	}
	printf("a[%d]={",n);
	for(int i=0;i<n;i++)
	{
		cout<<*(p+i);
		if(i!=n-1)
		printf(",");
	}
	printf("}\n");
	printf("a[%d]={",n);
	for(int i=0;i<n;i++)
	{
		if(*(p+i)>0)
		cout<<*(p+i);
		else
		cout<<"0";
		if(i!=n-1)
		printf(",");
	}
	printf("}\n");
}