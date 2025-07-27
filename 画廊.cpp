#include <bits/stdc++.h>
using namespace std;
//dp[左边i副][右边j副][0：已算好左边 1：已算好右边]
double dp[505][505][2];
double ld[505],rd[505];
double d,w;
int l,r;
double min(double x1,double x2)
{
    return x1>x2?x2:x1;
}
double dis(double x1,double x2,double w)
{
    return sqrt((x1-x2)*(x1-x2)+w*w);
}
int main()
{
    memset(dp,127,sizeof(dp));
    scanf("%d %d %lf %lf",&l,&r,&d,&w);
  
  for(int i=1;i<=l;i++) scanf("%lf",&ld[i]);
  
  for(int j=1;j<=r;j++) scanf("%lf",&rd[j]);

  //起点到左边第一幅画
  dp[1][0][0] = dis(ld[1],0,w/2);
  //起点到右边第一幅画
  dp[0][1][1] = dis(rd[1],0,w/2);

  for(int i=0;i<=l;i++)
    for(int j=0;j<=r;j++)
    {
      //dp[i-1][j][0]+ld[i]-ld[i-1]:同一边到左边第i副画
      //dp[i-1][j][1]+dis(rd[j],ld[i],w):另一边到左边第i副画
      if(i) dp[i][j][0]=min(dp[i][j][0],min(dp[i-1][j][0]+ld[i]-ld[i-1],dp[i-1][j][1]+dis(rd[j],ld[i],w)));
      //dp[i][j-1][1]+rd[j]-rd[j-1]:同一边到右边第i副画
      //dp[i][j-1][0]+dis(ld[i],rd[j],w)):另一边到右边第i副画
      if(j) dp[i][j][1]=min(dp[i][j][1],min(dp[i][j-1][1]+rd[j]-rd[j-1],dp[i][j-1][0]+dis(ld[i],rd[j],w)));
    }
  //                左边到终点                     右边到终点
  double res = min(dp[l][r][0]+dis(ld[l],d,w/2),dp[l][r][1]+dis(rd[r],d,w/2));
  printf("%0.2f",res); 
    return 0;
}