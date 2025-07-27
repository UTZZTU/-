#include <bits/stdc++.h>
using namespace std;
int n,f[10];
void fun(int list[],int k,int m)
{
	int i,j;
	if(k==m)
	{
		for(i=1;i<m;i++)
		printf("%d ",list[i]);
		printf("%d\n",list[i]);
		return;
	}
	for(j=k;j<=m;j++)
	{
		swap(list[k],list[j]);
		fun(list,k+1,m);
		swap(list[k],list[j]);
	}
}
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	f[i]=i;
	fun(f,1,n);
	return 0;
}