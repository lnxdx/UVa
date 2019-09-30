// ITNOA
#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int VAL = 7490;

ll dp[VAL][5];
int coins[] = { 1,5,10,25,50 };

int main()
{

	for (int i = 0;i < 5;i++)
		dp[0][i] = 1;
	for (int x = 1;x < VAL;x++)
		for (int i = 0;i < 5;i++)
			dp[x][i] = (x - coins[i] >= 0 ? dp[x - coins[i]][i] : 0) + (i ? dp[x][i-1] : 0);

	int val;
	while (cin >> val)
		cout << dp[val][4] << "\n";
}
