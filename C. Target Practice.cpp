#include <bits/stdc++.h>
using namespace std;
int t,res,maxx;
string s[10];
int main ()
{
	cin>>t;
	while(t--)
	{
		res=0;
		for(int i=0;i<=9;i++)
		{
			cin>>s[i];
		}
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				if(s[i][j]!='X') continue;
				int x=i+1,y=j+1;
				maxx=max(x,max(y,max(10-x+1,10-y+1)));
				res+=10-maxx+1;
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}