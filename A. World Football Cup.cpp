#include <bits/stdc++.h>
using namespace std;
int n;
string ss;
int u,v;
struct node
{
	string s;
	int num;
	int pp;
	int score;
}s[110];
bool cmp(node x,node y)
{
	if(x.num!=y.num) return x.num>y.num;
	else if(x.pp!=y.pp) return x.pp>y.pp;
	else return x.score>y.score;
}
map<string,int> mp;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ss;
		s[i].s=ss;
		s[i].num=s[i].score=s[i].pp=0;
		mp[ss]=i;
	}
	for(int i=1;i<=n*(n-1)/2;i++)
	{
		string t;
		cin>>ss;
		cin>>t;
		int pos=ss.find('-');
		string a=ss.substr(0,pos);
		string b=ss.substr(pos+1);
		pos=t.find(':');
		u=stoi(t.substr(0,pos));
		v=stoi(t.substr(pos+1));
		if(u>v)
		{
			s[mp[a]].num+=3;
			s[mp[a]].score+=u;
			s[mp[b]].score+=v;
			s[mp[a]].pp+=u-v;
			s[mp[b]].pp+=v-u;
		}
		else if(u==v)
		{
			s[mp[a]].num+=1;
			s[mp[b]].num+=1;
			s[mp[a]].score+=u;
			s[mp[b]].score+=v;
			s[mp[a]].pp+=u-v;
			s[mp[b]].pp+=v-u;
		}
		else
		{
			s[mp[b]].num+=3;
			s[mp[b]].score+=v;
			s[mp[a]].score+=u;
			s[mp[a]].pp+=u-v;
			s[mp[b]].pp+=v-u;
		}
	}
	sort(s+1,s+1+n,cmp);
	vector<string> vec;
	for(int i=1;i<=n/2;i++)
	{
		vec.push_back(s[i].s);
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<n/2;i++)
	{
		cout<<vec[i]<<endl;
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