#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int a[3];
	for(int i=0;i<3;i++)
	cin>>a[i];
	sort(a,a+3);
	int x,y,z;
	x=a[0],y=a[1],z=a[2];
	int minn;
	if(y-x-1==0&&z-y-1==0)
	minn=0;
	else if(y-x-1==1||z-y-1==1)
	minn=1;
	else
	minn=2;
	cout<<minn<<endl;
	x=a[0],y=a[1],z=a[2];
	int maxn=max(y-x-1,z-y-1);
	cout<<maxn<<endl;
	return 0;
}