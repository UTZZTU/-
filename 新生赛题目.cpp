#include <bits/stdc++.h>
using namespace std;
int n,x,res;
string s,u;
bool judge(string u)
{
	int ans=0,pos=u.size()-1;
	for(int i=pos;i>=0;i--)
	{
		if(u[i]==u[pos])
		ans++;
		else
		break;
		if(ans>=x)
		return true;
	}
	return ans>=x;
}
int main ()
{
	cin>>n>>x;
	getchar();
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		u+=s[i];
		if(u.size()>=x&&judge(u))
		{
			u.erase(u.size()-x,x);
			res++;
		}
	}
	if(res&1)
	cout<<"Fang is winner";
	else
	cout<<"Liang is winner";
	return 0;
}