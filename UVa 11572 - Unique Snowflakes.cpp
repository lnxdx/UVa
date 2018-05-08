// ITNOG
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N];
map<int, int>ind;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ind.clear();

		int n;
		cin >> n;
		for (int i = 0;i < n;i++)
			cin >> a[i];
		
		int ans = 1;
		int l, r;
		l = 0, r = 0;
		while (r<n)
		{
			if (ind.count(a[r]) && ind[a[r]] >= l)
				l = ind[a[r]] + 1;
			ind[a[r]] = r;
			ans = max(ans, r - l + 1);
			r++;
		}

		cout << ans << "\n";
	}
}
