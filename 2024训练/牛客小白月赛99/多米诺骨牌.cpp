#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,m;
struct node
{
	int h,x;
}s[200010];
bool cmp(node x,node y)
{
	return x.x<y.x;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].h;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].x;
	}
	sort(s+1,s+1+n,cmp);
	vector<int> vec;
	int maxx=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			cnt++;
			maxx=s[i].x+s[i].h;
		}
		else
		{
			if(maxx>=s[i].x)
			{
				cnt++;
				maxx=max(maxx,s[i].x+s[i].h);
			}
			else
			{
				vec.push_back(cnt);
				cnt=1;
				maxx=s[i].x+s[i].h;
			}
		}
	}
	if(cnt)
	{
		vec.push_back(cnt);
	}
	sort(vec.begin(),vec.end());
	int res=0;
	int x=vec.size();
	for(int i=x-1;i>=max(0,x-m);i--)
	{
		res+=vec[i];
	}
	cout<<res<<endl;
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