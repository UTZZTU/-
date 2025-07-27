#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d,k,ans,f[100],s[100],num;
map<vector<ll>,int> mp;
string u;
int get_long(int n)
{
	int res=0;
	while(n)
	{
		res++;
		n/=10;
	}
	return res;
}
int main ()
{
	cin>>d>>k;
	for(int i=1;i<=k;i++)
	cin>>f[i];
	for(int i=1;i<=k;i++)
	s[i]=i;
	do
	{
		num=0;
		for(int i=1;i<=k;i++)
		{
			num=num*(ll)pow(10,get_long(f[s[i]]))+f[s[i]];
			num%=d;
		}
		if(!num)
		{
			vector<ll> vec;
			for(int i=1;i<=k;i++)
			vec.push_back(f[s[i]]);
			if(!mp.count(vec))
			{
				mp[vec]=1;
				ans++;
			}
		}
	}while(next_permutation(s+1,s+1+k));
	cout<<ans;
	return 0;
}