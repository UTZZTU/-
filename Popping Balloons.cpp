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
// #define int long long
using ll = long long;
//using u32 = unsigned int;
//using u64 = unsigned long long;
//using i128 = __int128;
//using u128 = unsigned __int128;
//using f128 = __float128;

// struct Node
// {
// 	int num,pos;
// }S[N];

// bool Cmp(Node x,Node y)
// {
// 	return x.num<y.num;
// }

// int qmi(int a,int b,int mod)
// {
// 	int res=1;
// 	while(b)
// 	{
// 		if(b&1) res=res*a%mod;
// 		b>>=1;
// 		a=a*a%mod;
// 	}
// 	return res;
// }

// int qmi(int a,int b)
// {
// 	int res=1;
// 	while(b)
// 	{
// 		if(b&1) res=res*a;
// 		b>>=1;
// 		a=a*a;
// 	}
// 	return res;
// }

// int gcd(int a,int b)
// {
// 	return b==0?a:gcd(b,a%b);
// }

//cout<<fixed<<setprecision(x)
// map<ll,int> point;
//map<PI,int> point;
map<int,map<int,int> > mp;
int h[300010],l[300010],mx,my;
int n,r,x,y,pos1,pos2,maxx;
struct node
{
	int p,sum;
}hh[300010],lll[300010];
bool cmp(node x,node y)
{
	return x.sum>y.sum;
}
void solve()
{
	cin>>n>>r;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
        mx=max(mx,x);
        my=max(my,y);
		h[x]++;
		l[y]++;
// 		point[{x*100000ll+y}]++;
        mp[x][y]++;
	}
	for(int i=0;i<=mx;i++)
	{
//		if(!h[i]) continue;
		++pos1;
		hh[pos1].p=i;
		hh[pos1].sum=h[i]+h[i+r]+h[i+2*r];
	}
	for(int i=0;i<=my;i++)
	{
//		if(!l[i]) continue;
		++pos2;
		lll[pos2].p=i;
		lll[pos2].sum=l[i]+l[i+r]+l[i+2*r];
	}
	sort(hh+1,hh+1+pos1,cmp);
	sort(lll+1,lll+1+pos2,cmp);
	for(int i=1;i<=min(30,pos1);i++)
	{
		for(int j=1;j<=min(30,pos2);j++)
		{
			int res=hh[i].sum+lll[j].sum;
//			cout<<hh[i].p<<" "<<lll[j].p<<" "<<res<<endl;
			for(int k1=hh[i].p;k1<=hh[i].p+2*r;k1+=r)
			{
				for(int k2=lll[j].p;k2<=lll[j].p+2*r;k2+=r)
				{
// 					res-=point[k1*100000ll+k2];
                    res-=mp[k1][k2];
//					cout<<res<<endl;
				}
			}
			maxx=max(maxx,res);
		}
	}
	pr(maxx);
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