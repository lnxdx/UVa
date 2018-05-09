// ITNOG
// O(n) greedy by lnxdx, Mashhad, 2018

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 13;
int INF = 1e9;

int main()
{
	int t, n, casi = 1;
	char s[111];
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		scanf("%s", s);

		int ans = 0;
		int i = 1;
		while (i < n)
		{
			if (s[i - 1] == '.')
			{
				s[i] = s[i - 1] = s[i + 1] = '#';
				ans++;
				i += 3;
			}
			else
				i++;
		}
		if (s[n - 1] == '.')
			ans++;

		printf("Case %d: %d\n", casi++, ans);
	}

}
