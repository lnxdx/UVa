// ITNOG
// Bottom Up Backwarding bitmask dp thanks to floyd by lnxdx :)

#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long
ll INF = 1e13;

ll g[20][20], dp[1 << 15];
int degree[20];

int main()
{
	int n, e, m;

	while (cin >> n, n) // yes, we can do this :)
	{
		for (int i = 0;i < n;i++)
			for (int j = 0;j < n;j++)
				g[i][j] = INF, degree[i] = 0;
		cin >> e;
		long long ans = 0;
		for (int i = 0;i < e;i++)
		{
			ll u, v, w;
			cin >> u >> v >> w;
			u--, v--;
			ans += w;
			g[u][v] = g[v][u] = min(g[u][v], w);
			degree[u]++, degree[v]++;
		}
		for (int k = 0;k < n;k++) // Floyd Always helps :) Thank You man:*
			for (int i = 0;i < n;i++)
				for (int j = 0;j < n;j++)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

		// Use DP to solve min weighted perfect matching on small general graph.
		int target = (1 << n) - 1;
		for (int i = 0;i < n;i++)
			if (degree[i] % 2 == 0)
				target ^= (1 << i); // We remove nodes with even degree from nodes that should be matched.
		dp[0] = 0;
		for (int mask = 1;mask <= target;mask++)
		{
			dp[mask] = INF;
			int u, v;
			for (u = 0;u<n;u++)
				for (v = u + 1;v<n;v++)
				{
					if (degree[u] % 2 && degree[v] % 2)
						if (((1 << u)&mask) && ((1 << v)&mask))
							dp[mask] = min(dp[mask], g[u][v] + dp[mask ^ (1 << u) ^ (1 << v)]);
				}
		}
		ans += dp[target];
		cout << ans << "\n";
	}
}
