#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <math.h>
#include <stdio.h>
#define mem(a) memset(a,0,sizeof(a))
#define maxn 1025
using namespace std;
int a[maxn];
int main(){
     ios::sync_with_stdio(0);
    int m,n,k;
     scanf("%d",&m);
     while(m--){
        scanf("%d%d",&n,&k);
         int j=0;
         mem(a);
         for(int i=0;i<n;++i){
             scanf("%d",&a[i]);
         }
         while(k--){
            next_permutation(a,a+n);
         }
         for(int i=0;i<n;i++){
             if(i!=0)
                 printf(" ");
             printf("%d",a[i]);
         }
        printf("\n");
     }
     return 0;
 }
