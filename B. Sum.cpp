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
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;

int a,b;
int get_max(int a,int b)
{
	int maxx=0;
	while(a)
	{
		maxx=max(maxx,a%10);
		a/=10;
	}
	while(b)
	{
		maxx=max(maxx,b%10);
		b/=10;
	}
	return maxx+1;
}
int get_len(int a,int b,int p)
{
	int res=0;
	int pp=1;
	while(a)
	{
		res+=(a%10)*pp;
		pp*=p;
		a/=10;
	}
	pp=1;
	while(b)
	{
		res+=(b%10)*pp;
		pp*=p;
		b/=10;
	}
	int cnt=0;
	while(res)
	{
		res/=p;
		cnt++;
	}
	return cnt;
}
void solve()
{
	cin>>a>>b;
	int maxx=get_max(a,b);
	int len=get_len(a,b,maxx);
	cout<<len<<endl;
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