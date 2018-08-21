// ITNOG
// O(10^4.n) dp by lnxdx, Mashhad, 2018

#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 4;
const int M = 2e4 + 4;
int INF = 1e9;

int dp[N][M], coins[N];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		for (int i = 0;i < N;i++)
			for (int j = 0;j<M;j++)
				dp[i][j] = INF;

		int n, m;
		scanf("%d%d", &m, &n);
		for (int i = 0;i < n;i++)
			scanf("%d", coins + i);

		for (int i = 0;i<n;i++)
			dp[i][0] = 0;
		dp[0][coins[0]] = 1;
		for (int i = 1;i < n;i++)
			for (int s = 1;s < M;s++)
			{
				dp[i][s] = dp[i - 1][s];
				if (s - coins[i] >= 0)
					dp[i][s] = min(dp[i][s], dp[i - 1][s - coins[i]] + 1);
			}

		int s = m;
		while (dp[n - 1][s] == INF)
			s++;
		printf("%d %d\n", s, dp[n - 1][s]);
	}
}
