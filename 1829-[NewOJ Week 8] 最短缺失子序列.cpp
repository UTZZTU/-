#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
char v[30], s[N], t[N];
int Next[N][26];                    //Next[i][j]:  S[i]后面字符 'a'+j 的位置
int main(){
    scanf("%s", v + 1);             //从v[1]开始存
    scanf("%s", s + 1);
    int vlen = strlen(v + 1), slen = strlen(s + 1);  //不能写成strlen(v)-1，因为v[0]是0，空
    //下面先求最短缺失子序列长度len
    int vK = 0, len = 1;
    for(int i = 1; i <= vlen; i++)
        vK |= (1 << (v[i] - 'a'));   //vK的二进制: 记录v有哪些字符
    int sK = 0;
    for(int i = 1; i <= slen; i++){
        sK |= (1 << (s[i] - 'a'));  //sK的二进制: 记录s有哪些字符
        if(sK == vK)   len++, sK = 0; //
        //对于字符s[i]，往前暴力更新Next数组
        for(int j = i - 1; j >= 0; j--){
            Next[j][s[i] - 'a'] = i;
            if(s[j] == s[i])  break;             //直到找到上一个s[i]停止
        }
    }
    //下面判断t是否为缺失子序列
    int n;   scanf("%d", &n);
    while(n--){
        scanf("%s", t + 1);
        int tlen = strlen(t + 1);
        int ok = 0;
        if(tlen == len ) {     //t的长度等于len
            int pos = 0;
            for(int i = 1; i <= tlen; i++) {
                pos = Next[pos][t[i] - 'a'];
                if(!pos)   break;
            }
            ok = (pos == 0);   //pos等于0说明无法匹配,此时为缺失子序列
        }
        printf("%d\n", ok);
    }
    return 0;
}

