// ITNOG

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MSK = 1 << 15;
const int N = 23;
const int H = 113;

int in[N];
char dp[H][MSK], visit = 0;
int sum[1 << 15];
int popcount[1 << 15];


int subset_sum(int mask) {
	int resp = 0; int i = 0;
	while (mask>0) { if (mask & 1 == 1) resp += in[i]; mask >>= 1; i++; }
	return resp;
}

bool f(int y, int mask)
{
	if (dp[y][mask] == visit)
		return false;
	if (dp[y][mask] == visit + 1)
		return true;
	int x = sum[mask] / y;
	if (popcount[mask] == 1 && sum[mask] == x * y)
	{
		dp[y][mask] = visit + 1;
		return true;
	}
	for (int i = 1;i<y;i++)
	{
		int s = mask;
		while (s)
		{
			s = (s - 1) & mask; // Tests all possible subsets of s which also is a subset of mask.
								// horizontal 
			if (x * (y - i) == sum[s] && x * (i) == sum[(~s)&mask])
				if (f(max(x, y - i), s) && f(max(x, i), ((~s)&mask)))
				{
					dp[y][mask] = visit + 1;
					return true;
				}
			// vertical
			if ((i < x) && (x - i) * (y) == sum[s] && (i)*(y) == sum[(~s)&mask])
				if (f(max(x - i, y), s) && f(max(i, y), ((~s)&mask)))
				{
					dp[y][mask] = visit + 1;
					return true;
				}
		}
	}
	dp[y][mask] = visit;
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, casi = 1;
	for (int i = 0; i < (1 << 15); i++)
		popcount[i] = __builtin_popcount(i);
	while (scanf("%d", &n) > 0 && n)
	{
		visit += 2;
		ll total_sum = 0;
		int x, y;
		scanf("%d%d", &x, &y);
		for (int i = 0;i<n;i++)
		{
			scanf("%d", in + i);
			total_sum += in[i];
		}
		if (total_sum != x * y)
			printf("Case %d: No\n", casi++);
		else
		{
			for (int i = 0; i< (1 << n); i++)
				sum[i] = subset_sum(i);
			if (f(max(x, y), ((1 << n) - 1)))
				printf("Case %d: Yes\n", casi++);
			else
				printf("Case %d: No\n", casi++);
		}
	}
	return 0;
}
