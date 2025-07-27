#include <bits/stdc++.h>
using namespace std;
string s,u,v;
int flag1,flag2;
bool judge(string s,string u,string v)
{
	int pos1=s.find(u);
	if(pos1==-1) return false;
	int pos2=s.find(v,pos1+u.size());
	if(pos2==-1) return false;
	return true;
}
void solve()
{
	cin>>s>>u>>v;
//	cout<<s<<u<<v<<endl;
	if(judge(s,u,v)) flag1=1;
	reverse(s.begin(),s.end());
	if(judge(s,u,v)) flag2=1;
	if(flag1&&flag2) cout<<"both"<<endl;
	else if(flag1) cout<<"forward"<<endl;
	else if(flag2) cout<<"backward"<<endl;
	else cout<<"fantasy"<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}