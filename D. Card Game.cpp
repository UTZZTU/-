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

int n,num1,num2;
char c;
string s;
void solve()
{
	num1=0,num2=0;
	map<char,vector<string>> mp;
	cin>>n;
	cin>>c;
	for(int i=1;i<=2*n;i++)
	{
		cin>>s;
		mp[s[1]].pb(s);
	}
	if(c!='C')
	{
		num1+=mp['C'].sz()%2;
	}
	else num2+=mp['C'].sz();
	sort(mp['C'].bg(),mp['C'].ed());
	if(c!='D')
	{
		num1+=mp['D'].sz()%2;
	}
	else num2+=mp['D'].sz();
	sort(mp['D'].bg(),mp['D'].ed());
	if(c!='H')
	{
		num1+=mp['H'].sz()%2;
	}
	else num2+=mp['H'].sz();
	sort(mp['H'].bg(),mp['H'].ed());
	if(c!='S')
	{
		num1+=mp['S'].sz()%2;
	}
	else num2+=mp['S'].sz();
	sort(mp['S'].bg(),mp['S'].ed());
	if(num2>=num1&&(num2-num1)%2==0)
	{
		vector<string> vec;
		vector<string> v;
		if(c!='C')
		{
			vector<string> temp=mp['C'];
			for(int i=0;i<temp.sz();i+=2)
			{
				if(i+1<temp.sz())
				{
					cout<<temp[i]<<" "<<temp[i+1]<<'\n';
				}
				else break;
			}
			if(temp.sz()&1) v.pb(temp[temp.sz()-1]);
		}
		else
		{
			vec=mp['C'];
		}
		if(c!='D')
		{
			vector<string> temp=mp['D'];
			for(int i=0;i<temp.sz();i+=2)
			{
				if(i+1<temp.sz())
				{
					cout<<temp[i]<<" "<<temp[i+1]<<'\n';
				}
				else break;
			}
			if(temp.sz()&1) v.pb(temp[temp.sz()-1]);
		}
		else
		{
			vec=mp['D'];
		}
		if(c!='H')
		{
			vector<string> temp=mp['H'];
			for(int i=0;i<temp.sz();i+=2)
			{
				if(i+1<temp.sz())
				{
					cout<<temp[i]<<" "<<temp[i+1]<<'\n';
				}
				else break;
			}
			if(temp.sz()&1) v.pb(temp[temp.sz()-1]);
		}
		else
		{
			vec=mp['H'];
		}
		if(c!='S')
		{
			vector<string> temp=mp['S'];
			for(int i=0;i<temp.sz();i+=2)
			{
				if(i+1<temp.sz())
				{
					cout<<temp[i]<<" "<<temp[i+1]<<'\n';
				}
				else break;
			}
			if(temp.sz()&1) v.pb(temp[temp.sz()-1]);
		}
		else
		{
			vec=mp['S'];
		}
		for(int i=0;i<v.sz();i++)
		{
			cout<<v[i]<<" "<<vec[i]<<'\n';
		}
		for(int i=v.sz();i<vec.sz();i+=2)
		{
			cout<<vec[i]<<" "<<vec[i+1]<<'\n';
		}
	}
	else
	pr("IMPOSSIBLE");
}
int main ()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	IOS;
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}