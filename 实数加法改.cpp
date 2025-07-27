#include <string>
#include <algorithm>
#include <iostream>
#include <cstdio>
 
using namespace std;
 
const int MAXN = 250;
 
string s1,s2;
int len1,len2;
int a[MAXN],b[MAXN],c[MAXN]={0};
 
void add0(string &s,int &l,int &r)
{
    for (int i = l+1;i <= r;i++)
                s+='0';
    l = r;
}
 
string sub(string s1,string s2)
{
    int len1 = s1.size(),len2 = s2.size();
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    for (int i = 1;i <= len1;i++)
        a[i] = s1[i-1]-'0';
    for (int i = 1;i <= len2;i++)
        b[i] = s2[i-1]-'0';
    for (int i = 1;i <= 210;i++)
        c[i] = a[i]+b[i];
    for (int i = 1;i <= 210;i++)
    {
        c[i+1] = c[i+1]+c[i]/10;
        c[i] %= 10;
    }
    string temp = "";
    for (int i = 1;i <= 210;i++)
    {
        char key = c[i]+'0';
        temp+=key;
    }
    return temp;
}
 
int main()
{
    //freopen("F:\rush.txt","r",stdin);
    cin >> s1>>s2;
    len1 = s1.size(),len2 = s2.size();
    int pos1,pos2;
    pos1 = s1.find('.',0),pos2 = s2.find('.',0);
    int lp1,lp2;
    lp1 = len1-1-pos1,lp2 = len2-1-pos2;
    if (pos1!=-1 && pos2!=-1)
    {
        if (lp1>lp2)
            add0(s2,lp2,lp1);
        else
            add0(s1,lp1,lp2);
        s1.erase(s1.find('.',0),1);
        s2.erase(s2.find('.',0),1);
    }
    else
        if (pos1!=-1)
        {
            lp2 = 0;
            add0(s2,lp2,lp1);
            s1.erase(s1.find('.',0),1);
        }
        else
            if (pos2!=-1)
            {
                lp1 = 0;
                add0(s1,lp1,lp2);
                s2.erase(s2.find('.',0),1);
            }
            else
                lp1 = lp2 = 0;
    string tempans = sub(s1,s2);
    if (lp1!=0)
        tempans.insert(lp1,".");
    while (tempans!=""&& tempans[0]=='0')
        tempans.erase(0,1);
    if (tempans=="")
        puts("0");
    else
    {
        if (tempans[0]=='.')
            tempans.erase(0,1);
        reverse(tempans.begin(),tempans.end());
        int len = tempans.size();
        while (tempans[0]=='0' && tempans[1]!='.')
            tempans.erase(0,1);
        cout << tempans;
    }
    return 0;
}
