#include <bits/stdc++.h>
using namespace std;
int t,n,cnt;
map<string,int> mp;
string ss;
int f[]={0, 25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
struct node
{
	string name;
	int score;
	int cnt[110];
}s[110];
bool cmp1(node x,node y)
{
	if(x.score!=y.score) return x.score>y.score;
	else
	{
		for(int i=1;i<=100;i++)
		{
			if(x.cnt[i]>y.cnt[i]) return true;
			else if(x.cnt[i]<y.cnt[i]) return false;
		}
		return true;
	}
}
bool cmp2(node x,node y)
{
	if(x.cnt[1]!=y.cnt[1]) return x.cnt[1]>y.cnt[1];
	else if(x.score!=y.score) return x.score>y.score;
	else
	{
		for(int i=2;i<=100;i++)
		{
			if(x.cnt[i]>y.cnt[i]) return true;
			else if(x.cnt[i]<y.cnt[i]) return false;
		}
		return true;
	}
}
void solve()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>ss;
			if(mp[ss]==0) 
			{
				mp[ss]=++cnt;
				s[mp[ss]].name=ss;
				s[mp[ss]].score=0;
				for(int j=1;j<=100;j++)
				{
					s[mp[ss]].cnt[j]=0;
				}
			}
			s[mp[ss]].cnt[i]++;
			if(i<=10) s[mp[ss]].score+=f[i];
		}
	}
	sort(s+1,s+1+cnt,cmp1);
	cout<<s[1].name<<endl;
	sort(s+1,s+1+cnt,cmp2);
	cout<<s[1].name<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int _=1;
//	cin>>t;
	while(_--)
	{
		solve();
	}
	return 0;
}