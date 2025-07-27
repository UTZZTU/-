#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,k,res;
string n;
queue<char> q;
bool judge(ll x)
{
	if(x==1)
	return false;
	if(x==2||x==3)
	return true;
	if(x%6!=1&&x%6!=5)
	return false;
	else{
		for(int i=5;i<=floor(sqrt(x));i+=6)
		{
			if(x%i==0||x%(i+2)==0)
			return false;
		}
		return true;
	}
}
int main ()
{
	cin>>l>>k;
	getchar();
	cin>>n;
	if(l<k)
	{
		cout<<404;
		return 0;
	}
	else
	{
		int i=0;
		for(i;i<k;i++)
		{
			res=res*10+(n[i]-'0');
			q.push(n[i]);
		}
		if(judge(res))
		{
			while(!q.empty())
			{
				cout<<q.front();
				q.pop();
			}
			return 0;
		}
		for(i;i<n.size();i++)
		{
			res=res%(ll)pow(10,k-1);
			res=res*10+(n[i]-'0');
			q.pop();
			q.push(n[i]);
			if(judge(res))
		    {
				while(!q.empty())
				{
					cout<<q.front();
					q.pop();
				}
				return 0;
			}
		}
		cout<<404;
	}
	return 0;
}