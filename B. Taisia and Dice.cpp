#include <bits/stdc++.h>
using namespace std;
int t,n,s,r,maxx,num;
int main ()
{
	cin>>t;
	while(t--)
	{
		num=1;
		cin>>n>>s>>r;
		maxx=s-r;
		s-=maxx;
		while(s&&s>=n-num+maxx-1)
		{
			num++;
			s-=maxx;
		}
		int i=1;
		for(i;i<=n-num;i++)
		{
			if(i==n-num)
			cout<<s<<" ";
			else
			cout<<1<<" ";
			s--;
		}
		for(i;i<=n;i++)
		cout<<maxx<<" ";
		cout<<endl;
	}
	return 0;
}