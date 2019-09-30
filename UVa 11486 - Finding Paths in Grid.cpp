// ITNOG
// O(35.2^4(log(35) + 4.log(4)) + t.log(n).35^3) Exponentiating Adjacency Matrix by lnxdx, Mashhad, 2018

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX_N = 7 + 10;
const int MAX_V = ((7 * 6 * 5) / 6) + 5; // = 35
ll MOD = 1e9 + 7;

struct Matrix
{
	ll mat[MAX_V][MAX_V];
	int n, m;
	Matrix(int n, int m) :n(n), m(m) {};
};
struct Node
{
	int a, b, c, d;
	Node(int a, int b, int c, int d) :a(a), b(b), c(c), d(d) {};
	Node() :a(0), b(0), c(0), d(0) {};
	bool operator < (const Node& y) const
	{
		if (this->a < y.a)
			return true;
		if (this->a == y.a)
			if (this->b < y.b)
				return true;
			else if (this->b == y.b)
				if (this->c < y.c)
					return true;
				else if (this->c == y.c)
					if (this->d < y.d)
						return true;
		return false;
	}
};

map<Node, int>ind;
map<int, Node>node;
ll adj[MAX_V][MAX_V];
int r[MAX_N];

Matrix mul(Matrix a, Matrix b)
{
	Matrix ans(a.n, b.m);;
	int i, j, k;
	for (i = 0; i < a.n; i++)
		for (j = 0; j < b.m; j++)
			for (ans.mat[i][j] = k = 0; k < a.m; k++)
				ans.mat[i][j] = (ans.mat[i][j] + (a.mat[i][k] * b.mat[k][j]) % MOD + MOD) % MOD;
	return ans;
}
Matrix po(Matrix base, ll p)
{
	Matrix ans(base.n, base.m);
	for (int i = 0; i < base.n; i++)
		for (int j = 0; j < base.m; j++)
			ans.mat[i][j] = (i == j); // Identity Matrix
	while (p)
	{
		if (p & 1) ans = mul(ans, base);
		base = mul(base, base);
		p >>= 1;
	}
	return ans;
}
void model(int n)
{
	for (int i = 0;i < n;i++)
		for (int j = i + 1;j < n;j++)
			for (int k = j + 1;k < n;k++)
				for (int l = k + 1;l < n;l++)
				{
					Node u(i, j, k, l);
					ind[u] = ind.size();
					node[ind[u]] = u;
				}
	for (int u = 0;u < ind.size();u++)
		for (int i = 0;i < 2;i++)
			for (int j = 0;j < 2;j++)
				for (int k = 0;k < 2;k++)
					for (int l = 0;l < 2;l++)
					{
						int a, b, c, d;
						a = node[u].a + 2 * i - 1;
						b = node[u].b + 2 * j - 1;
						c = node[u].c + 2 * k - 1;
						d = node[u].d + 2 * l - 1;
						if (a < 0 || d>6)
							continue;
						int arr[] = { a,b,c,d };
						set<int>st(arr, arr + 4);
						if (st.size() < 4)
							continue;
						sort(arr, arr + 4);
						Node v(arr[0], arr[1], arr[2], arr[3]);
						adj[u][ind[v]] = adj[ind[v]][u] = true;
					}
}
int main()
{
	model(7);

	int m = ind.size();
	Matrix mat(m, m);
	for (int i = 0;i < m;i++)
		for (int j = 0;j < m;j++)
			mat.mat[i][j] = adj[i][j];

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int>poses;
		for (int i = 0;i < 7;i++)
		{
			cin >> r[i];
			if (r[i])
				poses.push_back(i);
		}
		sort(poses.begin(), poses.end());
		Node source(poses[0], poses[1], poses[2], poses[3]);
		Matrix res = po(mat, n - 1);

		ll ans = 0;
		for (int i = 0;i < ind.size();i++)
		{
			ans += res.mat[ind[source]][i];
			ans %= MOD;
		}

		cout << ans << "\n";
	}
}
