#include<bits/stdc++.h>

using namespace std;
 
char s[110][110];
int p[110][110];
 
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%s", s[i]);
    memset(p,0,sizeof(p));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int flag = 0;
            for(int k = j+1; k < m; k++){
                if(s[i][k]==s[i][j]){
                    p[i][k] = 1;
                    flag = 1;
                }
            }
            for(int k = i+1; k < n; k++){
                if(s[k][j]==s[i][j]){
                    p[k][j] = 1;
                    flag = 1;
                }
            }
            if(flag==1) p[i][j] = 1;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(p[i][j]==0) printf("%c", s[i][j]);
        }
    }
    return 0;
}
