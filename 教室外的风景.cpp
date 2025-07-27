#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
bool cmp(int a,int b)
{
	if(abs(a)==abs(b))return a<b;
	return abs(a)<abs(b);
}
int main ()
{
	int n,a,b,c[200010],i,m,sum=0,ll=0;
	scanf("%d",&n);
	m=0;
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		c[m]=a;
		m++;
		c[m]=-(b+1);
		m++;
	}
	sort(c,c+m,cmp);
	for(i=0;i<m;i++)
	{
		if(c[i]<0)
		sum--;
		else
		sum++;
		if(sum>ll)
		ll=sum;
	}
	printf("%d",ll);
    return 0;
}
