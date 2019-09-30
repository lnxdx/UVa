// ITNOA
#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int VAL = 7489 + 1;

ll dp[VAL];
int coins[] = { 1,5,10,25,50 };

int main()
{
	dp[0] = 1;
	for (int i = 0;i < 5;i++)
		for (int x = coins[i];x < VAL;x++)
			dp[x] += dp[x - coins[i]];

	int val;
	while (~scanf("%d", &val))
		printf("%lld\n", dp[val]);
}
