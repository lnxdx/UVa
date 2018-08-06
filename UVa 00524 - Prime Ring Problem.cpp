#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, a[16] = { 1 }, mask;

bool is_prime(int n)
{
	for (int d = 2;d*d <= n;d++)
		if (n%d == 0)
			return false;
	return n >= 2;
}
void BT(int i)
{
	if (i == n && is_prime(a[0] + a[n - 1]))
	{
		cout << a[0]  ;
		for (int j = 1;j < n;j++)
			cout << " " << a[j];
		cout << "\n";
		return;
	}
	for (int j = 2;j <= n;j++)
		if (((1 << j)&mask) == 0 && is_prime(a[i - 1] + j))
		{
			a[i] = j;
			mask |= (1 << j);
			BT(i + 1);
			mask ^= (1 << j);
		}
}

int main()
{
	int casi = 0;
	while (cin >> n)
	{
		if (casi)
			cout << "\n";
		cout << "Case " << ++casi << ":\n";
		BT(1);
	}
}
