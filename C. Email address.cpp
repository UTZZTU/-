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

string s;
void solve()
{
	cin>>s;
	string u;
	int num=0;
	u+=s[0];
	for(int i=1;i<s.sz();i++)
	{
		if(s[i]=='d')
		{
			if(i+1<s.sz()&&s[i+1]=='o'&&i+2<s.sz()-1&&s[i+2]=='t')
			{
				u+='.';
				i+=2;
			}
			else
			{
				u+=s[i];
			}
		}
		else if(s[i]=='a'&&!num)
		{
			if(i+1<s.sz()-1&&s[i+1]=='t')
			{
				num++;
				u+='@';
				i++;
			}
			else u+=s[i];
		}
		else
		{
			u+=s[i];
		}
	}
	cout<<u<<endl;
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