#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int n;
double a[N][N],b[N][N];
void guass()
{
	for(int r=1,c=1;c<=n;r++,c++)
	{
		int t=r;
		for(int i=r+1;i<=n;i++)
		{
			if(fabs(b[i][c])>fabs(b[t][c]))
			t=i;
		}
		for(int i=c;i<=n+1;i++) swap(b[t][i],b[r][i]);
		for(int i=n+1;i>=c;i--) b[r][i]/=b[r][c];
		for(int i=r+1;i<=n;i++)
		{
			for(int j=n+1;j>=c;j--)
			{
				b[i][j]-=b[i][c]*b[r][j];
			}
		}
	}
	for(int i=n;i>1;i--)
	{
		for(int j=i-1;j>=1;j--)
		{
			b[j][n+1]-=b[j][i]*b[i][n+1];
		}
	}
}
int main ()
{
	cin>>n;
	for(int i=0;i<n+1;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			b[i][j]=2*(a[i][j]-a[0][j]);
			b[i][n+1]+=a[i][j]*a[i][j]-a[0][j]*a[0][j];
		}
	}
	guass();
	for(int i=1;i<=n;i++) printf("%.3f ",b[i][n+1]);
	return 0;
}