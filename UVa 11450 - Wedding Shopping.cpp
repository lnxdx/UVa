// ITNOG
// O(m.c.k) dp by lnxdx, Mashhad, 2018

#include<bits/stdc++.h>
using namespace std;

vector<int>p[22];
bool dp[22][202];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		memset(dp, false, sizeof dp);

		int m, c;
		scanf("%d%d", &m, &c);
		for (int i = 0;i < c;i++)
		{
			int k;
			scanf("%d", &k);
			p[i].assign(k, 0);
			for (int j = 0;j < k;j++)
				scanf("%d", &p[i][j]);
		}


		for (int j = 0; j < p[0].size(); j++) // initial values (base cases)
			if (m - p[0][j] >= 0) // to prevent array index out of bound
				dp[0][p[0][j]] = true; // using first garment g = 0
		for (int i = 1;i < c;i++)
			for (int x = 0; x <= m; x++)
				for (int j = 0; j < p[i].size(); j++)
					if (x - p[i][j] >= 0)
						dp[i][x] |= dp[i - 1][x - p[i][j]];

		bool ans = false;
		for (int x = m; x >= 0; x--)
			if (dp[c - 1][x])
			{
				printf("%d\n", x);
				ans = true;
				break;
			}
		if(!ans)
			printf("no solution\n");
	}
}
