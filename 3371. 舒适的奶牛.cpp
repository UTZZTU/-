#include <bits/stdc++.h>
using namespace std;
int ans,n;
int f[1010][1010];
int main ()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;i++)
	{
		scanf("%d %d",&x,&y);
		x++;
		y++;
		f[x][y]=1;
		if(f[x-1][y])
		{
			if(f[x-2][y]+f[x-1][y+1]+f[x-1][y-1]==3)
			ans--;
			else if(f[x-2][y]+f[x-1][y+1]+f[x-1][y-1]==2)
			ans++;
		}
		if(f[x+1][y])
		{
			if(f[x+2][y]+f[x+1][y+1]+f[x+1][y-1]==3)
			ans--;
			else if(f[x+2][y]+f[x+1][y+1]+f[x+1][y-1]==2)
			ans++;
		}
		if(f[x][y-1])
		{
			if(f[x][y-2]+f[x-1][y-1]+f[x+1][y-1]==3)
			ans--;
			else if(f[x][y-2]+f[x-1][y-1]+f[x+1][y-1]==2)
			ans++;
		}
		if(f[x][y+1])
		{
			if(f[x][y+2]+f[x-1][y+1]+f[x+1][y+1]==3)
			ans--;
			else if(f[x][y+2]+f[x-1][y+1]+f[x+1][y+1]==2)
			ans++;
		}
		if(f[x-1][y]+f[x+1][y]+f[x][y+1]+f[x][y-1]==3)
		ans++;
		cout<<ans<<endl;
	}
	return 0;
}