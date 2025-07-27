#include <bits/stdc++.h>
using namespace std;
int m,s,a[110],b[110];
int main ()
{
	cin>>m>>s;
	if(m==1&&s==0)
	{
	    cout<<0<<" "<<0;
	    return 0;
	}
	if(s==0||s>m*9)
	{
		cout<<-1<<" "<<-1;
		return 0;
	}
	int n=s;
	for(int i=m;i>=1;i--)
	{
		a[i]=min(n,9);
		n-=a[i];
	}
	if(a[1]==0)
	{
		a[1]=1;
		for(int i=2;i<=m;i++)
		{
			if(a[i])
			{
				a[i]--;
				break;
			}
		}
	}
	n=s;
	for(int i=1;i<=m;i++)
	{
		b[i]=min(n,9);
		n-=b[i];
	}
	for(int i=1;i<=m;i++)
	cout<<a[i];
	cout<<" ";
	for(int i=1;i<=m;i++)
	cout<<b[i];
	return 0;
}