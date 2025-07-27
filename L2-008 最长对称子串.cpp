#include <bits/stdc++.h>
using namespace std;
int maxn=1;
int main ()
{
	string u;
	getline(cin,u);
	for(int i=0;i<u.size();i++)
	{
		int q=i-1,h=i+1;
		int js=1;
		while(q>=0&&h<u.size()&&u[q]==u[h])
		{
			js+=2;
			q--;
			h++;
		}
		maxn=max(maxn,js);
		q=i,h=i+1,js=0;
		while(q>=0&&h<u.size()&&u[q]==u[h])
		{
			js+=2;
			q--;
			h++;
		}
		maxn=max(maxn,js);
		q=i-1,h=i,js=0;
		while(q>=0&&h<u.size()&&u[q]==u[h])
		{
			js+=2;
			q--;
			h++;
		}
		maxn=max(maxn,js);
	}
	cout<<maxn;
	return 0;
}