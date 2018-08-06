// ITNOG
#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int VAL = 7490;

ll dp[VAL][5];
int coins[] = { 1,5,10,25,50 };

ll f(int x, int i)
{
	if (i < 0 || x < 0)
		return false;
	if (x == 0)
		return dp[x][i] = true;
	if (dp[x][i])
		return dp[x][i];
	return dp[x][i] = f(x - coins[i], i) + f(x, i - 1);
}

int main()
{

	for (int x = 0;x <= VAL;x++)
		for (int i = 0;i < 5;i++)
			f(x, i);

	int val;
	while (cin >> val)
		cout << dp[val][4] << "\n";
}
