#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n;;
	m = n;
	int a[111][111];
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			cin >> a[i][j];
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
	int ans = a[1][1];
	for (int i = 1;i <= n;i++)
		for (int j = i;j <= n;j++)
			for (int k = 1;k <= m;k++)
				for (int l = k;l <= m;l++)
					ans = max(ans, a[j][l] - a[j][k - 1] - a[i - 1][l] + a[i - 1][k - 1]);
	cout << ans << "\n";
}
