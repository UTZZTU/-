#include<bits/stdc++.h>
using namespace std;
set<vector<pair<int,int>>>tot;
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int m;     scanf("%d", &m);
        vector<pair<int,int> >a;      //用vector存一个图案a
        while(m--){                   //读一个图案的m个点
            int x, y;   scanf("%d%d", &x, &y);
            a.push_back(make_pair(x, y));
        }
        sort(a.begin(), a.end()); //把这个图案的m个点排序，先x从小到大，x相同再y从小到大
        int delta_x = a[0].first, delta_y = a[0].second;
        for(auto & x : a)       //把最左下点移到原点，其他点平移到相应位置
            x.first -= delta_x, x.second -= delta_y;
        tot.insert(a);  //插入到set tot中，判重
    }
    cout<<tot.size()<<endl;
    return 0;
}
