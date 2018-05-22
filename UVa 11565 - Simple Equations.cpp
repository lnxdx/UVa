// ITNOG
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int A, B, C;
		cin >> A >> B >> C;
		bool sol = false;
		int x, y, z;
		for (x = -21; x <= 21; x++) if (x * x <= C)
			for (y = x + 1; y <= 100; y++) if (x * x + y * y <= C)
				for (z = y + 1; z <= 100; z++)
					if (x + y + z == A &&
						x * y * z == B &&
						x * x + y * y + z * z == C)
					{
						printf("%d %d %d\n", x, y, z);
						sol = true;
						x = y = z = 1e6;
					}
		if (!sol)
			printf("No solution.\n");
	}
}
