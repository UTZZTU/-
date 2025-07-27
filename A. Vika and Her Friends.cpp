#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,k1,k2,flag;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		flag=0;
		cin>>x>>y;
		while(k--)
		{
			cin>>k1>>k2;
			if((abs(x-k1)+abs(y-k2))%2==0) flag=1;
		}
		if(flag) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}
/*
-1 0 0 0 -1
0 0 0 0 0
0 0 1 0 0
0 0 0 0 0
-1 0 0 0 -1
*/