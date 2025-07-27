#include <bits/stdc++.h>
using namespace std;
const double Eps = 1e-8;
const double PI = atan(-1.0);
const int N = 1e5+5;
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
#define pr(x) cout<<x<<endl

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;

//struct node
//{
//	int num,pos;
//}S[N];
//
//bool cmp(node x,node y)
//{
//	return x.num<y.num;
//}

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

VI vec;
VI link[200005];
struct Edge
{
	int u,v,w;
}edge[200005];
int fa[200005],n,m,eu,ev,pre[200005],cnt,pp[200005],vis[200005];
void bfs(int p1,int p2)
{
	VI vf;
	queue<pair<int,int>> q;
	q.push({p1,-1});
	while(!q.empty())
	{
		auto [u,v]=q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		if(v!=-1) pre[u]=v;
		if(u==p2) break;
		for(int i=0;i<link[u].sz();i++)
		{
			if(!vis[link[u][i]])
			{
				q.push({link[u][i],u});
			}
		}
	}
	int pos=p2;
	while(pre[pos]!=pos)
	{
		vf.emplace_back(pos);
		pos=pre[pos];
	}
	vf.emplace_back(pos);
	vec=vf;
}
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
int find(int x)
{
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}
bool kruskal(int num)
{
    for(int i=1;i<=n;i++)
    {
    	fa[i]=i;
    	link[i].clear();
    	pre[i]=i;
    	vis[i]=0;
	}
	int pos=lower_bound(pp+1,pp+1+m,num)-pp;
	int flag=0;
    for(int i=pos;i<=m;i++)
    {
        eu=find(edge[i].u), ev=find(edge[i].v);
        int uu=edge[i].u,vv=edge[i].v;
        if(eu==ev)
        {
        	flag=1;
        	bfs(uu,vv);
            break;
        }
        fa[ev]=eu;
        link[uu].emplace_back(vv);
        link[vv].emplace_back(uu);
    }
    if(flag)
    {
    	return true;
	}
	else return false;
}
bool check(int x)
{
	if(kruskal(x)) return true;
	else return false;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		pp[i]=edge[i].w;
	}
	int l=1,r=1000000;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	pr(l);
	cout<<vec.sz()<<endl;
	for(auto x:vec) cout<<x<<" ";
	cout<<endl;
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