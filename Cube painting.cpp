#include <stdio.h>
#include <string.h>
char s[15], s1[7], s2[7], s3[7];
int flag;
int d[7][7] = { {0,1,2,3,4,5},{1,5,2,3,0,4},{2,1,5,0,4,3}, {3,1,0,5,4,2},{4,0,2,3,5,1},{5,4,2,3,1,0} };
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (~scanf("%s", s))
	{
		flag = 0;
		for (int i = 0;i < 12;i++)
		{
			if (i < 6) s1[i] = s[i];
			else s2[i-6] = s[i];
		}
		s1[6] = '\0';
		s2[6] = '\0';
		//puts(s1);
		//puts(s2);
		for (int i = 0;i < 6;i++)
		{
			for (int j = 0;j < 6;j++)
				s3[j] = s1[d[i][j]];
			s3[6] = '\0';
			//puts(s3);
			if (strcmp(s3, s2) == 0)
			{
				flag = 1;
				break;
			}
			for (int j = 0;j < 3;j++)//这时首尾颜色不变，只变化中间四种颜色
			{
				char ch = s3[1];
				s3[1] = s3[2];
				s3[2] = s3[4];
				s3[4] = s3[3];
				s3[3] = ch;
				//puts(s3);
				if (strcmp(s3, s2) == 0)
				{
					flag = 1;
					break;
				}
			}
			if (flag) break;
		}
		if (flag) printf("TRUE\n");
		else printf("FALSE\n");
	}
}