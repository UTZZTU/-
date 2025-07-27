#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[10010];
int main() {
    int N,i;
    while(scanf("%d",&N)!=EOF)
    {
    for(i=0;i<N;i++)
        scanf("%d",&a[i]);
    sort(a,a+N);
        printf("%d\n",a[N/2]);
    }
    return 0;
}