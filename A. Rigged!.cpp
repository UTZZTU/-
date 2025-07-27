#include <bits/stdc++.h>
using namespace std;
int t,n,s[110],e[110],flag;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		flag=1;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i]>>e[i];
		}
		for(int i=2;i<=n;i++)
		{
			if(s[i]>=s[1]&&e[i]>=e[1])
			{
				flag=0;
				break;
			}
		}
		if(flag) printf("%d\n",s[1]);
		else puts("-1");
	}
	return 0;
}