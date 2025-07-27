#include <bits/stdc++.h>
using namespace std;
double X, Y;
struct Point
{
    double x, y;
} a[2005];
void solve(Point a, Point b, Point c) //三点共圆圆心公式
{
    double fm1=2 * (a.y - c.y) * (a.x - b.x) - 2 * (a.y - b.y) * (a.x - c.x);
    double fm2=2 * (a.y - b.y) * (a.x - c.x) - 2 * (a.y - c.y) * (a.x - b.x);

    if (fm1 == 0 || fm2 == 0)
    {
        X = Y = 1e18;
        return;
    }
    double fz1=a.x * a.x - b.x * b.x + a.y * a.y - b.y * b.y;
    double fz2=a.x * a.x - c.x * c.x + a.y * a.y - c.y * c.y;
    X = (fz1 * (a.y - c.y) - fz2 * (a.y - b.y)) / fm1;
    Y = (fz1 * (a.x - c.x) - fz2 * (a.x - b.x)) / fm2;
}
vector<pair<double,double>> mp;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)  scanf("%lf%lf", &a[i].x, &a[i].y);

    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            solve({0, 0}, a[i], a[j]);
            if (X == Y && fabs(X - 1e18) < 1e-8)
                continue;
            mp.push_back({X,Y});
        }
    }
     if(mp.size()==0){
        putchar('1');
        return 0;
    }
    sort(mp.begin(),mp.end());
    int ma = 1;
    int num = 1;
    pair<double,double> now=mp[0];
    for(int i=1;i<mp.size();i++){
       if(mp[i]==now) ++num;
       else{
            now=mp[i];
            ma=max(ma,num);
            num=1;
       }
       ma=max(ma,num);
    }

    for (int i = 1; i <= n; i++){
        if (i * (i - 1) == ma * 2){
            printf("%d", i);
            return 0;
        }
    }

    return 0;
}