// ITNOG
// O(?) Backtrack by lnxdx, Mashhad, 2018

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 101;

vector<int>adj[N];
vector<int>cur_path, path;

int n, m, MAX;
void bt1(int i, vector<bool> used, int depth)
{
	if (count(used.begin(), used.end(), true) == n)
	{
		if (depth > MAX)
		{
			MAX = depth;
			path = cur_path;
		}
		return;
	}
	for (int j = i; j < n; j++)
		if (!used[j])
		{
			vector<bool>next_used(used.begin(),used.end());
			next_used[j] = true;
			for (int k = 0;k < adj[j].size();k++)
				next_used[adj[j][k]] = true;
			
			cur_path.push_back(j);
			bt1(j + 1, next_used, depth + 1);
			cur_path.pop_back();
		}
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		MAX = 0;
		for (int i = 0;i < n;i++)
			adj[i].clear();
		for (int i = 0;i < m;i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			u--, v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		vector<bool>used;
		used.assign(n, 0);
		bt1(0, used, 0);

		printf("%d\n", MAX);
		for (int i = 0;i < path.size() - 1;i++)
			printf("%d ", path[i] + 1);
		printf("%d\n", path.back() + 1);
	}
}
