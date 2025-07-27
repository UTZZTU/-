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
#define debug(x) cout<<"x"<<endl
#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define Mem(x) memset(x,0,sizeof x)
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
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

struct Node
{
	int pos;
	char c;
};
int n,k,pl,pr;
VI vec;
string s,a="backspace",b="delete",c="<-",d="->",u;
void solve()
{
	cin>>n>>k;
	cin>>s;
	int pos=s.find("I");
	pl=pos-1,pr=pos+1;
	list<Node> ls;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='I')
		{
			;
		}
		else
		{
			ls.pb({i,s[i]});
		}
	}
	auto it=ls.bg();
	list<Node>::iterator l=null,r=null;
	for(it;it!=ls.ed();it++)
	{
		if(*it.pos==pos-1)
		{
			l=it;
		}
		if(*it.pos==pos+1)
		{
			r=it;
		}
	}
	while(k--)
	{
		cin>>u;
		if(u==c)
		{
			if(r==null)
			{
				if(l==null)
				{
					;
				}
				else if(l==ls.bg())
				{
					r=l;
					l=null;
				}
				else
				{
					r=l;
					l=prev(l);
				}
			}
		}
		else if(u==d)
		{
			if(l==null)
			{
				if(r==null)
				{
					;
				}
				else if(next(r)==ls.ed())
				{
					l=r;
					r=null;
				}
				else
				{
					l=r;
					r=next(r);
				}
			}
		}
		else if(u==a)
		{
			if(l!=null&&r!=null)
			{
				if(*l.c=='('&&*r.c==')')
				{
					list<Node>::iterator ll=null,rr=null;
					if(l!=ls.bg())  ll=prev(l);
					if(next(r)!=ls.ed()) rr=next(r);
					ls.erase(r);
					ls.erase(l);
					l=ll,r=rr;
				}
				else
				{
					list<Node>::iterator ll=null,rr=null;
					if(l!=ls.bg())  ll=prev(l);
					if(next(r)!=ls.ed()) rr=next(r);
					ls.erase(r);
					ls.erase(l);
					l=ll,r=rr;
				}
			}
			else if(l>=0)
			{
				int pre=vec[l];
				vec.erase(lower_bound(vec.bg(),vec.ed(),pre));
				l--;
				r=l+1;
			}
			else if(r<n)
			{
				;
			}
			else
			{
				;
			}
		}
		else if(u==b)
		{
			if(r<n)
			{
				int post=vec[r];
				vec.erase(lower_bound(vec.bg(),vec.ed(),post));
			}
		}
	}
	auto it1=ls.bg();
	for(it1;it1!=ls.ed();it1++)
	{
		if(*it1.pos<pos) cout<<*it1.c;
	}
	cout<<"I";
	auto it2=ls.bg();
	for(it2;it2!=ls.ed();it2++)
	{
		if(*it2.pos<pos) cout<<*it2.c;
	}
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