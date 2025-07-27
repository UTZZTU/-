#include <stdio.h>
int main()
{
  int n,k,i,j=0;
  scanf("%d %d",&n,&k);
  for(i=1; i<=n; i++)
  {
    j=(j+k)%i;
  }
  j++;
  printf("%d",j);
  return 0;
}