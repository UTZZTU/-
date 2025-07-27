#include <bits/stdc++.h>
using namespace std;
int t,n,flag,x,y;
string u;
int main ()
{
	cin>>t;
	while(t--)
	{
		flag=0,x=y=0;
		cin>>n;
		getchar();
		cin>>u;
		for(int i=0;i<u.size();i++)
		{
			if(u[i]=='L')
			x--;
			else if(u[i]=='R')
			x++;
			else if(u[i]=='U')
			y++;
			else
			y--;
			if(x==1&&y==1)
			{
				flag=1;
				break;
			}
		}
		if(flag)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
	return 0;
}