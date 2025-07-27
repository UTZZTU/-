#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
char s[N];
int son[N][26], ed[N], sum[N], calc[N];
// ed[i] is the num of string end of node i
// sum[i] is the sum of ed in subtree of i
// des[i] is true if there is a subnode j of i ,and ed[j]>0
// calc[i] is the sum of des[j], j is all i direct son
bool des[N];
int tot, slen;
void insert() {
    // insert to the trie
    int p = 0;
    for (int i = 1; i <= slen; i++) {
        if (!son[p][s[i] - 'a'])
            son[p][s[i] - 'a'] = ++tot;
        p = son[p][s[i] - 'a'];
    }
    ed[p]++;
}
void build(int i) {
    // initial the des,sum,calc
    if (ed[i]) {
        des[i] = true;
        sum[i] = ed[i];
    }
    for (int j : son[i]) {
        if (j) {
            build(j);
            des[i] |= des[j];
            sum[i] += sum[j];
            calc[i] += des[j];
        }
    }
}
char ans[N];
// ans string
int anstot, n, k, L, R;
// L is all sum,which node is located left of now
// R is all des and ed ,which node is located right of now
void dfs(int i) {
    if (L + R >= k)
        return;
    // if at begining, the L+R>=k, return
    // int the initial, R is added all des[j],j is direct son of i
    for (int c = 0; c < 26; c++) {
        int j = son[i][c];
        if (j) {
            R -= des[j];
            L += sum[j];
            // j is turn from right node to mid node
            if (L + R >= k) {
                ans[++anstot] = char('a' + c);
                // add ans
                // repeal the change and dfs down
                R += ed[j] + calc[j];
                L -= sum[j];
                dfs(j);
                return;
            }
        }
    }
}
int main() {
    int t_;
    cin >> t_;
    while (t_--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> (s + 1);
            slen = strlen(s + 1);
            insert();
        }
        build(0);
        // build trie and get sum,des,calc
        R = calc[0];
        calc[0] = 0;
        dfs(0);
        // get ans and output ans
        if (!anstot)
            cout << "EMPTY";
        else
            for (int i = 1; i <= anstot; i++)
                cout << ans[i];
        cout << "\n";
        // clear
        for (int i = 0; i <= tot; i++) {
            memset(son[i], 0, sizeof son[i]);
            ed[i] = sum[i] = calc[i] = 0;
            des[i] = false;
        }
        tot = anstot = L = R = 0;
    }
}