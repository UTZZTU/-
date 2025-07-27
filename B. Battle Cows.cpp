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
//using u32 = unsigned int;
//using u64 = unsigned long long;
//using i128 = __int128;
//using u128 = unsigned __int128;
//using f128 = __float128;

struct Node
{
	int num,pos;
}S[N];

bool Cmp(Node x,Node y)
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

//cout<<fixed<<setprecision(x)
int n,k,pos,a[100010],maxx,p;
void solve()
{
	maxx=0;
	p=-1;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	pos=0;
	swap(a[k],a[1]);
	for(int i=2;i<=n;i++)
	{
		if(a[i]>a[1])
		{
			break;
		}
		else pos++;
	}
	maxx=pos;
	swap(a[k],a[1]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]>a[k])
		{
			p=i;
			break;
		}
	}
	if(p!=-1&&p<k) ;
	else 
	{
		if(k!=1)
		pos=1;
		else pos=0;
		for(int i=k+1;i<=n;i++)
		{
			if(a[i]>a[k]) break;
			else pos++;
		}
		maxx=max(maxx,pos);
	}
	
	if(p!=-1&&p<k)
	{
		if(p==1)
		pos=0;
		else pos=1;
		swap(a[k],a[p]);
		for(int i=p+1;i<=n;i++)
		{
			if(a[i]>a[p]) break;
			else pos++;
		}
		maxx=max(maxx,pos);
	}
//	cout<<maxx<<endl;
//	cout<<pos<<endl;
//	cout<<p<<endl;
//	int i=1,pre=0,post=0;
//	while(i<=n&&a[i]<a[k])
//	{
//		post++;
//		i++;
//	}
//	for(i;i<=n;i++)
//	{
//		pre=post;
//		post=0;
//		int j=i+1;
//		while(j<=n&&a[j]<a[k])
//		{
//			j++;
//			post++;
//		}
//		j--;
//		if(i<=k)
//		maxx=max(maxx,post+min(1,pre));
//		i=j;
//	}
//	pr(max(maxx,0));
	cout<<maxx<<endl;
}
/*
6 5
625778431 491759484 676109737 276223667 374227387 242827289
*/
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