#include <bits/stdc++.h>
using namespace std;
int n,m,cnt,k,num;
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		if(cnt+k>m)
		{
			num++;
			cnt=0;
		}
		cnt+=k;
	}
	cout<<num;
	return 0;
}