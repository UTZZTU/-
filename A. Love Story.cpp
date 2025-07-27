#include <bits/stdc++.h>
using namespace std;
int t;
string u,v="codeforces";
int main ()
{
	cin>>t;
	getchar();
	while(t--)
	{
		int res=0;
		cin>>u;
		for(int i=0;i<10;i++)
		{
			if(u[i]!=v[i]) res++;
		}
		printf("%d\n",res);
	}
	return 0;
}