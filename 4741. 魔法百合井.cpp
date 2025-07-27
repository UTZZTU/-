#include <bits/stdc++.h>
using namespace std;
int t,f[100010],l;
int main  ()
{
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>l;
		memset(f,0x3f,sizeof(f));
		f[0]=0;
		for(int i=1;i<=l;i++)
		{
			f[i]=min(f[i],f[i-1]+1);
			for(int j=2*i,k=1;j<=l;j+=i,k++)
			f[j]=min(f[j],f[i]+4+2*k);
		}
		printf("Case #%d: %d\n",i,f[l]);
	}
	return 0;
}