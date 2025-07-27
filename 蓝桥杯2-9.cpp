#include <bits/stdc++.h>
using namespace std;
int n,m,sum;
string a[110];
bool judge(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<n)
	return true;
	else
	return false;
}
int main ()
{
	cin>>n>>m;
	getchar();
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=1;;k++)
			{
				if(judge(i-k,j-k)&&judge(i-k,j+k)&&judge(i+k,j-k)&&judge(i+k,j+k)&&a[i-k][j-k]==a[i][j]&&a[i-k][j+k]==a[i][j]&&a[i+k][j-k]==a[i][j]&&a[i+k][j+k]==a[i][j])
				sum++;
				else
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}