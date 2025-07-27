#include<stdio.h>
#include<string.h>
int main()
{
	int n, m, i, nu[30] = {},p;
	char c,C[200];
	scanf("%d%d%d", &n, &m,&p);
	getchar();
	for (i = 1; i <= n*(m+1); i++){
		scanf("%c", &c);
		if (c == 'A')nu[1] += 1;
		if (c == 'B')nu[2] += 1;
		if (c == 'C')nu[3] += 1;
		if (c == 'D')nu[4] += 1;
		if (c =='E')nu[5] += 1;
		if (c == 'F')nu[6] += 1;
		if (c =='G')nu[7] += 1;
		if (c =='H')nu[8] += 1;
		if (c =='I')nu[9] += 1;
		if (c =='J')nu[10] += 1;
		if (c =='K')nu[11] += 1;
		if (c =='L')nu[12] += 1;
		if (c =='M')nu[13] += 1;
		if (c =='N')nu[14] += 1;
		if (c =='O')nu[15] += 1;
		if (c =='P')nu[16] += 1;
		if (c =='Q')nu[17] += 1;
		if (c =='R')nu[18] += 1;
		if (c =='S')nu[19] += 1;
		if (c =='T')nu[20] += 1;
		if (c =='U')nu[21] += 1;
		if (c =='V')nu[22] += 1;
		if (c =='W')nu[23] += 1;
		if (c =='X')nu[24] += 1;
		if (c =='Y')nu[25] += 1;
		if (c =='Z')nu[26] += 1;
	}
	for (int a = 1; a<= p; a++){
	gets(C);
		for (i = 0; C[i]!='\0'; i++){
			if (C[i] == 'A')nu[1] -= 1;
			if (C[i] =='B')nu[2] -= 1;
			if (C[i] =='C')nu[3] -= 1;
			if (C[i] == 'D')nu[4] -= 1;
			if (C[i] =='E')nu[5] -= 1;
			if (C[i] =='F')nu[6] -= 1;
			if (C[i] =='G')nu[7] -= 1;
			if (C[i] =='H')nu[8] -= 1;
			if (C[i] =='I')nu[9] -= 1;
			if (C[i] =='J')nu[10] -= 1;
			if (C[i] =='K')nu[11] -= 1;
			if (C[i] =='L')nu[12] -= 1;
			if (C[i] =='M')nu[13] -= 1;
			if (C[i] =='N')nu[14] -= 1;
			if (C[i] =='O')nu[15] -= 1;
			if (C[i] =='P')nu[16] -= 1;
			if (C[i] =='Q')nu[17] -= 1;
			if (C[i] =='R')nu[18] -= 1;
			if (C[i] =='S')nu[19] -= 1;
			if (C[i] =='T')nu[20] -= 1;
			if (C[i] =='U')nu[21] -= 1;
			if (C[i] =='V')nu[22] -= 1;
			if (C[i] =='W')nu[23] -= 1;
			if (C[i] =='X')nu[24] -= 1;
			if (C[i] =='Y')nu[25] -= 1;
			if (C[i] =='Z')nu[26] -= 1;
		}
	}
	for (i = 1; i <= nu[1]; i++)printf("A\n");
	for (i = 1; i <= nu[2]; i++)printf("B\n");
	for (i = 1; i <= nu[3]; i++)printf("C\n");
	for (i = 1; i <= nu[4]; i++)printf("D\n");
	for (i =1; i <= nu[5]; i++)printf("E\n");
	for (i = 1; i <= nu[6]; i++)printf("F\n");
	for (i = 1; i <= nu[7]; i++)printf("G\n");
	for (i = 1; i <= nu[8]; i++)printf("H\n");
	for (i = 1; i <= nu[9]; i++)printf("I\n");
	for (i = 1; i <= nu[10]; i++)printf("J\n");
	for (i = 1; i <= nu[11]; i++)printf("K\n");
	for (i = 1; i <= nu[12]; i++)printf("L\n");
	for (i = 1; i <= nu[13]; i++)printf("M\n");
	for (i = 1; i <= nu[14]; i++)printf("N\n");
	for (i = 1; i <= nu[15]; i++)printf("O\n");
	for (i = 1; i <= nu[16]; i++)printf("P\n");
	for (i = 1; i <= nu[17]; i++)printf("Q\n");
	for (i = 1; i <= nu[18]; i++)printf("R\n");
	for (i = 1; i <= nu[19]; i++)printf("S\n");
	for (i = 1; i <= nu[20]; i++)printf("T\n");
	for (i = 1; i <= nu[21]; i++)printf("U\n");
	for (i = 1; i <= nu[22]; i++)printf("V\n");
	for (i = 1; i <= nu[23]; i++)printf("W\n");
	for (i = 1; i <= nu[24]; i++)printf("X\n");
	for (i = 1; i <= nu[25]; i++)printf("Y\n");
	for (i = 1; i <= nu[26]; i++)printf("Z\n");
	return 0;
}
