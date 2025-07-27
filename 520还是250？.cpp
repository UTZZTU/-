#include <bits/stdc++.h>
using namespace std;
string u;
int res1,res2,pre0[510],pre2[510],pre5[510];
int main ()
{
	cin>>u;
	for(int i=0;i<u.size();i++)
	{
		if(u[i]=='0')
		{
			pre0[i+1]=1;
		}
		else if(u[i]=='2')
		{
			pre2[i+1]=1;
		}
		else pre5[i+1]=1;
		pre0[i+1]+=pre0[i];
		pre2[i+1]+=pre2[i];
		pre5[i+1]+=pre5[i];
	}
	for(int i=0;i<u.size();i++)
	{
		if(u[i]=='2')
		{
			res1+=pre5[i]*(pre0[u.size()]-pre0[i+1]);
		}
		else if(u[i]=='5')
		{
			res2+=pre2[i]*(pre0[u.size()]-pre0[i+1]);
		}
	}
	cout<<res1<<" "<<res2<<endl;
	if(res1>res2) cout<<"Yes";
	else cout<<"No";
	return 0;
}