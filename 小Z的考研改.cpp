#include <stdio.h>
int main();
void sort(int *a, int size);

int main()
{
    int fen[205];
    int p;
    int n;
    int m;
    while (scanf("%d%d%d", &n, &m, &p) != EOF)
    {
        int a, b;
        for (int i = 0; i < n; ++i)
        {
            scanf ("%d%d", &a, &b);
            fen[i] = a * 7 + b * 3;
        }
        sort(fen, n);
        int goal = fen[m - 1];
        goal -= p * 3;
        int temp = goal / 7;
        if (temp * 7 == goal)
        {
            goal = temp;
        }
        else
        {
            goal = temp + 1;
        }
        if (goal < 0) goal = 0;
        printf("%d\n", goal);
    }
}

void sort(int *a, int size) // ²åÈëÅÅÐò
{
    for (int i = 0; i < size; ++i)
    {
        int temp = a[i];
        for (int j = i; j > 0; --j)
        {
            if (a[j - 1] < temp)
            {
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
            else // a[j - 1] >= temp
            {
                break;
            }
        }
    }
}

