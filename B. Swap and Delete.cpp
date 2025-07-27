#include <bits/stdc++.h>
using namespace std;
string s;
int num1,num2,res;
void solve()
{
	num1=num2=res=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0') num1++;
		else num2++;
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0')
		{
			if(num2) num2--,res++;
			else break;
		}
		else
		{
			if(num1) num1--,res++;
			else break;
		}
	}
	cout<<(int)s.size()-res<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
}