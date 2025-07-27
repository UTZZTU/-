#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
int pos[305][305];
int sx,sy,ex,ey,l;
int T;
int Move[8][2]={-2,1,-2,-1,-1,2,-1,-2,1,2,1,-2,2,1,2,-1};
struct Node{
    int x,y,step;
};
int check(Node x){
    if (x.x<0||x.x>=l||x.y<0||x.y>=l) {
        return 1;
    }else{
        return pos[x.x][x.y];
    }
}
void dfs(){
    Node SN,next,temp;
    SN.x = sx;SN.y = sy;SN.step = 0;
    queue<Node>q;
    pos[sx][sy] = 1;
    q.push(SN);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if (temp.x == ex && temp.y == ey) {
            printf("%d\n",temp.step);
            break;
        }
        for (int i = 0; i < 8; i++) {
            next.x = temp.x + Move[i][0];
            next.y = temp.y + Move[i][1];
            if(check(next))
                continue;
            else{
                pos[next.x][next.y] = 1;
                next.step = temp.step + 1;
                q.push(next);
            }
        }
    }
}
int main() {
    scanf("%d",&T);
    while(T--) {
        memset(pos,0,sizeof(pos));
        scanf("%d",&l);
        scanf("%d %d",&sx,&sy);
        scanf("%d %d",&ex,&ey);
        dfs();
    }
    return 0;
}
