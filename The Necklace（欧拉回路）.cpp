//#include"bits/stdc++.h"
//#include<unordered_map>
//#include<unordered_set>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<bitset>
#include<climits>
#include<queue>
#include<iomanip>
#include<cmath>
#include<stack>
#include<map>
#include<ctime>
#include<new>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define MT(a,b) memset(a,b,sizeof(a))
#define lson l, mid, node << 1
#define rson mid + 1, r, node << 1 | 1
const int INF  =  0x3f3f3f3f;
const int O    =  1e5;
const int mod  =  1e4 + 7;
const int maxn =  1e3+5;
const double PI  =  acos(-1.0);
const double E   =  2.718281828459;
 
int f[maxn];
int col[maxn];
int way[51][51];
int n;
 
void init(){
    MT(way, 0);
    for(int i=1; i<=50; i++){
        f[i] = i; col[i] = 0;
    }
}
 
int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}
 
void Union(int u, int v){
    if((u=find(u))!=(v=find(v))){
        f[u] = f[v];
    }
}
 
void Oular(int u){ // 欧拉回路模板
    for(int v=1; v<=50; v++) {
        if(way[u][v]) {
            way[u][v] -- ; way[v][u] -- ;
            Oular(v);
            printf("%d %d\n", v, u);
        }
    }
}
 
bool check(){ // 如果存在度为奇数，返回false， 如果不是连通图，返回false
    int front = 0; //记录遍历的上一个节点
    for(int i=1; i<=50; i++) {
        if(col[i] & 1) return false;
        if(!front && col[i]) {front = i; continue;}
        if(col[i] && find(i) != find(front)) return false;
    }
    return true;
}
 
int main(){
    int T, ca = 0; scanf("%d", &T);
    while(T --) {
        init(); scanf("%d", &n);
        int st = 0; //起点
        for(int i=0; i<n; i++) {
            int u, v; scanf("%d%d", &u, &v);
            if(!st) st = u;
            way[u][v] ++; way[v][u] ++; // 记录每条边的的个数
            col[u] ++; col[v] ++; // 记录每个节度的个数
            Union(u, v);
        }
        printf("Case #%d\n", ++ca);
        if(!check()) { // 判断是否存在欧拉回路
            printf("some beads may be lost\n");
            goto loop;
        }
        Oular(st);
    loop:if( T ) printf("\n");
    }
    return 0;
}