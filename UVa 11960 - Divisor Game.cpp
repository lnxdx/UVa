// ITNOA
// O(n.log(n) + t) DP Sparse Table by lnxdx, Mashhad, 2019
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 6;
const int LOGN = 20;
ll divs[N];
int _spt[N][LOGN];
struct SPT
{
	SPT(int n, ll a[])
	{
		for (int i = 0; i < n; i++)
			_spt[i][0] = i;
		for (int j = 1; (1 << j) <= n; j++)
			for (int i = 0; i + (1 << j) - 1 < n; i++)
				if (a[_spt[i][j - 1]] > a[_spt[i + (1 << (j - 1))][j - 1]])
					_spt[i][j] = _spt[i][j - 1];
				else
					_spt[i][j] = _spt[i + (1 << (j - 1))][j - 1];
	}
	int query(ll a[], int i, int j)
	{
		int k = ilogb(j - i + 1);
		if (a[_spt[i][k]] > a[_spt[j - (1 << k) + 1][k]])
			return _spt[i][k];
		else
			return _spt[j - (1 << k) + 1][k];
	}
};
int main()
{
	for (int i = 1;i <= 1e6;i++)
		for (int j = i;j <= 1e6;j += i)
			divs[j]++;
	SPT spt(1e6 + 1, divs);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", spt.query(divs, 1, n));
	}
}
