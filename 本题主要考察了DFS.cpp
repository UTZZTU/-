#include <bits/stdc++.h>
using namespace std;
int t,n,res,l,r;
string u;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		l=r=0;
		getchar();
		for(int i=1;i<=n*n-1;i++)
		{
			cin>>u;
			for(int j=0;j<u.size();j++)
			{
				if(u[j]=='1')
				l++;
				if(u[j]=='2')
				r++;
			}
		}
		int minn=min(l,r);
		l-=minn;
		r-=minn;
		cout<<10+l-r<<endl;	
}
	return 0;
}