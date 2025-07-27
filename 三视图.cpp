#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> mp1,mp2,mp3;
int x,y,z,n,a,b,c;
int main ()
{
	scanf("%d %d %d %d",&x,&y,&z,&n);
	while(n--)
	{
		scanf("%d %d %d",&a,&b,&c);
		mp1[{a,b}]=1;
		mp2[{a,c}]=1;
		mp3[{b,c}]=1;
	}
	for(int j=y;j>=1;j--)
	{
		for(int i=1;i<=x;i++)
		{
			if(mp1.count({i,j}))
			cout<<"x";
			else
			cout<<".";
		}
		cout<<" ";
		for(int k=1;k<=z;k++)
		{
			if(mp3.count({j,k}))
			cout<<"x";
			else
			cout<<".";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int k=1;k<=z;k++)
	{
		for(int i=1;i<=x;i++)
		{
			if(mp2.count({i,k}))
			cout<<"x";
			else
			cout<<".";
		}
		cout<<endl;
	}
	return 0;
}