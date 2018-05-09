// ITNOG
// O(n.logn) greedy by lnxdx, Mashhad, 2018

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4 + 13;
int INF = 1e9;
double EPS = 1e-9;

vector<pair<double, double>>intervals;

int main()
{
	ll n, l, w;	
	while (scanf("%lld%lld%lld", &n, &l, &w) != EOF)
	{
		intervals.clear();
		for (int i = 0;i < n;i++)
		{
			ll x, r;
			scanf("%lld%lld", &x, &r);
			if (r > w / 2.0)
			{
				double d = sqrt(r*r - (w / 2.0)*(w / 2.0));
				intervals.push_back({ x - d,x + d });
			}
		}
		
		sort(intervals.begin(), intervals.end());

		double covered = 0;
		int i = 0,ans=0;
		while(i < intervals.size()) // O(n)
		{
			double MAX=0, max_i,j=i;
			while (j < intervals.size())
			{
				double lef, rig;
				lef = intervals[j].first;
				rig = intervals[j].second;

				if (lef <= covered)
				{
					if (rig > MAX)
						MAX = rig, max_i = j;
				}
				else
					break;
				j++;
			}
			covered = MAX;
			ans++;
			if (i == j || covered>=l)
				break;
			i = j;
		}

		if (covered >= l)
			printf("%d\n", ans);
		else
			printf("-1\n");
	}

}
