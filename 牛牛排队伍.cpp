#include <bits/stdc++.h>
using namespace std;
int pre[1000010],k,n,pass[1000010],num,x;
int main ()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		pre[i]=0,pass[i]=2;
		else
		pre[i]=i-1,pass[i]=i+1;
	}
	while(k--)
	{
		scanf("%d%d",&num,&x);
		if(num==1)
		{
			int p=pre[x],q=pass[x];
			pre[q]=p;
			pass[p]=q;
		}
		else
		{
			printf("%d\n",pre[x]);
		}
	}
	return 0;
}