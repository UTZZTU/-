#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 10;
const int N = 3e3 + 10;
const int inf = 1e6 + 10;
int a[maxn];
vector<int>ver[maxn];
int vis[N];
int visk[maxn];
void init(int n){
    for(int i = 0; i <= n; i++)   ver[i].clear();
}
int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int>vv;
        memset(visk, 0, sizeof(visk));
        int n, k;
        cin>>n>>k;
        init(n);
        for(int i = 1; i <= n; i++){
            cin>>a[i];
        }
        for(int i = 1; i <= n; i++){
            fill(vis, vis + N, 0);
            for(int j = k; j >= 1; j--){   
                if(vis[a[i]/j] == 0) {
                    ver[i].push_back(a[i]/j);
                    vis[a[i]/j] = 1;
                }  
                if(visk[a[i]/j] == 0){
                    vv.push_back(a[i]/j);
                    visk[a[i]/j] = 1;
                }        
            }
        }
        sort(vv.begin(), vv.end());
        int minans = inf;
        for(int i = 0; i < vv.size(); i++){
            int minval = vv[i];
            int maxans = -inf;  int f = 1;
            for(int j = 1; j <= n; j++){
                int num = lower_bound(ver[j].begin(), ver[j].end(), minval) - ver[j].begin();
                if(num >= 0 && num < ver[j].size()){
                    maxans = max(maxans, ver[j][num] - minval);
                }else{
                    f = 0;
                    break;
                }
            }
            if(f == 1){
                minans = min(maxans, minans);
            }
        }
        printf("%d\n", minans);
    }
        
    return 0;
}