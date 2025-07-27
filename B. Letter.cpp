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

string u,v;
int s[26],S[26];
void solve()
{
	getline(cin,u);
	getline(cin,v);
	for(auto c:u)
	{
		if(c==' ') continue;
		if(c>='a'&&c<='z') s[c-'a']++;
		else S[c-'A']++;
	}
	for(auto c:v)
	{
		if(c==' ') continue;
		if(c>='a'&&c<='z')
		{
			s[c-'a']--;
			if(s[c-'a']<0)
			{
				cout<<"NO"<<endl;
				return;
			}
		}
		else
		{
			S[c-'A']--;
			if(S[c-'A']<0)
			{
				cout<<"NO"<<endl;
				return;
			}
		}
	}
	cout<<"YES"<<endl;
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