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

int f[4]={0,1,2,3};
string s[3];
bool judge()
{
	map<char,int> mp;
	mp[f[1]-1+'A']=3;
	mp[f[2]-1+'A']=2;
	mp[f[3]-1+'A']=1;
	for(int i=0;i<3;i++)
	{
		char c1=s[i][0],c2=s[i][2];
		if(s[i][1]=='>')
		{
			if(mp[c1]<mp[c2]) return false;
		}
		else
		{
			if(mp[c1]>mp[c2]) return false;
		}
	}
	return true;
}
void solve()
{
	cin>>s[0]>>s[1]>>s[2];
	do
	{
		if(judge())
		{
			for(int i=3;i>=1;i--)
			{
				cout<<(char)(f[i]-1+'A');
			}
			return;
		}
	}while(next_permutation(f+1,f+4));
	cout<<"Impossible"<<endl;
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