///*By:Luckyblock*/
#include <bits/stdc++.h>
#define LL long long
const int kN = 210;
LL f[kN][kN][kN];

int main() {  
// freopen("1.txt", "r", stdin);  
std::ios::sync_with_stdio(0), std::cin.tie(0);  
for (int i = 0; i <= 200; ++ i) 
{    for (int j = 0; j <= 200; ++ j) 
{      for (int k = 0; k <= 200; ++ k) 
{        int d = (((i + 1) % 2 + (j % 2)) == (2 * (k % 2)));        
f[i + 1][j][k] = std::max(f[i + 1][j][k], f[i][j][k] + d);         
d = (((i % 2) + ((j + 1) % 2)) == (2 * (k % 2)));        
f[i][j + 1][k] = std::max(f[i][j + 1][k], f[i][j][k] + d);         
d = (((i % 2) + (j % 2)) == (2 * ((k + 1) % 2)));        
f[i][j][k + 1] = std::max(f[i][j][k + 1], f[i][j][k] + d);      
}    }  }   int T; std::cin >> T;  
while (T --) {    int p[4];    for (int i = 0; i < 4; ++ i) std::cin >> p[i];    
// LL ans = p[4] / 2;    
std::cout << (f[p[0]][p[1]][p[2]] + (p[3] / 2)) << "\n";   }  
return 0;}