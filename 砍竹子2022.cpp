#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long h[200001][8];

long long sum(long long n)
{
  long long res;
  res=sqrtl(n/2+1);
  return res;
}

int main(int argc, char *argv[])
{
  long long n,i,j,res=0,k;
  scanf("%lld",&n);
  for(i=0;i<n;i++){
    scanf("%lld",&h[i][0]);
    for(j=1;h[i][j-1]>1;j++){
      h[i][j]=sum(h[i][j-1]);
      res++;
    }
  }
  for(i=0;i<n-1;i++){
    for(j=0;h[i][j]!=1;j++){
      for(k=0;h[i+1][k]!=1;k++){
          if(h[i][j]==h[i+1][k]){
              res--;
              break;
        }
      }
    }
  }
  printf("%lld",res);
  return 0;
}