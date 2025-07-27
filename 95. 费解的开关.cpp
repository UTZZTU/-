#include <bits/stdc++.h>
using namespace std;
string a[5],b[5];
int n,dx[5]={0,0,0,1,-1},dy[5]={0,1,-1,0,0};
void turn(int x,int y)
{
	for(int i=0;i<5;i++)
	{
		int da=x+dx[i],db=y+dy[i];
		if(da>=0&&da<5&&db>=0&&db<5)
		{
			a[da][db]='0'+('1'-a[da][db]);
		}
	}
}
int work()
{
	int minn=1000000,res,flag=1;
	for(int i=0;i<32;i++)
	{
		res=0,flag=1;
		for(int j=0;j<5;j++)
		b[j]=a[j];
		for(int j=0;j<5;j++)
		{
			if(i>>j&1)
			{
				res++;
				turn(0,j);
			}
		}
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<5;k++)
			{
				if(a[j][k]=='0')
				{
					res++;
					turn(j+1,k);
				}
			}
		}
		for(int j=0;j<5;j++)
		{
			if(a[4][j]=='0')
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			minn=min(minn,res);
		}
		for(int j=0;j<5;j++)
		a[j]=b[j];
	}
	if(minn>6) return -1;
	return minn;
}
int main ()
{
	cin>>n;
	getchar();
	while(n--)
	{
		for(int i=0;i<5;i++)
		cin>>a[i];
		cout<<work()<<endl;
	}
	return 0;
}