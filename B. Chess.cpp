#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char c1,c2;
int x1,x2,y1,y2;
int dir[8][2]={1,2,1,-2,-1,2,-1,-2,2,1,2,-1,-2,1,-2,-1};
bool check(int x,int y){
    for(int i=0;i<8;i++){
        int X = x + dir[i][0];
        int Y = y + dir[i][1];
        if(X<1||X>8||Y<1||Y>8) continue;
        if((X==x1&&Y==y1)||(X==x2&&Y==y2)) return true;
    }
    return false;
}
int main()
{
    scanf("%c%d\n%c%d",&c1,&y1,&c2,&y2);
    x1 = c1-'a'+1; x2 = c2-'a'+1;
    int ans = 0;
    for(int i=1;i<=8;i++){
        if(i==x1) continue;
        for(int j=1;j<=8;j++){
            if(j==y1||(i==x2&&j==y2)||check(i,j)) continue;
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}