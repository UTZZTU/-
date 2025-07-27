#include<iostream>  
using namespace std;
int a[200005];
int main()
{
int n, count1, count2;
while (cin >> n)
{
int flag = 0;
count1 = count2 = 0;
for (int i = 0; i<n; i++)
{
cin >> a[i];
if (a[i] % 4 == 0)
count1++;
if (a[i] % 2 != 0)
count2++;
}
if (count2 == count1 + 1 && count2 + count1 == n)
flag = 1;
if (count1 >= count2)
flag = 1;
if (flag)
cout << "Yes" << endl;
else
cout << "No" << endl;
}
return 0;
}