#include <bits/stdc++.h>
using namespace std;
#define re register
bool st[100010];
int prime[100010],cnt,n;
int main ()
{
	st[1]=true;
	for(re int i=2;i<=100010;++i)
	{
		if(!st[i]) prime[cnt++]=i;
		for(re int j=0;prime[j]<=100010/i;++j)
		{
			st[prime[j]*i]=true;
			if(i%prime[j]==0) break;
		}
	}
	cin>>n;
	if(n<=2)
	cout<<1<<endl;
	else
	cout<<2<<endl;
	for(int i=2;i<=n+1;i++)
	{
		if(!st[i])
		cout<<1<<" ";
		else
		cout<<2<<" ";
	}
	return 0;
}