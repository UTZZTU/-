#include <bits/stdc++.h>
using namespace std;
string s;
int q,l,r,flag;
bool judge(string t)
{
	for(int i=t.size()-1;i>=0;i--)
	{
		if(t[i]!='a')
		{
			t[i]-=1;
			cout<<t<<endl;
			if(s.find(t)!=-1)
			return true;
			else
			return false;
		}
		else
		t[i]='z';
	}
	cout<<"NULL"<<endl;
	return false;
}
int main ()
{
	cin>>s;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&l,&r);
		string t=s.substr(l-1,r-(l-1));
		if(judge(t))
		{
			cout<<"Happy New Year!"<<endl;
		}
		else
		{
			cout<<"Happy Chinese New Year!"<<endl;
		}
	}
	return 0;
}