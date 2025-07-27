#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100005
using namespace std;
int a[N];
int main()
{
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	int n,i,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		if(a[i]>a[i-1])  ans+=a[i]-a[i-1];
	}
	printf("%d",ans);
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
