// ITNOG
// binary search O(n^2.logn) by lnxdx, 2018
// This solution is wrong for "-98 1 2 97 98" but got AC. So tests are very weak.

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 13;
ll INF = 1e9;

ll a[N];
int n;

struct Q
{
	ll sub, t, z; // t-z = sub
	Q(ll sub, ll t, ll z) :sub(sub), t(t), z(z) {};
};
vector<Q>q;

bool cmp1(Q a, Q b)
{
	if (a.sub > b.sub) return true;
	if (a.sub == b.sub) if (a.t > b.t) return true;
	return false;
}

bool cmp2(Q a, int val)
{
	if (a.sub > val) return true;
	return false;
}

int main()
{
	while (~scanf("%d", &n) && n)
	{
		q.clear();
		for (int i = 0;i < n;i++)
			scanf("%lld", a + i);

		sort(a, a + n);

		for (int i = 0;i < n;i++)
			for (int j = 0;j < n;j++)
			{
				ll z, t;
				z = a[i];
				t = a[j];
				if (z != t)
					q.push_back(Q(t - z, t, z));
			}

		sort(q.begin(), q.end(), cmp1);

		bool ans = false;
		ll MAX = -INF;
		for (int i = 0;i < n;i++)
			for (int j = i + 1;j < n;j++)
			{
				if (a[i] == a[j])
					continue;
				int x, y;
				x = a[i];
				y = a[j];
				// x + y = t - z (p = q)
				auto find = lower_bound(q.begin(), q.end(), x + y, cmp2); // binary search
				if (find != q.end() && find->sub == x + y
					&& find->z > y && find->t != x && find->t != y)
				{
					ans = true;
					MAX = max(find->t, MAX);
				}
			}
		if (ans)
			printf("%lld\n", MAX);
		else
			printf("no solution\n");
	}
}
