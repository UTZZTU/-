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
char u[100010],v[100010];
VI vec[4];
int n,q;
char c;
int l,r;
void solve()
{
	scanf("%d",&n);
	scanf("%s",u+1);
	scanf("%s",v+1);
	scanf("%d",&q);
	for(int i=1;i<=n;i++)
	{
		if(u[i]=='0'&&v[i]=='0') vec[0].pb(i);
		else if(u[i]=='1'&&v[i]=='0') vec[1].pb(i);
		else if(u[i]=='0'&&v[i]=='1') vec[2].pb(i);
		else vec[3].pb(i);
	}
	while(q--)
	{
		getchar();
		scanf("%c %d %d",&c,&l,&r);
//		printf("%c %d %d\n",c,l,r);
		if(c=='A')
		{
			auto it1=lower_bound(vec[0].bg(),vec[0].ed(),l);
			while(it1!=vec[0].ed()&&*it1<=r)
			{
				vec[1].insert(upper_bound(vec[1].bg(),vec[1].ed(),*it1),*it1);
				it1=vec[0].erase(it1);
			}
			auto it2=lower_bound(vec[2].bg(),vec[2].ed(),l);
			while(it2!=vec[2].ed()&&*it2<=r)
			{
				vec[3].insert(upper_bound(vec[3].bg(),vec[3].ed(),*it2),*it2);
				it2=vec[2].erase(it2);
			}
		}
		else
		{
			auto it1=lower_bound(vec[0].bg(),vec[0].ed(),l);
			while(it1!=vec[0].ed()&&*it1<=r)
			{
				vec[2].insert(upper_bound(vec[2].bg(),vec[2].ed(),*it1),*it1);
				it1=vec[0].erase(it1);
			}
			auto it2=lower_bound(vec[1].bg(),vec[1].ed(),l);
			while(it2!=vec[1].ed()&&*it2<=r)
			{
				vec[3].insert(upper_bound(vec[3].bg(),vec[3].ed(),*it2),*it2);
				it2=vec[1].erase(it2);
			}
		}
// 		int pos1=upper_bound(vec[3].bg(),vec[3].ed(),r)-vec[3].bg();
// 		int pos2=lower_bound(vec[3].bg(),vec[3].ed(),l)-vec[3].bg();
//		printf("%d\n%d\n",pos1,pos2);
//		for(int i=0;i<vec[0].sz();i++) printf("%d ",vec[0][i]);
//		printf("\n");
//		for(int i=0;i<vec[1].sz();i++) printf("%d ",vec[1][i]);
//		printf("\n");
//		for(int i=0;i<vec[2].sz();i++) printf("%d ",vec[2][i]);
//		printf("\n");
//		for(int i=0;i<vec[3].sz();i++) printf("%d ",vec[3][i]);
//		printf("\n");
		printf("%d\n",vec[3].sz());
	}
}
int main ()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
//	IOS;
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