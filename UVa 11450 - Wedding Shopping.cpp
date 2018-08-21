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
		for (int i = 1;i <= c;i++)
		{
			int k;
			scanf("%d", &k);
			p[i].assign(k, 0);
			for (int j = 0;j < k;j++)
				scanf("%d", &p[i][j]);
		}

		dp[0][0] = true;
		for (int x = 0; x < m; x++)
			for (int i = 0;i < c;i++)
				if (dp[i][x])
					for (int j = 0; j < p[i + 1].size(); j++)
						dp[i + 1][x + p[i + 1][j]] = true;

		bool ans = false;
		for (int x = m; x >= 0; x--)
			if (dp[c][x])
			{
				printf("%d\n", x);
				ans = true;
				break;
			}
		if (!ans)
			printf("no solution\n");
	}
}
