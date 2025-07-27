#include <iostream>

using namespace std;

int main()
{
    int k = 0;
    string str;
    cin >> k;
    cin >> str;

    int size = str.size();
    if((size%k) != 0) {
        cout << -1;
        return 0;
    }

    int sum = 0;
    int alph[26];//记录该列中26个小写字母出现的次数
    int max = 0;//该列中出现的最大次数
    int temp = 0;
    for(int i=0; i<26; i++)
        alph[i] = 0;

    for(int i=0; i<size/k; i++){
        for(int j=i; j<size; j+=(size/k)){
            temp = (int)(str[j]-'a');
            alph[temp]++;
        }
        for(int m=0; m<26; m++)//找到该列中的最大值
            if(alph[m]>max) max = alph[m];

        sum += (k - max);//将所有列需要修改的次数全部加起来，k-max为需要修改的次数
        max = 0;//清零
        for(int n=0; n<26; n++)
            alph[n] = 0;//将数组清空
    }
    cout << sum << endl;
    return 0;
}
