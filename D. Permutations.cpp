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

struct node
{
	int num,pos;
}s[100010];
bool cmp(node x,node y)
{
	return x.num<y.num;
}
int n,k,f[100010],bh[100010];
bool judge()
{
	int cnt=0;
	while(f[1])
	{
		int i=1;
		while(f[i])
		{
			f[i]--;
			i++;
			cnt++;
		}
	}
	return cnt==n;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		s[i].num=k;
		s[i].pos=i;
		f[k]++;
	}
	sort(s+1,s+1+n,cmp);
	if(judge())
	{
		s[0].num=s[0].pos=0;
		int maxx=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i].num==s[i-1].num)
			{
				bh[s[i].pos]=bh[s[i-1].pos]+1;
				
			}
			else
			{
				bh[s[i].pos]=1;
			}
			maxx=max(maxx,bh[s[i].pos]);
		}
		cout<<maxx<<endl;
		for(int i=1;i<=n;i++) cout<<bh[i]<<" ";
	}
	else cout<<"-1"<<endl;
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