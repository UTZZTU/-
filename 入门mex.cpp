#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,a[100010],pos,cnt;
map<int,bool> mp;
int main ()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]=true;
	}
	while(cnt<k)
	{
		if(mp[pos])
		{
			pos++,cnt++;
		}
		else
		break;
	}
	cout<<pos;
	return 0;
}