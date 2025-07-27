#include <bits/stdc++.h>
using namespace std;
int n,f[100010],flag,k,num,a[100010];
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[a[i]]++;
		if(f[a[i]]>=2)
		{
			flag=1;
			num=a[i];
		}
	}
	k=2;
	if(flag)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==num)
			{
				cout<<i<<" ";
				k--;
				if(!k)
				break;
			}
		}
	}
	return 0;
}