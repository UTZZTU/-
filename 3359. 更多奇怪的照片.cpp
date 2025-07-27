#include <bits/stdc++.h>
using namespace std;
int ans1,ans2,ans,n,pos=0,len;
int main ()
{
	cin>>n;
	for(int i=1,k;i<=n;i++)
	{
		cin>>k;
		if(k&1)
		ans1++;
		else
		ans2++;
	}
	while(ans1>0||ans2>0)
	{
		if(pos==0)
		{
			if(ans2>0)
			{
				ans2--;
				ans++;
			}
			else if(ans1>=2)
			{
				ans1-=2;
				ans++;
			}
			else if(ans1==1)
			{
				if(len>1)
				{
					ans--;
					break;
				}
				else
				break;
			}
			else
			break;
			pos=1;
		}
		else
		{
			if(ans1>=1)
			{
			ans1--;
			ans++;
			}
			else
			break;
			pos=0;
		}
		len++;
	}
	cout<<ans;
	return 0;
}