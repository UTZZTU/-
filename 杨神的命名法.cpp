#include <bits/stdc++.h>
using namespace std;
int t;
string u;
int main ()
{
	cin>>t;
	getchar();
	while(t--)
	{
		cin>>u;
		for(int i=0;i<u.size();i++)
		{
			if(u[i]>='A'&&u[i]<='Z')
			{
				u[i]+=32;
				if(i!=0)
				{
					u[i-1]-=32;
				}
			}
		}
		u[u.size()-1]-=32;
		cout<<u<<endl;
	}
	return 0;
}