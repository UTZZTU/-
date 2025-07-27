#include <bits/stdc++.h>
using namespace std;
int t;
string u;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>u;
		string v;
		int len=0;
		for(int i=0;i<u.size();i++)
		{
			if(len==0)
			{
				if(u[i]=='^')
				{
					v+=u[i];
					len++;
				}
				else
				{
					v+='^';
					v+=u[i];
					len+=2;
				}
			}
			else
			{
				if(u[i]=='^')
				{
					v+=u[i];
					len++;
				}
				else
				{
					if(v[len-1]=='^')
					{
						v+=u[i];
						len++;
					}
					else
					{
						v+='^';
						v+=u[i];
						len+=2;
					}
				}
			}
		}
		if(v[len-1]=='_') v+='^';
		if(len==1&&v[len-1]=='^') v+='^';
//		cout<<v<<endl;
		cout<<v.size()-u.size()<<endl;
	}
	return 0;
}