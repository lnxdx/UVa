// ITNOG
// O(#tests.n) dfs by lnxdx, Mashhad, 2018

#include<bits/stdc++.h>
using namespace std;
const int N = 101;

vector<int>adj[N];
int dfs_num[N], dfs_low[N], par[N], is_art[N];
int dfs_num_counter, dfs_root, root_childs, n;

void dfs(int u)
{
	dfs_low[u] = dfs_num[u] = dfs_num_counter++;
	for (int j = 0; j < adj[u].size(); j++)
	{
		int v = adj[u][j];
		if (par[v] == -1)
		{
			par[v] = u;
			if (u == dfs_root) root_childs++;
			dfs(v);
			if (dfs_low[v] >= dfs_num[u])
				is_art[u] = true;
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else // if (v != par[u]) // This is optional.
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}

int main()
{
	while (~scanf("%d", &n) && n)
	{
		for (int i = 0;i < n;i++)
		{
			par[i] = -1;
			dfs_num[i] = dfs_low[i] = is_art[i] = 0;
			adj[i].clear();
		}

		getchar();
		int u, v;
		string line;
		while (getline(cin, line) && line != "0")
		{
			stringstream ss;
			ss << line;
			ss >> u;
			while (!ss.eof())
			{
				ss >> v;
				adj[u - 1].push_back(v - 1);
				adj[v - 1].push_back(u - 1);
			}
		}

		dfs_num_counter = dfs_root = root_childs = 0;
		par[dfs_root] = dfs_root;
		dfs(dfs_root);

		is_art[dfs_root] = (root_childs> 1);
		printf("%d\n", count(is_art, is_art + n, true));
	}
}
