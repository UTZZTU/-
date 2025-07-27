#include <bits/stdc++.h>
using namespace std;
int n,w,res,k,f[20];
int main ()
{
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		f[k]++;
	}
	sort(f+1,f+1+13);
	while(1)
	{
		int flag=1,num=0;
		for(int i=13;i>=1;i--)
		{
			if(w-num>=f[i])
			{
				num+=f[i];
				f[i]=0;
			}
		}
		if(!num) break;
		else res++;
	}
	cout<<res;
	return 0;
}