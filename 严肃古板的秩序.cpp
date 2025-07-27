#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> vec;
vector<char> vect;
ll number,flag,num;
string s;
ll fast_power(ll a, ll b, ll p)
{
	ll res=1;
	while(b)
	{
		if(b&1)
		res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
void dfs(ll level,ll res)
{
	if(flag)
	return;
	if(level>=vec.size())
	{
		if(res==number)
		{
			flag=1;
			for(int i=0;i<vec.size();i++)
			{
				cout<<vec[i];
				if(i==vec.size()-1)
				cout<<"=";
				else
				cout<<vect[i];
			}
			cout<<number;
			return;
		}
	}
	else
	{
		vect.push_back('+');
		dfs(level+1,res+vec[level]);
		vect.pop_back();
		vect.push_back('-');
		dfs(level+1,res-vec[level]);
		vect.pop_back();
		if(res>0&&vec[level]>0)
		{
			vect.push_back('#');
		    dfs(level+1,fast_power(res%vec[level],res,vec[level]));
		    vect.pop_back();
		}
		
	}
}
int main ()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int j=i;
			while(j<s.size()&&s[j]>='0'&&s[j]<='9')
			{
				num=num*10+(s[j]-'0');
				j++;
			}
			i=j-1;
		}
		else
		{
			vec.push_back(num);
			num=0;
		}
	}
	number=num;
	dfs((ll)1,vec[0]);
	if(!flag)
	cout<<"-1";
	return 0;
}