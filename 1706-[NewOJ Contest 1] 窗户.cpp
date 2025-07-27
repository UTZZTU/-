#include<bits/stdc++.h>
using namespace std;
int n, m;                     //照片的长、宽
char w[125][125];             //窗户照片
char s[125][125];             //一个窗户
void Rotate(int a, int b){    //把窗户s转90度
    char tmp[125][125];
    for(int i=1; i<=a; i++)
        for(int j=1; j<=b; j++)
            tmp[i][j] = s[i][j];
    for(int i=1; i<=a; i++)
        for(int j=1; j<=b; j++)
            s[j][a+1-i] = tmp[i][j];
}
string check(int x1, int y1){            //将左上角坐标为(x1,y1)的窗户变成一个字符串
    int x2=x1, y2=y1;                    //找到窗户右下角坐标(x2, y2)
    while(x2+1<=n && w[x2+1][y1]!='#')  x2++;
    while(y2+1<=m && w[x1][y2+1]!='#')  y2++;
    for(int i=x1; i<=x2; i++)            //将窗户拷贝到s中
        for(int j=y1; j<=y2; j++)
            s[i-x1+1][j-y1+1] = w[i][j];
    string ans;
    int a=x2-x1+1, b=y2-y1+1;            //窗户长a、宽b
    for(int t=1;t<=4;t++){               //旋转4次
        string now;
        for(int i=1; i<=a; i++)          //把这个二维的窗户转换为一个字符串now
            for(int j=1; j<=b; j++)
                now += s[i][j];
        if(ans.size()==0 || now<ans)  ans=now;    //用其中最小的字符串表示这个窗户
        Rotate(a, b);                   //旋转90度
        swap(a, b);                     //旋转后注意交换长、宽
    }
    return ans;                         //返回一个窗户，用它的4种旋转的最小字符串表示
}
int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++)  cin>>(w[i]+1);   //读窗户照片
    set<string> win;                          //win记录所有的窗户，并用set判重
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)               //定位一个窗户，即左上，左、上都是‘#’
            if(w[i-1][j-1]=='#' && w[i][j-1]=='#' && w[i-1][j]=='#')
                win.insert(check(i, j));      //插入一个新窗户，用set判重
    cout<<win.size()<<endl;                   //win.size()就是不同窗户的数量
    return 0;
}
