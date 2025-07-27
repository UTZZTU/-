#include <iostream>
using namespace std;
string s,t;
int pos1,pos2;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s>>t;
	for(int i=s.size()-1,j=t.size()-1;i>=0&&j>=0;i--,j--)
	{
		if(s[i]!='?'&&t[j]!='?'&&s[i]!=t[j])
		break;
		else
		pos2++;
	}
	for(int i=0,j=0;i<s.size()&&j<t.size();i++,j++)
	{
		if(s[i]!='?'&&t[j]!='?'&&s[i]!=t[j])
		break;
		else
		pos1++;
	}
	for(int i=1;i<=t.size()+1;i++)
	{
		if(i-1<=pos1&&(t.size()-i+1)<=pos2)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
	return 0;
}