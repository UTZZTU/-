//四分树
//2012 ACM
#include <iostream>
#include <string.h>
using namespace std;

const int len = 32;
const int maxn = 1024 + 20;
char str[maxn];
int matrix[len][len];
int cnt;//对坐标技术

void print(int matrix[len][len], int rows, int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//1.前序遍历，
//2.完成单元色块的染色与统计
void draw(char *s, int &p, int row, int col, int wid){
    char ch = str[p++];
    if(ch == 'p'){
        draw(s, p, row, col + wid / 2, wid / 2);//1
        draw(s, p, row, col, wid / 2);//2
        draw(s, p, row + wid / 2, col, wid / 2);//3
        draw(s, p, row + wid / 2, col + wid / 2, wid / 2);//4
    } else if(ch == 'f'){
        for(int i = row; i < row + wid; i++){
            for(int j = col; j < col + wid; j++){
                if(matrix[i][j] == 0){
                    matrix[i][j] = 1;
                    cnt++;
                }
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        memset(matrix, 0, sizeof(matrix));
        cnt = 0;
        for(int i = 0;i<2;i++){
            scanf("%s", str);
            int p = 0;
            draw(str, p, 0, 0, len);
        }
        print(matrix, len, len);
        printf("There are %d black pixels.\n", cnt);
    }
    return 0;
}
