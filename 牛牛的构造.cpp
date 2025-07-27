#include <bits/stdc++.h>
using namespace std;
int a[1010],n;
bool check(int x,int y)
{
	if(x<y)
	return false;
	int t=x-y;
	while(t)
	{
		if(t==1)
		return true;
		if(t%2!=0)
		return false;
		t/=2;
	}
	return false;
}
int main ()
{
	cin>>n;
		int res=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(check(a[i],a[j]))
				res++;
			}
		}
		printf("--- %d\n",res);
	return 0;
}