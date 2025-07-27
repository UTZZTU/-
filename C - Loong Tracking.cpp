#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int n,q,posx,posy,cnt,op,pp;
pair<int,int> p[N];
string c;
void solve()
{
	cin>>n>>q;
	for(int i=n;i>=1;i--)
	{
		p[++cnt]={i,0};
	}
	posx=1,posy=0;
	while(q--)
	{
		cin>>op;
		if(op==1)
		{
			cin>>c;
//			cout<<c<<endl;
			if(c[0]=='U')
			{
				posy++;
			}
			else if(c[0]=='L')
			{
				posx--;
			}
			else if(c[0]=='R')
			{
				posx++;
			}
			else
			{
				posy--;
			}
			p[++cnt]={posx,posy};
		}
		else
		{
			cin>>pp;
			cout<<p[cnt-pp+1].first<<" "<<p[cnt-pp+1].second<<endl;
		}
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}