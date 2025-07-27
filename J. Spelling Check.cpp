#include <bits/stdc++.h>
using namespace std;
const double Eps = 1e-8;
const double PI = atan(-1.0);

#define pb push_back
#define pf push_front
#define cl clear
#define fi first
#define se second
#define bg begin
#define ed end
#define sz size
#define fd find
#define PI pair<int,int>
#define Um unordered_map
#define Mul multiset
#define VI vector<int>
#define VII vector< vector<int> > 
#define VS vector<string>
#define VN vector<node>
#define VP vector< pair<int,int> >
#define debug(x) cout<<"x"<<endl
#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define Mem(x) memset(x,0,sizeof x)

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;

string a,b;
int s[26],num,pre[1000010],post[1000010];
void solve()
{
	cin>>a>>b;
	for(auto x:a)
	{
		s[x-'a']++;
	}
	for(auto x:b)
	{
		s[x-'a']--;
	}
	for(int i=0;i<26;i++)
	{
		if(s[i]==0)
		{
			;
		}
		else if(s[i]==1)
		{
			num++;
			if(num>=2)
			{
				cout<<0<<endl;
				return;
			}
		}
		else
		{
			cout<<0<<endl;
			return;
		}
	}
	int flag=0;
	VI vec;
	for(int i=0;i<a.sz()-1;i++)
	{
		if(a[i]==b[i])
		{
			if(!flag) pre[i+1]=pre[i]+1;
			else pre[i+1]=pre[i];
		}
		else
		{
			flag=1;
			pre[i+1]=pre[i];
		}
	}
	flag=0;
	for(int i=a.sz()-1;i>0;i--)
	{
		if(a[i]==b[i-1])
		{
			if(!flag) post[i+1]=post[i+2]+1;
			else post[i+1]=post[i+2];
		}
		else
		{
			flag=1;
			post[i+1]=post[i+2];
		}
	}
	for(int i=0;i<a.sz();i++)
	{
		if(pre[i]+post[i+2]==b.sz())
		{
			vec.pb(i+1);
		}
	}
	cout<<vec.sz()<<endl;
	for(auto x:vec) cout<<x<<" ";
	cout<<endl;
}
int main ()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
//	cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}