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
			if(u[i]>='0'&&u[i]<='9')
			{
				int res=0;
				while(i<u.size()&&u[i]>='0'&&u[i]<='9')
				{
					res=res*10+(u[i]-'0');
					i++;
				}
				string v;
				while(i<u.size()&&(u[i]>='a'&&u[i]<='z'||u[i]>='A'&&u[i]<='Z'))
				{
					v+=u[i];
					i++;
				}
				i--;
				for(int j=1;j<=res;j++)
				{
					cout<<v;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}