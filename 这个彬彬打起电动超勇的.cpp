#include <bits/stdc++.h>
using namespace std;
int t,t1,t2,t3,t4,n,k,flag=0;
int main ()
{
	cin>>t;
	while(t--)
	{
		flag=0;
		int f[2000]={0};
		cin>>t1>>t2>>t3>>t4;
		for(int i=t1;i<=t2;i++)
		f[i]=1;
		for(int i=t3;i<=t4;i++)
		f[i]=1;
		cin>>n;
		while(n--)
		{
			cin>>k;
			if(f[k])
			flag=1;
		}
		if(flag)
		cout<<"Y"<<endl;
		else
		cout<<"N"<<endl;
	}
	return 0;
}