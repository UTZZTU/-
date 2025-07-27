#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n;
bool num(vector<int> vec, int l, int r)
{
	ll x=0;
	for(int i=0;i<vec.size();i++)
	{
		if(i<vec.size()-r||i>vec.size()-l)
		x=x*10+vec[i];
	}
	if(x%4==0)
	return true;
	else
	return false;
}
bool judge(ll x)
{
	vector<int> vec;
	while(x)
	{
		vec.push_back(x%10);
		x/=10;
	}
	reverse(vec.begin(),vec.end());
	if(vec.size()==1)
	{
		return false;
	}
	for(int i=1;i<=vec.size();i++)
	{
		int j=vec.size();
		if(i==1)
		j--;
		for(int k=i;k<=j;k++)
		{
			if(num(vec,i,k))
			return true;
		}
	}
	return false;
}
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n%4==0||judge(n))
		{
			cout<<"Yes"<<endl;
		}
		else
		cout<<"No"<<endl;
	}
	return 0;
}