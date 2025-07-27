#include<bits/stdc++.h>
using namespace std;
struct node{ int x, y, v; };
bool cmp(node x, node y){ return x.x!=y.x? x.x<y.x : x.y<y.y; }
map<double, vector<node> >mp;
int main(){
    int n;  cin>>n;
    int sum = 0, cnt = 0;
    for(int i = 1; i <= n; i++){
        int x, y, v;  cin>>x>>y>>v;
        sum += v;  //sum肯定全拿
        mp[y*1.0/x].push_back(node{x,y,v});//按斜率（方向）分类
    }
    for(auto x : mp){ //枚举每个方向
        vector<node>vc = x.second; 
        sort(vc.begin(), vc.end(), cmp);//按x,y排序
        for(int i = 0; i < vc.size(); i++){
            if(i==0 || vc[i].v!=1 || vc[i-1].v!=1){
                cnt++;
            }
        }
    }
    cout<<sum<<" "<<cnt<<"\n";
    return 0;
}

