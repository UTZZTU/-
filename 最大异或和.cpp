#include <bits/stdc++.h>
using namespace std;
int t,n,res1,res2,res3,res4;
string u,v;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		res1=res2=res3=res4=0;
		cin>>u>>v;
		for(int i=0;i<n;i++)
		{
			if(u[i]=='1') res1++;
			if(v[i]=='1') res2++;
		}
		res3=n-res1;
		res4=n-res2;
		for(int i=1;i<=n;i++)
		{
			if(res1&&res4)
			{
				cout<<1;
				res1--,res4--;
			}
			else if(res2&&res3)
			{
				cout<<1;
				res2--,res3--;
			}
			else
			cout<<0;
		}
		cout<<endl;
	}
	return 0;
}