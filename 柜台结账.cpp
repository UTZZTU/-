#include <bits/stdc++.h>
using namespace std;
string a1,a2;
bool judgezero()
{
	for(int i=0;i<a2.size();i++)
	{
		if(a2[i]!='0')
		return false;
	}
	return true;
}
bool judgethan()
{
	if(a2[0]>='6'&&a2[0]<='9')
	return true;
	else if(a2[0]=='5')
	{
		for(int i=1;i<a2.size();i++)
		{
			if(a2[i]!='0')
			return true;
		}
		return false;
	}
	else
	return false;
}
bool judgeequal()
{
	for(int i=0;i<a2.size();i++)
	{
		if(i==0)
		{
			if(a2[i]!='5')
			return false;
		}
		else
		{
			if(a2[i]!='0')
			return false;
		}
	}
	return true;
}
int main ()
{
	cin>>a1>>a2;
	if(judgezero())
	{
		cout<<"PLMM";
	}
	else if(judgethan())
	{
		cout<<"Happy birthday to MFGG";
	}
	else if(judgeequal())
	{
		if((a1[a1.size()-1]-'0')&1)
		cout<<"Happy birthday to MFGG";
		else
		cout<<"Happy birthday to YXGG";
	}
	else
	{
		cout<<"Happy birthday to YXGG";
	}
	return 0;
}