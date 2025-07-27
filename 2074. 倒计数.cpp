#include <bits/stdc++.h>
using namespace std;
int t,n,k,f[200010],cnt,num;
int main ()
{
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		cnt=0;
		scanf("%d %d",&n,&k);
		for(int j=1;j<=n;j++)
		scanf("%d",&f[j]);
		for(int j=1;j<=n;j++)
		{
			num=k;
			int t=j;
			while(f[t]==num&&num>=1&&t<=n)
			{
				num--;
				t++;
			}
			if(num<=0)
			cnt++;
			if(num==k)
			t++;
			j=t-1;
		}
		cout<<"Case #"<<i<<": "<<cnt<<endl;
	}
	return 0;
}