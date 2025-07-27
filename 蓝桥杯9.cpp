#include <bits/stdc++.h>
using namespace std;
string a[110];
int n,m,k,sum;
bool judge(int x,int y)
{
	if(x<0||x>=n||y<0||y>=m)
	return false;
	else
	return true;
}
int main ()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=1;k<=4;k++)
			{
				if(k==1)
				{
					for(int p1=i-1,p2=j+1;judge(i,p2)&&judge(p1,j)&&a[i][p2]==a[i][j]&&a[p1][j]==a[i][j];p1--,p2++)
					{
						int ans=0,q1=p1,q2=j;
						while(q1!=i&&q2!=p2)
						{
							if(a[q1][q2]==a[i][j])
							q1++,q2++;
							else
							break;
						}
						if(q1==i&&q2==p2)
						sum++;
					}
				}
				else if(k==2)
				{
					for(int p1=i+1,p2=j+1;judge(i,p2)&&judge(p1,j)&&a[i][p2]==a[i][j]&&a[p1][j]==a[i][j];p1++,p2++)
					{
						int ans=0,q1=p1,q2=j;
						while(q1!=i&&q2!=p2)
						{
							if(a[q1][q2]==a[i][j])
						    q1--,q2++;
							else
							break;
						}
						if(q1==i&&q2==p2)
						sum++;
					}
				}
				else if(k==3)
				{
					for(int p1=i+1,p2=j-1;judge(i,p2)&&judge(p1,j)&&a[i][p2]==a[i][j]&&a[p1][j]==a[i][j];p1++,p2--)
					{
						int ans=0,q1=p1,q2=j;
						while(q1!=i&&q2!=p2)
						{
							if(a[q1][q2]==a[i][j])
							q1--,q2--;
							else
							break;
						}
						if(q1==i&&q2==p2)
						sum++;
					}
				}
				else if(k==4)
				{
					for(int p1=i-1,p2=j-1;judge(i,p2)&&judge(p1,j)&&a[i][p2]==a[i][j]&&a[p1][j]==a[i][j];p1--,p2--)
					{
						int ans=0,q1=p1,q2=j;
						while(q1!=i&&q2!=p2)
						{
							if(a[q1][q2]==a[i][j])
							q1++,q2--;
							else
							break;
						}
						if(q1==i&&q2==p2)
						sum++;
					}
				}
			}
		}
	}
	cout<<sum;
	return 0;
}