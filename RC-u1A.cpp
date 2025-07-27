#include <bits/stdc++.h>
using namespace std;
int n,w,x1,x2,k;
int main ()
{
	cin>>n>>w;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		if(k>=35)
		{
			if(w==4) x2++;
			else x1++;
		}
		w++;
		w%=7;
		if(w==0) w=7;
	}
	cout<<x1<<" "<<x2;
	return 0;
}
