#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y;
ll ans;
int main ()
{
	cin>>x>>y;
	for(int k=3;k<=17;k++)
	{
		for(int i=0;i<=9;i++)
	{
		string str(k, '0' + i);
		for(int j=0;j<=9;j++)
		{
			if(i==j)
			continue;
			for(int o=0;o<k;o++)
			{
				str[o]='0'+j;
				ll p=0;
				for(int q=0;q<k;q++) p=p*10+str[q]-'0';
				if(str[0]!='0'&&p>=x&&p<=y)
				ans++;
				str[o]='0'+i;
			}
		}
	}
	
	}
	cout<<ans;
	return 0;
}