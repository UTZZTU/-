#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1500;

struct seq
{
    int st, ed;
    seq() {}
    seq(int a, int b): st(a), ed(b) {}
    int len()
    {
        return ed - st;
    }
};

char s[N+2];
vector<seq> g[26];

int solve(int x, int m, int n)
{
    int res = min(m, n), tmp = 0;
    for(int l=0, r=0, add, e=g[x].size(); l<e; )
    {
        if(l == r)
        {
            if(++r >= e)
            {
                res = max(res,
                    g[x][l].len() + min(m, g[x][l].st + n-g[x][l].ed));
                break;
            }
            if(m >= g[x][r].st - g[x][l].ed)
            {
                m -= g[x][r].st - g[x][l].ed;
                tmp = g[x][r].st - g[x][l].ed + g[x][l].len() + g[x][r].len();
                ++r;
            }
            else
            {
                res = max(res,
                    g[x][l].len() + min(m, g[x][l].st + n-g[x][l].ed));
                ++l;
            }
            continue;
        }
        while(r < e && m >= g[x][r].st - g[x][r-1].ed)
        {
            m -= g[x][r].st - g[x][r-1].ed;
            tmp += g[x][r].st - g[x][r-1].ed + g[x][r].len();
            ++r;
        }
        if(m > 0)
            add = min(m, g[x][l].st + n-g[x][r-1].ed);
        else
            add = 0;
        res = max(res, tmp + add);
        if(l + 1 < e)
        {
            if(l + 1 != r)
            {
                m += g[x][l+1].st - g[x][l].ed;
                tmp -= g[x][l+1].st - g[x][l].ed + g[x][l].len();
            }
            ++l;
        }
        else
            break;
    }
    return res;
}

int main()
{
    int n, q;
    scanf("%d %s %d", &n, s, &q);
    for(int i=0, j; i<n; i=j)
    {
        for(j=i+1; j<n && s[j]==s[i]; )
            ++j;
        g[s[i]-'a'].push_back(seq(i, j));
    }
    for(int m; q--; )
    {
        char c;
        scanf("%d %c", &m, &c);
        printf("%d\n", solve(c-'a', m, n));
    }
    return 0;
}