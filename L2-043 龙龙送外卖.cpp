#include<bits/stdc++.h>
using namespace std;
struct Drop{
    long last{},deep=0;  //  他的父亲,深度
    vector<long> next;
}drop[100001];
void findDeep(long start,long deep);    //  查询出所有点的深度
long findRoad(long num,bool appear[]);  //  找出新增该点所需的路程
int main()
{
    bool appear[100001]={false};
    long N,M,start,num;
    cin >> N >> M;
    for(long z=1;z<=N;z++){
        cin >> num;
        drop[z].last = num;
        if(num==-1) start=z;
        else drop[num].next.push_back(z);
    }
    
    findDeep(start,0);
    appear[start] = true;
 
    long minRoadSum=0,maxDeep=0;
    while (M--){
        cin >> num;
        minRoadSum += findRoad(num,appear);
        maxDeep = max(maxDeep,drop[num].deep);
        cout << minRoadSum - maxDeep << endl;
    }
    
    return 0;
}
void findDeep(long start,long deep){
    drop[start].deep = deep;
    for(long x:drop[start].next) findDeep(x,deep+1);
}
long findRoad(long num,bool appear[]){
    if(appear[num]) return 0;
    appear[num] = true;
    return 2 + findRoad(drop[num].last,appear);
}