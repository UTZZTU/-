#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int c[N],n,x,t;
int main ()
{
	scanf("%d",&n);
	for(int k=1;k<=n;k++)
	{
		scanf("%d",&x);
		t=max(t,x);
		for(int i=1;i<=floor(sqrt(x));i++)
		{
			if(x%i==0)
			{
				c[i]++;
				if(i*i!=x)
				c[x/i]++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		while(c[t]<i) t--;
		cout<<t<<endl;
	}
	return 0;
}