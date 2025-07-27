#include <bits/stdc++.h>
using namespace std;
int t,n,m,cnt;
string x,s;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		cin>>x;
		cin>>s;
		cnt=0;
		while(n<=2*m&&x.find(s)==-1)
		{
			x=x+x;
			n*=2;
			cnt++;
		}
		if(cnt==0&&x.find(s)==-1)
		{
			cnt++;
			x=x+x;
		}
		if(x.find(s)!=-1) cout<<cnt<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}