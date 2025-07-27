#include <bits/stdc++.h>
using namespace std;
string u,v;
void solve()
{
	cin>>u;
	int pos=u.find('@');
	if(pos==-1)
	{
		cout<<"No solution"<<endl;
		return;
	}
	if(u[0]=='@'||u[u.size()-1]=='@')
	{
		cout<<"No solution"<<endl;
		return;
	}
	int i=0;
	while(u[i]!='@')
	{
		v+=u[i];
		i++;
	}
	for(i;i<u.size();i++)
	{
		v+=u[i];
		int j=i+1;
		while(j<u.size()&&u[j]!='@')
		{
			j++;
		}
		j--;
		if(j==u.size()-1)
		{
			for(int k=i+1;k<=j;k++)
			{
				v+=u[k];
			}
			break;
		}
		else if(j-i<=1)
		{
			cout<<"No solution"<<endl;
			return;
		}
		else
		{
			int k=i+1;
			v+=u[k];
			v+=',';
			k++;
			for(k;k<=j;k++)
			{
				v+=u[k];
			}
			i=j;
		}
	}
	cout<<v<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}