// ITNOG
// greedy O(cs) by lnxdx, Mashhad, 2018
// At each step pick up the heaviest specimen and place it in the lightest chamber.
// I think O(s.logc) exists.

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 13;
int INF = 1e9;

int main()
{
	int c, s,casi=1;
	while (~scanf("%d%d", &c,&s))
	{
		int a[13] = { 0 };
		double ave = 0;
		for (int i = 0;i < s;i++)
		{
			scanf("%d", a + i);
			ave += a[i];
		}
		ave /= c;
		
		sort(a, a + s);;

		int b[13] = { 0 };
		vector<int>v[13];
		for (int i = s - 1;i >= 0;i--)
		{
			int min_i, MIN = INF;
			for (int j = 0;j < c;j++)
				if (b[j] < MIN && v[j].size() < 2)
					MIN = b[j], min_i = j;
			b[min_i] += a[i];
			v[min_i].push_back(a[i]);
		}
		double ans = 0;
		for (int i = 0;i < c;i++)
			ans += abs(b[i] - ave);

		printf("Set #%d\n", casi++);
		for (int i = 0;i < c;i++)
		{
			printf(" %d:", i);
			for (int j = 0;j < v[i].size();j++)
				printf(" %d", v[i][j]);
			printf("\n");
		}
		printf("IMBALANCE = %.5lf\n\n", ans);
	}
}
