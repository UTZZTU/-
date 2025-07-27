#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,num,pos;
vector<int> vec;
vector<string> v;
void solve(string s)
{
	for(int i=7;i>=0;i--)
	{
		num+=(ll)(s[i]-'0')*(ll)pow((ll)2,pos);
		pos++;
	}
}
int main ()
{
	cin>>x;
	while(x)
	{
		if(x%2) vec.push_back(1);
		else vec.push_back(0);
		x/=2;
	}
	while(vec.size()<32)
	{
		vec.push_back(0);
	}
	reverse(vec.begin(),vec.end());
	string x;
//	cout<<vec.size()<<endl;
	for(int i=0;i<32;i++)
	{
		if(vec[i]==0)
		{
			x+="0";
		}
		else
		{
			x+="1";
		}
		if(x.size()==8)
		{
			v.push_back(x);
			x.clear();
		}
	}
//	cout<<v.size()<<endl;
	sort(v.begin(),v.end());
	for(int i=0;i<4;i++)
	{
		solve(v[i]);
//		cout<<num<<endl;
	}
	cout<<num;
	return 0;
}