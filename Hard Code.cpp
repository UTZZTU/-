#include <bits/stdc++.h>
using namespace std;
int t,n,m;
string u;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		getchar();
		getline(cin,u);
		for(int i=0;i<u.size();i++)
		{
			if((i+1)%m==0)
			cout<<u[i]<<endl;
			else
			cout<<u[i];
		}
	}
	return 0;
}