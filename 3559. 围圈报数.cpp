#include <bits/stdc++.h>
using namespace std;
int a[55],js,rs,n,cs;
int main ()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		js=0;
		rs=0;
		cs=0;
		memset(a,0,sizeof(a));
		while(js<n)
		{
			rs++;
			if(rs>n)
			rs%=n;
			if(!a[rs])
			{
				cs++;
				if(cs==3)
				{
					js++;
					if(js!=n)
					cout<<rs<<" ";
					else
					cout<<rs<<endl;
					cs=0;
					a[rs]=1;
				}
			}
		}
	}
	return 0;
}