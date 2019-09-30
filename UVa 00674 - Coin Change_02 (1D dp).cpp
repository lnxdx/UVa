// ITNOA
#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int VAL = 1515;

int dp[VAL];
int coins[] = { 1,1,2,5,10 };

int main()
{
	dp[0] = 1;
	for (int i = 0;i < 5;i++)
		for (int x = 0;x < VAL;x++)
			dp[x + coins[i]] += dp[x];

	int val;
	while (~scanf("%d", &val))
		printf("%d\n", dp[val / 5]);
}
