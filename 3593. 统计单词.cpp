#include <bits/stdc++.h>
using namespace std;
int ans,st;
string u;
int main ()
{
	getline(cin,u);
	for(int i=0;i<u.size();i++)
	{
		if(u[i]=='.')
		{
			printf("%d ",ans);
			break;
		}
		else if(u[i]==' '&&st==1)
		{
			printf("%d ",ans);
			ans=0;
			st=0;
		}
		else if(u[i]>='a'&&u[i]<='z')
		{
			ans++;
			st=1;
		}
	}
	return 0;
}