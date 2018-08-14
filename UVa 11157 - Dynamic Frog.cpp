// ITNOG
// O(t.n) Greedy by lnxdx, Mashhad, 2018
// Choose small rocks every other rock.

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	int t, n, d;
	int casi = 1;
	scanf("%d", &t);
	while (t--)
	{
		bool odd = true;
		int ans = 0;
		int old_go_pos = 0;
		int old_back_pos = 0;
		scanf("%d%d", &n, &d);
		for (int i = 0;i <= n;i++)
		{
			char typ;
			int pos;
			if (i == n)
			{
				typ = 'B';
				pos = d;
			}
			else
				scanf(" %c-%d", &typ, &pos);
			if (typ == 'B')
			{
				ans = max(ans, pos - old_go_pos);
				ans = max(ans, pos - old_back_pos);
				old_go_pos = pos;
				old_back_pos = pos;
			}
			else
			{
				if (odd)
				{
					ans = max(ans, pos - old_go_pos);
					old_go_pos = pos;
				}
				else
				{
					ans = max(ans, pos - old_back_pos);
					old_back_pos = pos;
				}
				odd = !odd;
			}
		}
		printf("Case %d: %d\n", casi++, ans);
	}
}
