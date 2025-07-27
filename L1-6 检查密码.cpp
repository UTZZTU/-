#include <bits/stdc++.h>
using namespace std;
int n;
string s;
void judge()
{
	int res1=0,res2=0;
	if(s.size()<6)
	{
		cout<<"Your password is tai duan le."<<endl;
		return;
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z')
		{
			res1=1;
		}
		else if(s[i]>='0'&&s[i]<='9')
		{
			res2=1;
		}
		else if(s[i]=='.')
		{
			;
		}
		else
		{
			cout<<"Your password is tai luan le."<<endl;
			return;
		}
	}
	if(res1&&!res2)
	{
		cout<<"Your password needs shu zi."<<endl;
		return;
	}
	if(!res1&&res2)
	{
		cout<<"Your password needs zi mu."<<endl;
		return;
	}
	if(res1&&res2)
	{
		cout<<"Your password is wan mei."<<endl;
		return;
	}
}
int main ()
{
	cin>>n;
	getchar();
	while(n--)
	{
		getline(cin,s);
		judge();
	}
	return 0;
}