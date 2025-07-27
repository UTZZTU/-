#include <bits/stdc++.h>
using namespace std;
#define int long long
string l,r,u;
int num1,num2,num3;
int get_num(string s)
{
	int res=0,k=1;
	for(int i=s.size()-1;i>=0;i--)
	{
		if(s[i]=='1') res+=k;
		k*=2;
	}
	return res;
}
string get_str(int x)
{
	string v;
	while(x)
	{
		if(x&1) v+="1";
		else v+="0";
		x>>=1;
	}
	reverse(v.begin(),v.end());
	return v;
}
signed main ()
{
	cin>>l>>r;
	num1=get_num(l);
	num2=get_num(r);
	num3=(long long)pow(num1,num2);
// 	u=get_str(num3);
	cout<<num1<<" "<<num2<<" "<<num3;
	return 0;
}