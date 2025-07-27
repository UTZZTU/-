#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p,q,r,k,ans1,ans2,ans3,m,judge;
int main ()
{
	cin>>p>>q>>r;
	for(int i=2;i<=16;i++)
	{
		judge=0;
		k=1,ans1=0,ans2=0,ans3=0,m=r;
		while(m)
		{
			if(m%10>=i)
			{
				judge=-1;
				break;
			}
		  	ans3+=k*(m%10);
		  	m/=10;
		  	k*=i;
		}
		m=p,k=1;
		while(m&&judge!=-1)
		{
			if(m%10>=i)
			{
				judge=-1;
				break;
			}
		  	ans1+=k*(m%10);
		  	m/=10;
		  	k*=i;
		}
		m=q,k=1;
		while(m&&judge!=-1)
		{
			if(m%10>=i)
			{
				judge=-1;
				break;
			}
		  	ans2+=k*(m%10);
		  	m/=10;
		  	k*=i;
		}
		if(judge==-1)
		continue;
		if(ans3==ans2*ans1)
		{
			cout<<i;
			return 0;
		}
	}
	cout<<0;
	return 0;
}