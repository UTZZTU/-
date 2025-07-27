#include <bits/stdc++.h>
using namespace std;
bool judge(int n)
{
	if(n==2||n==3)
	return true;
	if(n%6!=1&&n%6!=5)
	return false;
	else
	{
		for(int i=5;i<=floor(sqrt(n));i+=6)
		{
			if(n%i==0||n%(i+2)==0)
			return false;
		}
		return true;
	}
}
int a[10010],k=1;
int main ()
{
	int n,tot=0;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		if(judge(i))
		{
			a[k]=i;
			k++;
		}
	}
	for(int i=1;i<k-1;i++)
	{
		int j=i+1;
		if(a[j]-a[i]==2)
		tot++;
	}
	cout<<tot;
	return 0;
}