// ITNOA
// O(#tests.n) Two Pointers by lnxdx, Mashhad, 2019
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int a[N];
int main()
{
	int n, s;
	while (~scanf("%d%d", &n, &s))
	{
		for (int i = 0;i < n;i++)
			scanf("%d", a + i);

		int l, r;
		l = r = 0;
		ll sum = 0;
		int ansl, ansr;
		ansl = 0;
		ansr = n + 1;
		while (l<n)
		{
			if (sum >= s)
			{
				if (r - l < ansr - ansl)
				{
					ansl = l;
					ansr = r;
				}
			}
			if (sum < s)
			{
				if (r < n)
				{
					sum += a[r];
					r++;
				}
				else
				{
					sum -= a[l];
					l++;
				}
			}
			else
			{
				sum -= a[l];
				l++;
			}
		}

		if (ansr - ansl == n + 1)
			printf("0\n");
		else
			printf("%d\n", ansr - ansl);
	}
}
