#include<iostream>
using namespace std;
#define rep(i,a,b) for(int i = a;i<=b;i++)
#define per(i,a,b) for(int i = a;i>=b;i--)
char mp[35][55];
int main(void)
{
    int n = 30;
    int m = 50;
    rep(i, 1, n)
        rep(j, 1, m)
        cin >> mp[i][j];

    int ans = 0;

    rep(i, 1, n)
        rep(j, 1, m)
        rep(k, j + 1, m)
        rep(l, k + 1, m)
        if (mp[i][l] > mp[i][k] && mp[i][k] > mp[i][j])
        {
            //cout << mp[i][j] << mp[i][k] << mp[i][l] << endl;
            ans++;
        }
    rep(i, 1, m)
        rep(j, 1, n)
        rep(k, j + 1, n)
        rep(l, k + 1, n)
        if (mp[k][i] > mp[j][i] && mp[l][i] > mp[k][i])
        {
            //cout << mp[j][i] << mp[k][i] << mp[l][i] << endl;
            ans++;
        }
    rep(i, 1, n)
        rep(j, 1, m)
        for (int ii = i + 1, jj = j - 1; ii <= n && jj > 0; ii++, jj--)
            for (int iii = ii + 1, jjj = jj - 1; iii <= n && jjj > 0; iii++, jjj--)
                if (mp[iii][jjj] > mp[ii][jj] && mp[ii][jj] > mp[i][j])
                {
                    //cout << mp[i][j] << mp[ii][jj] << mp[iii][jjj] << endl;
                    ans++;
                }
                else if (mp[iii][jjj] < mp[ii][jj] && mp[ii][jj] < mp[i][j])
                {
                    //cout << mp[i][j] << mp[ii][jj] << mp[iii][jjj] << endl;
                    ans++;
                }

    rep(i, 1, n)
        rep(j, 1, m)
        for (int ii = i + 1, jj = j + 1; ii <= n && jj <= m; ii++, jj++)
            for (int iii = ii + 1, jjj = jj + 1; iii <= n && jjj <= m; iii++, jjj++)
                if (mp[iii][jjj] > mp[ii][jj] && mp[ii][jj] > mp[i][j])
                {
                    //cout << mp[i][j] << mp[ii][jj] << mp[iii][jjj] << endl;
                    ans++;
                }
    cout << ans;
    return 0;

}