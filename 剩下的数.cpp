#include <bits/stdc++.h>
using namespace std;
int f1[1000100],f2[1000100],n,cnt,primes[1000010],flag1,flag2,k,flag=1;
bool st[1000010];
void init(int x)
{
	for(int i=2;i<=x;i++)
	{
		if(!st[i])
		{
			flag1=flag2=0;
			if(f1[i])
			flag1=1;
			if(f2[i])
			flag2=1;
			if(flag1&&flag2)
			{
				flag=0;
				break;
			}
			for(int j=2*i;j<=x;j+=i)
			{
				st[j]=true;
				if(f1[j])
				flag1=1;
				if(f2[j])
				flag2=1;
			}
			if(flag1&&flag2)
			{
				flag=0;
				break;
			}
		}
		else
		continue;
	}
}
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		f1[k]=1;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		f2[k]=1;
	}
	init(1000000);
	if(flag)
	cout<<"Yes";
	else
	cout<<"No";
	return 0;
}