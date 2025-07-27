#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
#define  INF 0x3f3f3f3f
const  int MAXN=200100;
double a[MAXN];
double maxx;
int main()
{
      int n;
      while(scanf("%d",&n)!=EOF)
      {
          maxx=-INF;
           for(int i=0;i<n;i++)
           scanf("%lf",&a[i]);
          for(int i=1;i<n;i++)
           maxx=max(a[i]-a[i-1],maxx);
          printf("%.2f\n",maxx);
      }
    return 0;
}