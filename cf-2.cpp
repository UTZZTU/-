#include <bits/stdc++.h>
using namespace std;
int t;
int a[2][2];
bool flag;
bool judge()
{
	if(a[0][0]<a[0][1]&&a[1][0]<a[1][1]&&a[0][0]<a[1][0]&&a[0][1]<a[1][1])
	return true;
	else
	return false;
}
int main ()
{
	cin>>t;
	while(t--)
	{
		flag=false;
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			cin>>a[i][j];
		}
		for(int i=0;i<4;i++)
		{
			if(judge())
			{
				flag=true;
				break;
			}
			int t=a[0][0];
			a[0][0]=a[1][0];
			a[1][0]=a[1][1];
			a[1][1]=a[0][1];
			a[0][1]=t;
		}
		if(flag)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
	return 0;
}