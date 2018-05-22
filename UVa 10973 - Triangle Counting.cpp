// ITNOG
// O(n.m) brute force using 'adjacency matrix' and 'edge list' by lnxdx, Mashhad, 2018

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3003;
const int M = 1e6; // Number of edges is less than 10^6.

bool adj[N][N];
int edg[M][2];

int main()
{
	int t, n, m;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		memset(adj, 0, sizeof adj);
		for (int i = 0;i<m;i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			u--, v--;
			adj[u][v] = adj[v][u] = true;
			edg[i][0] = u;
			edg[i][1] = v;
		}

		int ans = 0;
		for (int i = 0;i < m;i++)
		{
			int u, v;
			u = edg[i][0];
			v = edg[i][1];
			for (int z = max(u, v) + 1;z < n;z++)
				if (adj[u][z] && adj[v][z])
					ans++;
		}

		printf("%d\n", ans);
	}
}
