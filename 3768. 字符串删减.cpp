#include <bits/stdc++.h>
using namespace std;
string u;
int n,res,ans;
int main ()
{
	cin>>n;
	getchar();
	cin>>u;
	for(int i=0;i<n;i++)
	{
		if(u[i]!='x')
		{
			res=0;
		}
		else
		{
			res++;
			if(res>=3)
			{
				res--;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}