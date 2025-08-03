#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int pp;
int ask(int a,int b)
{
	cout<<"? "<<a<<" "<<b<<endl;
	int tt;
	cin>>tt;
	if(tt==a*b) return -1;
	else if(tt==a*(b+1)) return 0;
	else return 1;
}
void sf(int ll,int rr)
{
	if(ll==rr)
	{
		pp=ll;
		return;
	}
	int lmid=(rr-ll)/3+ll;
	int rmid=(rr-ll)*2/3+ll;
	int ans=ask(lmid,rmid);
	if(ans==-1)
	{
		sf(rmid+1,rr);
	}
	else if(ans==0)
	{
		sf(lmid+1,rmid);
	}
	else
	{
		sf(ll,lmid);
	}
}
void solve()
{
	sf(1,1000);
	cout<<"! "<<pp<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}