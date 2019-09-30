// ITNOG
// O(t.log(n)) Matrix Power DP by lnxdx, Mashhad, 2018

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX_N = 3 + 10;
ll MOD = 1e9 + 9;

struct Matrix
{
	ll mat[MAX_N][MAX_N];
	int n, m;
	Matrix(int n_, int m_) :n{ n_ }, m{ m_ } {};
};

Matrix mul(Matrix a, Matrix b)
{
	Matrix ans(a.n, b.m);;
	int i, j, k;
	for (i = 0; i < a.n; i++)
		for (j = 0; j < b.m; j++)
			for (ans.mat[i][j] = k = 0; k < a.m; k++)
				ans.mat[i][j] = (ans.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % MOD;
	return ans;
}
Matrix po(Matrix base, ll p)
{
	Matrix ans(base.n, base.m);
	for (int i = 0; i < base.n; i++)
		for (int j = 0; j < base.m; j++)
			ans.mat[i][j] = (i == j);
	while (p)
	{
		if (p & 1) ans = mul(ans, base);
		base = mul(base, base);
		p >>= 1;
	}
	return ans;
}
int main()
{
	ll n;
	while (cin >> n && n)
	{
		int k = 3;
		ll m1[MAX_N][MAX_N] = { { 1,1,1 },{ 1,0,0 },{ 0,1,0 } };
		ll m2[MAX_N][1] = { { 1 },{ 0 },{ 1 } }; // T(2), T(1), T(0)
		Matrix mat1(k, k), mat2(k, 1);
		for (int i = 0;i < k;i++)
			for (int j = 0;j < k;j++)
			{
				mat1.mat[i][j] = m1[i][j];
				mat2.mat[i][0] = m2[i][0];
			}

		cout << mul(po(mat1, n), mat2).mat[k - 1][0] << "\n";
	}
}
