// ITNOG
// O(n^2 + q.n.log(n)) Binary Search by lnxdx, Mashhad, 2018
// Binary search on the diagonals.

#include<bits/stdc++.h>
using namespace std;

const int N = 505;

int diag[2 * N][N]; // We can define array of vectors.
int diag_size[2 * N];

int main()
{
	int n, m, q;
	while (scanf("%d%d", &n, &m) && n && m)
	{
		memset(diag_size, 0, sizeof diag_size);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &diag[i - j + m - 1][diag_size[i - j + m - 1]]);
				diag_size[i - j + m - 1]++;
			}

		scanf("%d", &q);
		while (q--)
		{
			int l, u;
			scanf("%d%d", &l, &u);
			int ans = 0;
			for (int i = 0;i < m + n - 1; i++)
			{
				int lo = lower_bound(diag[i], diag[i] + diag_size[i], l) - diag[i];
				int hi = upper_bound(diag[i], diag[i] + diag_size[i], u) - diag[i];
				ans = max(ans, hi - lo);
			}
			printf("%d\n", ans);
		}

		printf("-\n");
	}
}
