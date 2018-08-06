// ITNOG
// I Think O(2^n) Backtrack by lnxdx, Mashhad, 2018

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 13;

int a[N];
vector<int>ans;
int s, n,flag;

void bt(int i, int sum)
{
	if (sum == s)
	{
		flag = true;
		for (int i = 0;i < ans.size() - 1;i++)
			printf("%d+", ans[i]);
		printf("%d\n", ans.back());
		return;
	}
	for (int j = i;j < n;j++)
		if (sum + a[j] <= s && (j>i ? a[j] != a[j - 1] : true))
		{
			ans.push_back(a[j]);
			bt(j + 1, sum + a[j]);
			ans.pop_back();
		}
}

int main()
{
	while (scanf("%d%d", &s, &n) && n && s)
	{
		for (int i = 0;i < n;i++)
			scanf("%d", a + i);
		printf("Sums of %d:\n", s);		
		flag = false;		
		
		bt(0, 0);

		if (!flag)
			printf("NONE\n");
	}
}
