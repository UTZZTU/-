#include <bits/stdc++.h>
using namespace std;
string u,v;
int num;
void solve()
{
	cin>>u>>v;
	vector<char> vec;
	for(int i=0;i<u.size();i++)
	{
		if(u[i]=='0') num++;
		else vec.push_back(u[i]);
	}
	sort(vec.begin(),vec.end());
	string s="";
	if(vec.size())
	{
		s+=vec[0];
	}
	for(int i=1;i<=num;i++) s+='0';
	for(int i=1;i<vec.size();i++)
	{
		s+=vec[i];
	}
	if(s==v) cout<<"OK"<<endl;
	else cout<<"WRONG_ANSWER"<<endl;
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