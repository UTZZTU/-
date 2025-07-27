#include <bits/stdc++.h>
using namespace std;
int t,n,f[1000010];
bool judge(int x)
{
	int res=0;
	while(x)
	{
		if(x%10!=0)
		res++;
		if(res>1)
		return false;
		x/=10;
	}
	return true;
}
int main ()
{
	for(int i=1;i<=1000000;i++)
	{
		if(judge(i))
		f[i]=1;
		f[i]+=f[i-1];
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",f[n]);
	}
	return 0;
}