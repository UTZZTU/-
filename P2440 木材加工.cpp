#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int h[100010],n,k,l=0,r=100000001,mid;
ll sum;
bool check(int e)
{
	int tot=0;
	for(int i=1;i<=n;i++)
	tot+=h[i]/e;
	return tot>=k;
}
int main ()
{
  cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
  	scanf("%d",&h[i]);
  	sum+=h[i];
  }
  if(sum<k)
  {
  	printf("0");
  	return 0;
  }
  while(r-l>0)
  {
  	mid=ceil((r+l)*1.0/2);
  	if(check(mid))
  	l=mid;
  	else
  	r=mid-1;
  }
  printf("%d",l);
  return 0;
}