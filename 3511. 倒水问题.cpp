#include <bits/stdc++.h>
#define ll long long
using namespace std;
int A, B, C;//记录最大容量
unordered_set<int> cVal;//c出现过的所有水量
set<pair<int, int>> ab;//记录ab的值以存储出现过的状态
//a, b, c为当前状态下三个杯子的水量
void dfs(int a, int b, int c)
{
    if(ab.count({a, b}))//当前状态已经出现过， 返回
        return;
    ab.insert({a, b});
    cVal.insert(c);

    //枚举六个动作
    if(a != 0)
    {
        //将A中的水倒入B中， 分为两种情况：A可以被倒空以及B被倒满
        if(a+b <= B) dfs(0, a+b, c);
        else dfs(a-(B-b), B, c);

        if(a+c <= C) dfs(0, b, a+c);
        else dfs(a-(C-c), b, C);
    }

    if(b != 0)
    {
        if(b+a <= A) dfs(a+b, 0, c);
        else dfs(A, b-(A-a), c);

        if(b+c <= C) dfs(a, 0, b+c);
        else dfs(a, b-(C-c), C);
    }

    if(c != 0)
    {
        if(c+a <= A) dfs(a+c, b, 0);
        else dfs(A, b, c-(A-a));

        if(c+b <= B) dfs(a, b+c, 0);
        else dfs(a, B, c-(B-b));
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while(cin >> A >> B >> C)
    {
        dfs(0, 0, C);//起始状态为AB空， C满
        cout << cVal.size() << endl;
        cVal.clear();
        ab.clear();
    }
    return 0;
}