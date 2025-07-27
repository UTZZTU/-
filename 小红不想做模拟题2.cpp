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
int tr[100010];
int lowbit(int x)
{
	return x & -x;
}
int sum(int x)
{
	int res=0;
	for(int i=x;i;i-=lowbit(i)) res+=tr[i];
	return res;
}
int n,q;
void add(int x,int c)
{
	for(int i=x;i<=n;i+=lowbit(i)) tr[i]+=c;
}

//cout<<fixed<<setprecision(x)
//char u[100010],v[100010];
string u,v;
//VI vec[4];
multiset<int> mul1,mul2,mul3;

string c;
int l,r;
void solve()
{
//	scanf("%d",&n);
//	scanf("%s",u+1);
//	scanf("%s",v+1);
//	scanf("%d",&q);
	cin>>n;
	cin>>u;
	cin>>v;
	cin>>q;
	for(int i=0;i<n;i++)
	{
		if(u[i]=='0'&&v[i]=='0') mul1.insert(i+1);
		else if(u[i]=='1'&&v[i]=='0') mul2.insert(i+1);
		else if(u[i]=='0'&&v[i]=='1') mul3.insert(i+1);
		else add(i+1,1);
	}
	while(q--)
	{
//		scanf("%c %d %d",&c,&l,&r);
		cin>>c>>l>>r;
//		printf("%c %d %d\n",c,l,r);
		if(c=="A")
		{
//			auto it1=lower_bound(vec[0].bg(),vec[0].ed(),l);
//			while(it1!=vec[0].ed()&&*it1<=r)
//			{
//				vec[1].insert(upper_bound(vec[1].bg(),vec[1].ed(),*it1),*it1);
//				it1=vec[0].erase(it1);
//			}
//			auto it2=lower_bound(vec[2].bg(),vec[2].ed(),l);
//			while(it2!=vec[2].ed()&&*it2<=r)
//			{
//				vec[3].insert(upper_bound(vec[3].bg(),vec[3].ed(),*it2),*it2);
//				it2=vec[2].erase(it2);
//			}
			while(1)
			{
				auto it=mul1.lower_bound(l);
				if(it==mul1.ed()||*it>r) break;
				else
				{
					mul2.insert(*it);
					mul1.erase(it);
				}
			}
			while(1)
			{
				auto it=mul3.lower_bound(l);
				if(it==mul3.ed()||*it>r) break;
				else
				{
//					mul2.insert(*it);
					add(*it,1);
					mul3.erase(it);
				}
			}
		}
		else
		{
//			auto it1=lower_bound(vec[0].bg(),vec[0].ed(),l);
//			while(it1!=vec[0].ed()&&*it1<=r)
//			{
//				vec[2].insert(upper_bound(vec[2].bg(),vec[2].ed(),*it1),*it1);
//				it1=vec[0].erase(it1);
//			}
//			auto it2=lower_bound(vec[1].bg(),vec[1].ed(),l);
//			while(it2!=vec[1].ed()&&*it2<=r)
//			{
//				vec[3].insert(upper_bound(vec[3].bg(),vec[3].ed(),*it2),*it2);
//				it2=vec[1].erase(it2);
//			}
			while(1)
			{
				auto it=mul1.lower_bound(l);
				if(it==mul1.ed()||*it>r) break;
				else
				{
					mul3.insert(*it);
					mul1.erase(it);
				}
			}
			while(1)
			{
				auto it=mul2.lower_bound(l);
				if(it==mul2.ed()||*it>r) break;
				else
				{
//					mul2.insert(*it);
					add(*it,1);
					mul2.erase(it);
				}
			}
		}
//		cout<<mul1.sz()<<endl;
//		pr(mul2.sz());
//		pr(mul3.sz());
//		int pos1=upper_bound(vec[3].bg(),vec[3].ed(),r)-vec[3].bg();
//		int pos2=lower_bound(vec[3].bg(),vec[3].ed(),l)-vec[3].bg();
//		printf("%d\n%d\n",pos1,pos2);
//		for(int i=0;i<vec[0].sz();i++) printf("%d ",vec[0][i]);
//		printf("\n");
//		for(int i=0;i<vec[1].sz();i++) printf("%d ",vec[1][i]);
//		printf("\n");
//		for(int i=0;i<vec[2].sz();i++) printf("%d ",vec[2][i]);
//		printf("\n");
//		for(int i=0;i<vec[3].sz();i++) printf("%d ",vec[3][i]);
//		printf("\n");
//		printf("%d\n",sum(r)-sum(l-1));
		cout<<sum(n)-sum(0)<<endl;
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
/*
4
1111
0000
3
B 1 1
B 2 2
B 3 3
*/