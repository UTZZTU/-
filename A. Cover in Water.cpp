#include <bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
int t,n;
string s;
void solve()
{
	cin>>n>>s;
	int maxx=0,res=0,cnt=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='#')
		{
			maxx=max(maxx,cnt);
			cnt=0;
		}
		else
		{
			res++;
			cnt++;
		}
	}
	maxx=max(maxx,cnt);
	if(res<=2) printf("%d\n",res);
	else if(maxx>=3) printf("2\n");
	else printf("%d\n",res);
}
int main ()
{
	ios;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}