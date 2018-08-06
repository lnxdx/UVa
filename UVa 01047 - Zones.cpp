#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define VI vector<int>
#define PII pair<int,int>
#define double long double

double PI = acosl(-1);
int INF = 1e8;
double EPS = 1e-12;

VI min_v(VI v1, VI v2)
{
	for (int i = 0;i < v1.size();i++)
		if (v1[i] < v2[i])
			return v1;
	return v2;
}

int main()
{
	int cnt[20];
	int n, k, casi = 1;;
	while (cin >> n >> k && n && k)
	{
		cout << "Case Number  " << casi++ << "\n";
		for (int i = 0;i < n;i++)
			cin >> cnt[i];
		int m;
		vector<int>shares[10];
		cin >> m;
		for (int i = 0;i < m;i++)
		{
			int t, c;
			cin >> t;
			for (int j = 0;j < t;j++)
			{
				int tower;
				cin >> tower;
				tower--;
				shares[i].push_back(tower);
			}
			cin >> c;
			shares[i].push_back(c);
		}
		int ans = 0;
		VI real_ans;
		for (int mask = 0;mask < (1 << n);mask++)
		{
			VI v;
			if (__builtin_popcount(mask) != k)
				continue;
			int sum = 0;
			for (int j = 0;j<n;j++)
				if (mask&(1 << j))
				{
					sum += cnt[j];
					v.push_back(j);
				}
			for (int i = 0;i < m;i++)
			{
				int common = 0;
				for (int j = 0;j < shares[i].size() - 1;j++)
					if ((mask&(1 << shares[i][j])))
						common++;
				if (common >= 2)
					sum -= (common - 1)*shares[i].back();
			}
			if (sum > ans)
			{
				ans = sum;
				real_ans = v;
			}
			else if (sum == ans)
			{
				real_ans = min_v(real_ans, v);
			}
		}

		cout << "Number of Customers: " << ans << "\n";
		cout << "Locations recommended: ";
		for (int i = 0;i<real_ans.size() - 1;i++)
			cout << real_ans[i] + 1 << " ";
		cout << real_ans.back() + 1;
		cout << "\n\n";
	}
}
