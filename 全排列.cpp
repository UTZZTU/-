#include<stdio.h>
#include <iostream>
using namespace std;
bool p[10];
int a[10];
int cnt=0;
void dfs(int k){
    if (k>8){
        for (int i =1 ; i <= 7 ; i ++ )
            printf("%d ",a[i]);
        printf("%d\n",a[8]);
        return ;
    }
    for (int i = 1 ; i <= 8 ; i ++ )
       if (!p[i]){
           p[i]=1;
           a[k]=i;
           dfs(k+1);
           p[i]=0;
       }
}
int main(){
    dfs(1);
    return 0;
}