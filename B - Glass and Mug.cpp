#include <bits/stdc++.h>
using namespace std;
int k,g,m,f1,f2;
int main ()
{
	cin>>k>>g>>m;
	while(k--)
	{
		if(f1==g)
		{
			f1=0;
		}
		else if(f2==0)
		{
			f2=m;
		}
		else
		{
			int x=min(g-f1,f2);
			f2-=x;
			f1+=x;
		}
	}
	cout<<f1<<" "<<f2;
	return 0;
}