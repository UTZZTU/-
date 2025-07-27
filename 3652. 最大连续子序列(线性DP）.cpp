#include <bits/stdc++.h>
using namespace std;
int a[100010],f[100010];
int main ()
{
	int n;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		int l=1,r=1,res=a[1];
		for(int i=1,j=1;i<=n;i++)
		{
			f[i]=max(f[i-1],0)+a[i];
			if(f[i-1]<0)
			j=i;
			if(f[i]>res)
			{
				l=j,r=i,res=f[i];
			}
		}
		if(res<0)
		puts("0 0 0");
		else
		cout<<res<<" "<<l-1<<" "<<r-1<<endl;
	}
	return 0;
}