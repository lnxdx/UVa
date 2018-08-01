// ITNOG
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int st[3 * N], a[N], b[N], lef[N], rig[N]; // I don't know why 3*N!
int n, q;
int off = 1e6;
int left(int p) { return p << 1; } // same as binary heap operations
int right(int p) { return (p << 1) + 1; }
int middle(int l, int r) { return (l + r) >> 1; }
void build(int p, int l, int r)
{
	if (l == r)
		st[p] = l;
	else
	{
		build(left(p), l, middle(l, r));
		build(right(p), middle(l, r) + 1, r);
		int p1 = st[left(p)], p2 = st[right(p)];
		st[p] = (b[p1] >= b[p2]) ? p1 : p2;
	}
}
int rmq(int p, int l, int r, int i, int j)
{
	if (i > r || j < l) return -1; // no overlap
	if (l >= i && r <= j) return st[p]; // total overlap
	int p1 = rmq(left(p), l, middle(l, r), i, j); // partial overlap
	int p2 = rmq(right(p), middle(l, r) + 1, r, i, j);
	if (p1 == -1) return p2;
	if (p2 == -1) return p1;
	return (b[p1] >= b[p2]) ? p1 : p2;
}
int main()
{
	while (cin >> n && n)
	{
		cin >> q;
		for (int i = 0;i < n;i++)
			cin >> a[i];
		a[n] = 1e9;
		int j = 0, cnt = 0;
		for (int i = 0;i < n;i++)
		{
			cnt++;
			if (a[i] != a[i + 1])
			{
				for (;j <= i;j++)
					b[j] = cnt;
				cnt = 0;
			}
		}
		lef[0] = 0;
		for (int i = 1;i < n;i++)
		{
			if (a[i] != a[i - 1])
			{
				lef[i] = i;
				continue;
			}
			lef[i] = lef[i - 1];
		}
		rig[n - 1] = n - 1;
		for (int i = n - 2;i >= 0;i--)
		{
			if (a[i] != a[i + 1])
			{
				rig[i] = i;
				continue;
			}
			rig[i] = rig[i + 1];
		}
		build(1, 0, n - 1);
		for (int k = 0;k < q;k++)
		{
			int i, j;
			cin >> i >> j;
			i--, j--;
			if (rig[i] == rig[j])
				cout << j - i + 1 << "\n";
			else if (rig[i] + 1 == lef[j])
			{
				cout << max(rig[i] - i + 1, j - lef[j] + 1) << "\n";
			}
			else
			{
				int l, r;
				l = rig[i] - i + 1;
				r = j - lef[j] + 1;
				cout << max(b[rmq(1, 0, n - 1, rig[i] + 1, lef[j] - 1)], max(l, r)) << "\n";
			}
		}
	}
}
