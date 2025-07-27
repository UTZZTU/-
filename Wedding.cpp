#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
 
const int maxn = 100;
 
struct TwoSAT {
  int n;
  vector<int> G[maxn*2];
  bool mark[maxn*2];
  int S[maxn*2], c;
 
  bool dfs(int x) {
    if (mark[x^1]) return false;
    if (mark[x]) return true;
    mark[x] = true;
    S[c++] = x;
    for (int i = 0; i < G[x].size(); i++)
      if (!dfs(G[x][i])) return false;
    return true;
  }
 
  void init(int n) {
    this->n = n;
    for (int i = 0; i < n*2; i++) G[i].clear();
    memset(mark, 0, sizeof(mark));
  }
 
  // x = xval or y = yval
  void add_clause(int x, int xval, int y, int yval) {
    x = x * 2 + xval;
    y = y * 2 + yval;
    G[x^1].push_back(y);
    G[y^1].push_back(x);
  }
 
  bool solve() {
    for(int i = 0; i < n*2; i += 2)
      if(!mark[i] && !mark[i+1]) {
        c = 0;
        if(!dfs(i)) {
          while(c > 0) mark[S[--c]] = false;
          if(!dfs(i+1)) return false;
        }
      }
    return true;
  }
};
 
TwoSAT solver;
 
int main(){
    int n,m;
    char s1[10],s2[10];
    int a1,a2;
    while(scanf("%d%d",&n,&m)){
        if(n == 0 && m == 0) break;
        solver.init(2*n);
        solver.mark[1] = true;
        for(int i = 0;i < n;i++){
            solver.add_clause(2*i,1,2*i+1,1);
            solver.add_clause(2*i,0,2*i+1,0);
        }
        while(m--){
            scanf("%d%s%d%s",&a1,s1,&a2,s2);
            int xval,yval,x,y;
            xval = s1[0]=='h'?1:0;
            yval = s2[0]=='h'?1:0;
            x = a1*2+xval; y = a2*2+yval;
            solver.add_clause(x,1,y,1);
        }
        if(!solver.solve()) printf("bad luck\n");
        else{
            for(int i = 2;i < 2*(n-1);i+=2){
                printf("%d",i/2);
                if(solver.mark[2*i+1]) printf("w ");
                else printf("h ");
            }
            printf("%d",n-1);
            if(solver.mark[2*2*(n-1)+1]) printf("w\n");
            else printf("h\n");
        }
    }
    return 0;
}