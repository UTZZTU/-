#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int t,n,s;
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		int res1=0,res2=0,flag1=0,flag2=0;
		for(int i=1;i<=n;i++)
		{
			int r,c;
			cin>>r>>c;
			if(r==1) res1++;
			res2+=c;
		}
		if(res1*2>=n) flag1=1;
		if(res2>=s+50) flag2=1;
		cout<<flag1<<" "<<flag2<<endl;
	}
	return 0;
}
