#include <bits/stdc++.h>
using namespace std;
const double Eps = 1e-8;
const double PI = atan(-1.0);
const int N = 1e6+5;
const int MOD = 1e9+7;

#define pb push_back
#define pf push_front
#define cl clear
#define fi first
#define se second
#define bg begin
#define ed end
#define sz size
#define fd find
#define is insert
#define PI pair<int,int>
#define PS pair<string,string>
#define Um unordered_map
#define Us unordered_set
#define Mul multiset<int>
#define VI vector<int>
#define VII vector< vector<int> > 
#define VS vector<string>
#define VN vector<node>
#define VP vector< pair<int,int> >
#define debug(x) cout<<"x"<<'\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define Mem(x) memset(x,0,sizeof x)
#define no cout<<"NO"<<'\n'
#define yes cout<<"YES"<<'\n'
#define pr(x) cout<<x<<'\n'

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;

struct node
{
	int num,pos;
}S[N];

bool cmp(node x,node y)
{
	return x.num<y.num;
}

int qmi(int a,int b,int mod)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}

int qmi(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a;
		b>>=1;
		a=a*a;
	}
	return res;
}

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
string a,b;
int n;
string sa[10],sb[10];
int extend(queue<string> &q,unordered_map<string,int> &mp1, unordered_map<string,int> &mp2, string a[], string b[])
{
	string s=q.front();
	q.pop();
	for(int i=0;i<s.sz();i++)
	{
		for(int j=0;j<n;j++)
		{
			string t=s.substr(i,a[j].sz());
			if(t==a[j])
			{
				t=s.substr(0,i)+b[j]+s.substr(i+a[j].sz());
				if(mp2.count(t))
				{
					return mp1[s]+1+mp2[t];
				}
				else if(mp1.count(t)==0)
				{
					mp1[t]=mp1[s]+1;
					q.push(t);
				}
			}
		}
	}
	return 11;
}
int bfs()
{
	unordered_map<string,int> mp1,mp2;
	queue<string> q1,q2;
	q1.push(a);
	q2.push(b);
	mp1[a]=0;
	mp2[b]=0;
	while(!q1.empty()&&!q2.empty())
	{
		if(q1.sz()<=q2.sz())
		{
			int x=extend(q1,mp1,mp2,sa,sb);
			if(x<=10) return x;
		}
		else
		{
			int x=extend(q2,mp2,mp1,sb,sa);
			if(x<=10) return x;
		}
	}
	return 11;
}
void solve()
{
	cin>>a>>b;
	n=0;
	while(cin>>sa[n]>>sb[n]) n++;
	if(a==b)
	{
		pr(0);
		return;
	}
	int x=bfs();
	if(x>10) pr("NO ANSWER!");
	else pr(x);
}
int main ()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	IOS;
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