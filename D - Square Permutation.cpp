#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <set>
using namespace std;
typedef long long ll;
set<ll> st;
ll n,f[10],cnt;
string s;
bool check(ll num)
{
	cnt=0;
	int pos[10]={0};
	if(num==0) pos[num]++,cnt++;
	while(num)
	{
		pos[num%10]++;
		num/=10;
		cnt++;
	}
	while(cnt<n)
	{
		pos[0]++;
		cnt++;
	}
	for(int i=0;i<10;i++)
	{
		if(pos[i]!=f[i]) return false;
	}
	return true;
}
int main ()
{
	cin>>n;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		f[s[i]-'0']++;
	}
	for(ll i=0;i<=1e7;i++)
	{
		ll num=i*i;
		if(check(num))
		{
			st.insert(num);
//			cout<<i<<endl;
		}
	}
	cout<<st.size();
	return 0;
}