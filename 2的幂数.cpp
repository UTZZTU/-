#include<cstdio>
int f[1010];
int main(){
   int n;
   scanf("%d",&n);
   f[1]=1;
   for(int i=2;i<=n;i++){
    if(i%2!=0) f[i]=f[i-1];
    else f[i]=f[i-1]+f[i/2];
   }
   printf("%d\n",f[n]);
   return 0;
}
