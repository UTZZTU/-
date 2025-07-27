#include <iostream>
#include <cstring>
#include <set>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int w[N],q[N];
LL f[N];

int n;
LL m;

multiset<LL> S;

void remove(LL x)
{
    auto it = S.find(x);
    S.erase(it);
}

int main(void)
{
    scanf("%d%lld",&n,&m);
    for(int i = 1; i <= n; i ++)
    {
        scanf("%d",&w[i]);
        if(w[i] > m)
        {
            puts("-1");
            return 0;
        }
    }

    int hh = 0, tt = -1;
    LL sum =0;

    for(int i = 1, j = 1; i <= n; i ++)
    {
        sum += w[i];
        while(sum > m)
        {
            sum -= w[j ++];
            if(hh <= tt && q[hh] < j) 
            {
                if(hh < tt) remove(f[q[hh]] + w[q[hh + 1]]);
                hh ++;
            }
        }

        while(hh <= tt && w[q[tt]] <= w[i])
        {
            if(hh < tt) remove(f[q[tt - 1]] + w[q[tt]]);
            tt --;
        }
        q[++ tt] = i;
        if(hh < tt) S.insert(f[q[tt - 1]] + w[q[tt]]);
        f[i] = f[j - 1] + w[q[hh]];
        if(S.size()) f[i] = min(f[i], *S.begin());
    }
    cout << f[n];

    return 0;
}