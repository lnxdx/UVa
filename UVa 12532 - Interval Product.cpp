// ITNOG
// O(n + k.log(n)) Segment Tree by lnxdx, Mashhad, 2018

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 5;

int st[4 * N], a[N];
int n, k;

int left(int p) { return p << 1; } // same as binary heap operations
int right(int p) { return (p << 1) + 1; }
int middle(int l, int r) { return (l + r) >> 1; }
void build(int p, int l, int r)
{
	if (l == r)
		st[p] = a[l];
	else
	{
		build(left(p), l, middle(l, r));
		build(right(p), middle(l, r) + 1, r);
		int p1 = st[left(p)], p2 = st[right(p)];
		st[p] = p1*p2;
	}
}
void update(int p, int l, int r, int ind, int val)
{
	if (ind<l || ind>r) // no overlap
		return;
	if (l == r) // total overlap
	{
		a[ind] = val; // changed
		st[p] = val;
		return;
	}
	update(left(p), l, middle(l, r), ind, val); // partial everlap
	update(right(p), middle(l, r) + 1, r, ind, val);
	int p1 = st[left(p)], p2 = st[right(p)];
	st[p] = p1*p2;
}
int rpq(int p, int l, int r, int i, int j)
{
	if (i > r || j < l) return 1; // no overlap
	if (l >= i && r <= j) return st[p]; // total overlap
	int p1 = rpq(left(p), l, middle(l, r), i, j); // partial overlap
	int p2 = rpq(right(p), middle(l, r) + 1, r, i, j);
	return p1*p2;
}
int sign(int x)
{
	return -1 * (x < 0) + 1 * (x > 0);
}
int main()
{
	while (~scanf("%d%d",&n,&k))
	{
		for (int i = 0;i < n;i++)
		{
			scanf("%d", a + i);
			a[i] = sign(a[i]);
		}

		build(1, 0, n - 1);

		for (int i = 0;i < k;i++)
		{
			char typ;
			scanf(" %c", &typ);
			if (typ == 'C')
			{
				int ind, val;
				scanf("%d%d", &ind, &val);
				ind--;
				update(1, 0, n - 1, ind, sign(val));
			}
			else
			{
				int l, r;
				scanf("%d%d", &l, &r);
				l--, r--;
				int p = rpq(1, 0, n - 1, l, r);
				printf("%c", (p > 0 ? '+' :( p < 0 ? '-' : '0')));
			}
		}
		printf("\n");
	}
}
